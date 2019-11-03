#ifndef __BELT_SINK_H
#define __BELT_SINK_H

#include "Item.h"
#include "Belt.h"

class BeltSink : public Belt {
    typedef unsigned collected_t[Lane::COUNT];

    private:
        //unsigned collected[Lane::COUNT];
        collected_t collected;

    public:
        BeltSink();

        virtual void tick(unsigned time);

        const collected_t &getCounts() const;
};

#endif

