#include "proc&func.h"

void createlistpemain(List_pemain &L){
    first(L)=nil;
    last(L)=nil;
}

void createlistfilm(List_film &L){
    first(L)=nil;
}
void createlistrelasi(List_relasi &L){
    first(L)=nil;
}

void insertpemain(List_pemain &L){
    //kalo ada nama/judul yg udah pernah ada, input yg beda
    address_pemain p=new ElmList_pemain;
    cout<<"Masukkan nama aktor/aktris: ";
    char input[100];
    cin.getline(input,100);

    info(p).nama=input;
    cout<<"Masukkan jenis kelamin(L/P): ";
    char sex;
    cin>>sex;
    while ((sex!='L')&&(sex!='P')) {
        cout<<"input jenis kelamin error. input lagi"<<endl;
        cin>>sex;
    }
    info(p).sex=sex;
    info(p).jmlfilm=0;
    if (first(L) == nil){last(L) = p;}
    next(p)=first(L);
    if (first(L) != nil){prev(first(L))=p;}
    prev(p)=nil;
    first(L)=p;
    cout<<"input pemain selesai"<<endl;
    cin.get();
    system("CLS");
}

void insertfilm(List_film &Lfilm, List_relasi &Lrel, List_pemain &Lpem){
    //kalo ada nama/judul yg udah pernah ada, input yg beda
    system("CLS");
    while(ActorCheck(Lpem)!=3){
        insertpemain(Lpem);
    }
    address_film adrfilm=new ElmList_film;
    address_film r=first(Lfilm);
    cout<<"Masukkan judul film: ";
    char input[100];
    cin.getline(input,100);
    info(adrfilm)=input;
    next(adrfilm)=first(Lfilm);
    first(Lfilm)=adrfilm;
    pilihPemUtamaFilmUntilValid(Lrel,Lpem,adrfilm);
    pilihPemPendamping(Lrel,Lpem,adrfilm);
}

void outnamapemain(List_pemain &L){
    address_pemain q=first(L);
    int c=0;
    while(q!=nil){
           c=c+1;
           cout<<c<<". "<<info(q).nama<<endl;
            q=next(q);
        }
    if(c==0){
        cout<<"Tidak ada data pemain untuk dipilih. Silahkan input data pemain terlebih dahulu"<<endl;
        insertpemain(L);
        outnamapemain(L);
    }
}

void outNamaPemBelumBerelasi(List_relasi Lrel, List_pemain &Lpem, address_film film){
    address_pemain p=first(Lpem);
    int c=0;
    while (p!=nil){
        if(cekSudahBerelasi(Lrel,p,film)==0){
           c=c+1;
           cout<<c<<". "<<info(p).nama<<endl;
        }
        p=next(p);
    }
    if(c==0){
        cout<<"Tidak ada pemain untuk dipilih, silahkan input pemain"<<endl;
        insertpemain(Lpem);
        outNamaPemBelumBerelasi(Lrel, Lpem, film);
    }
}

void outNamaFilm(List_film &Lfilm, List_relasi &Lrel, List_pemain &Lpem){
    address_film q=first(Lfilm);
    int c=0;
    while(q!=nil){
        c=c+1;
        cout<<c<<". "<<info(q)<<endl;
        q=next(q);

    }
    if(c==0){
        cout<<"Tidak ada data film. Silahkan input data film terlebih dahulu"<<endl;
        insertfilm(Lfilm,Lrel,Lpem);
        outNamaFilm(Lfilm,Lrel,Lpem);
    }
}

void showFilmInfo(List_relasi L, address_film x){
    address_relasi P;
    if ((x != nil) && (first(L)!=nil)){
        cout<<"Judul Film        : ";cout<<info(x)<<endl;
        cout<<"Pemain Utama      : "<<endl;
        P = first(L);
        while (P != nil){
            if((x == film(P))&&(utama(P) == 1)){
                cout<<info(pemain(P)).nama<<endl;
            }
            P = next(P);
        }
        cout<<"Pemain Pendamping: "<<endl;
        P = first(L);
        while (P != nil){
            if((x == film(P))&&(utama(P) == 0)){
                cout<<info(pemain(P)).nama<<endl;
            }
            P = next(P);
        }
    }
    else{
        cout<<"List film kosong"<<endl;
    }
}

void showActorFilm(List_relasi L, address_pemain x){
    address_relasi P;
    int ada=0;
    if ((x != nil) && (first(L)!=nil)){
        cout<<"Nama Pemain      : ";cout<<info(x).nama<<endl;
        cout<<"Jenis Kelamin    : ";
            if (info(x).sex == 'L'){cout<<"Pria"<<endl;}
            if (info(x).sex == 'P'){cout<<"Wanita"<<endl;}
        cout<<"List Film        : "<<endl;
        P = first(L);
        while ((P) != nil){
            if (x == pemain(P)){
                if (utama(P) == 1){
                    cout<<info(film(P));
                    cout<<"---Pemeran Utama"<<endl;
                    ada=1;}
                if (utama(P) == 0){
                    cout<<info(film(P));
                    cout<<"---Pemeran Pendamping"<<endl;
                    ada=1;}
            }
            P = next(P);
        }
    }
    if(ada==0){
            cout<<"Pemain yang anda pilih tidak bermain film apapun"<<endl;
        }
}

address_pemain searchActor(List_pemain L, int x){
    int c = 0;
    address_pemain P = first(L);
    while ((P != nil)&&(x != c)){
        c=c+1;
        if(x!=c){P = next(P);}
    }
    if   (x == c){return P;}
    else        {return nil;}
}

address_film searchFilm(List_film L, int x){
    int c = 0;
    address_film P = first(L);
    while ((P!=nil)&&(x != c)){
        c = c+1;
        if(x!=c){P = next(P);}
    }
    if   (x == c){return P;}
    else        {return nil;}
}

address_pemain searchPemBelumBerelasi(List_relasi Lrel, List_pemain Lpem, int x, address_film film){
    int c=0;
    address_pemain p=first(Lpem);
    while((p!=nil)&&(c!=x)){
            if(cekSudahBerelasi(Lrel,p,film)==0){
                    c=c+1;
            }
            if(c!=x){p=next(p);}
    }
    if(x==c){return p;}
    else{return nil;}
}


int ActorCheck(List_pemain L){
    if (first(L) != nil){
        address_pemain P = first(L);
        int cowo = 0;
        int cewe = 0;
        while (P != nil){
            if (info(P).sex == 'L'){cowo = 1;};
            if (info(P).sex == 'P'){cewe = 1;};
            P = next(P);
        }
        if      ((cowo == 1) && (cewe == 1)){
                return 3;}
        else if ((cowo == 0) && (cewe == 1)){
            cout<<"Daftar pemain hanya berisikan pemain wanita saja"<<endl;
            cout<<"Silahkan input pemain laki-laki"<<endl;
            return 2;}
        else if ((cowo == 1) && (cewe == 0)){
            cout<<"Daftar pemain hanya berisikan pemain laki-laki saja"<<endl;
            cout<<"Silahkan input pemain wanita"<<endl;
            return 1;}
    }
    else {
            cout<<"List pemain kosong, silahkan input pemain dulu"<<endl;
            return nil;}
}

int CekValidPemUtama(List_relasi L, address_film x){
    if  (first(L) != nil){
        address_relasi P = first(L);
        int cowo = 0;
        int cewe = 0;
        while (P != nil){
            if ((x == film(P))&&(utama(P) == 1)){
                if (info(pemain(P)).sex == 'L'){cowo = 1;}
                if (info(pemain(P)).sex == 'P'){cewe = 1;}
            }
            P = next(P);
        }
        if ((cowo == 1) && (cewe == 1)){return 1;}
        else {return 0;}
    }
    else {return 0;}
}

void relPemUtamatoFilm(List_relasi &L, address_film film, address_pemain &pemain){
    address_relasi p=new ElmList_relasi;
    pemain(p)=pemain;
    film(p)=film;
    utama(p)=1;
    next(p)=first(L);
    first(L)=p;
    info(pemain).jmlfilm=info(pemain).jmlfilm+1;
}

void relPemPendampingtoFilm(List_relasi &L, address_film film, address_pemain &pemain){
    address_relasi p=new ElmList_relasi;
    pemain(p)=pemain;
    film(p)=film;
    utama(p)=0;
    next(p)=first(L);
    first(L)=p;
    info(pemain).jmlfilm=info(pemain).jmlfilm+1;
}

void relFilmtoPemain(List_relasi &L,address_film film, address_pemain &pemain){
    address_relasi p=new ElmList_relasi;
    pemain(p)=pemain;
    film(p)=film;
    next(p)=first(L);
    first(L)=p;
    info(pemain).jmlfilm=info(pemain).jmlfilm+1;
    cout<<"Apakah peran pemain ini dalam film "<<info(film)<<"?"<<endl;
    cout<<"1. Pemain utama"<<endl;
    cout<<"2. Pemain pendamping"<<endl;
    cout<<"Pilihan anda: ";
    int pilihanloop;
    do{
            cin>>pilihanloop;
            cin.get();
            if((pilihanloop!=1)&&(pilihanloop!=2)){
                cout<<"input pilihan tidak valid. silahkan input lagi"<<endl;
            };
    }while((pilihanloop!=1)&&(pilihanloop!=2));
    if(pilihanloop==1){
        utama(p)=1;
    }
    else{
        utama(p)=0;
    }
}

int DoubleActorCheck(List_relasi L, address_pemain x, address_film y){
    int check = 0;
    if ((first(L) != nil) && (x !=nil)){
        address_relasi P = first(L);
        while (P != nil){
            if ((pemain(P) == x) && (film(P) == y)){
                check = 1;
               }
            P = next(P);
        }
    }
    return check;
}

void pilihPemUtamaFilmUntilValid(List_relasi &Lrel, List_pemain &Lpem, address_film adrfilm){
    int pilihanpem; int pilihanloop; address_pemain adrpem;
    do{
        do{
            do{
                outNamaPemBelumBerelasi(Lrel,Lpem,adrfilm);
                cout<<"Silahkan pilih nomor pemain utama(Contoh input: 2)"<<endl;
                do{
                    cin>>pilihanpem;
                    cin.get();
                    adrpem=searchPemBelumBerelasi(Lrel,Lpem,pilihanpem,adrfilm);
                    if(adrpem==nil){
                        cout<<"pilihan tidak ditemukan. silahkan pilih lagi"<<endl;
                    }
                }while(adrpem==nil);
                if(DoubleActorCheck(Lrel,adrpem,adrfilm)==1){
                    cout<<"Pemain yang anda pilih sudah menjadi pemain di film ini "<<endl;
                    cout<<"silahkan pilih lagi"<<endl;
                }
            }while(DoubleActorCheck(Lrel,adrpem,adrfilm)==1);
            relPemUtamatoFilm(Lrel,adrfilm,adrpem);
            cout<<"Apakah anda ingin menambah pemain utama lagi?"<<endl;
            cout<<"1. Ya"<<endl;
            cout<<"2. Tidak"<<endl;
            cout<<"Pilihan anda: ";
            do{
                cin>>pilihanloop;
                cin.get();
                if((pilihanloop!=1)&&(pilihanloop!=2)){
                    cout<<"input pilihan tidak valid. silahkan input lagi"<<endl;
                };
            }while((pilihanloop!=1)&&(pilihanloop!=2));
            system("CLS");
        }while(pilihanloop==1);
        if(CekValidPemUtama(Lrel, adrfilm)!=1){
            cout<<"Pemain utama sebuah film setidaknya terdiri dari 1 laki-laki dan 1 perempuan"<<endl;
            cout<<"Silahkan pilih pemain utama lagi"<<endl;
        }
    }while(CekValidPemUtama(Lrel, adrfilm)!=1);
}

void pilihPemPendamping(List_relasi &Lrel, List_pemain &Lpem, address_film adrfilm){
    int pilihanpem; int pilihanloop; address_pemain adrpem;
        do{
            do{
                outNamaPemBelumBerelasi(Lrel,Lpem,adrfilm);
                cout<<"Silahkan pilih nomor pemain pendamping(Contoh input: 2)"<<endl;
                do{
                    cin>>pilihanpem;
                    cin.get();
                    adrpem=searchPemBelumBerelasi(Lrel,Lpem,pilihanpem,adrfilm);
                    if(adrpem==nil){
                        cout<<"pilihan tidak ditemukan. silahkan pilih lagi"<<endl;
                    }
                }while(adrpem==nil);
                if(DoubleActorCheck(Lrel,adrpem,adrfilm)==1){
                    cout<<"Pemain yang anda pilih sudah menjadi pemain di film ini "<<endl;
                    cout<<"silahkan pilih lagi"<<endl;
                }
            }while(DoubleActorCheck(Lrel,adrpem,adrfilm)==1);
            relPemPendampingtoFilm(Lrel,adrfilm,adrpem);
            cout<<"Apakah anda ingin menambah pemain pendamping lagi?"<<endl;
            cout<<"1. Ya"<<endl;
            cout<<"2. Tidak"<<endl;
            cout<<"Pilihan anda: ";
            do{
                cin>>pilihanloop;
                cin.get();
                if((pilihanloop!=1)&&(pilihanloop!=2)){
                    cout<<"input pilihan tidak valid. silahkan input lagi"<<endl;
                };
            }while((pilihanloop!=1)&&(pilihanloop!=2));
            system("CLS");
        }while(pilihanloop==1);
}

int cekSudahBerelasi(List_relasi L, address_pemain pemain, address_film film){
    if(first(L)!=nil){
        address_relasi p = first(L);
        while((next(p)!=nil)&&((film(p)!=film)||(pemain(p)!=pemain))) {
            p=next(p);
        }
        if((film(p)==film)&&(pemain(p)==pemain)){return 1;}
        else{return 0;};
    }
    else{
      return 0;
    }
}

void PilihFilmthenShow(List_film &Lfilm, List_pemain &Lpem, List_relasi &Lrel){
    system("CLS");
    address_film adrfilm=nil;
    while(adrfilm==nil){
        outNamaFilm(Lfilm,Lrel,Lpem);
        cout<<"Pilih film yang ingin dioutputkan"<<endl;
        cout<<"Pilihan: ";
        int pilihan;
        cin>>pilihan;
        cin.get();
        adrfilm=searchFilm(Lfilm,pilihan);
        if(adrfilm==nil){
            cout<<"Pilihan tidak ditemukan. Silahkan input lagi"<<endl;
        }
    }
    showFilmInfo(Lrel,adrfilm);
}

void pilihPemainthenShow(List_pemain &Lpem,List_relasi Lrel){
    system("CLS");
    address_pemain adrpem=nil;
    while(adrpem==nil){
        outnamapemain(Lpem);
        cout<<"Pilih pemain yang ingin dioutputkan"<<endl;
        cout<<"Pilihan: ";
        int pilihan;
        cin>>pilihan;
        cin.get();
        adrpem=searchActor(Lpem,pilihan);
        if(adrpem==nil){
            cout<<"Pilihan tidak ditemukan. Silahkan input lagi"<<endl;
        }
    }
    showActorFilm(Lrel,adrpem);
}

void showAll(List_film &Lfilm, List_relasi Lrel, List_pemain &Lpem){
    int ada=0;
    while(ada==0){
        system("CLS");
        if(first(Lfilm)!=nil){
            ada=1;
            address_film adrfilm=first(Lfilm);
            while (adrfilm!=nil){
                showFilmInfo(Lrel,adrfilm);
                cout<<endl;
                adrfilm=next(adrfilm);
            }
        }
        else{
            cout<<"Tidak ada data film. Silahkan input film terlebih dahulu"<<endl;
            insertfilm(Lfilm,Lrel,Lpem);
        }
    }
}

void pilihPemainPilihFilmThenRel(List_pemain &Lpem, List_relasi &Lrel, List_film &Lfilm){
    address_pemain adrpem=nil;
    address_film adrfilm=nil;
        system("CLS");
        while(adrpem==nil){
            outnamapemain(Lpem);
            cout<<"Pilih pemain yang ingin direlasikan"<<endl;
            cout<<"Pilihan: ";
            int pilihan;
            cin>>pilihan;
            cin.get();
            adrpem=searchActor(Lpem,pilihan);
            if(adrpem==nil){
                cout<<"Pilihan tidak ditemukan. Silahkan input lagi"<<endl;
            }
        }
        system("CLS");
        while(adrfilm==nil){
            outNamaFilm(Lfilm,Lrel,Lpem);
            cout<<"Pilih film yang ingin direlasikan"<<endl;
            cout<<"Pilihan: ";
            int pilihan;
            cin>>pilihan;
            cin.get();
            adrfilm=searchFilm(Lfilm,pilihan);
            if(adrfilm==nil){
                cout<<"Pilihan tidak ditemukan. Silahkan input lagi"<<endl;
            }
        }
        if(cekSudahBerelasi(Lrel,adrpem,adrfilm)==1){
            cout<<"Pemain "<<info(adrpem).nama<<" sudah bermain di film "<<info(adrfilm)<<endl;
            cout<<"Silahkan pilih pemain dan film yang lain"<<endl;
            cout<<"Tekan sembarang tombol untuk lanjut";
            getch();
            cout<<endl;
        }
        else{
            system("CLS");
            cout<<"Apakah peran "<<info(adrpem).nama<<" dalam film "<<info(adrfilm)<<"?"<<endl;
            cout<<"1. Sebagai pemain utama"<<endl;
            cout<<"2. Sebagai pemain Pendamping"<<endl;
            cout<<"Pilihan anda: ";
            char pilihan='0';
            while( (pilihan!='1')&&(pilihan!='2')){
                pilihan=getch();
                if(pilihan=='1'){
                    relPemUtamatoFilm(Lrel,adrfilm,adrpem);
                }
                else if(pilihan=='2'){
                    relPemPendampingtoFilm(Lrel,adrfilm,adrpem);
                }
                else{
                    cout<<"Pilihan anda tidak valid, silahkan input lagi"<<endl;
                }
            }
        }

}

void showTop(List_pemain Lpem, List_relasi Lrel){
    system("CLS");
    if(first(Lpem)!=nil){
        int maxcowo=0;
        int maxcewe=0;
        address_pemain p=first(Lpem);
        while (p!=nil){
            if((maxcowo<info(p).jmlfilm)&&(info(p).sex=='L')){
                maxcowo=info(p).jmlfilm;
            }
            if((maxcewe<info(p).jmlfilm)&&(info(p).sex=='P')){
                maxcewe=info(p).jmlfilm;
            }
            p=next(p);
        }
        if(maxcowo==0){
            cout<<"Tidak ada pemain laki-laki top"<<endl;
        }
        else{
            cout<<"Berikut adalah pemain laki-laki paling top"<<endl;
            cout<<endl;
            p=first(Lpem);
            while (p!=nil){
                if((maxcowo==info(p).jmlfilm)&&(info(p).sex=='L')){
                    showActorFilm(Lrel,p);
                    cout<<endl;
                }
                p=next(p);
            }
        }
        cout<<"Ketik tombol sembarang untuk lanjut";
        getch();
        system("CLS");
        if(maxcewe==0){
            cout<<"Tidak ada pemain perempuan top"<<endl;
        }
        else{
            cout<<"Berikut adalah pemain perempuan paling top"<<endl;
            cout<<endl;
            p=first(Lpem);
            while (p!=nil){
                if((maxcewe==info(p).jmlfilm)&&(info(p).sex=='P')){
                    showActorFilm(Lrel,p);
                    cout<<endl;
                }
                p=next(p);
            }
        }
    }
    else{
        cout<<"Tidak ada data  pemain "<<endl;
        cout<<"Silahkan kembali ke menu utama dan input pemain terlebih dahulu"<<endl;
    }
    cout<<"Ketik tombol sembarang untuk kembali ke menu utama";
    getch();
}
int deleteActorPreventionV2(List_relasi R, List_film F, address_pemain x){
    char pv = '0';int cowoU; int ceweU; int pend; int utm;char mark;
    char gen = info(x).sex;
    address_film LF = first(F);
    address_relasi r1;
    address_relasi r2;
    while ((LF != nil)&&(pv == '0')){ //checking every film
        showFilmInfo(R,LF);
        r1 =first(R);
        while ((r1 != nil)&&(pv == '0')){ //checking every relation on film
            if ((x == pemain(r1))&&(LF == film(r1))){
                utm = utama(r1);
                r2 = first(R);
                cowoU = 0;
                ceweU = 0;
                pend  = 0;
                while ((r2 != nil)&&(pv == '0')){ //counting every actor on relation
                    if (film(r2) == LF){
                        if ((info(pemain(r2)).sex == 'L')&&(utama(r2) == 1)){
                            if (pemain(r2) == x){mark = '1';cout<<"checkPointMk1"<<endl;}
                            cowoU = cowoU + 1;}
                        if ((info(pemain(r2)).sex == 'P')&&(utama(r2) == 1)){
                            if (pemain(r2) == x){mark = '2';cout<<"checkPointMk2"<<endl;}
                            ceweU = ceweU + 1;}
                        else if (utama(r2) == 0){
                            if (pemain(r2) == x){mark = '3';cout<<"checkPointMk3"<<endl;}
                            pend = pend + 1;};
                    }
                    r2 = next(r2);
                }
                if (utm == 1){
                    if ((gen == 'L')&&(cowoU <= 1)) {
                            if (mark == '1'){pv = '1';}}
                    if ((gen == 'P')&&(ceweU <= 1)) {
                            if (mark == '2'){pv = '1';}}
                }
                else if ((utm == 0)&&(pend <= 1)) {
                    if (mark == '3'){pv = '1';}}
                cowoU = 0;
                ceweU = 0;
                pend  = 0;
                mark = '0';
            }
            r1=next(r1);
        }
        LF = next(LF);
    }
    return pv;
}


void deleteActor(List_relasi &R, List_pemain &C, List_film &F, address_pemain &x){
    address_relasi P = first(R);
    address_relasi Q = first(R);
    address_pemain y = first(C);
        while (P != nil){
            if (x == pemain(P)){
                if ((P == first(R)) && (next(P) == nil)){
                    first(R) = nil;
                    delete (P);
                }
                else if (P == first(R)){
                    Q = next(Q);
                    first(R) = Q;
                    delete (P);
                    P = Q;
                }
                else if (next(P) == nil){
                    next(Q) = nil;
                    delete (P);
                }
                else if ((first(R) != P) && (next(P) != nil)){
                    next(Q) = next(P);
                    delete (P);
                    P = next(Q);
                }
            }
            else {
                Q = P;
                P = next(P);
            }
        }
        if ((x == first(C)) && (next(x) == nil)){
            first(C) = nil;
            last(C)  = nil;
            delete (x);
        }
        else if (x == first(C)){
            first(C) = next(x);
            prev(x)  = nil;
            delete (x);
        }
        else if (next(x) == nil){
            while (next(y) != x){
                y = next(y);}
            last(C) = y;
            next(y) = nil;
            delete (x);
        }
        else {
            while (next(y) != x){
                y = next(y);}
            next(y) = next(x);
            prev(next(y)) = y;
            delete (x);
        }
        system("CLS");cout<<endl;
        cout<<"Pemain terhapus"<<endl;cout<<endl;
}

void deleteFilm(List_relasi &R, List_pemain &C, List_film &F, address_film &x){
    address_relasi P = first(R);
    address_relasi Q = first(R);
    address_film y = first(F);
        while (P != nil){
            if (x == film(P)){
                if ((P == first(R)) && (next(P) == nil)){
                    first(R) = nil;
                    delete (P);
                    P = nil;
                }
                else if (P == first(R)){
                    info(pemain(P)).jmlfilm = info(pemain(P)).jmlfilm-1;
                    Q = next(Q);
                    first(R) = Q;
                    delete (P);
                    P = Q;
                }
                else if (next(P) == nil){
                    info(pemain(P)).jmlfilm = info(pemain(P)).jmlfilm-1;
                    next(Q) = nil;
                    delete (P);
                    P = nil;
                }
                else if ((first(R) != P) && (next(P) != nil)){
                    info(pemain(P)).jmlfilm = info(pemain(P)).jmlfilm-1;
                    next(Q) = next(P);
                    delete (P);
                    P = next(Q);
                }
            }
            else {
                Q = P;
                P = next(P);
            }
        }
        if ((x == first(F)) && (next(x) == nil)){
            first(F) = nil;
            delete (x);
        }
        else if (x == first(F)){
            first(F) = next(x);
            delete (x);
        }
        else if (next(x) == nil){
            while (next(y) != x){
                y = next(y);}
            next(y) = nil;
            delete (x);
        }
        else {
            while (next(y) != x){
                y = next(y);}
            next(y) = next(x);
            delete (x);
        }
        system("CLS");cout<<endl;
        cout<<"Film terhapus"<<endl;cout<<endl;
}

void deleteActorMenu(List_relasi &R, List_pemain &C, List_film &F){
    address_pemain P = first(C);
    int c=0;int pick;
    if (first(C) != nil){
        while(P!=nil){
           c=c+1;
           cout<<c<<". "<<info(P).nama<<endl;
           P = next(P);
        }
        cout<<"========00========"<<endl;cout<<endl;
        cout<<"Pilih pemain yang ingin anda hapus : ";
        cin>>pick;
        cin.get();
        P = searchActor(C,pick);
        while (P == nil){
            cout<<"Inputan anda tidak valid. Silahkan input lagi"<<endl;
            cout<<"Pick Actor number for deletion : ";
            cin>>pick;
            cin.get();
            P = searchActor(C,pick);
        }
        int pv = deleteActorPreventionV2(R,F,P);
        system("CLS");cout<<endl;
        if      (pv == '0'){
            deleteActor(R, C, F, P);}
        else if (pv == '1'){
            cout<<"Pemain yang Anda pilih tidak dapat dihapus"<<endl;cout<<endl;}
    }
    else if (first(C) == nil){
        system("CLS");cout<<endl;
        cout<<"Anda tidak memiliki data pemain"<<endl;cout<<endl;}
}

void deleteFilmMenu(List_relasi &R, List_pemain &C, List_film &F){
    address_film P = first(F);
    int c=0; int pick;
    if (first(F) != nil){
        while(P!=nil){
            c=c+1;
            cout<<c<<". "<<info(P)<<endl;
            P=next(P);
        }
        cout<<"========00========"<<endl;cout<<endl;
        cout<<"Pilih film yang ingin Anda hapus : ";
        cin>>pick;
        cin.get();
        P = searchFilm(F,pick);
        while (P == nil){
            cout<<"Inputan anda tidak valid. Silahkan input lagi"<<endl;
            cout<<"Pilih film yang ingin Anda hapus : ";
            cin>>pick;
            cin.get();
            P = searchFilm(F,pick);
        }
        system("CLS");cout<<endl;
        deleteFilm(R, C, F, P);
    }
    else if (first(F) == nil){
        system("CLS");cout<<endl;
        cout<<"Anda tidak memiliki data film"<<endl;;cout<<endl;}
}
