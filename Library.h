#pragma once
#include <vector>
#include <string>
#include <memory> 
#include "Shelf.h"
#include "Member.h" 

using namespace std;

class Item; 

class Library {
private:
    vector<unique_ptr<Item>> items; 
    vector<Shelf> shelves; 
    vector<Member> members;
    int itemCounter; 

public:
    Library(); 
    ~Library() = default;

    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;
    Library(Library&&) noexcept = default;
    Library& operator=(Library&&) noexcept = default;

    string addBook(string title, string author, int pages); 
    string addMagazine(string title, string author, int issueNumber); 
    void addShelf(string name, int capacity); 
    bool placeItemToShelf(const string& itemId, const string& shelfName); 
    
    Item* findById(const string& id); 
    vector<Item*> searchByTitle(const string& title) const; 
    
    Member* addMember(string memberId, string name);
    Member* getMemberByName(const string& name);

    bool borrowItem(const string& memberName, const string& itemId);
    bool returnItem(const string& memberName, const string& itemId);
    void checkEmptySlots() const;
    void report() const; 

private:
    bool removeItemFromShelves(const string& itemId);
    bool placeItemOnFirstAvailableShelf(Item* item, string& shelfName);
    Shelf* getShelfByName(const string& name);
};