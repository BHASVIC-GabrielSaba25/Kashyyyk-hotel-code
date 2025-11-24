#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// GLOBALS //
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

int check_out(char g_booking_id[10][50], char g_dobs[10][50], char g_board_type[10][50], char g_children[10][50], char g_newspaper[10][50], char g_room_number[10][50], char g_firstnames[10][50], char g_surnames[10][50]);
int table_booking(char g_children[10][50],char g_adults[10][50],char g_board_type[10][50],char g_booking_id[10][50], int g_tables_booked[10]);
int booking_valid(char g_board_type[10][50],char g_booking_id[10][50]);
int choose_and_book_table(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]);
void display_table_free(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7], char table_choice);
int check_free_spot(char day[4], int time, char table_choice, char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]);
void check_in(char g_room_number[10][50]);
void clear_user(int ID_found, char g_firstnames[10][50], char g_surnames[10][50], char g_dobs[10][50], char g_children[10][50], char g_adults[10][50], char g_board_type[10][50], char g_length_of_stay[10][50], char g_newspaper[10][50], char g_room_number[10][50], char g_booking_id[10][50], int g_tables_booked[10]);


// MAIN //
int main(void) {
    setbuf(stdout,NULL);
    srand(time(NULL));

    int running = 1;

    // Continuous Loop
    while (running) {
        printf("\n---- MAIN MENU ----\n");
        printf("1. Check In\n");
        printf("2. Book a Table\n");
        printf("3. Check Out\n");
        printf("4. Finish/Next User\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_in(g_room_number);
                break;

            case 2:
                table_booking(g_children, g_adults, g_board_type, g_booking_id, g_tables_booked);
                break;

            case 3:
                check_out(g_booking_id, g_dobs, g_board_type, g_children, g_newspaper, g_room_number, g_firstnames, g_surnames);
                break;

            case 4:
                printf("Thanks for booking a place at our hotel!\n");
                break;

            default:
                printf("Invalid Option.\n");
        }

    }
    return 0;
}

// TABLE BOOKING //
int table_booking(char g_children[10][50],char g_adults[10][50],char g_board_type[10][50],char g_booking_id[10][50], int g_tables_booked[10]) {
    char would_you_like_to_book;
    char booking_id[100];
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
            if (strcmp(g_booking_id[id_place], booking_id) == 0) {
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

// BOOKING VALID //
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
        printf("Your Board Type is invalid!\nOnly full board and half board can book a table).\n");
    }

    return valid;
}

// CHOOSE AND BOOK TABLE //
int choose_and_book_table(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]) {
    char table_choice, day[4];
    int time, table_booked = 0;

    while (!table_booked) {
        printf("Which table would you like to book? (E = endor, T = tatooine, N = naboo)\n");
        scanf(" %c", &table_choice);

        if (table_choice == 'Q' || table_choice == 'q') {
            printf("Booking cancelled.\n");
        }

        display_table_free(endor_table_data, tatooine_table_data, naboo_table_data, table_choice);
        printf("Table %c is free at these times (represented by a '-')\n", table_choice);

        printf("What day would you like to book? (first 3 letters, lower case): ");
        scanf("%s", &day);
        printf("And at what time? (7 or 9): ");
        scanf("%d", &time);


        table_booked = check_free_spot(day, time, table_choice, endor_table_data, tatooine_table_data, naboo_table_data);
        if (!table_booked) {
            printf("That slot is unavailable or invalid. Please try again\n");
        }
    }

    return table_booked;
}

// HELPERS TO MAP DAY/TIME TO INDEXES //
int day_to_index(char day[4]) {
    if (strcmp(day, "mon") == 0) return 0;
    if (strcmp(day, "tue") == 0) return 1;
    if (strcmp(day, "wed") == 0) return 2;
    if (strcmp(day, "thu") == 0) return 3;
    if (strcmp(day, "fri") == 0) return 4;
    if (strcmp(day, "sat") == 0) return 5;
    if (strcmp(day, "sun") == 0) return 6;
    return -1;
}

int time_to_index(int time) {
    if (time == 7) return 0;
    if (time == 9) return 1;
    return -1;
}

// CHECK FUNCTION //
int check_free_spot(char day[4], int time, char table_choice, char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7]) {
    int row = time_to_index(time);
    int col = day_to_index(day);
    char (*table)[7] = NULL;

    if (row < 0 || col < 0) return 0;

    if (table_choice == 'E') table = endor_table_data;
    else if (table_choice == 'T') table = tatooine_table_data;
    else if (table_choice == 'N') table = naboo_table_data;
    else return 0;

    if (table[row][col] == '-') {
        table[row][col] = 'X';
        return 1;
    }
    else{
        return 0;
    }

}

// DISPLAYS AVAILABILITY //
void display_table_free(char endor_table_data[2][7], char tatooine_table_data[2][7], char naboo_table_data[2][7], char table_choice) {
    int i,j;
    char days[7][10] = {"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    char (*table)[7] = NULL;

    if (table_choice == 'E' || table_choice == 'e') table = endor_table_data;
    else if (table_choice == 'T' || table_choice == 't') table = tatooine_table_data;
    else if (table_choice == 'N' || table_choice == 'n') table = naboo_table_data;
    else {
        printf("Invalid table choice.\n");
        return;
    }

    printf("\nDays\t");
    for (i = 0; i < 7; i++) {
        printf("%s ", days[i]);
    }
    printf("\n");

    for (i = 0; i < 2; i++) {
        if (i == 0) printf("7PM \t");
        else printf("9PM \t");
        for (j = 0; j < 7; j++) {
            printf("%c \t", table[i][j]);
        }
        printf("\n");
    }
}

// CHECK IN //
void check_in(char g_room_number[10][50]) {
    int children = 0, adults = 0, length = 0;
    char room_number[1];
    char first_name[50], surname[50], dob[9], board_type[3];
    char newspaper;
    char booking_id[50], random_str[50];

    int random_number = (rand() % 100) + 1;

    int has_number = 0;
    do { printf("Enter first name: ");
    scanf("%s", first_name);

    for (int i = 0; first_name[i] != '\0'; i++) {
        if (isdigit((unsigned char)first_name[i])) {
            has_number = 1;  
            printf("Invalid name. Names do not contain numbers.\n");
            break;           
        }

        else {
            has_number = 0;
        }
    }

    } while (has_number == 1);

    do { printf("Enter surname: ");
    scanf("%s", surname);

    for (int i = 0; surname[i] != '\0'; i++) {
        if (isdigit((unsigned char)surname[i])) {
            has_number = 1;  
            printf("Invalid name. Names do not contain numbers.\n");
            break;           
            }
        
        else{
            has_number = 0;
    }
    }
    } while (has_number == 1);

    if (first_name[0] == '\0' || surname[0] == '\0') {
        printf("Invalid name");
    }

    int check_num = 0;

    while (g_firstnames[check_num][0] != 0) {
        check_num +=1;
    }

    strcpy(g_firstnames[check_num], first_name);
    strcpy(g_surnames[check_num], surname);

    int valid_dob = 0;
    do { printf("Enter date of birth (DDMMYYYY or DD/MM/YYYY): ");
    scanf("%s", dob);

    char cleaned_dob[9];
    int j = 0;
    for (int i = 0; dob[i] != '\0'; i++) {
        if (isdigit(dob[i])) {
            cleaned_dob[j++] = dob[i];
        }
    }
    dob[j] = '\0';

    int day, month, year;
    if (strlen(cleaned_dob) != 8) {
        printf("Invalid date format.\n");
        valid_dob = 1;
    }

    day = (cleaned_dob[0]-'0')*10 + (cleaned_dob[1]-'0');
    month = (cleaned_dob[2]-'0')*10 + (cleaned_dob[3]-'0');
    year = (cleaned_dob[4]-'0')*1000 + (cleaned_dob[5]-'0')*100 + (cleaned_dob[6]-'0')*10 + (cleaned_dob[7]-'0');

    int leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    int max_day;

    switch(month) {
        case 2: max_day = leap ? 29 : 28; break;
        case 4: case 6: case 9: case 11: max_day = 30; break;
        default: max_day = 31;
    }

    if (month < 1 || month > 12 || day < 1 || day > max_day) {
        printf("Invalid date of birth.\n");
        valid_dob = 1;
    }

    else if (year <= 1895) {
        printf("Impossible date of birth.\n");
        valid_dob = 1;
    }
    
    else if (year >= 2009) {
        printf("Under 16s cannot book rooms.\n");
        valid_dob = 1;
    }

    } while (valid_dob == 1);

    strcpy(g_dobs[check_num], dob);

    int total_people;
    do {
        printf("Enter number of adults (above 16): ");
        scanf("%d", &adults);
        printf("Enter number of children (16 or below): ");
        scanf("%d", &children);
        
        total_people = children + adults;

        if (total_people > 4) {
            printf("Maximum occupancy per room is 4 people.\n");
            printf("To book more than 4 people, you must book 2 separate rooms with separate IDs.\n");
        }
    } while (total_people > 4);

    sprintf(g_children[check_num], "%d", children);
    sprintf(g_adults[check_num], "%d", adults);


    int valid_board = 0;
    do {
    printf("Enter board type (FB, HB, BB): ");
    scanf("%s", board_type);

    if (strcmp(board_type, "FB") == 0) {
        valid_board = 1;
    }
    else if (strcmp(board_type, "HB") == 0) {
        valid_board = 1;
    }
    else if (strcmp(board_type, "BB") == 0) {
        valid_board = 1;
    }
    else {
        printf("Invalid board type. Try Again.\n");
    }

    } while (valid_board == 0);

    strcpy(g_board_type[check_num], board_type);


    do {printf("Enter length of stay (days): ");
    scanf("%d", &length);
    sprintf(g_length_of_stay[check_num], "%d", length);

    if (length == 0 || length > 30) {
        printf("Please enter a suitable length for your stay. Try again");
    }

    } while (length == 0 || length > 30);



    printf("Would you like a daily newspaper? (Y/N): ");
    scanf(" %c", &newspaper);
    sprintf(g_newspaper[check_num], "%c", newspaper);

    printf("There are 6 rooms.\nRooms 1 & 2 = £100\nRoom 3 = £85\nRooms 4 & 5 = £75\nRoom 6 = £50\nEnter the room number:\n");
    scanf(" %c", room_number);

    int found = 0;

    do { for (int i = 0; i < 10; i++) {
        if (g_room_number[i][0] == room_number[0]) {
            printf("This room is currently booked. Try again.\n");
            scanf(" %c", room_number);
            found = 1;
            break;
        }

        else {
            found = 0;
        }
    }
    } while (found == 1);

    strcpy(g_room_number[check_num], room_number);

    sprintf(random_str, "%d", random_number);
    strcpy(booking_id, surname);
    strcat(booking_id, random_str);

    printf("Your booking ID: %s\n", booking_id);
    strcpy(g_booking_id[check_num], booking_id);



}

int check_out(char g_booking_id[10][50], char g_dobs[10][50], char g_board_type[10][50], char g_children[10][50], char g_newspaper[10][50], char g_room_number[10][50], char g_firstnames[10][50], char g_surnames[10][50]) {
    float total_bill = 0;
    float total_board = 0;
    float checkout_boardprice = 0;
    int dob_checkout = 0;
    int ID_found = 0;
    int room_price = 0;
    int total_room;
    char booking_ID[100];
    int valid = 0;
    int repeat = 0;

    printf("Please enter your booking ID: ");
    scanf("%s", booking_ID);

    // Find booking
    while (valid == 0) {
    if (strcmp(g_booking_id[repeat], booking_ID) == 0) {
        ID_found = repeat;
        valid = 1;
    } 
    else {
        repeat++;
        if (repeat >= 10) {
            printf("Booking not found\n");
            return 0;
        }
    }
    }
    // --- SET ROOM PRICE 
    room_price = 0;
    int room_num = atoi(g_room_number[ID_found]);

    if (room_num == 1 || room_num == 2) room_price = 100;
    else if (room_num == 3) room_price = 85;
    else if (room_num == 4 || room_num == 5) room_price = 75;
    else if (room_num == 6) room_price = 50;

    // --- ROOM PRICE 

    int days = atoi(g_length_of_stay[ID_found]);
    int adults = atoi(g_adults[ID_found]);
    int children = atoi(g_children[ID_found]);

    total_room = room_price * days;


    // --- OVER 65 DISCOUNT (ROOM ONLY)

    dob_checkout = atoi(g_dobs[ID_found]);
    int year = dob_checkout % 10000;   // DDMMYYYY → YYYY is last 4 digits

    if (year < 1960) {
        total_room = total_room * 0.9;     // 10% discount
    }


    // --- BOARD PRICE

    if (strcmp(g_board_type[ID_found], "FB") == 0) {
        checkout_boardprice = 20;
    }
    else if (strcmp(g_board_type[ID_found], "HB") == 0) {
        checkout_boardprice = 15;
    }
    else if (strcmp(g_board_type[ID_found], "BB") == 0) {
        checkout_boardprice = 5;
    }

    // Adult meals
    float adult_total = adults * checkout_boardprice * days;

    // Child meals (50% discount)
    float child_total = children * 0.5 * checkout_boardprice * days;

    total_board = adult_total + child_total;


    // --- NEWSPAPER

    float newspaper_charge = 0;
    if (strcmp(g_newspaper[ID_found], "Y") == 0) {
        newspaper_charge = 5.5;
    }


    // --- TOTAL BILL

    total_bill = total_room + total_board + newspaper_charge;


    // --- OUTPUT 

    printf("\nThanks for checking out %s %s.\n", 
        g_firstnames[ID_found], g_surnames[ID_found]);

    printf("\nRoom charge: £%.2f", (float)total_room);
    printf("\nBoard charge: £%.2f", (float)total_board);

    if (children > 0)
        printf("\nChildren's meals have been discounted by 50%%.");

    if (year < 1960)
        printf("\nAn over-65 discount has been applied to the room charge.");

    if (strcmp(g_newspaper[ID_found], "Y") == 0)
        printf("\nNewspaper fee: £5.50");

    printf("\n\nTotal bill: £%.2f\n", total_bill);

    return 0;
}

void clear_user(int ID_found, char g_firstnames[10][50], char g_surnames[10][50], char g_dobs[10][50], char g_children[10][50], char g_adults[10][50], char g_board_type[10][50], char g_length_of_stay[10][50], char g_newspaper[10][50], char g_room_number[10][50], char g_booking_id[10][50], int g_tables_booked[10]) {
    strcpy(g_firstnames[ID_found], '\0');
    strcpy(g_surnames[ID_found], '\0');
    strcpy(g_dobs[ID_found], '\0');
    strcpy(g_children[ID_found], '\0');
    strcpy(g_adults[ID_found], '\0');
    strcpy(g_board_type[ID_found], '\0');
    strcpy(g_length_of_stay[ID_found], '\0');
    strcpy(g_newspaper[ID_found], '\0');
    strcpy(g_room_number[ID_found], '\0');
    strcpy(g_booking_id[ID_found], '\0');
    g_tables_booked[ID_found] = 0;
}
