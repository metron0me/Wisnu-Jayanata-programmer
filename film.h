#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include<iostream>
using namespace std;

#define nil NULL
#define next(P) P->next
#define info(P) (P)->info
#define first(L) (L).first


typedef struct ElmList_film *address_film; //  Type address : pointer to ElmList
struct ElmList_film {
    string info;
    address_film next;
};
struct List_film{
    address_film first;
};

#endif // FILM_H_INCLUDED
