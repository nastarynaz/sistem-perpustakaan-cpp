#pragma once
#include <vector>
#include <string>
#include "Slot.h"

using namespace std;

class Item; 

class Shelf {
private:
    string name; 
    vector<Slot> slots; 

public:
    Shelf(string name, int capacity); 
    bool placeItem(Item* item); 
    bool removeItem(const string& itemId); 
    int emptyCount() const; 
    void summary() const; 

    string getName() const;
    const vector<Slot>& getSlots() const;
    int getCapacity() const; 
};