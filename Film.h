#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>
#include <string>
#include "Sutradara.h"
using namespace std;

struct Film;
typedef Film *adrFilm;

struct Sutradara;
typedef Sutradara *adrSutradara;

struct ListSutradara;

struct Film{
    string id;
    string judul;
    int tahun;
    adrFilm next;
};

adrFilm buatFilmNode(string id, string judul, int tahun);
void insertLastFilm(adrSutradara S, adrFilm F);
void adminTampilSemuaFilm(ListSutradara L);
adrFilm findFilm(adrSutradara S, string idFilm);
void userCariFilmByJudul(ListSutradara L);
void userTampilSemuaFilmUnik(ListSutradara L);
void userHitungTotalFilm(ListSutradara L);
void userUrutkanFilmPerSutradara(ListSutradara &L);
void userLihatDetailFilm(ListSutradara L);
void adminInsertFirstFilm(ListSutradara &L);
void adminInsertLastFilm(ListSutradara &L);
void adminInsertAfterFilm(ListSutradara &L);
void adminDeleteFirstFilm(ListSutradara &L);
void adminDeleteLastFilm(ListSutradara &L);
void adminDeleteAfterFilm(ListSutradara &L);
void userTampilSemuaFilm(ListSutradara L);
void userMenyisipkanFilm(ListSutradara &L);
void userHapusFilmBerdasarkanKondisi(ListSutradara &L);

#endif
