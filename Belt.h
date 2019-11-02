#ifndef __BELT_H
#define __BELT_H

#include <string>
#include <vector>

#include "Item.h"
#include "SimulatedComponent.h"

enum struct Lane { left, right };

class Belt : public SimulatedComponent {
    private:
        std::vector<Item> items;
        Belt *prev;
        Belt *next;
        
    public:
        Belt();
        void tick(int time);
};

#endif

