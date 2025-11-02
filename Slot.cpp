#include "Slot.h"
#include "Item.h" 

using namespace std;

Slot::Slot(int index) : index(index), placedItem(nullptr) {}

bool Slot::isEmpty() const {
    return placedItem == nullptr;
}

void Slot::placeItem(Item* item) {
    placedItem = item;
}

void Slot::remove() {
    placedItem = nullptr;
}

Item* Slot::getItem() const {
    return placedItem;
}