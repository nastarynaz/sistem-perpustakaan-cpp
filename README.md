# Sistem Manajemen Perpustakaan (Library Management System)

Proyek ini adalah implementasi sistem manajemen perpustakaan berbasis C++ yang mencakup fitur pengelolaan buku, majalah, anggota, dan peminjaman.

## Struktur Proyek

```
pbo/
├── Book.cpp          # Implementasi kelas Book
├── Book.h            # Header kelas Book
├── Item.cpp          # Implementasi kelas Item (base class)
├── Item.h            # Header kelas Item
├── Library.cpp       # Implementasi kelas Library
├── Library.h         # Header kelas Library
├── Magazine.cpp      # Implementasi kelas Magazine
├── Magazine.h        # Header kelas Magazine
├── main.cpp          # Program utama dengan skenario pengujian
├── Member.cpp        # Implementasi kelas Member
├── Member.h          # Header kelas Member
├── Shelf.cpp         # Implementasi kelas Shelf
├── Shelf.h           # Header kelas Shelf
├── Slot.cpp          # Implementasi kelas Slot
├── Slot.h            # Header kelas Slot
└── README.md         # Dokumentasi proyek
```

## Fitur Utama

1. **Manajemen Item**

   - Menambahkan buku dengan informasi judul, penulis, dan jumlah halaman
   - Menambahkan majalah dengan informasi judul, penerbit, dan edisi
   - Pencarian item berdasarkan ID
   - Pencarian item berdasarkan judul

2. **Manajemen Rak (Shelf)**

   - Membuat rak dengan kapasitas tertentu
   - Menempatkan item ke rak tertentu
   - Menghapus item dari rak
   - Menghitung slot kosong pada rak

3. **Manajemen Anggota (Member)**

   - Mendaftarkan anggota perpustakaan
   - Meminjam item (maksimal 3 item per anggota)
   - Mengembalikan item yang dipinjam
   - Melihat daftar pinjaman anggota

4. **Laporan Perpustakaan**
   - Menampilkan total item
   - Menampilkan item yang ada di rak
   - Menampilkan slot kosong
   - Menampilkan item yang sedang dipinjam

## Cara Menjalankan Program

### Prasyarat

Pastikan Anda memiliki compiler C++ yang terinstal di sistem Anda. Untuk macOS, Anda dapat menggunakan:

- **Clang** (sudah terinstal dengan Xcode Command Line Tools)
- **GCC** (dapat diinstal via Homebrew)

### Langkah 1: Navigasi ke Direktori Proyek

Buka terminal dan navigasi ke direktori proyek:

```bash
cd /pbo
```

### Langkah 2: Kompilasi Program

Gunakan salah satu perintah berikut untuk mengkompilasi program:

**Menggunakan g++:**

```bash
g++ -std=c++17 main.cpp Book.cpp Item.cpp Library.cpp Magazine.cpp Member.cpp Shelf.cpp Slot.cpp -o program_perpustakaan
```

**Menggunakan clang++:**

```bash
clang++ -std=c++17 main.cpp Library.cpp Member.cpp Shelf.cpp Slot.cpp Item.cpp Book.cpp Magazine.cpp -o program_perpustakaan
```

### Langkah 3: Jalankan Program

Setelah kompilasi berhasil, jalankan program dengan perintah:

```bash
./program_perpustakaan
```

## Contoh Output

Program akan menjalankan skenario pengujian lengkap yang mencakup:

1. **Setup Library** - Membuat rak dan menambahkan item (buku dan majalah)
2. **Penempatan** - Menempatkan item ke rak-rak yang tersedia
3. **Pencarian** - Mencari item berdasarkan ID dan judul
4. **Peminjaman dan Pengembalian** - Simulasi peminjaman dan pengembalian oleh anggota
5. **Ringkasan** - Menampilkan statistik perpustakaan

## Cara Membersihkan File Executable

Untuk menghapus file executable yang telah dikompilasi:

```bash
rm library_system
```

## Troubleshooting

### Error: "command not found: g++" atau "command not found: clang++"

**Solusi:** Instal Xcode Command Line Tools:

```bash
xcode-select --install
```

### Error: "undefined reference" atau "linker error"

**Solusi:** Pastikan semua file .cpp disertakan dalam perintah kompilasi.

### Error kompilasi lainnya

**Solusi:** Pastikan semua file header (.h) dan implementasi (.cpp) ada di direktori yang sama.
