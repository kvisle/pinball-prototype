#include <cstdio>
#include <algorithm>
#include <stdint.h>

using namespace std;

#include <Box2D/Box2D.h>

#include "b2dJson.h"
#include "box.h"
#include "collide.h"

static std::string
readInput( const char *path )
{
    FILE *file = fopen( path, "rb" );
    if ( !file )
        return std::string("");
    fseek( file, 0, SEEK_END );
    long size = ftell( file );
    fseek( file, 0, SEEK_SET );
    std::string text;
    char *buffer = new char[size+1];
    buffer[size] = 0;
    if ( fread( buffer, 1, size, file ) == (unsigned long)size )
        text = buffer;
    fclose( file );
    delete[] buffer;
    return text;
}

box::box(const char *s)
{
    std::string conf = readInput(s);
//    b2dJson json(true);
    cl *listener = new cl(this);

    world = json.readFromString(conf);
    world->SetContactListener(listener);

    world->SetDebugDraw(&dbd);
    dbd.SetFlags(b2Draw::e_shapeBit + b2Draw::e_jointBit);
    timeStep = 1.0f/90.f;
    velocityIterations = 8;
    positionIterations = 10;

    launcher = (b2PrismaticJoint*) json.getJointByName("launcher");

    vector<b2Joint*> f;
    json.getJointsByName("flip_left", f);
    leftFlipper = (b2RevoluteJoint*)f[0];
    leftFlipper->SetMotorSpeed(-10);

    f.clear();
    json.getJointsByName("flip_right", f);
    rightFlipper = (b2RevoluteJoint*)f[0];
    rightFlipper->SetMotorSpeed(10);
}

void box::flipOff(b2RevoluteJoint *f)
{
    f->SetMotorSpeed(-10);
}

void box::flipOn(b2RevoluteJoint *f)
{
    f->SetMotorSpeed(20);
}

void box::flip(int id, int on)
{
    switch(id)
    {
    case 0:
        if ( on ) leftFlipper->SetMotorSpeed(20);
        else leftFlipper->SetMotorSpeed(-10);
        break;
    case 1:
        if ( on ) rightFlipper->SetMotorSpeed(-20);
        else rightFlipper->SetMotorSpeed(10);
        break;
    }
}

void box::launch(int on)
{
    if ( !on )
        launcher->SetMotorSpeed(-6);
    else
        launcher->SetMotorSpeed(1);
}

void box::step(void)
{
    world->Step(timeStep, velocityIterations, positionIterations);
    world->ClearForces();
}

box::~box()
{

}

void box::newball(float x, float y)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.bullet = true;

    b2Body* body = world->CreateBody(&bodyDef);

    b2CircleShape circle;
    circle.m_radius = 0.04f;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 20.0f;
    fixtureDef.friction = 0.f;
    fixtureDef.restitution = 0.2f;
    fixtureDef.filter.groupIndex = 0;
    fixtureDef.filter.maskBits = 0x1;
    fixtureDef.filter.categoryBits = 0x001;
    body->CreateFixture(&fixtureDef);


    balls.push_back(body);
}
