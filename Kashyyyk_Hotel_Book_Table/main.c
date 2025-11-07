#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int table_booking(char booking_data[10][50], char table_data[2][7]);
int booking_valid(char *booking_data[10][50]);
char (*check_in())[50];

// have a main subprogram that co-ordinates every other sub-program - this returns which tables booked by who
// 2d array for each table displaying what times of the week they are free e.g Monday 7PM and Monday 9PM are diff items etc
// first function to check if booking a table is possible (checks if has valid booking ID, if are staying FB/HB, if there is a free table for the number of people they have)
// display free booking times of the tables
// second function to allow guest to book a table at a specific time
// tell user they have successfully booked the table
// update which tables are free and when

int main(void) {
    char booking_data[10][50] = {"gabriel", "ben", "george"};
    char table_data [2][7];
    // ^^ these variables have to be established globally ^^
    check_in();
    table_booking(booking_data, table_data);
    return 0;
}

int table_booking(char bt[10][50], char table_data[2][7]) {
    char would_you_like_to_book = ' ';
    int can_you_book, valid_input = 0;

    while (valid_input == 0) {
        printf("Would you like to book a table? (Y/N)\n");
        fflush(stdin);
        scanf("%c", &would_you_like_to_book);

        if (would_you_like_to_book == 'Y') {
            can_you_book = booking_valid(bt);
            valid_input = 1;
        }
        else if (would_you_like_to_book == 'N') {
            printf("returns to menu");
            valid_input = 1;
        }
        else {
            printf("invalid input please try again\n");
            valid_input = 0;
        }
    }
}

int booking_valid(char *booking_data[10][50]) {
    char booking_ID[100];
    int valid, repeat, ID_found;
    printf("Please enter your booking ID: ");
    fflush(stdin);
    scanf("%c", &booking_ID);

    while (valid == 0) {
        if (strcmp(booking_data[0][repeat], booking_ID) == 0) {
            repeat = ID_found;
            valid == 1;
        }
        else {
            repeat +=1;
            valid = 0;
            if (repeat > 49) {
                valid = 2;
            }
        }
    }
    return valid;
}

char (*check_in())[50] {
    int children = 0, adults = 0, length = 0, room_number = 0;
    char first_name[50], surname[50], dob[9], board_type[3], newspaper[2];
    char booking_id[50], random_str[50];

    srand(time(NULL));
    int random_number = (rand() % 100) + 1;


    printf("Enter first name:\n");
    scanf("%s", first_name);

    printf("Enter surname:\n");
    scanf("%s", surname);

    printf("Enter date of birth: DDMMYYYY\n");
    scanf("%s", dob);

    printf("Enter number of any children? (16 or below)\n");
    scanf("%d", &children);

    printf("Enter number of adults (above 16):\n");
    scanf("%d", &adults);

    printf("Enter board type (FB, HB, BB):\n");
    scanf("%s", board_type);

    printf("Enter length of stay (in days):\n");
    scanf("%d", &length);

    printf("Would you like a daily newspaper? (Y or N)\n");
    scanf(" %c", &newspaper);

    printf("There are 6 rooms.\nRooms 1 & 2 = £100\nRoom 3 = £85\nRooms 4 & 5 = £75\nRoom 6 = £50\nEnter the room number:\n");
    scanf("%d", &room_number);

    sprintf(random_str, "%d", random_number);
    strcpy(booking_id, surname);
    strcat(booking_id, random_str);

    printf("%s", booking_id);

    static char booking_data[10][50];

    strcpy(booking_data[0], first_name);
    strcpy(booking_data[1], surname);
    strcpy(booking_data[2], dob);
    sprintf(booking_data[3], "%d", children);
    sprintf(booking_data[4], "%d", adults);
    strcpy(booking_data[5], board_type);
    sprintf(booking_data[6], "%d", length);
    strcpy(booking_data[7], newspaper);
    sprintf(booking_data[8], "%d", room_number);
    strcpy(booking_data[9], booking_id);

    printf("First name: %s\n", booking_data[0]);
    printf("Surname: %s\n", booking_data[1]);
    printf("DOB: %s\n", booking_data[2]);
    printf("Children: %s\n", booking_data[3]);
    printf("Adults: %s\n", booking_data[4]);
    printf("Board type: %s\n", booking_data[5]);
    printf("Length: %s\n", booking_data[6]);
    printf("Newspaper: %s\n", booking_data[7]);
    printf("Room number: %s\n", booking_data[8]);
    printf("Booking ID: %s\n", booking_data[9]);

    return booking_data;
}