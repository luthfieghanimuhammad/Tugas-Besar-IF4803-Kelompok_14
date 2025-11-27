#ifndef SUTRADARA_H_INCLUDED
#define SUTRADARA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct Film;
typedef Film *adrFilm;

struct Sutradara;
typedef Sutradara *adrSutradara;

struct Sutradara {
    string id;
    string nama;
    adrFilm firstFilm;
    adrSutradara next;
    adrSutradara prev;
};

struct ListSutradara {
    adrSutradara first;
    adrSutradara last;
};

void buatList(ListSutradara &L);
adrSutradara buatSutradaraNode(string id, string nama);
adrSutradara cariSutradaraById(ListSutradara L, string id);
void hapusSemuaFilm(adrSutradara S);
void adminTambahSutradara(ListSutradara &L);
void adminHapusSutradara(ListSutradara &L);
void adminUbahSutradara(ListSutradara &L);
void adminTampilSemuaSutradara(ListSutradara L);
void userCariSutradaraByNama(ListSutradara L);
void userCariSutradaraById(ListSutradara L);
void userTampilFilmPerSutradara(ListSutradara L);
void userSutradaraTerbanyakFilm(ListSutradara L);

#endif // SUTRADARA_H_INCLUDED
