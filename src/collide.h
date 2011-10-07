#include <Box2D/Box2D.h>

#include "box.h"

class cl : public b2ContactListener
{
    private:
        box * b;

    public:
        cl(box * bo) : b2ContactListener() { b = bo; }

        void BeginContact (b2Contact *contact);
        void EndContact (b2Contact *contact);
        void PreSolve (b2Contact *contact, const b2Manifold *oldManifold);
        void PostSolve (b2Contact *contact, const b2ContactImpulse *impulse);
};

