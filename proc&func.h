#ifndef PROC&FUNC_H_INCLUDED
#define PROC&FUNC_H_INCLUDED
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include "pemain.h"
#include "film.h"
#include "relasi.h"

void createlistpemain(List_pemain &L);
void createlistfilm(List_film &L);
void createlistrelasi(List_relasi &L);


void insertpemain(List_pemain &L);
void insertfilm(List_film &Lfilm, List_relasi &Lrel, List_pemain &Lpem);


void outnamapemain(List_pemain &L);
void outNamaPemBelumBerelasi(List_relasi Lrel, List_pemain &Lpem, address_film film);
void outNamaFilm(List_film &Lfilm, List_relasi &Lrel, List_pemain &Lpem);


void showFilmInfo(List_relasi L, address_film x);
void showActorFilm(List_relasi L, address_pemain x);


void PilihFilmthenShow(List_film &Lfilm, List_pemain &Lpem, List_relasi &Lrel);
void pilihPemainthenShow(List_pemain &Lpem,List_relasi Lrel);
void showAll(List_film &Lfilm, List_relasi Lrel, List_pemain &Lpem);


void pilihPemainPilihFilmThenRel(List_pemain &Lpem, List_relasi &Lrel, List_film &Lfilm);


address_pemain searchActor(List_pemain L, int x);
address_film searchFilm(List_film L, int x);
address_pemain searchPemBelumBerelasi(List_relasi Lrel, List_pemain Lpem, int x, address_film film);


int ActorCheck(List_pemain L);
int CekValidPemUtama(List_relasi L, address_film x);
int DoubleActorCheck(List_relasi L, address_pemain x, address_film y);
int cekSudahBerelasi(List_relasi L, address_pemain pemain, address_film film);
int deleteActorPreventionV2(List_relasi R, List_film F, address_pemain x);


void relPemUtamatoFilm(List_relasi &L, address_film film, address_pemain &pemain);
void relPemPendampingtoFilm(List_relasi &L, address_film film, address_pemain &pemain);
void relFilmtoPemain(List_relasi &Lrel,address_film film, address_pemain &pemain);


void pilihPemUtamaFilmUntilValid(List_relasi &Lrel, List_pemain &Lpem, address_film adrfilm);
void pilihPemPendamping(List_relasi &Lrel, List_pemain &Lpem, address_film adrfilm);

void deleteActor(List_relasi &R, List_pemain &C, List_film &F, address_pemain &x);
void deleteFilm(List_relasi &R, List_pemain &C, List_film &F, address_film &x);
void deleteActorMenu(List_relasi &R, List_pemain &C, List_film &F);
void deleteFilmMenu(List_relasi &R, List_pemain &C, List_film &F);

void showTop(List_pemain Lpem, List_relasi Lrel);
#endif // PROC&FUNC_H_INCLUDED
