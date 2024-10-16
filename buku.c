#include <stdio.h>
#include <string.h>

#define MAX 100

// Struktur untuk menyimpan informasi buku
typedef struct {
    char id[10];
    char judul[50];
    char pengarang[50];
    char penerbit[50];
    int tahun;
} Buku;

// Array untuk menyimpan buku-buku
Buku daftarBuku[MAX];
int jumlahBuku = 0;

// Fungsi untuk menambah buku
void tambahBuku() {
    if (jumlahBuku >= MAX) {
        printf("Kapasitas penuh! Tidak dapat menambah buku lagi.\n");
        return;
    }
    
    Buku bukuBaru;
    
    printf("Masukkan ID Buku: ");
    scanf("%s", bukuBaru.id);
    printf("Masukkan Judul Buku: ");
    scanf(" %[^\n]s", bukuBaru.judul);
    printf("Masukkan Pengarang: ");
    scanf(" %[^\n]s", bukuBaru.pengarang);
    printf("Masukkan Penerbit: ");
    scanf(" %[^\n]s", bukuBaru.penerbit);
    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &bukuBaru.tahun);
    
    daftarBuku[jumlahBuku] = bukuBaru;
    jumlahBuku++;
    
    printf("Buku berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan semua buku
void lihatBuku() {
    if (jumlahBuku == 0) {
        printf("Tidak ada buku yang tersedia.\n");
        return;
    }
    
    printf("Daftar Buku:\n");
    printf("---------------------------------------------------\n");
    printf("ID\tJudul\t\tPengarang\tPenerbit\tTahun\n");
    for (int i = 0; i < jumlahBuku; i++) {
        printf("%s\t%s\t%s\t%s\t%d\n", daftarBuku[i].id, daftarBuku[i].judul, daftarBuku[i].pengarang, daftarBuku[i].penerbit, daftarBuku[i].tahun);
    }
    printf("---------------------------------------------------\n");
}

// Fungsi untuk mengedit buku
void editBuku() {
    char id[10];
    printf("Masukkan ID Buku yang ingin diedit: ");
    scanf("%s", id);
    
    int index = -1;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].id, id) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Buku dengan ID %s tidak ditemukan.\n", id);
        return;
    }
    
    printf("Masukkan Judul Baru: ");
    scanf(" %[^\n]s", daftarBuku[index].judul);
    printf("Masukkan Pengarang Baru: ");
    scanf(" %[^\n]s", daftarBuku[index].pengarang);
    printf("Masukkan Penerbit Baru: ");
    scanf(" %[^\n]s", daftarBuku[index].penerbit);
    printf("Masukkan Tahun Terbit Baru: ");
    scanf("%d", &daftarBuku[index].tahun);
    
    printf("Buku berhasil diedit!\n");
}

// Fungsi untuk menghapus buku
void hapusBuku() {
    char id[10];
    printf("Masukkan ID Buku yang ingin dihapus: ");
    scanf("%s", id);
    
    int index = -1;
    for (int i = 0; i < jumlahBuku; i++) {
        if (strcmp(daftarBuku[i].id, id) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Buku dengan ID %s tidak ditemukan.\n", id);
        return;
    }
    
    for (int i = index; i < jumlahBuku - 1; i++) {
        daftarBuku[i] = daftarBuku[i + 1];
    }
    
    jumlahBuku--;
    
    printf("Buku berhasil dihapus!\n");
}

// Fungsi utama
int main() {
    int pilihan;
    
    do {
        printf("\nSistem Informasi Perpustakaan\n");
        printf("1. Tambah Buku\n");
        printf("2. Lihat Buku\n");
        printf("3. Edit Buku\n");
        printf("4. Hapus Buku\n");
        printf("5. Keluar\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                tambahBuku();
                break;
            case 2:
                lihatBuku();
                break;
            case 3:
                editBuku();
                break;
            case 4:
                hapusBuku();
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
    
    return 0;
}
