#ifndef __ITEM_H
#define __ITEM_H

#include <vector>

#include "SimulatedComponent.h"

class Item {
    struct HistoryEntry {
        SimulatedComponent *host;
        Lane::Type lane;
        unsigned pos;
    };

    private:
        //int source;
        std::vector<HistoryEntry> history;
        
    public:
        //Item();
        //int getSource() const;

        // history control
        void noop();
        void move(SimulatedComponent *container, Lane::Type lane, unsigned pos);
        void walk(SimulatedComponent *container, unsigned pos);
        void walk(SimulatedComponent *container);
};

#endif

