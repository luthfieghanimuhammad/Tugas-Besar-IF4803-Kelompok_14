#ifndef SUTRADARA_H_INCLUDED
#define SUTRADARA_H_INCLUDED
#include <string>

struct Film;
typedef Film *adrFilm;

struct Sutradara;
typedef Sutradara *adrSutradara;
typedef std::string infotype;

struct Sutradara {
    infotype id;
    infotype nama;
    adrFilm firstFilm;
    adrSutradara next;
};

struct ListSutradara {
    adrSutradara first;
};

void buatList(ListSutradara &L);
adrSutradara buatSutradaraNode(infotype id, infotype nama);
adrSutradara cariSutradaraById(ListSutradara L, infotype id);
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
