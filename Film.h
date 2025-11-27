#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct Sutradara;
typedef Sutradara *adrSutradara;

struct Film;
typedef Film *adrFilm;

struct Film {
    string id;
    string judul;
    int tahun;
    adrFilm next;
};

struct ListFilm {
    adrFilm first;
};

adrFilm buatFilmNode(string id, string judul, int tahun);
adrFilm cariFilmById(adrSutradara S, string id);
void adminTambahFilm(ListSutradara &L);
void adminHapusFilm(ListSutradara &L);
void adminUbahFilm(ListSutradara &L);
void adminTampilSemuaFilm(ListSutradara L);
void userCariFilmByJudul(ListSutradara L);
void userTampilSemuaFilmUnik(ListSutradara L);
void userHitungTotalFilm(ListSutradara L);
void userUrutkanFilmPerSutradara(ListSutradara &L);
void userLihatDetailFilm(ListSutradara L);

#endif // FILM_H_INCLUDED
