#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "film.h"
#include "pemain.h"

#define nil NULL
#define next(P) P->next
#define film(P) P->film
#define pemain(P) (P)->pemain
#define utama(P) (P)->utama
#define first(L) (L).first
#define last(L) (L).last

typedef struct ElmList_relasi *address_relasi; //  Type address : pointer to ElmList
struct ElmList_relasi{
    address_pemain pemain;
    address_film film;
    address_relasi next;
    int utama;
};
struct List_relasi{
    address_relasi first;
};

#endif // RELASI_H_INCLUDED
