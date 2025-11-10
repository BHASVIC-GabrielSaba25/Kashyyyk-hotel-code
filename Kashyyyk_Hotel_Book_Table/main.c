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
int endor_table_data[2][7] = {
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0
};
int tatooine_table_data[2][7] = {
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0
};
int naboo_table_data[2][7] = {
    0,0,0,0,0,0,0,
    0,0,0,0,0,0,0
};

int table_booking(char g_firstnames[10][50],char g_surnames[10][50],char g_dobs[10][50],char g_children[10][50],char g_adults[10][50],char g_board_type[10][50],char g_length_of_stay[10][50],char g_newspaper[10][50],char g_room_number[10][50],char g_booking_id[10][50]);
int booking_valid(char g_board_type[10][50],char g_booking_id[10][50]);
void check_in();

int main(void) {
    setbuf(stdout,NULL);
    printf("Hello, World!\n");


    check_in();
    table_booking(g_firstnames, g_surnames, g_dobs,g_children, g_adults, g_board_type, g_length_of_stay, g_newspaper,g_room_number, g_booking_id);
    return 0;
}

int table_booking(char g_firstnames[10][50],char g_surnames[10][50],char g_dobs[10][50],char g_children[10][50],char g_adults[10][50],char g_board_type[10][50],char g_length_of_stay[10][50],char g_newspaper[10][50],char g_room_number[10][50],char g_booking_id[10][50]) {
    char would_you_like_to_book;
    int can_you_book = 0, valid_input = 0;

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
            valid = 1;
        }
        else {
            repeat++;
            if (repeat >= 10) {
                valid = 2;
            }
        }
    }

    if (valid == 1)
        printf("You're valid for a booking!\n");
    else
        printf("ID not found.\n");

    return valid;
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
