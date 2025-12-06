#ifndef SUTRADARA_H_INCLUDED
#define SUTRADARA_H_INCLUDED
#include <iostream>
#include <string>
#include "Film.h"
using namespace std;

struct Film;
typedef Film *adrFilm;

struct Sutradara;
typedef Sutradara *adrSutradara;

struct Sutradara {
    string id;
    string nama;
    int umur;
    adrFilm firstFilm;
    adrSutradara next;
    adrSutradara prev;
};

struct ListSutradara {
    adrSutradara first;
    adrSutradara last;
};

void buatList(ListSutradara &L);
adrSutradara buatSutradaraNode(string id, string nama, int umur);
adrSutradara cariSutradaraById(ListSutradara L, string id);
void insertFirstSutradara(ListSutradara &L, adrSutradara S);
void insertLastSutradara(ListSutradara &L, adrSutradara S);
void insertAfterSutradara(ListSutradara &L, string idPatokan, adrSutradara S);
void deleteFirstSutradara(ListSutradara &L);
void deleteLastSutradara(ListSutradara &L);
void deleteAfterSutradara(ListSutradara &L, string idPatokan);
adrSutradara findSutradara(ListSutradara L, string id);
void adminTampilSemuaSutradara(ListSutradara L);
void adminInsertFirstSutradara(ListSutradara &L);
void adminInsertLastSutradara(ListSutradara &L);
void adminInsertAfterSutradara(ListSutradara &L);
void adminDeleteFirstSutradara(ListSutradara &L);
void adminDeleteLastSutradara(ListSutradara &L);
void adminDeleteAfterSutradara(ListSutradara &L);
void userCariSutradaraByNama(ListSutradara L);
void userCariSutradaraById(ListSutradara L);
void userTampilFilmPerSutradara(ListSutradara L);
void userSutradaraTerbanyakFilm(ListSutradara L);
void loadDummyData(ListSutradara &L);

#endif
