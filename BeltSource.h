#ifndef __BELT_SOURCE_H
#define __BELT_SOURCE_H

#include <vector>

#include "Item.h"
#include "Belt.h"

class BeltSource : public Belt {
    private:
        static std::vector<Item*> ledger;

    public:
        BeltSource();
        ~BeltSource();
        virtual void tick(unsigned time);
};

#endif

