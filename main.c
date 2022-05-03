#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "lib/utils.h"
#include "lib/menu.h"
#include "lib/dictionary.h"

#define clrscr() printf("\e[1;1H\e[2J")

#define window_size 100

void dictionary(){
    int option;
    draw_dictionary_menu(window_size);
    while(1){
        scanf("%d", &option);
        switch(option){
        case 1:
            create_dictionary();
            break;
        case 2:
            clrscr();
            draw_dictionary_add_word_menu(window_size, 1, "");
            dict_add_word(window_size);
            break;
        case 3:
            // remove_word();
            break;
        case 4:
            // search_word();
            break;
        case 5:
            // main_menu();
            break;
        default:
            center_text(window_size, "Invalid number, please choose one of the above options");
            draw_space_line((window_size/2));
            break;
        }
    }   
}
int main(){
    clrscr();
    int option = 0;
    int dict = 0;
    while(1){
        draw_main_menu(window_size);
        scanf("%d", &option);
        switch(option){
            case 1:
                clrscr();
                break;
            case 2:
                clrscr();
                dictionary();
                break;

        }
        sleep(1000000);
    }
    
}