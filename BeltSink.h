#ifndef __BELT_SINK_H
#define __BELT_SINK_H

#include <unordered_map>

#include "Item.h"
#include "Belt.h"

class BeltSink : public Belt {
    typedef std::unordered_map<Item::HistoryEntry, unsigned, Item::HistoryEntry> consumed_info_t;
    typedef std::unordered_map<Lane::Type, consumed_info_t, std::hash<int>> consumed_t;

    private:
        consumed_t consumed;

    protected:
        virtual void tick(unsigned time);

    public:
        BeltSink();
        virtual ~BeltSink();

        const consumed_t &getConsumed() const;
};

#endif

