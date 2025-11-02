#include <iostream>
#include <vector>
#include <string>
#include "Library.h"
#include "Member.h"
#include "Item.h"

using namespace std;

int main() {
    cout << "===== Memulai Skenario Pengujian Perpustakaan =====" << endl;

    cout << "\n--- 1. Setup Perpustakaan ---" << endl;
    Library library; 
    
    library.addShelf("Rak Fiksi", 5);
    library.addShelf("Rak Jurnal", 4);
    library.addShelf("Rak Referensi", 3); 

    cout << "\nMenambahkan 4 Buku... " << endl;
    string b1 = library.addBook("Dune", "Frank Herbert", 896);
    cout << "Buku 'Dune' ditambahkan ke perpustakaan." << endl;
    
    string b2 = library.addBook("Foundation", "Isaac Asimov", 255);
    cout << "Buku 'Foundation' ditambahkan ke perpustakaan." << endl;
    
    string b3 = library.addBook("Neuromancer", "William Gibson", 271);
    cout << "Buku 'Neuromancer' ditambahkan ke perpustakaan." << endl;

    string b4 = library.addBook("Hyperion", "Dan Simmons", 482);
    cout << "Buku 'Hyperion' ditambahkan ke perpustakaan." << endl;

    cout << "\nMenambahkan 6 Majalah... " << endl;
    string m1 = library.addMagazine("Analog Science Fiction", "Dell Magazines", 202501);
    cout << "Majalah 'Analog Science Fiction' ditambahkan ke perpustakaan." << endl;
    
    string m2 = library.addMagazine("Asimov's Science Fiction", "Dell Magazines", 202502);
    cout << "Majalah 'Asimov's Science Fiction' ditambahkan ke perpustakaan." << endl;
    
    string m3 = library.addMagazine("Clarkesworld", "Neil Clarke", 202503);
    cout << "Majalah 'Clarkesworld' ditambahkan ke perpustakaan." << endl;

    string m4 = library.addMagazine("F&SF", "Spilogale", 202504);
    cout << "Majalah 'F&SF' ditambahkan ke perpustakaan." << endl;

    string m5 = library.addMagazine("Lightspeed", "John Joseph Adams", 202505);
    cout << "Majalah 'Lightspeed' ditambahkan ke perpustakaan." << endl;

    string m6 = library.addMagazine("Strange Horizons", "An Eron", 202506);
    cout << "Majalah 'Strange Horizons' ditambahkan ke perpustakaan." << endl;


    cout << "\n--- 2. Penempatan ---" << endl;
    library.placeItemToShelf(b1, "Rak Fiksi");
    library.placeItemToShelf(b2, "Rak Fiksi");
    library.placeItemToShelf(b3, "Rak Fiksi");
    library.placeItemToShelf(b4, "Rak Fiksi");
    
    library.placeItemToShelf(m1, "Rak Jurnal");
    library.placeItemToShelf(m2, "Rak Jurnal");
    library.placeItemToShelf(m3, "Rak Jurnal");
    library.placeItemToShelf(m4, "Rak Jurnal");
    
    library.placeItemToShelf(m5, "Rak Referensi");
    library.placeItemToShelf(m6, "Rak Referensi"); 
    
    library.checkEmptySlots();

    cout << "\n--- 3. Pencarian ---" << endl;
    
    cout << "\nMencari ID: 'B3'..." << endl; 
    Item* foundById = library.findById(b3);
    if (foundById) {
        foundById->display();
        cout << endl;
    }

    cout << "\nMencari Judul: 'Hyperion'..." << endl; 
    vector<Item*> foundByTitle = library.searchByTitle("Hyperion");
    for (Item* item : foundByTitle) {
        item->display();
        cout << endl;
    }

    cout << "\nMencari ID: 'M99'..." << endl; 
    library.findById("M99"); 


    cout << "\n--- 4. Peminjaman dan Pengembalian ---" << endl;
    
    library.addMember("M001", "Rizki");
    library.addMember("M002", "Sita"); 
    cout << "Member Rizki dan Sita dibuat." << endl;

    cout << "\nRizki meminjam dua buku, Dune dan Neuromancer" << endl;
    library.borrowItem("Rizki", b1);
    library.borrowItem("Rizki", b3);
    
    cout << "\nSita meminjam buku yang sama, Neuromancer" << endl;
    library.borrowItem("Sita", b3); 

    cout << "\nRizki mengembalikan satu buku (Neuromancer)" << endl;
    library.returnItem("Rizki", b3); 

    cout << "\nSita meminjam buku itu lagi (Neuromancer)" << endl;
    library.borrowItem("Sita", b3); 

    cout << "\nDaftar pinjaman akhir:" << endl;
    Member* rizki = library.getMemberByName("Rizki");
    if(rizki) rizki->listLoans();
    
    Member* sita = library.getMemberByName("Sita");
    if(sita) sita->listLoans();

    cout << "\n--- 5. Ringkasan Akhir ---" << endl;
    library.report();

    cout << "\n===== Skenario Pengujian Selesai =====" << endl;
    
    return 0;
}