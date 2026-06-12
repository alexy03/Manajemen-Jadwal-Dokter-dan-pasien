# Sistem E-Health: Manajemen Jadwal Dokter dan Antrian Pasien

Aplikasi **Manajemen Rumah Sakit** berbasis konsol (CLI) ini dirancang menggunakan bahasa pemrograman C++ untuk mendemonstrasikan implementasi berbagai struktur data fundamental. 
Proyek ini disusun sebagai pemenuhan Tugas UTS untuk mata kuliah **Struktur Data dan Algoritma** (Kelas IF210, Prodi PJJ Informatika, Universitas Siber Asia).

## 👥 Anggota Kelompok
1. **Alexandre Rawi Ruto** (NIM: 250401010503)
2. **Rizqi Wahyu Saputra** (NIM: 250401010478)
3. **Almalik Rendrarazati** (NIM: 250401010523)
4. **Boby Goldamy Sihombing** (NIM: 250401010506)

**Dosen Pengampu:** Ir. Ahmad Chusyairi, M.Kom., CDS., IPM., ASEAN Eng

---

## 🛠️ Struktur Data yang Diimplementasikan

Aplikasi ini mengintegrasikan 6 konsep struktur data yang berbeda sesuai dengan kebutuhan fungsionalitas di dunia nyata:

1. **Tipe Data & Variabel:** Menggunakan tipe data primitif (`int`), objek (`string`), dan bentukan (`struct`) untuk mengelompokkan entitas data pasien dan rekam medis.
2. **Array Statis:** Digunakan untuk menyimpan data jadwal praktik dokter harian yang bersifat tetap (*hardcoded*).
3. **Queue (Antrean):** Menerapkan prinsip **FIFO (First-In, First-Out)** berbasis array untuk mengelola antrean pasien di loket pendaftaran secara adil.
4. **Stack (Tumpukan):** Menerapkan prinsip **LIFO (Last-In, First-Out)** untuk menyimpan riwayat rekam medis, sehingga dokter dapat langsung melihat hasil pemeriksaan yang paling terakhir/terbaru (*Top/Peek*).
5. **Linked List (Singly Linked List):** Digunakan untuk menampung database pasien tetap secara dinamis di dalam memori menggunakan alokasi penunjuk (*pointer*).
6. **Tree (Pohon Biner):** Digunakan untuk memetakan struktur klasifikasi hierarki kategori layanan poliklinik utama dan spesialisasi menggunakan penelusuran *In-Order Traversal*.

---

## 💻 Fitur Aplikasi

Sistem memiliki menu interaktif (1-9) sebagai berikut:
1. **Lihat Jadwal Praktik Dokter:** Menampilkan jadwal dokter aktif dari data array harian.
2. **Lihat Kategori Layanan Poli:** Menampilkan visualisasi hierarki poliklinik menggunakan struktur data Tree.
3. **Tambah Antrean Loket Fisik:** Memasukkan nama pasien baru ke barisan antrean belakang (*Enqueue*).
4. **Panggil Antrean Loket Fisik:** Memanggil dan mengeluarkan pasien di barisan terdepan (*Dequeue*).
5. **Lihat Semua Antrean Loket:** Menampilkan seluruh daftar pasien yang sedang mengantre di loket saat ini.
6. **Daftarkan Data Pasien Tetap:** Menambahkan simpul (*node*) pasien baru secara dinamis ke dalam *Linked List*.
7. **Lihat Data Pasien Tetap:** Melakukan perulangan (*traversing*) untuk menampilkan semua pasien tetap yang terdaftar di database lokal.
8. **Input & Cek Rekam Medis Terakhir:** Menyediakan sub-menu untuk menambahkan riwayat medis baru (*Push*) atau melihat rekam medis terakhir pasien (*Peek*).
9. **Keluar Sistem:** Menutup dan menyudahi jalannya aplikasi.

---

## 🚀 Cara Menjalankan Program

### Prasyarat
Pastikan komputer Anda sudah terinstal *compiler* C++ (seperti GCC/G++) atau menggunakan IDE yang mendukung (seperti Code::Blocks, Dev-C++, atau VS Code dengan ekstensi C++).

### Langkah-langkah
1. **Clone Repositori:**
   ```bash
   git clone [https://github.com/username-kamu/nama-repositori.git](https://github.com/username-kamu/nama-repositori.git)
   cd nama-repositori
