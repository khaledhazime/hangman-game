
void main_game_loop(int window_size);

void draw_game_win_menu(int window_size, int lifes, char* guesses, char* definition){

    int menu_option = 0;
    if(definition[strlen(definition)-1] == '\n'){
        definition[strlen(definition)-1] = '\0';
    }
        clrscr();
        int space_size = (window_size - (strlen(definition)-1))/2;
        draw_header(window_size, "The Hangman Game", "You won!!");
        draw_hangman(window_size, lifes);
        draw_multiple_boxes(window_size, guesses);
        center_text(window_size, "The definition of the word is: ");
        center_text(window_size, definition);

        
        draw_line_cross(window_size);
        center_text(window_size, "1. Play again         ");
        center_text(window_size, "2. Return to Main Menu");
        center_text(window_size, "3. Exit               ");
        draw_line_cross(window_size);
        center_text(window_size, "Choose an option: ");
        draw_space_line((window_size/2));
}

void draw_game_lose_menu(int window_size, int lifes, char* word, char* definition){

    int menu_option = 0;
    if(definition[strlen(definition)-1] == '\n'){
        definition[strlen(definition)-1] = '\0';
    }

    clrscr();
    int space_size = (window_size - (strlen(definition)-1))/2;
    draw_header(window_size, "The Hangman Game", "You Lost :(");
    draw_hangman(window_size, lifes);
    center_text(window_size, "The correct word was: ");
    draw_multiple_boxes(window_size, word);
    center_text(window_size, "The definition of the word is: ");
    center_text(window_size, definition);

    
    draw_line_cross(window_size);
    center_text(window_size, "1. Play again         ");
    center_text(window_size, "2. Return to Main Menu");
    center_text(window_size, "3. Exit               ");
    draw_line_cross(window_size);
    center_text(window_size, "Choose an option: ");
    draw_space_line((window_size/2));

}

void main_game_loop(int window_size){
    char word[100];
    char definition[100];
    
    int lifes = 6;
    char lifes_message[100];
    int correct = 0;
    int incorrect = 0;

    get_random_word_and_def(word, definition);

    char* guesses =(char*) malloc((strlen(word))*sizeof(char));
    char* wrong_guesses =(char*) malloc(6*sizeof(char));
    char guess;

    for(int i = 0; i <= strlen(word); i++){
        if(i == strlen(word)){
            guesses[i] = '\0';
        }
        else guesses[i] = ' ';
    }

    for(int i = 0; i <= 6; i++){
        wrong_guesses[i] = ' ';
    }

    while(lifes >= 0 && strcmp(word, guesses) != 0){
        clrscr();

        if(lifes>1) snprintf(lifes_message, sizeof(lifes_message), "You have %d guesses remaining", lifes);
        else if(lifes==1) snprintf(lifes_message, sizeof(lifes_message), "You have %d guess remaining", lifes);
        else snprintf(lifes_message, sizeof(lifes_message), "You lost!!");
        
        draw_header(window_size, "The Hangman Game", "A random word has been selected");
        center_text(window_size, lifes_message);
        center_text(window_size, "Wrong guesses:");
        draw_multiple_boxes(window_size, wrong_guesses);

        draw_hangman(window_size, lifes);

        draw_multiple_boxes(window_size, guesses);
        draw_line_cross(window_size);
        center_text(window_size, "Take your guess:");
        draw_vertical_line(1);
        draw_space_line(window_size/2);
        
        scanf(" %c", &guess);

        for(int i = 0; i < strlen(word); i++){
            if(guess == word[i]){
                guesses[i] = guess;
                correct=1;
            }
        }

        if(correct == 0){
            wrong_guesses[incorrect] = guess;
            incorrect++;
            lifes--;
        }
        correct = 0;
        
        if(strcmp(word, guesses) == 0){
            draw_game_win_menu(window_size, lifes, guesses, definition);       
        }

        if(lifes == 0){
            draw_game_lose_menu(window_size, lifes, word, definition);
        }
        
    }
}

