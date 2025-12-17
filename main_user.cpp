#include <iostream>
#include <string>
#include "Sutradara.h"
#include "Film.h"
using namespace std;

void menuUser(ListSutradara &L){
    int pilih = 0;
    while(pilih != 15){
        system("cls");
        cout << "\n+==============================================================================+";
        cout << "\n|                          DATA SUTRADARA DAN FILM                             |";
        cout << "\n+==============================================================================+\n";
        adrSutradara S = L.first;
        int jumlahSutradara = 0;
        while(S != nullptr){
            jumlahSutradara++;
            S = S->next;
        }
        if(jumlahSutradara == 0){
            cout << "Tidak ada data sutradara.\n\n";
        }else{
            S = L.first;
            while(S != nullptr){
                cout << "+----------------------";
                S = S->next;
            }
            cout << "+" << endl;
            S = L.first;
            while(S != nullptr){
                string info = S->nama + " (" + to_string(S->umur) + ")";
                if(info.length() > 20){
                    info = info.substr(0, 17) + "...";
                }
                cout << "| " << info;
                for(int i = info.length(); i < 21; i++){
                    cout << " ";
                }
                S = S->next;
            }
            cout << "|" << endl;
            S = L.first;
            while(S != nullptr){
                string id = "ID: " + S->id;
                cout << "| " << id;
                for(int i = id.length(); i < 21; i++){
                    cout << " ";
                }
                S = S->next;
            }
            cout << "|" << endl;
            S = L.first;
            while(S != nullptr){
                cout << "+----------------------";
                S = S->next;
            }
            cout << "+" << endl;
            int maxFilm = 0;
            S = L.first;
            while(S != nullptr){
                int count = 0;
                adrFilm F = S->firstFilm;
                while(F != nullptr){
                    count++;
                    F = F->next;
                }
                if(count > maxFilm){
                    maxFilm = count;
                }
                S = S->next;
            }
            for(int i = 0; i < maxFilm; i++){
                S = L.first;
                while(S != nullptr){
                    adrFilm F = S->firstFilm;
                    int idx = 0;
                    while(F != nullptr && idx < i){
                        F = F->next;
                        idx++;
                    }
                    if(F != nullptr){
                        string judul = F->judul;
                        if(judul.length() > 20){
                            judul = judul.substr(0, 17) + "...";
                        }
                        cout << "| " << judul;
                        for(int j = judul.length(); j < 21; j++){
                            cout << " ";
                        }
                    }else{
                        cout << "|                      ";
                    }
                    S = S->next;
                }
                cout << "|" << endl;
                S = L.first;
                while(S != nullptr){
                    adrFilm F = S->firstFilm;
                    int idx = 0;
                    while(F != nullptr && idx < i){
                        F = F->next;
                        idx++;
                    }
                    if(F != nullptr){
                        string info = "(" + to_string(F->tahun) + ") " + F->id;
                        cout << "| " << info;
                        for(int j = info.length(); j < 21; j++){
                            cout << " ";
                        }
                    }else{
                        cout << "|                      ";
                    }
                    S = S->next;
                }
                cout << "|" << endl;
                S = L.first;
                while(S != nullptr){
                    cout << "+----------------------";
                    S = S->next;
                }
                cout << "+" << endl;
            }
        }
        cout << "\n";
        cout << "\n+-------------------------------------------+\n";
        cout << "|               MENU USER                   |\n";
        cout << "+-------------------------------------------+\n";
        cout << "| 1. Sisipkan Sutradara Baru                |\n";
        cout << "| 2. Hapus Sutradara dengan Umur Dibawah X  |\n";
        cout << "| 3. Sisipkan Film (Jumlah Film < 5)        |\n";
        cout << "| 4. Hapus Film dengan Tahun Dibawah X      |\n";
        cout << "| 5. Hitung Total Film                      |\n";
        cout << "| 6. Hitung Film Berdasarkan Tahun          |\n";
        cout << "| 7. Cari Sutradara Berdasarkan Nama        |\n";
        cout << "| 8. Cari Sutradara Berdasarkan ID          |\n";
        cout << "| 9. Cari Sutradara (Umur > X)              |\n";
        cout << "| 10. Tampilkan Film per Sutradara          |\n";
        cout << "| 11. Sutradara dengan Film Terbanyak       |\n";
        cout << "| 12. Tampilkan Semua Sutradara             |\n";
        cout << "| 13. Tampilkan Semua Film                  |\n";
        cout << "| 14. Tampilkan Semua Film Unik             |\n";
        cout << "| 15. Kembali                               |\n";
        cout << "+-------------------------------------------+\n";
        cout << "Pilih Menu: ";
        cin >> pilih;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[!] Input harus berupa angka!\n";
            system("pause");
            pilih = 0;
            continue;
        }
       cout << endl;
        if(pilih == 1){
            userMenyisipkanSutradara(L);
        }else if(pilih == 2){
            userHapusSutradaraBerdasarkanKondisi(L);
        }else if(pilih == 3){
            userMenyisipkanFilm(L);
        }else if(pilih == 4){
            userHapusFilmBerdasarkanKondisi(L);
        }else if(pilih == 5){
            userHitungTotalFilm(L);
        }else if(pilih == 6){
            userHitungFilmBerdasarkanTahun(L);
        }else if(pilih == 7){
            userCariSutradaraByNama(L);
        }else if(pilih == 8){
            userCariSutradaraById(L);
        }else if(pilih == 9){
            userCariSutradaraBerumurDiatas(L);
        }else if(pilih == 10){
            userTampilFilmPerSutradara(L);
        }else if(pilih == 11){
            userSutradaraTerbanyakFilm(L);
        }else if(pilih == 12){
            userTampilSemuaSutradara(L);
        }else if(pilih == 13){
            userTampilSemuaFilm(L);
        }else if(pilih == 14){
            userTampilSemuaFilmUnik(L);
        }else if(pilih == 15){
            cout << "Kembali ke menu utama...\n";
        }else{
            cout << "\n[!] Pilihan tidak valid!\n";
            system("pause");
            pilih = 0;
            continue;
        }
        if(pilih != 15){
            system("pause");
        }
    }
}

void userTampilSemuaFilmUnik(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|           DAFTAR SEMUA FILM                 |";
    cout << "\n+=============================================+\n";
    if(L.first == nullptr){
        cout << "| Belum ada data film.\n";
        cout << "+=============================================+\n";
        return;
    }
    string filmList[100];
    string sutradaraList[100];
    int jumlah[100] = {0};
    int count = 0;
    int no = 1;
    adrSutradara S = L.first;
    while(S != nullptr){
        adrFilm F = S->firstFilm;
        while(F != nullptr){
            cout << "|\n";
            cout << "| " << no << ". " << F->judul
                 << " (" << F->tahun << ")\n";
            cout << "|    Sutradara: " << S->nama << "\n";
            bool sudahAda = false;
            int index = -1;
            for(int i = 0; i < count && !sudahAda; i++){
                if(filmList[i] == F->judul){
                    sudahAda = true;
                    index = i;
                    jumlah[i]++;
                }
            }
            if(!sudahAda){
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
    cout << "|\n";
    cout << "+=============================================+";
    cout << "\n|            FILM DUPLIKAT                    |";
    cout << "\n+=============================================+\n";

    bool adaDuplikat = false;
    for(int i = 0; i < count; i++){
        if(jumlah[i] > 1){
            cout << "|\n";
            cout << "| - " << filmList[i]
                 << " (muncul " << jumlah[i] << " kali)\n";
            adaDuplikat = true;
        }
    }
    if(!adaDuplikat){
        cout << "|\n";
        cout << "| Tidak ada film duplikat.\n";
        cout << "|\n";
    }
    cout << "+=============================================+\n";
}

void userHitungTotalFilm(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|           TOTAL FILM TERDAFTAR              |";
    cout << "\n+=============================================+\n";
    int total = 0;
    adrSutradara S = L.first;
    while(S != nullptr){
        adrFilm F = S->firstFilm;
        while(F != nullptr){
            total++;
            F = F->next;
        }
        S = S->next;
    }
    cout << "|\n";
    cout << "| Total Film: " << total << " film\n";
    cout << "|\n";
    cout << "+=============================================+\n";
}

void userCariSutradaraByNama(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|          CARI SUTRADARA BY NAMA             |";
    cout << "\n+=============================================+\n";
    string nama;
    cin.ignore();
    cout << "| Masukkan Nama Sutradara: ";
    getline(cin, nama);
    cout << "\n+=============================================+";
    cout << "\n|              HASIL PENCARIAN                |";
    cout << "\n+=============================================+\n";
    adrSutradara S = L.first;
    bool found = false;
    while(S != nullptr && !found){
        if(S->nama == nama){
            cout << "|\n";
            cout << "| Nama : " << S->nama << "\n";
            cout << "| ID   : " << S->id << "\n";
            cout << "| Umur : " << S->umur << " tahun\n";
            cout << "|\n";
            found = true;
        }
        S = S->next;
    }
    if(!found){
        cout << "|\n";
        cout << "| Sutradara tidak ditemukan.\n";
        cout << "|\n";
    }
    cout << "+=============================================+\n";
}

void userCariSutradaraById(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|           CARI SUTRADARA BY ID              |";
    cout << "\n+=============================================+\n";
    string id;
    cin.ignore();
    cout << "| Masukkan ID Sutradara: ";
    getline(cin, id);
    cout << "\n+=============================================+";
    cout << "\n|              HASIL PENCARIAN                |";
    cout << "\n+=============================================+\n";
    adrSutradara S = L.first;
    bool found = false;
    while(S != nullptr && !found){
        if(S->id == id){
            cout << "|\n";
            cout << "| ID   : " << S->id << "\n";
            cout << "| Nama : " << S->nama << "\n";
            cout << "| Umur : " << S->umur << " tahun\n";
            cout << "|\n";
            found = true;
        }
        S = S->next;
    }
    if(!found){
        cout << "|\n";
        cout << "| Sutradara tidak ditemukan.\n";
        cout << "|\n";
    }
    cout << "+=============================================+\n";
}

void userTampilFilmPerSutradara(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|        FILM PER SUTRADARA                   |";
    cout << "\n+=============================================+\n";
    string id;
    cin.ignore();
    cout << "| Masukkan ID Sutradara: ";
    getline(cin, id);
    cout << "\n+=============================================+";
    cout << "\n|           DAFTAR FILM                       |";
    cout << "\n+=============================================+\n";
    adrSutradara S = L.first;
    bool found = false;
    while(S != nullptr && !found){
        if(S->id == id){
            cout << "|\n";
            cout << "| Sutradara: " << S->nama << "\n";
            cout << "|\n";
            adrFilm F = S->firstFilm;
            if(F == nullptr){
                cout << "| Tidak ada film.\n";
            } else {
                int no = 1;
                while(F != nullptr){
                    cout << "| " << no << ". " << F->judul
                         << " (" << F->tahun << ")\n";
                    F = F->next;
                    no++;
                }
            }
            cout << "|\n";
            found = true;
        }
        S = S->next;
    }
    if(!found){
        cout << "|\n";
        cout << "| Sutradara tidak ditemukan.\n";
        cout << "|\n";
    }
    cout << "+=============================================+\n";
}

void userSutradaraTerbanyakFilm(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|        JUMLAH FILM PER SUTRADARA            |";
    cout << "\n+=============================================+\n";
    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Belum ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    int maxFilm = 0;
    while(S != nullptr){
        int count = 0;
        adrFilm F = S->firstFilm;
        while(F != nullptr){
            count++;
            F = F->next;
        }
        cout << "|\n";
        cout << "| " << S->nama << " : " << count << " film\n";
        if(count > maxFilm){
            maxFilm = count;
        }
        S = S->next;
    }
    cout << "|\n";
    cout << "+=============================================+";
    cout << "\n|      SUTRADARA DENGAN FILM TERBANYAK       |";
    cout << "\n+=============================================+\n";
    S = L.first;
    while(S != nullptr){
        int count = 0;
        adrFilm F = S->firstFilm;
        while(F != nullptr){
            count++;
            F = F->next;
        }
        if(count == maxFilm){
            cout << "|\n";
            cout << "| Nama        : " << S->nama << "\n";
            cout << "| ID          : " << S->id << "\n";
            cout << "| Jumlah Film : " << count << " film\n";
            cout << "|\n";
        }
        S = S->next;
    }
    cout << "+=============================================+\n";
}

void userTampilSemuaSutradara(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|         DAFTAR SEMUA SUTRADARA              |";
    cout << "\n+=============================================+\n";
    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Tidak ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    int no = 1;
    while(S != nullptr){
        cout << "|\n";
        cout << "| " << no << ". ID   : " << S->id << "\n";
        cout << "|    Nama : " << S->nama << "\n";
        cout << "|    Umur : " << S->umur << " tahun\n";
        S = S->next;
        no++;
    }
    cout << "|\n";
    cout << "+=============================================+\n";
}

void userTampilSemuaFilm(ListSutradara L){
    cout << "\n+=============================================+";
    cout << "\n|           DAFTAR SEMUA FILM                 |";
    cout << "\n+=============================================+\n";
    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Belum ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    while(S != nullptr){
        cout << "|\n";
        cout << "| Sutradara : " << S->nama << "\n";
        cout << "| ID        : " << S->id << "\n";
        cout << "|\n";
        adrFilm F = S->firstFilm;
        if(F == nullptr){
            cout << "| Tidak ada film.\n";
        }else{
            int no = 1;
            while(F != nullptr){
                cout << "| " << no << ". Judul : " << F->judul << "\n";
                cout << "|    Tahun : " << F->tahun << "\n";
                cout << "|    ID    : " << F->id << "\n";
                if(F->next != nullptr){
                    cout << "|\n";
                }
                F = F->next;
                no++;
            }
        }
        if(S->next != nullptr){
            cout << "|\n";
            cout << "+---------------------------------------------+\n";
        }
        S = S->next;
    }
    cout << "|\n";
    cout << "+=============================================+\n";
}

void userMenyisipkanSutradara(ListSutradara &L){
    string id, nama, umurStr;
    int umur;
    cout << "\n+=============================================+";
    cout << "\n|     MENYISIPKAN SUTRADARA (KONDISI)         |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| Kondisi: Menyisipkan sutradara baru\n";
    cout << "|          berdasarkan urutan umur \n";
    cout << "|\n";
    cout << "+=============================================+\n";
    bool idValid = false;
    while(!idValid){
        cout << "|\n";
        cout << "| ID Sutradara Baru: ";
        cin >> id;
        adrSutradara cek = L.first;
        bool idSudahAda = false;
        while(cek != nullptr){
            if(cek->id == id){
                idSudahAda = true;
                break;
            }
            cek = cek->next;
        }
        if(idSudahAda){
            cout << "|\n";
            cout << "| [GAGAL] ID " << id << " sudah digunakan!\n";
            cout << "| Silakan masukkan ID lain.\n";
        }else{
            idValid = true;
        }
    }
    cin.ignore();
    cout << "| Nama Sutradara    : ";
    getline(cin, nama);
    if(nama.empty()){
        cout << "|\n";
        cout << "| [!] Error: Nama tidak boleh kosong!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    cout << "| Umur              : ";
    cin >> umurStr;
    bool valid = true;
    for(int i = 0; i < umurStr.length(); i++){
        if(!isdigit(umurStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Umur harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    umur = stoi(umurStr);
    if(umur < 0 || umur > 150){
        cout << "|\n";
        cout << "| [!] Error: Umur tidak valid!\n";
        cout << "| Harus antara 0-150.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    if(L.first != nullptr){
        adrSutradara i = L.first;
        while(i != nullptr){
            adrSutradara j = i->next;
            while(j != nullptr){
                if(i->umur < j->umur){
                    string tempId = i->id;
                    string tempNama = i->nama;
                    int tempUmur = i->umur;
                    adrFilm tempFilm = i->firstFilm;
                    i->id = j->id;
                    i->nama = j->nama;
                    i->umur = j->umur;
                    i->firstFilm = j->firstFilm;
                    j->id = tempId;
                    j->nama = tempNama;
                    j->umur = tempUmur;
                    j->firstFilm = tempFilm;
                }
                j = j->next;
            }
            i = i->next;
        }
    }
    adrSutradara newS = buatSutradaraNode(id, nama, umur);
    if(L.first == nullptr){
        L.first = newS;
        L.last = newS;
        cout << "|\n";
        cout << "+=============================================+\n";
        cout << "| [BERHASIL] Sutradara " << nama << "\n";
        cout << "|            berhasil disisipkan!\n";
        cout << "+=============================================+\n";
        return;
    }
    if(umur > L.first->umur){
        newS->next = L.first;
        L.first->prev = newS;
        L.first = newS;
        cout << "|\n";
        cout << "+=============================================+\n";
        cout << "| [BERHASIL] Sutradara " << nama << "\n";
        cout << "|            berhasil disisipkan di awal!\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    while(S->next != nullptr && S->next->umur > umur){
        S = S->next;
    }
    newS->next = S->next;
    newS->prev = S;
    if(S->next != nullptr){
        S->next->prev = newS;
    }else{
        L.last = newS;
    }
    S->next = newS;
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| [BERHASIL] Sutradara " << nama << "\n";
    cout << "|            berhasil disisipkan!\n";
    cout << "+=============================================+\n";
}

void userHapusSutradaraBerdasarkanKondisi(ListSutradara &L){
    int umurMax;
    cout << "\n+=============================================+";
    cout << "\n|       HAPUS SUTRADARA (KONDISI)             |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| Kondisi: Hapus sutradara dengan umur < X\n";
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "|\n";
    cout << "| Masukkan umur maksimum: ";
    cin >> umurMax;
    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Belum ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    int count = 0;
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| Sutradara yang dihapus (umur < " << umurMax << "):\n";
    cout << "+=============================================+\n";
    while(S != nullptr){
        adrSutradara temp = S;
        S = S->next;
        if(temp->umur < umurMax){
            cout << "|\n";
            cout << "| " << (count + 1) << ". Nama : " << temp->nama << "\n";
            cout << "|    Umur : " << temp->umur << " tahun\n";

            if(temp == L.first && temp == L.last){
                L.first = nullptr;
                L.last = nullptr;
            }else if(temp == L.first){
                L.first = temp->next;
                L.first->prev = nullptr;
            }else if(temp == L.last){
                L.last = temp->prev;
                L.last->next = nullptr;
            }else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            count++;
        }
    }
    cout << "|\n";
    cout << "+=============================================+\n";
    if(count == 0){
        cout << "| Tidak ada sutradara yang memenuhi kondisi.\n";
        cout << "+=============================================+\n";
    }else{
        cout << "| [BERHASIL] Total " << count << " sutradara dihapus.\n";
        cout << "+=============================================+\n";
    }
}

void userMenyisipkanFilm(ListSutradara &L){
    string idS, idF, judul;
    int tahun;
    cout << "\n+============================================+";
    cout << "\n|   MENYISIPKAN FILM (KONDISI)               |";
    cout << "\n+============================================+\n";
    cout << "Kondisi: Sisipkan film ke sutradara yang memiliki < 5 film\n\n";
    cout << "Daftar Sutradara dengan film < 5:\n";
    adrSutradara S = L.first;
    int no = 1;
    bool adaSutradara = false;
    while(S != nullptr){
        int countFilm = 0;
        adrFilm F = S->firstFilm;
        while(F != nullptr){
            countFilm++;
            F = F->next;
        }
        if(countFilm < 5){
            cout << no << ". " << S->nama << " (ID: " << S->id << ") - Jumlah Film: " << countFilm << endl;
            adaSutradara = true;
            no++;
        }
        S = S->next;
    }
    if(!adaSutradara){
        cout << "\nSemua sutradara sudah memiliki >= 5 film. Film tidak disisipkan.\n";
        return;
    }
    bool idSutradaraValid = false;
    while(!idSutradaraValid){
        cout << "\nMasukkan ID Sutradara: ";
        cin >> idS;
        S = L.first;
        bool found = false;

        while(S != nullptr && !found){
            if(S->id == idS){
                int countFilm = 0;
                adrFilm F = S->firstFilm;
                while(F != nullptr){
                    countFilm++;
                    F = F->next;
                }
                if(countFilm < 5){
                    bool idFilmValid = false;
                    while(!idFilmValid){
                        cout << "ID Film Baru: ";
                        cin >> idF;
                        adrSutradara tempS = L.first;
                        bool idFilmSudahAda = false;
                        while(tempS != nullptr){
                            adrFilm cekFilm = tempS->firstFilm;
                            while(cekFilm != nullptr){
                                if(cekFilm->id == idF){
                                    idFilmSudahAda = true;
                                    break;
                                }
                                cekFilm = cekFilm->next;
                            }
                            if(idFilmSudahAda) break;
                            tempS = tempS->next;
                        }

                        if(idFilmSudahAda){
                            cout << "\n[GAGAL] ID Film " << idF << " sudah digunakan di sistem! Silakan masukkan ID lain.\n\n";
                        }else{
                            idFilmValid = true;
                        }
                    }
                    cin.ignore();
                    cout << "Judul Film: ";
                    getline(cin, judul);
                    cout << "Tahun: ";
                    cin >> tahun;
                    adrFilm newF = buatFilmNode(idF, judul, tahun);
                    insertLastFilm(S, newF);
                    cout << "\n[BERHASIL] Film " << judul << " berhasil disisipkan ke sutradara " << S->nama << " (Jumlah film sebelumnya: " << countFilm << ")\n";
                    found = true;
                    idSutradaraValid = true;
                }else{
                    cout << "\n[GAGAL] Sutradara " << S->nama << " sudah memiliki >= 5 film.\n";
                    found = true;
                }
            }else{
                S = S->next;
            }
        }
        if(!found){
            cout << "\n[GAGAL] Sutradara dengan ID " << idS << " tidak ditemukan.\n";
        }else{
            idSutradaraValid = true;
        }
    }
}

void userHapusFilmBerdasarkanKondisi(ListSutradara &L){
    int tahunMin;
    cout << "\n+=============================================+";
    cout << "\n|         HAPUS FILM (KONDISI)                |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| Kondisi: Hapus film dengan tahun < X\n";
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "|\n";
    cout << "| Masukkan tahun minimum: ";
    cin >> tahunMin;
    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Belum ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    int count = 0;
    cout << "|\n";
    cout << "+=============================================+\n";
    cout << "| Film yang dihapus (tahun < " << tahunMin << "):\n";
    cout << "+=============================================+\n";
    while(S != nullptr){
        adrFilm F = S->firstFilm;
        adrFilm prev = nullptr;
        while(F != nullptr){
            if(F->tahun < tahunMin){
                adrFilm temp = F;

                if(prev == nullptr){
                    S->firstFilm = F->next;
                    F = S->firstFilm;
                }else{
                    prev->next = F->next;
                    F = F->next;
                }
                cout << "|\n";
                cout << "| " << (count + 1) << ". Judul     : " << temp->judul << "\n";
                cout << "|    Tahun     : " << temp->tahun << "\n";
                cout << "|    Sutradara : " << S->nama << "\n";

                delete temp;
                count++;
            }else{
                prev = F;
                F = F->next;
            }
        }
        S = S->next;
    }
    cout << "|\n";
    cout << "+=============================================+\n";

    if(count == 0){
        cout << "| Tidak ada film yang memenuhi kondisi.\n";
        cout << "+=============================================+\n";
    }else{
        cout << "| [BERHASIL] Total " << count << " film dihapus.\n";
        cout << "+=============================================+\n";
    }
}

void userHitungFilmBerdasarkanTahun(ListSutradara L){
    int tahunCari;
    cout << "\n+=============================================+";
    cout << "\n|     HITUNG FILM BERDASARKAN TAHUN           |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| Masukkan tahun: ";
    cin >> tahunCari;

    if(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "|\n";
        cout << "| [!] Input tidak valid!\n";
        cout << "| Harap masukkan angka tahun.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }

    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Belum ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    int count = 0;
    cout << "|\n";
    cout << "+=============================================+";
    cout << "\n| Film yang dirilis pada tahun " << tahunCari << "\n";
    cout << "+=============================================+\n";
    while(S != nullptr){
        adrFilm F = S->firstFilm;
        while(F != nullptr){
            if(F->tahun == tahunCari){
                cout << "|\n";
                cout << "| " << (count + 1) << ". Judul     : " << F->judul << "\n";
                cout << "|    Sutradara : " << S->nama << "\n";
                count++;
            }
            F = F->next;
        }
        S = S->next;
    }
    cout << "|\n";
    cout << "+=============================================+\n";
    if(count == 0){
        cout << "| Tidak ada film yang ditemukan pada tahun " << tahunCari << "\n";
        cout << "+=============================================+\n";
    } else {
        cout << "| Total: " << count << " film pada tahun " << tahunCari << "\n";
        cout << "+=============================================+\n";
    }
}

void userCariSutradaraBerumurDiatas(ListSutradara L){
    string umurMinStr;
    int umurMin;
    cout << "\n+=============================================+";
    cout << "\n|     CARI SUTRADARA BERUMUR > X              |";
    cout << "\n+=============================================+\n";
    cout << "|\n";
    cout << "| Masukkan umur minimum: ";
    cin >> umurMinStr;
    bool valid = true;
    for(int i = 0; i < umurMinStr.length(); i++){
        if(!isdigit(umurMinStr[i])){
            valid = false;
            break;
        }
    }
    if(!valid){
        cout << "|\n";
        cout << "| [!] Error: Umur harus berupa angka!\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    umurMin = stoi(umurMinStr);
    if(L.first == nullptr){
        cout << "|\n";
        cout << "| Belum ada data sutradara.\n";
        cout << "|\n";
        cout << "+=============================================+\n";
        return;
    }
    adrSutradara S = L.first;
    int count = 0;
    cout << "|\n";
    cout << "+=============================================+";
    cout << "\n| Sutradara dengan umur > " << umurMin << " tahun\n";
    cout << "+=============================================+\n";
    while(S != nullptr){
        if(S->umur > umurMin){
            cout << "|\n";
            cout << "| " << (count + 1) << ". Nama : " << S->nama << "\n";
            cout << "|    ID   : " << S->id << "\n";
            cout << "|    Umur : " << S->umur << " tahun\n";
            count++;
        }
        S = S->next;
    }
    cout << "|\n";
    cout << "+=============================================+\n";
    if(count == 0){
        cout << "| Tidak ada sutradara yang memenuhi kriteria.\n";
        cout << "+=============================================+\n";
    } else {
        cout << "| Total: " << count << " sutradara\n";
        cout << "+=============================================+\n";
    }
}

void loadDummyData(ListSutradara &L){
    adrSutradara A = buatSutradaraNode("S01", "Budi Santoso", 45);
    adrSutradara B = buatSutradaraNode("S02", "Andi Wijaya", 50);
    adrSutradara C = buatSutradaraNode("S03", "Siti Rahma", 39);
    adrSutradara D = buatSutradaraNode("S04", "Rini Kusuma", 42);
    adrSutradara E = buatSutradaraNode("S05", "Dedi Saputra", 38);
    insertLastSutradara(L, A);
    insertLastSutradara(L, B);
    insertLastSutradara(L, C);
    insertLastSutradara(L, D);
    insertLastSutradara(L, E);
    insertLastFilm(A, buatFilmNode("F01", "Langit Senja", 2020));
    insertLastFilm(A, buatFilmNode("F02", "Petualangan Kota", 2018));
    insertLastFilm(A, buatFilmNode("F03", "Jejak Waktu", 2019));
    insertLastFilm(B, buatFilmNode("F04", "Hujan di Balik Awan", 2019));
    insertLastFilm(B, buatFilmNode("F05", "Gelombang Cinta", 2021));
    insertLastFilm(B, buatFilmNode("F06", "Langit Senja", 2020));
    insertLastFilm(B, buatFilmNode("F07", "Cahaya Pagi", 2022));
    insertLastFilm(C, buatFilmNode("F08", "Jejak Waktu", 2017));
    insertLastFilm(C, buatFilmNode("F09", "Mimpi Indah", 2023));
    insertLastFilm(C, buatFilmNode("F10", "Petualangan Kota", 2016));
    insertLastFilm(D, buatFilmNode("F11", "Bintang Malam", 2021));
    insertLastFilm(D, buatFilmNode("F12", "Cahaya Pagi", 2022));
    insertLastFilm(D, buatFilmNode("F13", "Senja Kelabu", 2020));
    insertLastFilm(D, buatFilmNode("F14", "Mimpi Indah", 2019));
    insertLastFilm(E, buatFilmNode("F15", "Hujan di Balik Awan", 2018));
    insertLastFilm(E, buatFilmNode("F16", "Bintang Malam", 2021));
    insertLastFilm(E, buatFilmNode("F17", "Daun Berguguran", 2023));
}
