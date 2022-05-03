#define clrscr() printf("\e[1;1H\e[2J")
// Function to create a dictionary file
int create_dictionary(){
    FILE *fp;
    fp = fopen("dictionary.txt", "a");
    fclose(fp);
    return 1;
}

// Add a word to the dictionary
void dict_add_word(){
    char word[100];
    gets(word);
    clrscr();
    char def[100];
    draw_dictionary_add_word_menu(100, 2, word);
    scanf("%s", def);
    FILE *fp;
    fp = fopen("dictionary.txt", "a");
    fprintf(fp, "%s : %s\n", word, def);
    fclose(fp);
}
