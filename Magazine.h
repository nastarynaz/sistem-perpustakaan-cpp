#pragma once
#include "Item.h"

using namespace std;

class Magazine : public Item {
private:
    int issueNumber; 

public:
    Magazine(string id, string title, string author, int issueNumber); 
    void display() const override; 
};