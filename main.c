#include <stdio.h>
#include <stdlib.h>
int main(void) {
    float total_bill = 0;
    float total_board = 0;
    float checkout_boardprice = 0;
    int dob_checkout = 0;


    int dob_checkout = atoi(booking_data[2]);
    if (dob_checkout % 10000 > 1960) {
        total_bill = total_bill + ((booking_data[8] * booking_data[6]) * 0.9);
    }
    else {
        total_bill = total_bill + (booking_data[8] * booking_data[6]);
    }



    if (booking_data[5] == "FB"){
        checkout_boardprice = 20;
    }
    else if (booking_data[5] == "HB") {
        checkout_boardprice = 15;
    }
    else if (booking_data[5] == "BB") {
        checkout_boardprice = 5;
    }



    if (booking_data[3] > 0) {
        total_board = booking_data[3] * (0.5 * checkout_boardprice);
    }
    total_board = total_board + (booking_data[4] * checkout_boardprice);
    total_bill = total_bill + total_board;



    if (booking_data[7] == "Y") {
        total_bill = total_bill + 5.5;
    }

    printf("\nThanks for checking out. Your booking ID is %s and your name is %s %s.\n", booking_data[9], booking_data[0], booking_data[1]);
    printf("\nYour room total was %f. Your board total was %f.\n", booking_data[8] * booking_data[6], total_board);

    if (dob_checkout % 10000 > 1960) {
        printf("Because the main user is over 65, you receive a discount on the room.\n");
    }

    if (booking_data[3] > 0) {
        printf("\nBecause members of your party are 16 or under, they receive a discount on the board meals.\n");
    }

    if (booking_data[7] == "Y") {
        printf("\nThere is also a £5.50 fee for the daily newspapers.\n");
    }
    printf("\nYour total bill is %f.\n", total_bill);

         return 0;
}

