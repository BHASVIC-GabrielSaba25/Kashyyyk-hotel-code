
int main(void) {
    float total_bill = 0;
    float total_board = 0;
    float checkout_boardprice = 0;
    total_bill = total_bill + (booking_data[8] * booking_data[6]);
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




         return 0;
}

