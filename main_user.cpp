#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void menuUser(ListSutradara &L) {
    int pilih = 0;
    cout << "\n+==============================================================================+";
    cout << "\n|                          DATA SUTRADARA DAN FILM                             |";
    cout << "\n+==============================================================================+\n";
    adrSutradara S = L.first;
    cout << "+----------------------+----------------------+----------------------+" << endl;
    cout << "|   Budi Santoso (45)  |  Andi Wijaya (50)    |   Siti Rahma (39)    |" << endl;
    cout << "|       ID: S01        |      ID: S02         |      ID: S03         |" << endl;
    cout << "+----------------------+----------------------+----------------------+" << endl;

    int maxFilm = 0;
    S = L.first;
    while (S != nullptr) {
        int count = 0;
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            count++;
            F = F->next;
        }
        if (count > maxFilm) maxFilm = count;
        S = S->next;
    }
    for (int i = 0; i < maxFilm; i++) {
        cout << "| ";
        S = L.first;
        while (S != nullptr) {
            adrFilm F = S->firstFilm;
            int idx = 0;
            while (F != nullptr && idx < i) {
                F = F->next;
                idx++;
            }
            if (F != nullptr) {
                string judul = F->judul;
                if (judul.length() > 18) judul = judul.substr(0, 15) + "...";
                cout << judul;
                for (int j = judul.length(); j < 20; j++) cout << " ";
            } else {
                cout << "                    ";
            }
            cout << " | ";
            S = S->next;
        }
        cout << endl;
        cout << "| ";
        S = L.first;
        while (S != nullptr) {
            adrFilm F = S->firstFilm;
            int idx = 0;
            while (F != nullptr && idx < i) {
                F = F->next;
                idx++;
            }
            if (F != nullptr) {
                string info = "(" + to_string(F->tahun) + ") " + F->id;
                cout << info;
                for (int j = info.length(); j < 20; j++) cout << " ";
            } else {
                cout << "                    ";
            }
            cout << " | ";
            S = S->next;
        }
        cout << endl;
        cout << "+----------------------+----------------------+----------------------+" << endl;
    }
    cout << "\n";
    while (pilih != 10) {
        cout << "\n+-------------------------------------------+\n";
        cout << "|               MENU USER                   |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| 1. Cari Film Berdasarkan Judul            |\n";
        cout << "| 2. Tampilkan Semua Film Unik              |\n";
        cout << "| 3. Hitung Total Film                      |\n";
        cout << "| 4. Urutkan Film per Sutradara             |\n";
        cout << "| 5. Lihat Detail Film                      |\n";
        cout << "| 6. Cari Sutradara Berdasarkan Nama        |\n";
        cout << "| 7. Cari Sutradara Berdasarkan ID          |\n";
        cout << "| 8. Tampilkan Film per Sutradara           |\n";
        cout << "| 9. Sutradara dengan Film Terbanyak        |\n";
        cout << "| 10. Kembali                               |\n";
        cout << "+-------------------------------------------+\n";
        cout << "Pilih Menu: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1) userCariFilmByJudul(L);
        else if (pilih == 2) userTampilSemuaFilmUnik(L);
        else if (pilih == 3) userHitungTotalFilm(L);
        else if (pilih == 4) userUrutkanFilmPerSutradara(L);
        else if (pilih == 5) userLihatDetailFilm(L);
        else if (pilih == 6) userCariSutradaraByNama(L);
        else if (pilih == 7) userCariSutradaraById(L);
        else if (pilih == 8) userTampilFilmPerSutradara(L);
        else if (pilih == 9) userSutradaraTerbanyakFilm(L);
    }
}

void userCariFilmByJudul(ListSutradara L) {
    string cari;
    cout << "Masukkan Judul Film: ";
    cin.ignore();
    getline(cin, cari);
    adrSutradara S = L.first;
    bool ketemu = false;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            if (F->judul == cari) {
                cout << "Film ditemukan pada Sutradara: " << S->nama << endl;
                cout << "ID Film : " << F->id << endl;
                cout << "Tahun   : " << F->tahun << endl;
                ketemu = true;
            }
            F = F->next;
        }
        S = S->next;
    }
    if (!ketemu) cout << "Film tidak ditemukan.\n";
}

void userTampilSemuaFilmUnik(ListSutradara L) {
    adrSutradara S = L.first;
    cout << "\n+============================================+";
    cout << "\n|         DAFTAR SEMUA FILM                  |";
    cout << "\n+============================================+\n";
    string filmList[100];
    string sutradaraList[100];
    int jumlah[100] = {0};
    int count = 0;
    int no = 1;
    S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            cout << no << ". " << F->judul << " (" << F->tahun << ") - Sutradara: " << S->nama << endl;
            bool sudahAda = false;
            int index = -1;
            for (int i = 0; i < count; i++) {
                if (filmList[i] == F->judul) {
                    sudahAda = true;
                    index = i;
                    jumlah[i]++;
                    break;
                }
            }
            if (!sudahAda) {
                filmList[count] = F->judul;
                sutradaraList[count] = S->nama;
                jumlah[count] = 1;
                count++;
            }
            F = F->next;
            no++;
        }
        S = S->next;
    }
    cout << "\n+============================================+";
    cout << "\n|         FILM DUPLIKAT                      |";
    cout << "\n+============================================+\n";
    bool adaDuplikat = false;
    for (int i = 0; i < count; i++) {
        if (jumlah[i] > 1) {
            cout << "- " << filmList[i] << " (muncul " << jumlah[i] << " kali)" << endl;
            adaDuplikat = true;
        }
    }
    if (!adaDuplikat) {
        cout << "Tidak ada film duplikat.\n";
    }
    cout << "+============================================+\n";
}

void userHitungTotalFilm(ListSutradara L) {
    int total = 0;
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            total++;
            F = F->next;
        }
        S = S->next;
    }
    cout << "Total Film: " << total << endl;
}

void userUrutkanFilmPerSutradara(ListSutradara &L) {
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F1 = S->firstFilm;
        while (F1 != nullptr && F1->next != nullptr) {
            adrFilm F2 = F1->next;
            while (F2 != nullptr) {
                if (F1->judul > F2->judul) {
                    swap(F1->judul, F2->judul);
                    swap(F1->id, F2->id);
                    swap(F1->tahun, F2->tahun);
                }
                F2 = F2->next;
            }
            F1 = F1->next;
        }
        S = S->next;
    }

    cout << "\n+============================================+";
    cout << "\n|    FILM BERHASIL DIURUTKAN                 |";
    cout << "\n+============================================+\n\n";
    S = L.first;
    while (S != nullptr) {
        cout << "Sutradara: " << S->nama << " (ID: " << S->id << ")" << endl;
        cout << "Film yang telah diurutkan:" << endl;
        adrFilm F = S->firstFilm;
        int no = 1;
        while (F != nullptr) {
            cout << "  " << no << ". " << F->judul << " (" << F->tahun << ") [" << F->id << "]" << endl;
            F = F->next;
            no++;
        }
        cout << endl;
        S = S->next;
    }
    cout << "+============================================+\n";
}

void userLihatDetailFilm(ListSutradara L) {
    string idf;
    cin.ignore();
    cout << "Masukkan ID Film: ";
    getline(cin, idf);
    adrSutradara S = L.first;
    while (S != nullptr) {
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            if (F->id == idf) {
                cout << "Judul : " << F->judul << endl;
                cout << "Tahun : " << F->tahun << endl;
                cout << "Sutradara : " << S->nama << endl;
                return;
            }
            F = F->next;
        }
        S = S->next;
    }
    cout << "Film tidak ditemukan.\n";
}

void userCariSutradaraByNama(ListSutradara L) {
    string nama;
    cin.ignore();
    cout << "Masukkan Nama Sutradara: ";
    getline(cin, nama);
    adrSutradara S = L.first;
    while (S != nullptr) {
        if (S->nama == nama) {
            cout << "ID : " << S->id << endl;
            cout << "Umur : " << S->umur << endl;
            return;
        }
        S = S->next;
    }
    cout << "Sutradara tidak ditemukan.\n";
}

void userCariSutradaraById(ListSutradara L) {
    string id;
    cin.ignore();
    cout << "Masukkan ID Sutradara: ";
    getline(cin, id);
    adrSutradara S = L.first;
    while (S != nullptr) {
        if (S->id == id) {
            cout << "Nama : " << S->nama << endl;
            cout << "Umur : " << S->umur << endl;
            return;
        }
        S = S->next;
    }
    cout << "Sutradara tidak ditemukan.\n";
}

void userTampilFilmPerSutradara(ListSutradara L) {
    string id;
    cin.ignore();
    cout << "Masukkan ID Sutradara: ";
    getline(cin, id);
    adrSutradara S = L.first;
    while (S != nullptr) {
        if (S->id == id) {
            cout << "Sutradara: " << S->nama << endl;
            adrFilm F = S->firstFilm;
            while (F != nullptr) {
                cout << "- " << F->judul << " (" << F->tahun << ")\n";
                F = F->next;
            }
            return;
        }
        S = S->next;
    }

    cout << "Sutradara tidak ditemukan.\n";
}

void userSutradaraTerbanyakFilm(ListSutradara L) {
    adrSutradara S = L.first;
    cout << "\n+============================================+";
    cout << "\n|    JUMLAH FILM PER SUTRADARA               |";
    cout << "\n+============================================+\n";
    int maxFilm = 0;
    while (S != nullptr) {
        int count = 0;
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            count++;
            F = F->next;
        }
        cout << "- " << S->nama << " : " << count << " film" << endl;
        if (count > maxFilm) {
            maxFilm = count;
        }
        S = S->next;
    }

    cout << "\n+============================================+";
    cout << "\n|    SUTRADARA DENGAN FILM TERBANYAK        |";
    cout << "\n+============================================+\n";
    S = L.first;
    while (S != nullptr) {
        int count = 0;
        adrFilm F = S->firstFilm;
        while (F != nullptr) {
            count++;
            F = F->next;
        }

        if (count == maxFilm) {
            cout << "Nama        : " << S->nama << endl;
            cout << "ID          : " << S->id << endl;
            cout << "Jumlah Film : " << count << " film" << endl;
            cout << endl;
        }
        S = S->next;
    }
    cout << "+============================================+\n";
}

void loadDummyData(ListSutradara &L) {
    adrSutradara A = buatSutradaraNode("S01", "Budi Santoso", 45);
    adrSutradara B = buatSutradaraNode("S02", "Andi Wijaya", 50);
    adrSutradara C = buatSutradaraNode("S03", "Siti Rahma", 39);
    insertLastSutradara(L, A);
    insertLastSutradara(L, B);
    insertLastSutradara(L, C);
    insertLastFilm(A, buatFilmNode("F01", "Langit Senja", 2020));
    insertLastFilm(A, buatFilmNode("F02", "Petualangan Kota", 2018));
    insertLastFilm(A, buatFilmNode("F03", "Jejak Waktu", 2019));
    insertLastFilm(B, buatFilmNode("F04", "Hujan di Balik Awan", 2019));
    insertLastFilm(B, buatFilmNode("F05", "Gelombang Cinta", 2021));
    insertLastFilm(B, buatFilmNode("F06", "Langit Senja", 2020));
    insertLastFilm(B, buatFilmNode("F07", "Cahaya Pagi", 2022));
    insertLastFilm(C, buatFilmNode("F08", "Jejak Waktu", 2017));
    insertLastFilm(C, buatFilmNode("F09", "Mimpi Indah", 2023));
}
