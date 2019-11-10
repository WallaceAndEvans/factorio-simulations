#ifndef __ITEM_H
#define __ITEM_H

#include <ostream>
#include <vector>

#include "SimulatedComponent.h"

class Item {
    public:
        struct HistoryEntry {
            SimulatedComponent *host;
            Lane::Type lane;
            unsigned pos;
            unsigned times;
            bool operator==(const HistoryEntry& other) const;
            size_t operator()(const HistoryEntry& entry) const;
        };

    private:
        std::vector<HistoryEntry> history;
        
    public:
        Item(SimulatedComponent* host, Lane::Type lane, unsigned pos);

        unsigned getNumTicks() const;
        const HistoryEntry &getCurrentLocation() const;
        const HistoryEntry &getSource() const;

        // history control
        void noop();
        void move(SimulatedComponent *host, Lane::Type lane, unsigned pos);
        void walk(SimulatedComponent *host, unsigned pos);
        void walk();
};

std::ostream& operator<<(std::ostream& out, const Item::HistoryEntry &entry);
std::ostream& operator<<(std::ostream& out, const Item* item);

#endif

