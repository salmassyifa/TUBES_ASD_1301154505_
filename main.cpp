#include <iostream>
#include <conio.h>
#include "ASD_bioskop.h"
using namespace std;

int main()
{
    int input;
    bool selesai = false;
    list_studio LS;
    list_film LF;

    createList_film(LF);
    createList_studio(LS);
    while(not(selesai))
    {
        menu_awal(input);
        switch(input)
        {
        case 1:
            {
                menu_add_studio(LS);
                break;
            }
        case 2:
            {
                menu_edit_studio(LS);
                break;
            }
        case 3:
            {
                menu_search_studio(LS);
                getch();
                break;
            }
        case 4:
            {
                menu_delete_studio(LS);
                getch();
                break;
            }
        case 5:
            {
                menu_add_film(LF);
                break;
            }
        case 6:
            {
                menu_edit_film(LF);
                break;
            }
        case 7:
            {
                menu_set_film(LF,LS);
                getch();
                break;
            }
        case 8:
            {
                menu_unset_film(LF,LS);
                getch();
                break;
            }
        case 9:
            {
                menu_search_film(LF);
                getch();
                break;
            }
        case 10:
            {
                menu_delete_film(LF,LS);
                getch();
                break;
            }
        case 11:
            {
                menu_sorting(LF,LS);
                getch();
                break;
            }
        case 12:
            {
                view_all(LF,LS);
                getch();
                break;
            }
        case 13:
            {
                finish();
                selesai = true;
                getch();
                break;
            }
        }
    }

    return 0;
}
