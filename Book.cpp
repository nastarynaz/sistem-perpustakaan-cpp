#include "Book.h"

using namespace std;

Book::Book(string id, string title, string author, int pages)
    : Item(id, title, author), pages(pages) {}

void Book::display() const {
    cout << "ID: " << id << ", "
         << "Title: " << title << ", "
         << "Author: " << author << ", "
         << "Pages: " << pages;
}