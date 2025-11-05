#include <stdio.h>
#include <ctype.h>
#include <string.h>

int table_booking(char booking_data[10][50]);
int booking_valid(char booking_data[10][50], char table_data[2][7]);

// have a main subprogram that co-ordinates every other sub-program - this returns which tables booked by who
// 2d array for each table displaying what times of the week they are free e.g Monday 7PM and Monday 9PM are diff items etc
// first function to check if booking a table is possible (checks if has valid booking ID, if are staying FB/HB, if there is a free table for the number of people they have)
// display free booking times of the tables
// second function to allow guest to book a table at a specific time
// tell user they have successfully booked the table
// update which tables are free and when

int main(void) {
    printf("Hello, World!\n");
    return 0;
}

int table_booking(char booking_data[10][50]) {
    char would_you_like_to_book;
    char table_data[2][7];
    int can_you_book;
    printf("Would you like to book a table? (Y/N)\n");
    fflush(stdin);
    scanf("%c", &would_you_like_to_book);

    if (would_you_like_to_book == 'Y') {
        can_you_book = booking_valid(booking_data[10][50], table_data[2][7]);
    }
}