#pragma once
#include "Item.h"

using namespace std;

class Book : public Item {
private:
    int pages; 

public:
    Book(string id, string title, string author, int pages); 
    void display() const override; 
};