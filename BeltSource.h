#ifndef __BELT_SOURCE_H
#define __BELT_SOURCE_H

#include <vector>

#include "Item.h"
#include "Belt.h"

class BeltSource : public Belt {
    private:
        unsigned created;
        static unsigned referenceCount;
        static std::vector<Item*> ledger;

        void populateItems();

    public:
        BeltSource();
        virtual ~BeltSource();
        virtual void tick(unsigned time);
        unsigned getNumCreated() const;
};

#endif

