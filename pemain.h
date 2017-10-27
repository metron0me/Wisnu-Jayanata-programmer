#ifndef PEMAIN_H_INCLUDED
#define PEMAIN_H_INCLUDED

#include<iostream>
using namespace std;

#define nil NULL
#define next(P) P->next
#define prev(P) P->prev
#define info(P) (P)->info
#define first(L) (L).first
#define last(L) (L).last

struct datpemain{
    string nama;
    char sex;
    int jmlfilm;
};

typedef struct datpemain infotype_pemain;
typedef struct ElmList_pemain *address_pemain; //  Type address : pointer to ElmList
struct ElmList_pemain{
    infotype_pemain info;
    address_pemain next;
    address_pemain prev;
};
struct List_pemain{
    address_pemain first;
    address_pemain last;
};


#endif // PEMAIN_H_INCLUDED
