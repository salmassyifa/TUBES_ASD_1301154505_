#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include "ASD_bioskop.h"
using namespace std;

bool isEmpty_film(list_film LF)
{
    bool x = true;
    if (first(LF) != NULL)
    {
        x = false;
    }
    return x;
}

void createList_film(list_film &LF)
{
    first(LF) = NULL;
    last(LF) = NULL;
}

adr_film allocate_film(infotype_film x)
{
    adr_film P = new elmnlist_film;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void deallocate(adr_film P)
{
    delete P;
}

adr_film findElmnt_film(list_film LF, int x)
{
    adr_film Q = first(LF);
    while((Q != NULL) and (info(Q).id != x))
    {
        Q = next(Q);
    }
    return Q;
}

void insFirst_film(list_film &LF, adr_film P)
{
    if (first(LF) != NULL)
    {
        next(P) = first(LF);
        prev(first(LF)) = P;
        first(LF) = P;
    }
    else
    {
        first(LF) = P;
        last(LF) = P;
    }
}

void insAfter_film(list_film &LF, adr_film P, adr_film Prec)
{
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    next(Prec) = P;
    prev(P) = Prec;
}

void insLast_film(list_film &LF, adr_film P)
{
    if (first(LF) != NULL)
    {
        next(last(LF)) = P;
        prev(P) = last(LF);
        last(LF) = P;
    }
    else
    {
        first(LF) = P;
        last(LF) = P;
    }
}

void delFirst_film(list_film &LF, adr_film &P)
{
    P = first(LF);
    if (first(LF) != last(LF))
    {
        first(LF) = next(P);
        prev(first(LF)) = NULL;
        next(P) = NULL;
    }
    else
    {
        first(LF) = NULL;
        last(LF) = NULL;
    }
}

void delAfter_film(list_film &LF, adr_film &P, adr_film Prec)
{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void delLast_film(list_film &LF, adr_film &P)
{
    P = last(LF);
    if (prev(last(LF)) != NULL)
    {
        last(LF) = prev(last(LF));
        next(last(LF)) = NULL;
        prev(P) = NULL;
    }
    else
    {
        first(LF) = NULL;
        last(LF) = NULL;
    }
}

void add_film(list_film &LF, infotype_film x)
{
    adr_film P = findElmnt_film(LF,x.id);
    adr_film Q;
    int id;
    if(P == NULL)
    {
        P = allocate_film(x);
        if(first(LF) == NULL)
        {
            insFirst_film(LF,P);
        }
        else if(first(LF) == last(LF))
        {
            if(info(first(LF)).id < info(P).id)
            {
                insLast_film(LF,P);
            }
            else
            {
                insFirst_film(LF,P);
            }
        }
        else
        {
            gotoxy(25,40); cout<<"                            ";
            gotoxy(25,40); cout<<"Input Data setelah ID : ";
            cin>>id;
            gotoxy(25,40); cout<<"                            ";
            Q = findElmnt_film(LF,id);
            if(Q != NULL)
            {
                if(next(Q) != NULL)
                {
                    insAfter_film(LF,P,Q);
                }
                else
                {
                    insLast_film(LF,P);
                }
            }
            else
            {
                gotoxy(25,40); cout<<"Data tidak ditemukan"<<endl;
            }
        }
    }
    else
    {
        gotoxy(25,40); cout<<"                            ";
        gotoxy(25,40); cout<<"Data sudah ada"<<endl;
    }
}

void delete_film(list_film &LF, list_studio &LS, int x)
{
    adr_film P = findElmnt_film(LF,x);
    if(P != NULL)
    {
        adr_studio Q = first(LS);
        while(Q != NULL)
        {
            if(info(next_film(Q)).id == info(P).id)
            {
                next_film(Q) = NULL;
            }
            Q = next(Q);
        }
        if(P == first(LF))
        {
            delFirst_film(LF,P);
        }
        else if(P == last(LF))
        {
            delLast_film(LF,P);
        }
        else
        {
            adr_film Prec = prev(P);
            delAfter_film(LF,P,Prec);
        }
        gotoxy(30,40); cout<<"                            ";
        gotoxy(30,40); cout<<"Data berhasil dihapus"<<endl;
        deallocate(P);
    }
    else
    {
        gotoxy(30,40); cout<<"                            ";
        gotoxy(30,40); cout<<"Data tidak ditemukan"<<endl;
    }
}

void set_film_to_studio(list_film LF, list_studio &LS, int x, int y)
{
    adr_film P = findElmnt_film(LF,x);
    adr_studio Q = findElmnt_studio(LS,y);
    if((P != NULL) and (Q != NULL))
    {
        next_film(Q) = P;
        gotoxy(30,42); cout<<"Berhasil";
    }
    else
    {
        gotoxy(30,42); cout<<"Terjadi kesalahan";
    }
}
void unset_film_to_studio(list_film LF, list_studio &LS, int x, int y)
{
    adr_film P = findElmnt_film(LF,x);
    adr_studio Q = findElmnt_studio(LS,y);
    if((P != NULL) and (Q != NULL))
    {
        next_film(Q) = NULL;
        gotoxy(30,42); cout<<"Berhasil";
    }
    else
    {
        gotoxy(30,42); cout<<"Terjadi kesalahan";
    }
}

int hitung_film(list_film LF)
{
    adr_film P = first(LF);
    int counter = 0;
    while(P != NULL)
    {
        counter++;
        P = next(P);
    }
    return counter;
}



//==============================================================================================


bool isEmpty_studio(list_studio LS)
{
    bool x = true;
    if (first(LS) != NULL)
    {
        x = false;
    }
    return x;
}

void createList_studio(list_studio &LS)
{
    first(LS) = NULL;
}

adr_studio allocate_studio(infotype_studio y)
{
    adr_studio P = new elmntlist_studio;
    info(P) = y;
    next(P) = NULL;
    next_film(P) = NULL;
    return P;
}

void deallocate(adr_studio P)
{
    delete P;
}

adr_studio findElmnt_studio(list_studio LS, int y)
{
    adr_studio Q = first(LS);
    while ((Q != NULL) and (info(Q).id != y))
    {
        Q = next(Q);
    }
    return Q;
}

void insFirst_studio(list_studio &LS, adr_studio P)
{
    if (first(LS) != NULL)
    {
        next(P) = first(LS);
        first(LS) = P;
    }
    else
    {
        first(LS) = P;
    }
}

void insAfter_studio(list_studio &LS, adr_studio P, adr_studio Prec)
{
    next(P) = next(Prec);
    next(Prec) = P;
}

void insLast_studio(list_studio &LS, adr_studio P)
{
    adr_studio Q = first(LS);
    if (first(LS) != NULL)
    {
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
    else
    {
        first(LS) = P;
    }
}

void delFirst_studio(list_studio &LS, adr_studio &P)
{
    P = first(LS);
    if (next(first(LS)) != NULL)
    {
        first(LS) = next(P);
        next(P) = NULL;
    }
    else
    {
        first(LS) = NULL;
    }
}

void delAfter_studio(list_studio &LS, adr_studio &P, adr_studio Prec)
{
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void delLast_studio(list_studio &LS, adr_studio &P)
{
    adr_studio Q = first(LS);
    if (next(first(LS)) != NULL)
    {
        while (next(next(Q)) != NULL)
        {
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = NULL;
    }
    else
    {
        first(LS) = NULL;
    }
}

void add_studio(list_studio &LS, infotype_studio y)
{
    adr_studio P = findElmnt_studio(LS,y.id);
    adr_studio Q;
    int id;
    if(P == NULL)
    {
        P = allocate_studio(y);
        if(first(LS) == NULL)
        {
            insFirst_studio(LS,P);
        }
        else if(next(first(LS)) == NULL)
        {
            if(info(first(LS)).id < info(P).id)
            {
                insLast_studio(LS,P);
            }
            else
            {
                insFirst_studio(LS,P);
            }
        }
        else
        {
            gotoxy(25,40); cout<<"                            ";
            gotoxy(25,40); cout<<"Input Data setelah ID : ";
            cin>>id;
            gotoxy(25,40); cout<<"                            ";
            Q = findElmnt_studio(LS,id);
            if(Q != NULL)
            {
                insAfter_studio(LS,P,Q);
            }
            else
            {
                gotoxy(25,40); cout<<"Data tidak ditemukan"<<endl;
            }
        }
    }
    else
    {
        gotoxy(25,40); cout<<"                            ";
        gotoxy(25,40); cout<<"Data sudah ada"<<endl;
    }
}

void delete_studio(list_studio &LS, int y)
{
    adr_studio P = findElmnt_studio(LS,y);
    if(P != NULL)
    {
        if(P == first(LS))
        {
            delFirst_studio(LS,P);
        }
        else if(next(P) == NULL)
        {
            delLast_studio(LS,P);
        }
        else
        {
            adr_studio Prec = first(LS);
            while(next(Prec) != P)
            {
                Prec = next(Prec);
            }
            delAfter_studio(LS,P,Prec);
        }
        gotoxy(30,40); cout<<"                            ";
        gotoxy(30,40); cout<<"Data berhasil dihapus"<<endl;
        next_film(P) = NULL;
        deallocate(P);
    }
    else
    {
        gotoxy(30,40); cout<<"                            ";
        gotoxy(30,40); cout<<"Data tidak ditemukan"<<endl;
    }
}

void sorting_studio(list_studio &LS)
{
    infotype_studio temp;
    adr_studio P = first(LS);
    adr_studio Q, Prec, Back;
    adr_film temp_next_film;

    while(next(P) != NULL)
          {
              Q = P;
              Prec = first(LS);
              temp = info(Q);
              temp_next_film = next_film(Q);
              while((next(Prec) != Q) and (Q != first(LS)))
              {
                  Prec = next(Prec);
              }
              while((Q != first(LS)) and (info(Prec).nama > temp.nama))
              {
                  info(Q) = info(Prec);
                  next_film(Q) = next_film(Prec);
                  Back = first(LS);
                  while((next(Back) != Q) and (Q != first(LS)))
                  {
                      Back = next(Back);
                  }
                  Q = Back;
              }
              info(Q) = temp;
              next_film(Q) = temp_next_film;
              P = next(P);
          }
}

int hitung_studio(list_studio LS)
{
    adr_studio P = first(LS);
    int counter = 0;
    while(P != NULL)
    {
        counter++;
        P = next(P);
    }
    return counter;
}



//==============================================================================================



void gotoxy(int x, int y)
{
    HANDLE hConsoleOutput;
    COORD dwCursorPostion;

    cout.flush();
    dwCursorPostion.X = x;
    dwCursorPostion.Y = y;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput,dwCursorPostion);
}

void menu_awal(int &input)
{
    system("cls");
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,35);
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(28,15);
    cout<<"1. Add Studio";
    gotoxy(28,16);
    cout<<"2. Edit Studio";
    gotoxy(28,17);
    cout<<"3. Search Studio";
    gotoxy(28,18);
    cout<<"4. Delete Studio";
    gotoxy(28,19);
    cout<<"5. Add Film";
    gotoxy(28,20);
    cout<<"6. Edit Film";
    gotoxy(28,21);
    cout<<"7. Set Film to Studio";
    gotoxy(28,22);
    cout<<"8. Unset Film to Studio";
    gotoxy(28,23);
    cout<<"9. Search Film";
    gotoxy(28,24);
    cout<<"10. Delete Film";
    gotoxy(28,25);
    cout<<"11. Sort Studio";
    gotoxy(28,26);
    cout<<"12. View All";
    gotoxy(28,27);
    cout<<"13. Exit Program";
    gotoxy(28,30);
    cout<<"Masukkan pilihan : ";
    cin>>input;
    if((input < 0) or (input > 13))
    {
        gotoxy(20,31);
        cout<<"Input tidak tersedia, Press any key....";
        getch();
        system("cls");
        menu_awal(input);
    }
}

void menu_add_studio(list_studio &LS)
{
    infotype_studio y;
    int ky = 9;

    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"================================  ADD STUDIO  ================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(25,6); cout<<"=========================";
    gotoxy(25,7); cout<<"|  ID   |  Nama Studio  |";
    gotoxy(25,8); cout<<"=========================";
    gotoxy(25,ky); cout<<"|       |               |";
    gotoxy(28,ky); cin>>y.id;
    while(y.id != 000)
    {
        gotoxy(35,ky); cin>>y.nama;
        add_studio(LS,y);
        ky++;
        gotoxy(25,ky); cout<<"|       |               |";
        gotoxy(28,ky); cin>>y.id;
    }
    gotoxy(25,ky); cout<<"=========================";
    gotoxy(25,ky+1); cout<<"Press any key....";
    getch();
}

void menu_add_film(list_film &LF)
{
    infotype_film x;
    int ky = 9;

    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"================================   ADD FILM   ================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(3,6); cout<<"========================================================================";
    gotoxy(3,7); cout<<"|  ID   |                      Nama Film                      | Durasi |";
    gotoxy(3,8); cout<<"========================================================================";
    gotoxy(3,ky); cout<<"|       |                                                     |        |";
    gotoxy(6,ky); cin>>x.id;
    while(x.id != 000)
    {
        gotoxy(14,ky); cin>>x.nama;
        gotoxy(69,ky); cin>>x.durasi;
        add_film(LF,x);
        ky++;
        gotoxy(3,ky); cout<<"|       |                                                     |        |";
        gotoxy(6,ky); cin>>x.id;
    }
    gotoxy(3,ky); cout<<"========================================================================";
    gotoxy(3,ky+1); cout<<"Press any key....";
    getch();
}

void menu_edit_studio(list_studio &LS)
{
    int id;
    infotype_studio y;

    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"================================  EDIT STUDIO ================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(20,10); cout<<"==========Current Data==========";
    gotoxy(20,11); cout<<"ID             : ";
    cin>>id;
    adr_studio P = findElmnt_studio(LS,id);
    if(P != NULL)
    {
        gotoxy(20,12); cout<<"Nama Studio    : "<<info(P).nama;
        gotoxy(20,13); cout<<"============New Data===========";
        gotoxy(20,14); cout<<"ID             : "<<info(P).id;
        gotoxy(20,15); cout<<"Nama Studio    : ";
        cin>>y.nama;
        gotoxy(20,16); cout<<"===============================";
        gotoxy(20,17); cout<<"Press any key....";
        y.id = info(P).id;
        info(P) = y;
    }
    else
    {
        gotoxy(20,12); cout<<"Data tidak ditemukan"<<endl;
        gotoxy(20,13); cout<<"===============================";
        gotoxy(20,14); cout<<"Press any key....";
    }
    getch();
}

void menu_edit_film(list_film &LF)
{
    int id;
    infotype_film x;

    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"=================================  EDIT FILM  ================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(20,10); cout<<"==============Current Data==============";
    gotoxy(20,11); cout<<"ID            : ";
    cin>>id;
    adr_film P = findElmnt_film(LF,id);
    if(P != NULL)
    {
        gotoxy(20,12); cout<<"Nama Film     : "<<info(P).nama;
        gotoxy(20,13); cout<<"Durasi        : "<<info(P).durasi;
        gotoxy(20,14); cout<<"================New Data================";
        gotoxy(20,15); cout<<"ID            : "<<info(P).id;
        gotoxy(20,16); cout<<"Nama Film     : ";
        cin>>x.nama;
        gotoxy(20,17); cout<<"Durasi        : ";
        cin>>x.durasi;
        gotoxy(20,18); cout<<"========================================";
        gotoxy(20,19); cout<<"Press any key....";
        x.id = info(P).id;
        info(P) = x;
    }
    else
    {
        gotoxy(20,12); cout<<"Data tidak ditemukan"<<endl;
        gotoxy(20,13); cout<<"========================================";
        gotoxy(20,14); cout<<"Press any key....";
    }
    getch();
}

void menu_view(list_film LF, list_studio LS)
{
    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================  Press any key....  ============================"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;

    adr_studio Q = first(LS);
    int ky = 10;
    gotoxy(0,7); cout<<"===================================";
    gotoxy(0,8); cout<<"|  ID   |  Nama Studio  | ID Film |";
    gotoxy(0,9); cout<<"===================================";
    while(Q != NULL)
    {
        gotoxy(0,ky); cout<<"|       |               |         |";
        gotoxy(3,ky); cout<<info(Q).id;
        gotoxy(11,ky); cout<<info(Q).nama;
        if(next_film(Q) != NULL)
        {
            gotoxy(29,ky); cout<<info(next_film(Q)).id;
        }
        else
        {
            gotoxy(26,ky); cout<<"Kosong";
        }
        Q = next(Q);
        ky++;
    }
    gotoxy(0,ky); cout<<"===================================";

    adr_film R = first(LF);
    ky = 10;
    gotoxy(36,7); cout<<"===========================================";
    gotoxy(36,8); cout<<"|  ID   |            Nama Film            |";
    gotoxy(36,9); cout<<"===========================================";
    while(R != NULL)
    {
        gotoxy(36,ky); cout<<"|       |                                 |";
        gotoxy(39,ky); cout<<info(R).id;
        gotoxy(47,ky); cout<<info(R).nama;
        R = next(R);
        ky++;
    }
    gotoxy(36,ky); cout<<"===========================================";
}

void menu_set_film(list_film LF, list_studio &LS)
{
    int idf, ids;

    menu_view(LF,LS);
    gotoxy(30,37); cout<<"===== Set Film =====";
    gotoxy(30,38); cout<<"ID    : ";
    cin>>idf;
    gotoxy(30,39); cout<<"==== To Studio  ====";
    gotoxy(30,40); cout<<"ID    : ";
    cin>>ids;
    gotoxy(30,41); cout<<"====================";
    set_film_to_studio(LF,LS,idf,ids);
}

void menu_unset_film(list_film LF, list_studio &LS)
{
    int idf, ids;

    menu_view(LF,LS);
    gotoxy(30,37); cout<<"==== Unset Film ====";
    gotoxy(30,38); cout<<"ID    : ";
    cin>>idf;
    gotoxy(30,39); cout<<"=== From Studio ====";
    gotoxy(30,40); cout<<"ID    : ";
    cin>>ids;
    gotoxy(30,41); cout<<"====================";
    unset_film_to_studio(LF,LS,idf,ids);
}

void view_all(list_film LF, list_studio LS)
{
    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================  Press any key....  ============================"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;

    adr_studio P = first(LS);
    int ky = 8;
    gotoxy(5,5); cout<<"=======================================================================";
    gotoxy(5,6); cout<<"|    STUDIO    |                       FILM                           |";
    gotoxy(5,7); cout<<"=======================================================================";
    while(P != NULL)
    {
        gotoxy(5,ky); cout<<"|              |                                                      |";
        gotoxy(8,ky); cout<<info(P).nama;
        if(next_film(P) != NULL)
        {
            gotoxy(23,ky); cout<<info(next_film(P)).nama;
        }
        else
        {
            gotoxy(42,ky); cout<<"----------";
        }
        ky++;
        P = next(P);
    }
    gotoxy(5,ky); cout<<"=======================================================================";
}

void menu_search_studio(list_studio LS)
{
    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"===============================  SEARCH STUDIO  ================================"<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================  Press any key....  ============================"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;

    int id;
    adr_studio P;
    gotoxy(30,6); cout<<"== Search Studio ==";
    gotoxy(30,7); cout<<"ID    : ";
    cin>>id;
    gotoxy(30,8); cout<<"===================";
    P = findElmnt_studio(LS,id);
    if(P != NULL)
    {
        gotoxy(23,11); cout<<"===================================";
        gotoxy(23,12); cout<<"|  ID   |  Nama Studio  | ID Film |";
        gotoxy(23,13); cout<<"===================================";
        gotoxy(23,14); cout<<"|       |               |         |";
        gotoxy(25,14); cout<<info(P).id;
        gotoxy(34,14); cout<<info(P).nama;
        if(next_film(P) != NULL)
        {
            gotoxy(50,14); cout<<info(next_film(P)).id;
        }
        else
        {
            gotoxy(50,14); cout<<"Kosong";
        }
        gotoxy(23,15); cout<<"===================================";
    }
    else
    {
        gotoxy(30,11); cout<<"Data tidak tersedia";
    }
}

void menu_search_film(list_film LF)
{
    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"================================  SEARCH FILM  ================================"<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================  Press any key....  ============================"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;

    int id;
    adr_film P;
    gotoxy(30,6); cout<<"=== Search Film ===";
    gotoxy(30,7); cout<<"ID    : ";
    cin>>id;
    gotoxy(30,8); cout<<"===================";
    P = findElmnt_film(LF,id);
    if(P != NULL)
    {
        gotoxy(3,11); cout<<"========================================================================";
        gotoxy(3,12); cout<<"|  ID   |                      Nama Film                      | Durasi |";
        gotoxy(3,13); cout<<"========================================================================";
        gotoxy(3,14); cout<<"|       |                                                     |        |";
        gotoxy(6,14); cout<<info(P).id;
        gotoxy(14,14); cout<<info(P).nama;
        gotoxy(69,14); cout<<info(P).durasi;
        gotoxy(3,15); cout<<"========================================================================";
    }
    else
    {
        gotoxy(30,11); cout<<"Data tidak tersedia";
    }
}

void menu_delete_studio(list_studio &LS)
{
    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"===============================  DELETE STUDIO  ==============================="<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================  Press any key....  ============================"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;

    int id;
    adr_film P;
    gotoxy(30,15); cout<<"== Search Studio ==";
    gotoxy(30,16); cout<<"ID    : ";
    cin>>id;
    gotoxy(30,17); cout<<"===================";
    delete_studio(LS,id);
}

void menu_delete_film(list_film &LF, list_studio &LS)
{
    system("cls");
    cout<<"=================================  TICKETING  ================================="<<endl;
    cout<<"===============================  Studio - Film  ==============================="<<endl;
    cout<<"================================  DELETE FILM  ================================"<<endl;
    cout<<"==============================================================================="<<endl;
    gotoxy(0,44);
    cout<<"==============================  Press any key....  ============================"<<endl;
    cout<<"==============================================================================="<<endl;
    cout<<"==============================================================================="<<endl;

    int id;
    adr_film P;
    gotoxy(30,15); cout<<"=== Search Film ===";
    gotoxy(30,16); cout<<"ID    : ";
    cin>>id;
    gotoxy(30,17); cout<<"===================";
    delete_film(LF,LS,id);
}

void menu_sorting(list_film LF, list_studio &LS)
{
    if(first(LS) != NULL)
    {
        sorting_studio(LS);
        gotoxy(25,40); cout<<"                                ";
        gotoxy(25,40); cout<<"Data tersusun, Press any key..."<<endl;
    }
    else
    {
        gotoxy(25,40); cout<<"                                    ";
        gotoxy(25,40); cout<<"Data belum terisi, Press any key..."<<endl;
    }
}

void finish()
{
    system("cls");
    gotoxy(37,22); cout<<"SELESAI";
    gotoxy(30,23); cout<<"=====================";
    gotoxy(34,24); cout<<"by salmassyf";
    gotoxy(33,25); cout<<"( 1301154505 )";
}
