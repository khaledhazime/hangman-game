#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
// #include <conio.h>

#include "lib/utils.h"
#include "lib/menu.h"
#include "lib/dictionary.h"
#include "lib/game.h"

#define clrscr() printf("\e[1;1H\e[2J")

#define window_size 100
void main_menu();

void dictionary(){
    int option;
    int menu_option;
    draw_dictionary_menu(window_size);
    while(1){
        scanf("%d", &option);
        switch(option){
        case 1:
            create_dictionary();
            break;
        case 2:
            clrscr();
            draw_dictionary_add_word_menu(window_size);
            dict_add_word(window_size);
            scanf("%d", &menu_option);
            if(menu_option == 1){
                clrscr();
                dictionary();
            }
            else{
                clrscr();
                main_menu();
            }
            break;

        case 3:
            clrscr();
            draw_dictionary_search_word_menu(window_size);
            dict_search_word(window_size);
            scanf("%d", &menu_option);
            if(menu_option == 1){
                clrscr();
                dictionary();
            }
            else{
                clrscr();
                main_menu();
            }
            break;
        case 4:
            clrscr();
            main_menu();
            break;
        default:
            center_text(window_size, "Invalid number, please choose one of the above options");
            draw_space_line((window_size/2));
            break;
        }
    }   
}

void main_menu(){
    int option;
		int menu_option;
    while(1){
        draw_main_menu(window_size);
        scanf("%d", &option);
        switch(option){
            case 1:
                clrscr();
                main_game_loop(window_size);
                scanf(" %d", &menu_option);
                if(menu_option == 1){
                    clrscr();
                    main_game_loop(window_size);
																				
                }
                else if(menu_option == 2){
                    clrscr();
                    main_menu();
                }
                else if(menu_option == 3){
                    clrscr();
                    exit(0);
                }
                break;
            case 2:
                clrscr();
                dictionary();
                break;
            case 3:
                clrscr();
								draw_credits_menu(window_size);
                draw_credits_menu(window_size);
                clrscr();
                break;
            case 4:
                clrscr();
                exit(0);
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
    main_menu();
}