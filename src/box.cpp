#include <cstdio>
#include <algorithm>
#include <stdint.h>

using namespace std;

#include <Box2D/Box2D.h>

#include "b2dJson.h"
#include "box.h"

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
    b2dJson json(true);

//    cout << "look, json:"  << conf << endl;

    world = json.readFromString(conf);

    world->SetDebugDraw(&dbd);
    dbd.SetFlags(b2Draw::e_shapeBit);
    timeStep = 1.0f/60.f;
    velocityIterations = 8;
    positionIterations = 3;

    vector<b2Joint*> f;
    json.getJointsByName("flip_left", f);
    leftFlipper = (b2RevoluteJoint*)f[0];
    flipOff(leftFlipper);
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
        if ( on ) flipOn(leftFlipper);
        else flipOff(leftFlipper);
        break;
    }
}

void box::step(void)
{
    world->Step(timeStep, velocityIterations, positionIterations);
    world->ClearForces();
}

box::~box()
{

}
