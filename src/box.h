#ifndef __BOX_H__
#define __BOX_H__

using namespace std;

#include <Box2D/Box2D.h>
#include <json/json.h>

#include "b2dJson.h"
#include "Render.h"

class box {
    private:
        DebugDraw dbd;
        float32 timeStep;
        int32 velocityIterations;
        int32 positionIterations;

        b2RevoluteJoint *leftFlipper;
        b2RevoluteJoint *rightFlipper;
        b2PrismaticJoint *launcher;

        void flipOn(b2RevoluteJoint *f);
        void flipOff(b2RevoluteJoint *f);
        void newball(float x, float y);

    public:
        b2World *world;

        b2dJson json;

        vector<b2Body*> balls;
        void flip(int id, int on);
        void launch(int on);
        box(const char *s);
        void step(void);
        ~box();
};


#endif /* __BOX_H__ */
