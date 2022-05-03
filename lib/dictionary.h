#define clrscr() printf("\e[1;1H\e[2J")
// Function to create a dictionary file
int create_dictionary(){
    FILE *fp;
    fp = fopen("dictionary.txt", "a");
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
    center_text(window_size, "Enter the definition of the word: ");
    draw_space_line((window_size/2));
    scanf("%s", def);
    FILE *fp;
    fp = fopen("dictionary.txt", "a");
    fprintf(fp, "%s : %s\n", word, def);
    fclose(fp);
}
