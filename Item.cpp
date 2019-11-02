#include "Item.h"

Item::Item(int source): source(source) {}

int Item::getSource() const {
    return this->source;
}


