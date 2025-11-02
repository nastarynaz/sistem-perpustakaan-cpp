#pragma once
#include <string>

using namespace std;

class Item; 

class Slot {
private:
    int index; 
    Item* placedItem; 

public:
    Slot(int index); 
    bool isEmpty() const; 
    void placeItem(Item* item); 
    void remove(); 
    Item* getItem() const;
};