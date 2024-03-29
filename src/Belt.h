#ifndef __BELT_H
#define __BELT_H

#include <string>
#include <vector>

#include "Item.h"
#include "SimulatedComponent.h"


class Belt : public SimulatedComponent {
    typedef Item *Storage[LANE_LENGTH];

    private:
        Belt *prev;
        Belt *next;

        bool willPushItem() const;
        void push(Item* &src, Item* &dest, Belt *other = nullptr);
        void pushEndOfLane(Lane::Type lane);

    protected:
        Storage lanes[Lane::COUNT];

        Belt(std::string name);

        virtual void tick(unsigned time);
        
    public:
        Belt();
        virtual ~Belt();

        void setNext(Belt *next);
        void setPrev(Belt *prev);
        Belt *getNext() const;
        Belt *getPrev() const;
};

#endif

