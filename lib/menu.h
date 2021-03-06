
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
    center_text(menu_size, "1. Create a new dictionary            ");
    center_text(menu_size, "2. Add a word to the dictionary       ");
    center_text(menu_size, "3. Search for a word in the dictionary");
    center_text(menu_size, "4. Back to main menu                  ");
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

void draw_dicitonary_repeated_word_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Dictionary Menu");
    draw_line_cross(menu_size);
    center_text(menu_size, "The word was already in the dictionary");
    draw_line_cross(menu_size);
    center_text(menu_size, "1. Return to Dictionary Menu");
    center_text(menu_size, "2. Return to Main Menu      ");
    draw_bottom_line(menu_size);
}

void draw_credits_menu(int menu_size){
    draw_menu_header(menu_size, "The Hangman Game", "Credits Menu");
    center_text(menu_size, "This game was created by:");
    center_text(menu_size, "Khaled Hazime Guimaraes : github.com/khaledhazime");
    center_text(menu_size, "Thanks for playing!");
    draw_blank_line(menu_size);
    draw_bottom_line(menu_size);
    center_text(menu_size, "Press any key to return to the main menu");
    draw_space_line((menu_size/2));
    //Press any key to return
    getchar();
    
}