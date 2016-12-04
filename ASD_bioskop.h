#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#define first(L) ((L).first)
#define last(L) ((L).last)
#define info(P) (P)->info
#define next(P) (P)->next
#define next_film(P) (P)->next_film
#define prev(P) (P)->prev

struct infotype_film
{
    int id;
    char nama[50];
    int durasi;
};

struct infotype_studio
{
    int id;
    char nama[10];
};

typedef struct elmnlist_film *adr_film;
typedef struct elmntlist_studio *adr_studio;

struct elmnlist_film
{
    infotype_film info;
    adr_film next;
    adr_film prev;
};

struct elmntlist_studio
{
    infotype_studio info;
    adr_studio next;
    adr_film next_film;
};

struct list_film
{
    adr_film first;
    adr_film last;
};

struct list_studio
{
    adr_studio first;
};

bool isEmpty_film(list_film LF);
void createList_film(list_film &LF);
adr_film allocate_film(infotype_film x);
void deallocate(adr_film P);
adr_film findElmnt_film(list_film LF, int x);
void insFirst_film(list_film &LF, adr_film P);
void insAfter_film(list_film &LF, adr_film P, adr_film Q);
void insLast_film(list_film &LF, adr_film P);
void delFirst_film(list_film &LF, adr_film &P);
void delAfter_film(list_film &LF, adr_film &P, adr_film Q);
void delLast_film(list_film &LF, adr_film &P);
void add_film(list_film &LF, infotype_film x);
void delete_film(list_film &LF, list_studio &LS, int x);
void set_film_to_studio(list_film LF, list_studio &LS, int x, int y);
void unset_film_to_studio(list_film LF, list_studio &LS, int x, int y);
int hitung_film(list_film LF);

//=============================================================================================

bool isEmpty_studio(list_studio LS);
void createList_studio(list_studio &LS);
adr_studio allocate_studio(infotype_studio y);
void deallocate(adr_studio P);
adr_studio findElmnt_studio(list_studio LS, int y);
void insFirst_studio(list_studio &LS, adr_studio P);
void insAfter_studio(list_studio &LS, adr_studio P, adr_studio Q);
void insLast_studio(list_studio &LS, adr_studio P);
void delFirst_studio(list_studio &LS, adr_studio &P);
void delAfter_studio(list_studio &LS, adr_studio &P, adr_studio Q);
void delLast_studio(list_studio &LS, adr_studio &P);
void add_studio(list_studio &LS, infotype_studio y);
void delete_studio(list_studio &LS, int y);
void sorting_studio(list_studio &LS);
int hitung_studio(list_studio LS);

//==============================================================================================

void gotoxy(int x, int y);
void menu_awal(int &input);
void menu_add_studio(list_studio &LS);
void menu_add_film(list_film &LF);
void menu_edit_studio(list_studio &LS);
void menu_edit_film(list_film &LF);
void menu_view(list_film LF, list_studio LS);
void menu_set_film(list_film LF, list_studio &LS);
void menu_unset_film(list_film LF, list_studio &LS);
void view_all(list_film LF, list_studio LS);
void menu_search_studio(list_studio LS);
void menu_search_film(list_film LF);
void menu_delete_film(list_film &LF, list_studio &LS);
void menu_delete_studio(list_studio &LS);
void menu_sorting(list_film LF, list_studio &LS);
void finish();

#endif // TICKET_H_INCLUDED
