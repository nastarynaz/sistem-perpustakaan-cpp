#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item {
protected:
    string id;
    string title;
    string author;
    bool borrowed;

public:
    Item(string id, string title, string author);
    virtual ~Item() = default;

    virtual void display() const = 0; 

    string getId() const;
    string getTitle() const;
    bool isBorrowed() const;
    void setBorrowed(bool status);
};