#define clrscr() printf("\e[1;1H\e[2J")

// Function to create a dictionary file
int create_dictionary(){
    FILE *fp;
    fp = fopen("dictionary.txt", "a");
    fclose(fp);
    return 1;
}

// Check if the user entered a repeated word
int dict_repeated_word(int window_size, char *word){
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    char line[100];
    char *word_sep;
    char *def_sep;
    int option;
   

    while(fgets(line, 100, fp) != NULL){
        // Separate the word and definition
        word_sep = strtok(line, ":");
        def_sep = strtok(NULL, ":");
        // Check if the word is repeated
        if(strstr(word_sep, word) != NULL){
            fclose(fp);
            return 0;
        }
    }
    
    fclose(fp);
    return 1;
}

// Add a word to the dictionary
void dict_add_word(int window_size){
    char word[100];
    char def[100];
    center_text(window_size, "Enter the word to add:");
    draw_space_line((window_size/2));
    scanf("%s", word);
    if(dict_repeated_word(window_size, word)){
        center_text(window_size, "Enter the definition of the word: ");
        draw_space_line((window_size/2));
        scanf("%s", def);
        FILE *fp;
        fp = fopen("dictionary.txt", "a");
        fprintf(fp, "%s : %s\n", word, def);
        fclose(fp);
        center_text(window_size, "Word added to the dictionary successfully!");
        draw_line_cross(window_size);
        center_text(window_size, "1. Return to Dictionary Menu");
        center_text(window_size, "2. Return to Main Menu      ");
        draw_bottom_line(window_size);
    }
    else{
        clrscr();
        draw_dicitonary_repeated_word_menu(window_size);
    }
   
}


// Function to search a word in the dictionary
void dict_search_word(int window_size){
    char word[100];
    center_text(window_size, "Enter the word to search:");
    draw_space_line((window_size/2));
    scanf("%s", word);
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    char line[100];
    // Separate the word and definition
    char *word_sep;
    char *def_sep;
    int option;
    while(fgets(line, 100, fp) != NULL){
        word_sep = strtok(line, ":");
        def_sep = strtok(NULL, ":");
        if(strstr(word_sep, word) != NULL){
            clrscr();
            draw_dictionary_word_found_menu(window_size);
            center_text(window_size, "Your word is:");
            center_text(window_size, word_sep);
            center_text(window_size, "The definition of this word is:");
            center_text(window_size, def_sep);
            draw_line_cross(window_size);
            center_text(window_size, "1. Return to Dictionary Menu");
            center_text(window_size, "2. Return to Main Menu      ");
            draw_bottom_line(window_size);
            fclose(fp);
            return;
        }
    }
    center_text(window_size, "Word not found in the dictionary!");
    draw_line_cross(window_size);
    center_text(window_size, "1. Return to Dictionary Menu");
    center_text(window_size, "2. Return to Main Menu      ");
    draw_bottom_line(window_size);
    fclose(fp);
    sleep(2);
    return;
}

// Function to count the number of words in the dictionary
int count_lines(char *filename){
    FILE *fp;
    fp = fopen(filename, "r");
    int count = 0;
    char line[100];
    while(fgets(line, 100, fp) != NULL){
        count++;
    }
    fclose(fp);
    return count;
}

//Function to get random word and definition from dictionary
void get_random_word_and_def(char *word, char *definition){
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    char line[100];
    char *chosen_word;
    char *chosen_def;
    srand(time(NULL));
    int line_number = rand() % count_lines("dictionary.txt");
    int i=0;

    //Get random line
    while(fgets(line, 100, fp) != NULL){
        if(line_number == i){
            chosen_word = strtok(line, ":");
            chosen_def = strtok(NULL, ": ");
            break;
        }
        i++;
    }

    strcpy(word, chosen_word);
    strcpy(definition, chosen_def);
}