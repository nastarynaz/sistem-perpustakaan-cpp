#include "Shelf.h"
#include "Item.h"
#include <iostream>

using namespace std;

Shelf::Shelf(string name, int capacity) : name(name) {
    for (int i = 0; i < capacity; ++i) {
        slots.emplace_back(i); 
    }
}

int Shelf::getCapacity() const {
    return slots.size();
}

string Shelf::getName() const {
    return name;
}

const vector<Slot>& Shelf::getSlots() const {
    return slots;
}

bool Shelf::placeItem(Item* item) {
    for (Slot& slot : slots) {
        if (slot.isEmpty()) {
            slot.placeItem(item);
            return true;
        }
    }
    return false; 
}

bool Shelf::removeItem(const string& itemId) {
    for (Slot& slot : slots) {
        if (!slot.isEmpty() && slot.getItem()->getId() == itemId) {
            slot.remove();
            return true;
        }
    }
    return false; 
}

int Shelf::emptyCount() const {
    int count = 0;
    for (const Slot& slot : slots) {
        if (slot.isEmpty()) {
            count++;
        }
    }
    return count;
}

void Shelf::summary() const {
    cout << "  Shelf: " << name 
         << " (Empty Slots: " << emptyCount() << "/" << slots.size() << ")" << endl;
    for (const Slot& slot : slots) {
        if (!slot.isEmpty()) {
            cout << "    - ";
            slot.getItem()->display();
        }
    }
}