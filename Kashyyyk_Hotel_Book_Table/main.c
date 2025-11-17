#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char g_firstnames[10][50];
char g_surnames[10][50];
char g_dobs[10][50];
char g_children[10][50];
char g_adults[10][50];
char g_board_type[10][50];
char g_length_of_stay[10][50];
char g_newspaper[10][50];
char g_room_number[10][50];
char g_booking_id[10][50];
int g_tables_booked[10];

char endor_table_data[2][7] = {
    'x','-','-','-','-','-','-',
    '-','-','-','-','-','-','-'
};
char tatooine_table_data[2][7] = {
    '-','x','-','-','-','-','-',
    '-','-','-','-','-','-','-'
};
char naboo_table_data[2][7] = {
    '-','-','x','-','-','-','-',
    '-','-','-','-','-','-','-'
};

int table_booking(char g_children[10][50],char g_adults[10][50],char g_board_type[10][50],char g_booking_id[10][50], int g_tables_booked[10]);
int booking_valid(char g_board_type[10][50],char g_booking_id[10][50]);
int choose_and_book_table(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]);
void display_table_free(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7], char table_choice);
int check_free_spot(char day[3], int time, char table_choice, char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]);
void check_in();

int main(void) {
    setbuf(stdout,NULL);
    printf("Hello, World!\n");


    check_in();
    table_booking(g_children, g_adults, g_board_type, g_booking_id, g_tables_booked);
    return 0;
}

int table_booking(char g_children[10][50],char g_adults[10][50],char g_board_type[10][50],char g_booking_id[10][50], int g_tables_booked[10]) {
    char would_you_like_to_book, booking_id[100];
    int can_you_book = 0, valid_input = 0, booked, id_place = 0, valid = 0;

    while (valid_input == 0) {
        printf("Would you like to book a table? (Y/N)\n");
        scanf(" %c", &would_you_like_to_book);

        if (would_you_like_to_book == 'Y' || would_you_like_to_book == 'y') {
            can_you_book = booking_valid(g_booking_id, g_board_type);
            valid_input = 1;
        }
        else if (would_you_like_to_book == 'N' || would_you_like_to_book == 'n') {
            printf("Returns to menu\n");
            valid_input = 1;
        }
        else {
            printf("Invalid input, please try again.\n");
        }
    }

    if (can_you_book == 1) {
        booked = choose_and_book_table(endor_table_data, tatooine_table_data, naboo_table_data);
    }
    else {
        printf("return to menu");
    }

    if (booked == 1) {
        printf("Please enter your booking ID once more to confirm your reservation: ");
        scanf("%s", &booking_id);
        while (valid == 0) {
            if (strcmp(g_booking_id[id_place], booking_id)) {
                valid = 1;
            }
            else {
                id_place ++;
            }
        }

        g_tables_booked[id_place] +=1;

        printf("Your table is successfully booked.");
    }
    else {
        printf("I am very sorry\n");
        printf("The table was either full or your booking was unsuccessful\n");
        printf("Please try again");
    }

    return 0;
}

int booking_valid(char g_booking_id[10][50], char g_board_type[10][50]) {
    char booking_ID[100];
    int valid = 0, repeat = 0, ID_found = -1;

    printf("Please enter your booking ID: ");
    scanf("%s", booking_ID);

    while (valid == 0) {
        if (strcmp(g_booking_id[repeat], booking_ID) == 0) {
            ID_found = repeat;
            if (strcmp(g_board_type[ID_found], "FB") == 0 || strcmp(g_board_type[ID_found], "HB") == 0)
                valid = 1;
            else {
                valid = 3;
            }
        }
        else {
            repeat++;
            if (repeat >= 10) {
                valid = 2;
            }
        }
    }

    if (valid == 1) {
        printf("You're valid for a booking!\n");
    }
    else if (valid == 2) {
        printf("ID not found.\n");
    }
    else {
        printf("Your Board Type is invalid (Only full board and half board can book a table).");
        printf("Therefore you are unable to book a table.");
    }

    return valid;
}

int choose_and_book_table(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]) {
    char table_choice, day[4];
    int time, table_booked;

    printf("Which table would you like to book? (E = endor, T = tatooine, N = naboo)\n");
    scanf("%s", &table_choice);
    display_table_free(endor_table_data, tatooine_table_data, naboo_table_data, table_choice);
    printf("Table %c is free at these times (represented by a '-')\n", table_choice);

    printf("What day would you like to book? (first 3 letters, lower case): ");
    scanf("%s", &day);
    printf("And at what time?: ");
    scanf("%d", &time);


    table_booked = check_free_spot(day, time, table_choice, endor_table_data, tatooine_table_data, naboo_table_data);

    return table_booked;

}

int check_free_spot(char day[3], int time, char table_choice, char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]) {
    int table_booked;
    if (table_choice == 'E') {
        if (strcmp(day, "mon") == 0) {
            if (time == 7) {
                if (endor_table_data[0][0] == '-') {
                    table_booked = 1;
                    endor_table_data[0][0] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][0] == '-') {
                    table_booked = 1;
                    endor_table_data[1][0] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "tue") == 0) {
            if (time == 7) {
                if (endor_table_data[0][1] == '-') {
                    table_booked = 1;
                    endor_table_data[0][1] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][1] == '-') {
                    table_booked = 1;
                    endor_table_data[1][1] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "wed") == 0) {
            if (time == 7) {
                if (endor_table_data[0][2] == '-') {
                    table_booked = 1;
                    endor_table_data[0][2] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][2] == '-') {
                    table_booked = 1;
                    endor_table_data[1][2] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "thu") == 0) {
            if (time == 7) {
                if (endor_table_data[0][3] == '-') {
                    table_booked = 1;
                    endor_table_data[0][3] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][3] == '-') {
                    table_booked = 1;
                    endor_table_data[1][3] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "fri") == 0) {
            if (time == 7) {
                if (endor_table_data[0][4] == '-') {
                    table_booked = 1;
                    endor_table_data[0][4] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][4] == '-') {
                    table_booked = 1;
                    endor_table_data[1][4] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "sat") == 0) {
            if (time == 7) {
                if (endor_table_data[0][5] == '-') {
                    table_booked = 1;
                    endor_table_data[0][5] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][5] == '-') {
                    table_booked = 1;
                    endor_table_data[1][5] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "sun") == 0) {
            if (time == 7) {
                if (endor_table_data[0][6] == '-') {
                    table_booked = 1;
                    endor_table_data[0][6] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (endor_table_data[1][6] == '-') {
                    table_booked = 1;
                    endor_table_data[1][6] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
    }

    if (table_choice == 'T') {
        if (strcmp(day, "mon") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][0] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][0] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][0] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][0] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "tue") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][1] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][1] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][1] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][1] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "wed") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][2] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][2] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][2] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][2] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "thu") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][3] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][3] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][3] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][3] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "fri") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][4] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][4] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][4] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][4] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "sat") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][5] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][5] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][5] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][5] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "sun") == 0) {
            if (time == 7) {
                if (tatooine_table_data[0][6] == '-') {
                    table_booked = 1;
                    tatooine_table_data[0][6] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (tatooine_table_data[1][6] == '-') {
                    table_booked = 1;
                    tatooine_table_data[1][6] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
    }

    if (table_choice == 'N') {
        if (strcmp(day, "mon") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][0] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][0] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][0] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][0] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "tue") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][1] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][1] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][1] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][1] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "wed") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][2] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][2] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][2] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][2] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "thu") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][3] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][3] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][3] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][3] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "fri") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][4] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][4] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][4] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][4] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "sat") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][5] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][5] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][5] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][5] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
        if (strcmp(day, "sun") == 0) {
            if (time == 7) {
                if (naboo_table_data[0][6] == '-') {
                    table_booked = 1;
                    naboo_table_data[0][6] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
            else if (time == 9) {
                if (naboo_table_data[1][6] == '-') {
                    table_booked = 1;
                    naboo_table_data[1][6] = 'x';
                }
                else {
                    table_booked = 0;
                }
            }
        }
    }



    if (table_booked == 1) {
        return table_booked;
    }
    else {
        return 0;
    }
}

void display_table_free(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7], char table_choice) {
    int i,j;
    char days[7][10] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    if (table_choice == 'E') {
        printf("Days\t");
        for (i = 0; i<7; i++) {
            printf("%s ", days[i]);
        }
        printf("\n");
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                printf("7PM \t");
            }
            else {
                printf("9PM \t");
            }
            for (j = 0; j < 7; j++) {
                printf("%c \t", endor_table_data[i][j]);
            }
            printf("\n");
        }
    }
    else if (table_choice == 'T') {
        printf("Days\t");
        for (i = 0; i<7; i++) {
            printf("%s ", days[i]);
        }
        printf("\n");
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                printf("7PM \t");
            }
            else {
                printf("9PM \t");
            }
            for (j = 0; j < 7; j++) {
                printf("%c \t", tatooine_table_data[i][j]);
            }
            printf("\n");
        }
    }
    else if (table_choice == 'N') {
        printf("Days\t");
        for (i = 0; i<7; i++) {
            printf("%s ", days[i]);
        }
        printf("\n");
        for (i = 0; i < 2; i++) {
            if (i == 0) {
                printf("7PM \t");
            }
            else {
                printf("9PM \t");
            }
            for (j = 0; j < 7; j++) {
                printf("%c \t", naboo_table_data[i][j]);
            }
            printf("\n");
        }
    }



}

void check_in() {
    int children = 0, adults = 0, length = 0, room_number = 0;
    char first_name[50], surname[50], dob[9], board_type[3];
    char newspaper;
    char booking_id[50], random_str[50];

    srand(time(NULL));
    int random_number = (rand() % 100) + 1;

    printf("Enter first name: ");
    scanf("%s", first_name);
    printf("Enter surname: ");
    scanf("%s", surname);
    printf("Enter date of birth (DDMMYYYY): ");
    scanf("%s", dob);
    printf("Enter number of children (16 or below): ");
    scanf("%d", &children);
    printf("Enter number of adults (above 16): ");
    scanf("%d", &adults);
    printf("Enter board type (FB, HB, BB): ");
    scanf("%s", board_type);
    printf("Enter length of stay (days): ");
    scanf("%d", &length);
    printf("Would you like a daily newspaper? (Y/N): ");
    scanf(" %c", &newspaper);
     printf("There are 6 rooms.\nRooms 1 & 2 = £100\nRoom 3 = £85\nRooms 4 & 5 = £75\nRoom 6 = £50\nEnter the room number:\n");
    scanf("%d", &room_number);

    sprintf(random_str, "%d", random_number);
    strcpy(booking_id, surname);
    strcat(booking_id, random_str);

    printf("Your booking ID: %s\n", booking_id);

    int check_num = 0;

    while (g_firstnames[check_num][0] != 0) {
        check_num +=1;
    }

    strcpy(g_firstnames[check_num], first_name);
    strcpy(g_surnames[check_num], surname);
    strcpy(g_dobs[check_num], dob);
    sprintf(g_children[check_num], "%d", children);
    sprintf(g_adults[check_num], "%d", adults);
    strcpy(g_board_type[check_num], board_type);
    sprintf(g_length_of_stay[check_num], "%d", length);
    sprintf(g_newspaper[check_num], "%c", newspaper);
    sprintf(g_room_number[check_num], "%d", room_number);
    strcpy(g_booking_id[check_num], booking_id);
}
