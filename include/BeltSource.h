#ifndef __BELT_SOURCE_H
#define __BELT_SOURCE_H

#include <vector>

#include "Belt.h"
#include "Item.h"

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
