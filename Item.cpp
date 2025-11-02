#include "Item.h"

using namespace std;

Item::Item(string id, string title, string author)
    : id(id), title(title), author(author), borrowed(false) {}

string Item::getId() const {
    return id;
}

string Item::getTitle() const {
    return title;
}

bool Item::isBorrowed() const {
    return borrowed;
}

void Item::setBorrowed(bool status) {
    borrowed = status;
}