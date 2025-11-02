#pragma once
#include <string>
#include <vector>

using namespace std;

class Item; 

class Member {
private:
    string memberId; 
    string name; 
    vector<Item*> loans; 

public:
    Member(string memberId, string name); 
    bool borrow(Item* item); 
    bool giveBack(const string& itemId); 
    void listLoans() const; 

    const vector<Item*>& getLoans() const;
    string getName() const; 
};