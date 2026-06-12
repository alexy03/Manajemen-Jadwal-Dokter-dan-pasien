// KELOMPOK 3 
// KELAS IF210
// PRODI PJJ Informatika
// DOSEN PENGAMPU : Ir. Ahmad Chusyairi, M.Kom., CDS., IPM., ASEAN Eng
/* TUGAS UTS STRUKTUR DATA DAN ALGORITMA
JUDUL : MANAJEMEN JADWAL DOKTER DAN ANTRIAN PASIEN
Struktur Data yang digunakan : 
1. Tipe data dan variabel
2. Array
3. Queue
4. Stack 
5. Linked List
6. Tree
=====================================================
 NAMA :
 1. ALEXANDRE RAWI RUTO (250401010503)
 =====================================================
*/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. TIPE DATA, VARIABEL, & LINKED LIST (Data Pasien Utama)
// ==========================================
struct Pasien {
    int idPasien;
    string nama;
    int umur;
    string keluhan;
    Pasien* next; // Pointer untuk Linked List
};

// ==========================================
// 2. STACK (Riwayat Konsultasi / Rekam Medis Terakhir)
// ==========================================
struct RekamMedis {
    string tanggal;
    string diagnosa;
    string resepObat;
};

class StackRekamMedis {
private:
    RekamMedis data[100]; // Array statis untuk menyimpan stack
    int top;
public:
    StackRekamMedis() {
        top = -1;
    }

    bool isFull() { return top == 99; }
    bool isEmpty() { return top == -1; }

    void push(string tgl, string diag, string obat) {
        if (!isFull()) {
            top++;
            data[top].tanggal = tgl;
            data[top].diagnosa = diag;
            data[top].resepObat = obat;
        } else {
            cout << "Riwayat penuh!\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }

    void cetakTerakhir() {
        if (!isEmpty()) {
            cout << "--- Rekam Medis Terakhir ---\n";
            cout << "Tanggal  : " << data[top].tanggal << endl;
            cout << "Diagnosa : " << data[top].diagnosa << endl;
            cout << "Resep    : " << data[top].resepObat << endl;
        } else {
            cout << "(Belum ada riwayat pemeriksaan)\n";
        }
    }
};

// ==========================================
// 3. QUEUE (Antrean Loket Pendaftaran Fisik)
// ==========================================
class QueueAntrean {
private:
    int head, tail;
    int maks;
    string namaAntrean[20]; // Array untuk antrean tipe data string
public:
    QueueAntrean() {
        head = -1;
        tail = -1;
        maks = 20;
    }

    bool isEmpty() { return head == -1; }
    bool isFull() { return tail == maks - 1; }

    void enqueue(string nama) {
        if (isFull()) {
            cout << "Antrean loket penuh, mohon tunggu.\n";
            return;
        }
        if (isEmpty()) {
            head = 0;
        }
        tail++;
        namaAntrean[tail] = nama;
        cout << "Pasien " << nama << " berhasil masuk antrean loket.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrean kosong.\n";
            return;
        }
        cout << "Pasien " << namaAntrean[head] << " dipanggil ke loket.\n";
        
        if (head == tail) { // jika hanya tinggal 1 elemen
            head = tail = -1;
        } else {
            head++;
        }
    }

    void lihatAntrean() {
        if (isEmpty()) {
            cout << "Tidak ada antrean di loket.\n";
            return;
        }
        cout << "Daftar Antrean Saat Ini: \n";
        for (int i = head; i <= tail; i++) {
            cout << (i - head + 1) << ". " << namaAntrean[i] << endl;
        }
    }
};

// ==========================================
// 4. TREE (Sistem Klasifikasi Spesialisasi Dokter)
// ==========================================
struct NodeTree {
    string namaKategori;
    NodeTree* kiri;
    NodeTree* kanan;

    NodeTree(string nama) {
        namaKategori = nama;
        kiri = NULL;
        kanan = NULL;
    }
};

// Fungsi sederhana untuk menampilkan struktur spesialisasi (In-order)
void tampilkanSpesialisasi(NodeTree* root) {
    if (root != NULL) {
        tampilkanSpesialisasi(root->kiri);
        cout << " -> " << root->namaKategori << "\n";
        tampilkanSpesialisasi(root->kanan);
    }
}

// ==========================================
// 5. DRIVER CODE & MAIN FUNCTION
// ==========================================
int main() {
    // Penggunaan ARRAY untuk jadwal dokter (statis)
    string jadwalDokter[3] = {
        "08:00 - 11:00 : Dr. Andi (Spesialis Anak)",
        "13:00 - 16:00 : Dr. Budi (Spesialis Jantung)",
        "17:00 - 20:00 : Dr. Citra (Umum)"
    };

    // Inisialisasi komponen struktur data
    QueueAntrean loketPendaftaran;
    StackRekamMedis riwayatPasien;
    Pasien* headPasien = NULL; // Head untuk Linked List data pasien aktif

    // Inisialisasi Tree kategori layanan
    NodeTree* rootPoli = new NodeTree("Poliklinik Utama");
    rootPoli->kiri = new NodeTree("Poli Anak & Ibu");
    rootPoli->kanan = new NodeTree("Poli Dalam & Umum");

    int pilihan;
    do {
        cout << "\n============================================\n";
        cout << "  SISTEM E-HEALTH: MANAJEMEN JADWAL & PASIEN\n";
        cout << "============================================\n";
        cout << "1. Lihat Jadwal Praktik Dokter\n";
        cout << "2. Lihat Kategori Layanan Poli\n";
        cout << "3. Tambah Antrean Loket Fisik\n";
        cout << "4. Panggil Antrean Loket Fisik\n";
        cout << "5. Lihat Semua Antrean Loket\n";
        cout << "6. Daftarkan Data Pasien Tetap\n";
        cout << "7. Lihat Data Pasien Tetap\n";
        cout << "8. Input & Cek Rekam Medis Terakhir\n";
        cout << "9. Keluar Sistem\n";
        cout << "Pilih menu (1-9): ";
        cin >> pilihan;
        cin.ignore(); // membersihkan buffer input

        cout << "\nHasil Aksi:\n-------------------------\n";

        switch (pilihan) {
            case 1:
                cout << "Jadwal Praktik Dokter Hari Ini:\n";
                for (int i = 0; i < 3; i++) {
                    cout << jadwalDokter[i] << endl;
                }
                break;

            case 2:
                cout << "Struktur Klasifikasi Layanan Poli:\n";
                tampilkanSpesialisasi(rootPoli);
                break;

            case 3: {
                string namaP;
                cout << "Masukkan nama pasien: ";
                getline(cin, namaP);
                loketPendaftaran.enqueue(namaP);
                break;
            }
            case 4:
                loketPendaftaran.dequeue();
                break;

            case 5:
                loketPendaftaran.lihatAntrean();
                break;

            case 6: {
                // Alokasi memori dinamis untuk Node Linked List baru
                Pasien* baru = new Pasien();
                cout << "Masukkan ID Pasien (Angka): ";
                cin >> baru->idPasien;
                cin.ignore();
                cout << "Masukkan Nama Lengkap: ";
                getline(cin, baru->nama);
                cout << "Masukkan Umur: ";
                cin >> baru->umur;
                cin.ignore();
                cout << "Keluhan Utama: ";
                getline(cin, baru->keluhan);
                baru->next = NULL;

                // Insert di akhir linked list (Append)
                if (headPasien == NULL) {
                    headPasien = baru;
                } else {
                    Pasien* temp = headPasien;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = baru;
                }
                cout << "Data Pasien berhasil disimpan ke database lokal.\n";
                break;
            }
            case 7: {
                if (headPasien == NULL) {
                    cout << "Belum ada data pasien tetap yang terdaftar.\n";
                } else {
                    Pasien* temp = headPasien;
                    cout << "Daftar Pasien Tetap di Database:\n";
                    while (temp != NULL) {
                        cout << "[" << temp->idPasien << "] " << temp->nama 
                             << " (" << temp->umur << " thn) - Keluhan: " << temp->keluhan << endl;
                        temp = temp->next;
                    }
                }
                break;
            }
            case 8: {
                int subPilih;
                cout << "1. Input Rekam Medis Baru (Push)\n";
                cout << "2. Lihat Rekam Medis Terakhir (Top/Peek)\n";
                cout << "Pilihan: ";
                cin >> subPilih;
                cin.ignore();
                
                if (subPilih == 1) {
                    string tgl, diag, obat;
                    cout << "Tanggal (DD/MM/YYYY): ";
                    getline(cin, tgl);
                    cout << "Diagnosa Dokter     : ";
                    getline(cin, diag);
                    cout << "Resep Obat          : ";
                    getline(cin, obat);
                    riwayatPasien.push(tgl, diag, obat);
                    cout << "Rekam medis berhasil ditambahkan ke riwayat.\n";
                } else if (subPilih == 2) {
                    riwayatPasien.cetakTerakhir();
                }
                break;
            }
            case 9:
                cout << "Keluar dari sistem e-Health. Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 9);

    return 0;
}
