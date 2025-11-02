#include "Member.h"
#include "Item.h"
#include <iostream>
#include <algorithm> 

using namespace std;

Member::Member(string memberId, string name) : memberId(memberId), name(name) {}

string Member::getName() const {
    return name;
}

const vector<Item*>& Member::getLoans() const {
    return loans;
}

bool Member::borrow(Item* item) {
    if (!item) return false;

    if (item->isBorrowed()) {
        return false;
    }

    item->setBorrowed(true);
    loans.push_back(item);
    
    cout << "Peminjaman berhasil: " << name << " meminjam '" << item->getTitle() << "'." << endl;
    return true;
}

bool Member::giveBack(const string& itemId) {
    auto it = find_if(loans.begin(), loans.end(), 
        [&](Item* item){ return item->getId() == itemId; });

    if (it != loans.end()) {
        (*it)->setBorrowed(false); 
        loans.erase(it);
        return true;
    }
    return false;
}

void Member::listLoans() const {
    cout << "Daftar pinjaman untuk: " << name << ":" << endl;
    if (loans.empty()) {
        cout << name << " tidak memiliki pinjaman." << endl;
        return;
    }
    for (const Item* item : loans) {
        item->display();
        cout << endl; 
    }
}