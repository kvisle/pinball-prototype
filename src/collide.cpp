#include <cstdio>

#include "b2dJson.h"
#include "collide.h"

void
cl::BeginContact (b2Contact *contact)
{
//    puts("BeginContact()");
}


void
cl::EndContact (b2Contact *contact)
{
//    puts("EndContact()");
}


void
cl::PreSolve (b2Contact *contact, const b2Manifold *oldManifold)
{
    b2Body *ba = contact->GetFixtureA()->GetBody();
    b2Body *bb = contact->GetFixtureB()->GetBody();
    b2Body *ball, *other;
    std::string othername;

    if ( std::find(b->balls.begin(), b->balls.end(), ba) != b->balls.end() )
    {
        ball = ba;
        other = bb;
    }
    else if ( std::find(b->balls.begin(), b->balls.end(), bb) != b->balls.end() )
    {
        ball = bb;
        other = ba;
    }
    else
    {
        // No balls.
        return;
    }

    othername = b->json.getBodyName(other);

    b2WorldManifold worldManifold;
    contact->GetWorldManifold(&worldManifold);
    b2Vec2 point = worldManifold.points[0];
    b2Vec2 vA = ba->GetLinearVelocityFromWorldPoint(point);
    b2Vec2 vB = bb->GetLinearVelocityFromWorldPoint(point);
    float32 approachVelocity = b2Dot(vB - vA, worldManifold.normal);
    if ( approachVelocity < 0 ) approachVelocity *= -1.0;

    if ( othername.compare("bumper") == 0 && approachVelocity >= 0.3 )
    {
        printf("BUMP! (%f)\n", approachVelocity);
    }
    else if ( othername.compare("slingshot") == 0 && approachVelocity >= 0.3 )
    {
        printf("SLING! (%f)\n", approachVelocity);
    }
    else if ( othername.compare("destroyball") == 0 )
    {
        b->balls.erase(std::find(b->balls.begin(), b->balls.end(), ball));
        b->destroy.push_back(ball);
    }
    else if ( othername.compare("onramp") == 0 )
    {
        b2Fixture *fix;
        b2Filter fd;

        puts("We're going up!");
        if ( ball == ba )
        {
            fix = contact->GetFixtureA();
        }
        else
        {
            fix = contact->GetFixtureB();
        }

        fd = fix->GetFilterData();

        fd.groupIndex = 0;
        fd.maskBits = 0x2;
        fd.categoryBits = 0x002;
        fix->SetFilterData(fd);

        contact->SetEnabled(false);
    }
    else if ( othername.compare("offramp") == 0 )
    {
        b2Fixture *fix;
        b2Filter fd;

        puts("We're going off!");
        if ( ball == ba )
        {
            fix = contact->GetFixtureA();
        }
        else
        {
            fix = contact->GetFixtureB();
        }

        fd = fix->GetFilterData();

        fd.groupIndex = 0;
        fd.maskBits = 0x1;
        fd.categoryBits = 0x001;
        fix->SetFilterData(fd);

        contact->SetEnabled(false);

    }
}


void
cl::PostSolve (b2Contact *contact, const b2ContactImpulse *impulse)
{
//    puts("PostSolve()");
}

