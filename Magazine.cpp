#include "Magazine.h"

using namespace std;

Magazine::Magazine(string id, string title, string author, int issueNumber)
    : Item(id, title, author), issueNumber(issueNumber) {}

void Magazine::display() const {
    cout << "ID: " << id << ", "
         << "Title: " << title << ", "
         << "Author: " << author << ", "
         << "Issue: " << issueNumber;
}