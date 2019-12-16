#ifndef __BELT_SOURCE_H
#define __BELT_SOURCE_H

#include <vector>

#include "Item.h"
#include "Belt.h"

class BeltSource : public Belt {
    private:
        unsigned created;

        void populateItems();

    protected:
        virtual void tick(unsigned time);

    public:
        BeltSource();
        unsigned getNumCreated() const;
};

#endif

