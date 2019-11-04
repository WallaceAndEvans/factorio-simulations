#ifndef __BELT_SINK_H
#define __BELT_SINK_H

#include <unordered_map>

#include "Item.h"
#include "Belt.h"

class BeltSink : public Belt {
    typedef std::unordered_map<Lane::Type, unsigned, std::hash<int>> consumed_t;

    private:
        consumed_t consumed;

    public:
        BeltSink();
        virtual ~BeltSink();

        virtual void tick(unsigned time);

        const consumed_t &getConsumed() const;
};

#endif

