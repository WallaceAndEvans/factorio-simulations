#include <iostream>

#include "Item.h"
#include "Belt.h"
#include "Splitter.h"
#include "SimulatedComponent.h"

int main() {
    std::cout << "Hello, world" << std::endl;
    const Item i = Item(123);
    std::cout << "Item: " << i.getSource() << std::endl;
    Belt b1 = Belt();
    Belt b2 = Belt();
    std::cout << "Belt b1 name: " << b1.getName() << std::endl;
    std::cout << "Belt b2 name: " << b2.getName() << std::endl;
    std::cout << "Belt b2 tick:" << std::endl;
    b2.tick(39);
    SimulatedComponent *c1 = &b1;
    SimulatedComponent *c2 = &b2;
    std::cout << "SimulatedComponent c1 tick:" << std::endl;
    c1->tick(39);
    std::cout << "SimulatedComponent c2 tick:" << std::endl;
    c2->tick(39);
    return 0;
}

