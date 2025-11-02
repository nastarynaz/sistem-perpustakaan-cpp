#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include <iostream>
#include <algorithm>

using namespace std;

Library::Library() : itemCounter(0) {}

string Library::addBook(string title, string author, int pages) {
    string id = "B" + to_string(++itemCounter);
    items.push_back(make_unique<Book>(id, title, author, pages));
    return id;
}

string Library::addMagazine(string title, string author, int issueNumber) {
    string id = "M" + to_string(++itemCounter);
    items.push_back(make_unique<Magazine>(id, title, author, issueNumber));
    return id;
}

void Library::addShelf(string name, int capacity) {
    shelves.emplace_back(name, capacity);
    cout << "Rak '" << name << "' dengan kapasitas " << capacity << " ditambahkan." << endl;
}

bool Library::placeItemToShelf(const string& itemId, const string& shelfName) {
    Item* item = findById(itemId);
    Shelf* shelf = getShelfByName(shelfName); 

    if (!item || !shelf) {
        cout << "Error: Item atau Rak tidak ditemukan." << endl;
        return false;
    }

    if (shelf->placeItem(item)) {
        cout << "Item '" << item->getTitle() 
             << "' berhasil ditempatkan di rak '" << shelf->getName() << "'." << endl;
        return true;
    }
    return false;
}

Item* Library::findById(const string& id) {
    auto it = find_if(items.begin(), items.end(), 
        [&](const auto& itemPtr){ return itemPtr->getId() == id; });
    
    Item* item = (it != items.end()) ? it->get() : nullptr;

    if (!item) {
        cout << "Item '" << id << "' tidak ditemukan." << endl;
    }
    return item;
}

vector<Item*> Library::searchByTitle(const string& title) const {
    vector<Item*> results;
    for (const auto& itemPtr : items) {
        if (itemPtr->getTitle().find(title) != string::npos) {
            results.push_back(itemPtr.get());
        }
    }
    return results;
}

Member* Library::addMember(string memberId, string name) {
    members.emplace_back(memberId, name);
    return &members.back();
}

Member* Library::getMemberByName(const string& name) {
     auto it = find_if(members.begin(), members.end(), 
        [&](const Member& m){ return m.getName() == name; });
    return (it != members.end()) ? &(*it) : nullptr;
}

Shelf* Library::getShelfByName(const string& name) {
     auto it = find_if(shelves.begin(), shelves.end(), 
        [&](const Shelf& s){ return s.getName() == name; });
    return (it != shelves.end()) ? &(*it) : nullptr;
}

bool Library::borrowItem(const string& memberName, const string& itemId) {
    Member* member = getMemberByName(memberName);
    Item* item = findById(itemId);

    if (!member || !item) {
        cout << "Peminjaman gagal: Member atau Item tidak ditemukan." << endl;
        return false;
    }

    if (!removeItemFromShelves(itemId)) {
        if (item->isBorrowed()) {
            cout << "Peminjaman gagal: item " << item->getId() << " sudah dipinjam." << endl;
        } else {
            cout << "Pencarian gagal: item " << item->getId() << " tidak ada di rak manapun." << endl;
        }
        return false;
    }

    return member->borrow(item);
}

bool Library::returnItem(const string& memberName, const string& itemId) {
    Member* member = getMemberByName(memberName);
    Item* item = findById(itemId);

    if (!member || !item) {
        cout << "Pengembalian gagal: Member atau Item tidak ditemukan." << endl;
        return false;
    }

    if (member->giveBack(itemId)) {
        string shelfName = "";
        if (placeItemOnFirstAvailableShelf(item, shelfName)) {
            cout << "Item '" << item->getTitle() << "' berhasil ditempatkan di rak '" << shelfName << "'." << endl;
            cout << "Pengembalian berhasil: Item " << item->getId() << " dikembalikan ke rak '" << shelfName << "'." << endl;
            return true;
        } else {
            cout << "Pengembalian gagal: Tidak ada ruang di rak manapun untuk " << item->getId() << "." << endl;
            return false;
        }
    }
    cout << "Pengembalian gagal: " << memberName << " tidak memiliki item " << itemId << "." << endl;
    return false;
}

void Library::checkEmptySlots() const {
    cout << "\nMengecek slot kosong :" << endl;
    for (const auto& shelf : shelves) {
        cout << "Rak '" << shelf.getName() << "' slot kosong: " << shelf.emptyCount() << endl;
    }
}

void Library::report() const {
    cout << "\nRingkasan Perpustakaan:" << endl;
    cout << "\nTotal Item di Perpustakaan: " << items.size() << endl;
    
    cout << "Status Rak:" << endl;
    vector<Item*> borrowedItems; 

    for (const auto& shelf : shelves) {
        cout << "\nRingkasan Rak: " << shelf.getName() << endl;
        cout << "Kapasitas: " << shelf.getCapacity() << " slot" << endl;
        cout << "Slot Kosong: " << shelf.emptyCount() << " slot" << endl;
        cout << "Daftar Item:" << endl;
        
        const auto& slots = shelf.getSlots();
        for (const auto& slot : slots) {
            if (!slot.isEmpty()) {
                slot.getItem()->display();
                cout << endl;
            }
        }
    }

    for (const auto& member : members) {
        for (Item* item : member.getLoans()) {
            borrowedItems.push_back(item);
        }
    }

    cout << "\nItem yang Dipinjam:" << endl;
    if (borrowedItems.empty()) {
        cout << "Tidak ada item yang sedang dipinjam." << endl;
    } else {
        for (Item* item : borrowedItems) {
            item->display();
            cout << endl;
        }
    }
    cout << "\nLaporan selesai." << endl;
}

bool Library::removeItemFromShelves(const string& itemId) {
    for (auto& shelf : shelves) {
        if (shelf.removeItem(itemId)) {
            return true;
        }
    }
    return false; 
}

bool Library::placeItemOnFirstAvailableShelf(Item* item, string& shelfName) {
    for (auto& shelf : shelves) {
        if (shelf.placeItem(item)) {
            shelfName = shelf.getName(); 
            return true;
        }
    }
    return false; 
}