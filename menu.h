#define RB "\e(0\x6a\e(B" // 188 Right Bottom corner
#define RT "\e(0\x6b\e(B" // 187 Right Top corner
#define LT "\e(0\x6c\e(B" // 201 Left Top cornet
#define LB "\e(0\x6d\e(B" // 200 Left Bottom corner
#define MC "\e(0\x6e\e(B" // 206 Midle Cross
#define HL "\e(0\x71\e(B" // 205 Horizontal Line
#define LC "\e(0\x74\e(B" // 204 Left Cross
#define RC "\e(0\x75\e(B" // 185 Right Cross
#define BC "\e(0\x76\e(B" // 202 Bottom Cross
#define TC "\e(0\x77\e(B" // 203 Top Cross
#define VL "\e(0\x78\e(B" // 186 Vertical Line
#define SP " " 		  // space string

void new_line() {
    printf("\n");
}

void draw_horizontal_line(int length){
    for(int i = 0; i < length; i++){
        printf("%s", HL);
    }
}

void draw_vertical_line(int length){
    for(int i = 0; i < length-1; i++){
        printf("%s\n", VL);
    }
    printf("%s", VL);
}

void draw_top_menu(int length){
    printf("%s", LT);
    draw_horizontal_line(length);
    printf("%s", RT);
    new_line();
}

void draw_bottom_menu(int length){
    printf("%s", LB);
    draw_horizontal_line(length);
    printf("%s", RB);
    new_line();
}

void draw_blank_line(int length){
    draw_vertical_line(1);
    for(int i = 0; i < length; i++){
        printf("%s", SP);
    }
    draw_vertical_line(1);
    new_line();
}

void draw_space_line(int length){
    for(int i = 0; i < length; i++){
        printf("%s", SP);
    }
}

void center_text(int length, char* text){;
    int text_length = strlen(text);
    int space_length = (length - text_length)/2;

    draw_vertical_line(1);
    for(int i=0; i<space_length; i++){
        printf("%s", SP);
    }
    printf("%s", text);
    if(text_length%2 != 0){
        for(int i=0; i<space_length+1; i++){
            printf("%s", SP);
        }
    }
    else{
        for(int i=0; i<space_length; i++){
            printf("%s", SP);
        }
    }
    
    draw_vertical_line(1);
    new_line();
}

void draw_hangman(int size, int hangman_status){
    int hangman_size = 6;
    draw_vertical_line(1);
    draw_space_line((size/2)-hangman_size);

    // Top part of the hangman
    printf("%s", LT);
    draw_horizontal_line(6);
    printf("%s", RT);

    draw_space_line((size/2)-hangman_size+4);
    draw_vertical_line(1);
    new_line();

    // Middle part of the hangman    
    draw_vertical_line(1);
    draw_space_line((size/2)-hangman_size);
    draw_vertical_line(1);
    draw_space_line(hangman_size);
    draw_vertical_line(1);

    draw_space_line((size/2)-hangman_size+4);
    draw_vertical_line(1);
    new_line();

    // Head of the hangman
    draw_vertical_line(1);
    draw_space_line((size/2)-hangman_size);
    draw_vertical_line(1);
    draw_space_line(hangman_size);
    if(hangman_status > 0){
        printf("O");
    }
    else printf("X");
    

    draw_space_line((size/2)-hangman_size+4);
    draw_vertical_line(1);
    new_line();

    // Left arm of the hangman
    draw_vertical_line(1);
    draw_space_line((size/2)-hangman_size);
    draw_vertical_line(1);
    draw_space_line(hangman_size-1);
    
    if(hangman_status >= 1 || hangman_status == 0) printf("/");
    else draw_space_line(1);

    // Body of the hangman
    draw_vertical_line(1);

    // Right arm of the hangman
    if(hangman_status >= 2 || hangman_status == 0) printf("\\");
    else draw_space_line(1);
    
    draw_space_line((size/2)-hangman_size+3);
    draw_vertical_line(1);
    new_line();

    // Left leg of the hangman
    draw_vertical_line(1);
    draw_space_line((size/2)-hangman_size);
    draw_vertical_line(1);
    draw_space_line(hangman_size-1);

    if(hangman_status >= 3 || hangman_status == 0) printf("/");
    else draw_space_line(1);

    draw_space_line(1);

    // Right leg of the hangman
    if(hangman_status >= 4 || hangman_status == 0) printf("\\");
    else draw_space_line(1);

    draw_space_line((size/2)-hangman_size+3);

    draw_vertical_line(1);
    new_line();
    draw_blank_line(size);
    if(hangman_status == 0){
        center_text(size, "You lost!");
        new_line();
    }
    
}

void draw_char_box(char* text){
    int length = strlen(text);
    if(length == 1) length++;
    printf("%s", LT);
    draw_horizontal_line(length);
    printf("%s", RT);
    new_line();
    center_text(length, text);
    printf("%s", LB);
    draw_horizontal_line(length);
    printf("%s", RB);
}

