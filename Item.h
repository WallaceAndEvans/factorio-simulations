#ifndef __ITEM_H
#define __ITEM_H

#include <vector>

#include "SimulatedComponent.h"

struct HistoryEntry {
    SimulatedComponent *host;
};

class Item {
    private:
        int source;
        std::vector<HistoryEntry> history;
        
    public:
        Item(int);
        int getSource() const;

        // history control
        void noop();
};

#endif

