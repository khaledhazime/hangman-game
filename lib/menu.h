
void draw_main_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Main Menu");
    center_text(menu_size, "1. Play the game");
    center_text(menu_size, "2. Dictionary   ");
    center_text(menu_size, "3. Credits      ");
    center_text(menu_size, "4. Exit         ");
    draw_blank_line(menu_size);
    draw_line_cross(menu_size);
    center_text(menu_size, "Choose an option: ");
    draw_space_line((menu_size/2));
}

void draw_dictionary_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Dictionary Menu");
    center_text(menu_size, "1. Generate default dictionary        ");
    center_text(menu_size, "2. Add a word to the dictionary       ");
    center_text(menu_size, "3. Remove a word from the dictionary  ");
    center_text(menu_size, "4. Search for a word in the dictionary");
    center_text(menu_size, "5. Back to main menu                  ");
    draw_blank_line(menu_size);
    draw_line_cross(menu_size);
    center_text(menu_size, "Choose an option: ");
    draw_space_line((menu_size/2));
}

void draw_dictionary_add_word_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Dictionary Menu");
    draw_line_cross(menu_size);
    center_text(menu_size, "You chose to add a word to the dictionary");
}

void draw_dictionary_remove_word_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Dictionary Menu");
    draw_line_cross(menu_size);
    center_text(menu_size, "You chose to remove a word from the dictionary");
}

void draw_dictionary_search_word_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Dictionary Menu");
    draw_line_cross(menu_size);
    center_text(menu_size, "You chose to search for a word in the dictionary");
}

void draw_dictionary_word_found_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Dictionary Menu");
    draw_line_cross(menu_size);
    center_text(menu_size, "The word was found in the dictionary");
}
