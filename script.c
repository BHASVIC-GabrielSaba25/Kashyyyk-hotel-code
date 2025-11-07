#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int table_booking(char booking_data[10][50], char table_data[2][7]);
int booking_valid(char booking_data[10][50]);
char (*check_in())[50];

int main(void) {
    printf("Hello, World!\n");
    char booking_data[10][50] = {"gabriel", "ben", "george"};
    char table_data[2][7];
    
    check_in();
    table_booking(booking_data, table_data);
    return 0;
}

int table_booking(char bt[10][50], char table_data[2][7]) {
    char would_you_like_to_book;
    int can_you_book, valid_input = 0;

    while (valid_input == 0) {
        printf("Would you like to book a table? (Y/N)\n");
        scanf(" %c", &would_you_like_to_book);

        if (would_you_like_to_book == 'Y' || would_you_like_to_book == 'y') {
            can_you_book = booking_valid(bt);
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

    return 0;
}

int booking_valid(char booking_data[10][50]) {
    char booking_ID[100];
    int valid = 0, repeat = 0, ID_found = -1;

    printf("Please enter your booking ID: ");
    scanf("%s", booking_ID);

    while (valid == 0) {
        if (strcmp(booking_data[repeat], booking_ID) == 0) {
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
        printf("Booking found at index %d!\n", ID_found);
    else
        printf("Booking not found.\n");

    return valid;
}

char (*check_in())[50] {
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
    printf("Enter room number (1–6): ");
    scanf("%d", &room_number);

    sprintf(random_str, "%d", random_number);
    strcpy(booking_id, surname);
    strcat(booking_id, random_str);

    printf("Your booking ID: %s\n", booking_id);

    static char booking_data[10][50];

    strcpy(booking_data[0], first_name);
    strcpy(booking_data[1], surname);
    strcpy(booking_data[2], dob);
    sprintf(booking_data[3], "%d", children);
    sprintf(booking_data[4], "%d", adults);
    strcpy(booking_data[5], board_type);
    sprintf(booking_data[6], "%d", length);
    sprintf(booking_data[7], "%c", newspaper);
    sprintf(booking_data[8], "%d", room_number);
    strcpy(booking_data[9], booking_id);

    return booking_data;
}
