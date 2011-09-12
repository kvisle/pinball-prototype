#ifndef __BOX_H__
#define __BOX_H__

#include <Box2D/Box2D.h>
#include <json/json.h>

#include "Render.h"

class box {
    private:
        DebugDraw dbd;
        float32 timeStep;
        int32 velocityIterations;
        int32 positionIterations;

        b2RevoluteJoint *leftFlipper;
        b2RevoluteJoint *rightFlipper;

        void flipOn(b2RevoluteJoint *f);
        void flipOff(b2RevoluteJoint *f);

    public:
        b2World *world;

        void flip(int id, int on);
        box(const char *s);
        void step(void);
        ~box();
};


#endif /* __BOX_H__ */
