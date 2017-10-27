#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include "film.h"
#include "pemain.h"
#include "relasi.h"
#include "proc&func.h"

using namespace std;

int main()
{
    List_film Lfilm;
    List_pemain Lpem;
    List_relasi Lrel;
    createlistpemain(Lpem);
    createlistfilm(Lfilm);
    createlistrelasi(Lrel);
    int exit = 0;
    char pilihan;

    while (exit != 1){
    system("CLS");
    cout<<"========= MAIN MENU ========="<<endl;
    cout<<"1.   Penambahan Pemain."<<endl;
    cout<<"2.   Penambahan Film."<<endl;
    cout<<"3.   Penghapusan Data."<<endl;
    cout<<"4.   Pengaturan Relasi Pemain - Film."<<endl;
    cout<<"5.   Penampilan Data."<<endl;
    cout<<"6.   Pemain Paling Top."<<endl;
    cout<<"0.   Exit"<<endl;
    cout<<"======= INPUT PILIHAN ======="<<endl;
    cout<<" Masukkan pilihan    : ";
    pilihan=getch();
    char loop;
        switch (pilihan){
    case '1':
        loop='1';
        while(loop=='1'){
          system("CLS");
         insertpemain(Lpem);
         cout<<"Apakah anda ingin memasukkan pemain lagi?"<<endl;
         cout<<"1. Ya "<<endl;
         cout<<"2. Tidak "<<endl;
         cout<<"Pilihan: ";
         loop=getch();
         while ((loop!='1')&&(loop!='2')){
            cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
            loop=getch();
         }
        }
        break;
    case '2':
        loop='1';
        while(loop=='1'){
          system("CLS");
         insertfilm(Lfilm,Lrel,Lpem);
         cout<<"Apakah anda ingin memasukkan film lagi?"<<endl;
         cout<<"1. Ya "<<endl;
         cout<<"2. Tidak "<<endl;
         cout<<"Pilihan: ";
         loop=getch();
         while ((loop!='1')&&(loop!='2')){
            cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
            loop=getch();
         }
        }
        break;
    case '3':
        char pick;
        loop='1';
        system("CLS");
        while(loop=='1'){
            cout<<"Pilih Menu Deletion"<<endl;
            cout<<"1. Delete Aktor "<<endl;
            cout<<"2. Delete Film "<<endl;
            cout<<"Pilihan: ";
            pick = getch();
            cout<<endl;
            while ((pick!='1')&&(pick!='2')){
                cout<<endl;
                cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
                cin>>pick;
                cin.get();
            }
            system("CLS");
            if      (pick == '1'){
                deleteActorMenu(Lrel, Lpem, Lfilm);
            }
            else if (pick == '2'){
                deleteFilmMenu(Lrel, Lpem, Lfilm);
            }
            cout<<"Apakah anda ingin melakukan Penghapusan lagi?"<<endl;
            cout<<"1. Ya "<<endl;
            cout<<"2. Tidak "<<endl;
            cout<<"Pilihan: ";
            loop=getch();
            while ((loop!='1')&&(loop!='2')){
                cout<<endl;
                cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
                loop=getch();
            }
            system("CLS");cout<<endl;

        }

        break;
    case '4':
        system("CLS");
        if(first(Lpem)!=nil){
            if(first(Lfilm)!=nil){
               loop='1';
               while(loop=='1'){
                    pilihPemainPilihFilmThenRel(Lpem,Lrel,Lfilm);
                    system("CLS");
                    cout<<"Apakah anda ingin menentukan relasi lagi?"<<endl;
                    cout<<"1. Ya "<<endl;
                    cout<<"2. Tidak "<<endl;
                    cout<<"Pilihan: ";
                    loop=getch();
                    while ((loop!='1')&&(loop!='2')){
                        cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
                        loop=getch();
                    }
                }

            }
            else{
               cout<<"List film kosong, silahkan input data film terlebih dahulu"<<endl;
               cout<<"Tekan sembarang untuk lanjut"<<endl;
               getch();
            }

        }
        else{
               cout<<"List pemain kosong, silahkan input data pemain terlebih dahulu"<<endl;
               cout<<"Tekan sembarang untuk lanjut"<<endl;
               getch();
            }

        break;
    case '5':
        loop='1';
        char pilihdisp;
        while(loop=='1'){
             system("CLS");
             cout<<"Data apa yang ingin anda tampilkan?"<<endl;
             cout<<"1. Semua Film beserta pemain-pemainnya"<<endl;
             cout<<"2. Aktor/aktris yang bermain di suatu film"<<endl;
             cout<<"3. Film-film yang dimainkan seorang aktor/aktris"<<endl;
             pilihdisp=getch();
             while ((pilihdisp!='1')&&(pilihdisp!='2')&&(pilihdisp!='3')){
                cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
                pilihdisp=getch();
             }
             if(pilihdisp=='1'){
                if (first(Lfilm)!=nil){
                    showAll(Lfilm,Lrel,Lpem);
                }
                else{
                    cout<<"List film kosong, silahkan input data film di menu Penambahan Film"<<endl;
                    cout<<"Tekan tombol sembarang untuk lanjut"<<endl;
                    getch();
                    loop=2;
                }
            }
             else if(pilihdisp=='2'){
                if (first(Lfilm)!=nil){
                    PilihFilmthenShow(Lfilm,Lpem,Lrel);
                }
                else{
                    cout<<"List film kosong, silahkan input data film di menu Penambahan Film"<<endl;
                    cout<<"Tekan tombol sembarang untuk lanjut"<<endl;
                    getch();
                    loop=2;
                }
             }
             else if(pilihdisp=='3'){
                if (first(Lpem)!=nil){
                    pilihPemainthenShow(Lpem,Lrel);
                }
                else{
                    cout<<"List film pemain, silahkan input data pemain di menu Penambahan Pemain"<<endl;
                    cout<<"Tekan tombol sembarang untuk lanjut"<<endl;
                    getch();
                    loop=2;
                }
             }
             if(loop!=2){
                 cout<<"Apakah anda ingin menampilkan data lagi?"<<endl;
                 cout<<"1. Ya "<<endl;
                 cout<<"2. Tidak "<<endl;
                 cout<<"Pilihan: ";
                 loop=getch();
                 while ((loop!='1')&&(loop!='2')){
                    cout<<"inputan anda tidak valid. silahkan input lagi"<<endl;
                    loop=getch();
                 }
             }
        }
        break;
    case '6':
        showTop(Lpem,Lrel);
        break;
    case '0':
          exit = 1;
          system("CLS");
          cout<<"Terima kasih telah menggunakan program ini"<<endl;
        }
    }

    return 0;
}
