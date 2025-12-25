#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>


using namespace std;

struct car{
    string name;
    int car_number;
    int floor_number;
    int slot_number;
    string parked_side;
    bool disabled_slot;
};

struct sfloor{
    int left_number_normal;
    int right_number_normal;
    int left_number_reserved;
    int right_number_reserved;
    string left_slot[5][10];
    string right_slot[5][10];
};

int same_plate(vector<car> car_history, int num_cars, int number){
    for (int i = 0; i < num_cars+1; i++){
        if(car_history[i].car_number == number){
            cout << endl << "Car number is fake. Renter." << endl << endl;
            return true;
        }
    }
    return false;
}

string disabled_parking(vector<car> car_history, int num_cars){
    if (car_history[num_cars].disabled_slot == true){
        return ("required");
    }
    else{
        return ("not required");
    }
}

string side(vector<car> car_history, int num_cars){
    if (car_history[num_cars].parked_side == "r"){
        return ("right");
    }
    else{
        return ("left");
    }
}

void receipt(vector<car> car_history, int num_cars){
    cout << "+--------------------+" << endl;
    cout << "|   PROVER PARKING   |" << endl;
    cout << "|  Memphis Tennessee |" << endl;
    cout << "|  TEL:010-4678-9896 |" << endl;
    cout << "|                    |" << endl;
    cout << "+--------------------+" << endl;
    cout << "| Name : " << car_history[num_cars].name << string(12 - car_history[num_cars].name.length(), ' ') <<"|\n";
    cout << "| Number : " << car_history[num_cars].car_number << "      |\n";
    cout << "| Floor : " << car_history[num_cars].floor_number << string(11 - (to_string(car_history[num_cars].slot_number)).length(), ' ') << "|\n"; 
    cout << "| Slot : " << car_history[num_cars].slot_number << string(12 - (to_string(car_history[num_cars].slot_number)).length(), ' ') << "|\n"; 
    cout << "| Price : $10.00     |\n";
    cout << "+--------------------+";
}

//Variable for the index
int num_cars = 0;

int main() {

    //NEW
    ofstream myfile;
    myfile.open("PARKING DATABASE.csv", ios::app);
    if (myfile.tellp() == 0) {
        myfile << "Name" << "," << "Action" << "," <<  "Car Number" << "," << "Floor" << "," << "Direction" << "," << "Slot Number" << "," << "Ticket Number" << "," << "Disabled Parking" << "," << "Date" << "," << "Time" << endl;
    }



    cout << "****** Welcome to the We've Parking! ******" << endl;
    
    //Initializing the number of slots in each floor
    string temp[50] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50"};

    int temp2 = 0;
    sfloor floor_one;
    floor_one.left_number_normal = 40; floor_one.right_number_normal = 40; 
    floor_one.left_number_reserved = 10; floor_one.right_number_reserved = 10; 
    for(int row = 0; row < 5; row ++){
        for(int column = 0; column < 10; column ++){
            floor_one.right_slot[row][column] = temp[temp2];
            floor_one.left_slot[row][column] = temp[temp2];
            temp2 ++;
        }
    }

    temp2 = 0;
    sfloor floor_two;
    floor_two.left_number_normal = 40; floor_two.right_number_normal = 40; 
    floor_two.left_number_reserved = 10; floor_two.right_number_reserved = 10; 
    for(int row = 0; row < 5; row ++){
        for(int column = 0; column < 10; column ++){
            floor_two.right_slot[row][column] = temp[temp2];
            floor_two.left_slot[row][column] = temp[temp2];
            temp2 ++;
        }
    }

    temp2 = 0;
    sfloor floor_three;
    floor_three.left_number_normal = 40; floor_three.right_number_normal = 40; 
    floor_three.left_number_reserved = 10; floor_three.right_number_reserved = 10; 
    for(int row = 0; row < 5; row ++){
        for(int column = 0; column < 10; column ++){
            floor_three.right_slot[row][column] = temp[temp2];
            floor_three.left_slot[row][column] = temp[temp2];
            temp2 ++;
        }
    }

    temp2 = 0;
    sfloor floor_four;
    floor_four.left_number_normal = 40; floor_four.right_number_normal = 40; 
    floor_four.left_number_reserved = 10; floor_four.right_number_reserved = 10; 
    for(int row = 0; row < 5; row ++){
        for(int column = 0; column < 10; column ++){
            floor_four.right_slot[row][column] = temp[temp2];
            floor_four.left_slot[row][column] = temp[temp2];
            temp2 ++;
        }
    } 

    string action;

    //Array to store all cars
    vector<car> car_history;

    while (action != "done"){

        //Will be used for display at the start
        int floor_one_total_normal = floor_one.left_number_normal + floor_one.right_number_normal;
        int floor_two_total_normal = floor_two.left_number_normal + floor_two.right_number_normal;
        int floor_three_total_normal = floor_three.left_number_normal + floor_three.right_number_normal;
        int floor_four_total_normal = floor_four.left_number_normal + floor_four.right_number_normal;

        int floor_one_total_reserved = floor_one.left_number_reserved + floor_one.right_number_reserved;
        int floor_two_total_reserved = floor_two.left_number_reserved + floor_two.right_number_reserved;
        int floor_three_total_reserved = floor_three.left_number_reserved + floor_three.right_number_reserved;
        int floor_four_total_reserved = floor_four.left_number_reserved + floor_four.right_number_reserved;

        //looking for the option the user wants
        do{
        cout << endl << "\n1. Entry - (e)" << endl << "2. Remove - (r)" << endl <<  "3. Done - (d)" << endl << "Enter desired action:  ";
        cin >> action;
        cout << endl;
        if (action != "e" && action != "r" && action != "d"){
            cout << "Enter Valid Option";
        }
        } while(action != "e" && action != "r" && action != "d");

        //Terminating program if user is done
        if(action == "d"){
            return 0;
        }

        //Condition when car wants to park
        if (action == "e"){

            //Defining the car and adding to the array
            car user_car;
            car_history.push_back(user_car);

            //Taking name and car nuumber with restriction
            cout << "Enter your name: ";
            cin >> car_history[num_cars].name;
            cout << endl;

            int number;
            do {
                cout << "Enter car number: ";
                cin >> number;

                // Check if the car number is valid and not a duplicate
                if (number > 9999 || number < 1000) {
                    cout << "Car number must be between 1000 and 9999. Please try again.\n";
                }
            } while (number > 9999 || number < 1000 || same_plate(car_history, num_cars, number));
            car_history[num_cars].car_number = number;

            char disabled;
            do {
                cout << endl << "1. Yes - (y)" << endl << "2. No - (n)" << endl << "Do you require a reserved disabled parking? ";
                cin >> disabled;
            } while(disabled != 'y' && disabled != 'n');

            if(disabled == 'y'){
                car_history[num_cars].disabled_slot = true;
            }

            else if(disabled == 'n'){
                car_history[num_cars].disabled_slot = false;
            }

            cout << endl;
            if (car_history[num_cars].disabled_slot == false){
                for (int floor = 1; floor < 5; floor ++){
                cout << "Slots on floor " << floor << ": ";
                switch(floor){
                    case 1:
                        cout << floor_one_total_normal << endl;
                        break;
                    case 2:
                        cout << floor_two_total_normal << endl;
                        break;
                    case 3:
                        cout << floor_three_total_normal << endl;
                        break;
                    case 4:
                        cout << floor_four_total_normal << endl;
                        break;
                    }
                }
            }

            else if (car_history[num_cars].disabled_slot == true){
                for (int floor = 1; floor < 5; floor ++){
                cout << "Slots on floor " << floor << ": ";
                switch(floor){
                    case 1:
                        cout << floor_one_total_reserved << endl;
                        break;
                    case 2:
                        cout << floor_two_total_reserved << endl;
                        break;
                    case 3:
                        cout << floor_three_total_reserved << endl;
                        break;
                    case 4:
                        cout << floor_four_total_reserved << endl;
                        break;
                    }
                }
            }

            do{
                cout << endl << "1. Floor 1 - (1)" << endl << "2. Floor 2 - (2)" << endl << "3. Floor 3 - (3)" << endl << "4. Floor 4 - (4)" << endl << "What floor: ";
                cin >> car_history[num_cars].floor_number;
            } while(car_history[num_cars].floor_number > 4 || car_history[num_cars].floor_number < 1 || sizeof(car_history[num_cars].floor_number) != 4);
            
            if(car_history[num_cars].floor_number == 1){
                cout << endl;
                if (car_history[num_cars].disabled_slot == false){
                    cout << "Number of slots to the left: " << floor_one.left_number_normal << endl;
                    cout << "Number of slots to the right: " << floor_one.right_number_normal << endl << endl;
                }
                else if (car_history[num_cars].disabled_slot == true){
                    cout << "Number of slots to the left: " << floor_one.left_number_reserved << endl;
                    cout << "Number of slots to the right: " << floor_one.right_number_reserved << endl << endl;
                }

                do{
                    cout << "1. Right - (r)" << endl << "2. Left - (l)" << endl << "What side: ";
                    cin >> car_history[num_cars].parked_side;
                } while(car_history[num_cars].parked_side != "r" && car_history[num_cars].parked_side != "l");

                if(car_history[num_cars].parked_side == "r"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_one.right_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_one.right_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x") || (car_history[num_cars].disabled_slot == false && slot_num > 40) || (car_history[num_cars].disabled_slot == true && slot_num < 41));


                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_one.right_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_one.right_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_one.right_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << " your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }

                else if(car_history[num_cars].parked_side == "l"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_one.left_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_one.left_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x") || (car_history[num_cars].disabled_slot == false && slot_num > 40) || (car_history[num_cars].disabled_slot == true && slot_num < 41));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_one.left_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_one.left_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_one.left_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << ", your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }

            }
            else if(car_history[num_cars].floor_number == 2){
                cout << endl;
                cout << "Number of slots to the left: " << floor_two.left_number_normal << endl;
                cout << "Number of slots to the right: " << floor_two.right_number_normal << endl << endl;

                do{
                    cout << "1. Right - (r)" << endl << "2. Left - (l)" << endl << "What side: ";
                    cin >> car_history[num_cars].parked_side;
                } while(car_history[num_cars].parked_side != "r" && car_history[num_cars].parked_side != "l");

                if(car_history[num_cars].parked_side == "r"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_two.right_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_two.right_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x" || (car_history[num_cars].disabled_slot == false && slot_num > 40)) || (car_history[num_cars].disabled_slot == true && slot_num < 41));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_two.right_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_two.right_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_two.right_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << " your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }

                else if(car_history[num_cars].parked_side == "l"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_two.left_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_two.left_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x" || (car_history[num_cars].disabled_slot == false && slot_num > 40)) || (car_history[num_cars].disabled_slot == true && slot_num < 41));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_two.left_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_two.left_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_two.left_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << ", your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }
            }

            else if(car_history[num_cars].floor_number == 3){
                cout << endl;
                cout << "Number of slots to the left: " << floor_three.left_number_normal << endl;
                cout << "Number of slots to the right: " << floor_three.right_number_normal << endl << endl;

                do{
                    cout << "1. Right - (r)" << endl << "2. Left - (l)" << endl << "What side: ";
                    cin >> car_history[num_cars].parked_side;
                } while(car_history[num_cars].parked_side != "r" && car_history[num_cars].parked_side != "l");

                if(car_history[num_cars].parked_side == "r"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_three.right_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while((floor_three.right_slot[(slot_num-1)/10][(slot_num-1)%10]) == "x" || (car_history[num_cars].disabled_slot == true && slot_num < 41) || (car_history[num_cars].disabled_slot == false && slot_num > 40));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_three.right_slot[(slot_num-1)/10][(slot_num-1)%10] = "x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_three.right_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_three.right_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << " your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }

                else if(car_history[num_cars].parked_side == "l"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_three.left_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_three.left_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x") || (car_history[num_cars].disabled_slot == true && slot_num < 41) || (car_history[num_cars].disabled_slot == false && slot_num > 40));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_three.left_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_three.left_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_three.left_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << ", your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }
            }
            else if(car_history[num_cars].floor_number == 4){
                cout << endl;
                cout << "Number of slots to the left: " << floor_four.left_number_normal << endl;
                cout << "Number of slots to the right: " << floor_four.right_number_normal << endl << endl;

                do{
                    cout << "1. Right - (r)" << endl << "2. Left - (l)" << endl << "What side: ";
                    cin >> car_history[num_cars].parked_side;
                } while(car_history[num_cars].parked_side != "r" && car_history[num_cars].parked_side != "l");

                if(car_history[num_cars].parked_side == "r"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_four.right_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_four.right_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x")|| (car_history[num_cars].disabled_slot == true && slot_num < 41)|| (car_history[num_cars].disabled_slot == false && slot_num > 40));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_four.right_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_four.right_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_four.right_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << " your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }

                else if(car_history[num_cars].parked_side == "l"){

                    cout << endl << "Available slots (numbered 1-25): " << endl << endl;
                    for(int row = 0; row < 5; row ++){
                        for(int column = 0; column < 10; column ++){
                            cout << "|" << floor_four.left_slot[row][column] << "| ";
                        }
                        cout << endl;
                        if(row == 1 || row == 3){
                            cout << endl;
                        }
                        if(row == 3){
                            cout << endl << "Disabled:" << endl;
                        }
                    }
                    int slot_num;
                    do{
                        cout << endl << "Enter slot: ";
                        cin >> slot_num;
                    } while(((floor_four.left_slot[(slot_num-1)/10][(slot_num-1)%10]) == " x")|| (car_history[num_cars].disabled_slot == true && slot_num < 41)|| (car_history[num_cars].disabled_slot == false && slot_num > 40));
                    car_history[num_cars].slot_number = slot_num - 1;
                    floor_four.left_slot[(slot_num-1)/10][(slot_num-1)%10] = " x";
                    if(car_history[num_cars].disabled_slot == false){
                        floor_four.left_number_normal --;
                    }
                    else if(car_history[num_cars].disabled_slot == true){
                        floor_four.left_number_reserved --;
                    }
                    cout << endl << "Thanks " << car_history[num_cars].name << ", your car with the number " << car_history[num_cars].car_number << " has been parked successfully!" << " Your ticket number is " << num_cars + 1 << ".";
                    cout << endl;
                }
            }
            myfile << car_history[num_cars].name << "," << "entry" << "," << car_history[num_cars].car_number << "," << car_history[num_cars].floor_number << "," << side(car_history,num_cars) << "," << car_history[num_cars].slot_number+1 << "," << num_cars + 1 << "," << disabled_parking(car_history , num_cars) << ","<<__DATE__ << "," << __TIME__<< endl;   
            num_cars ++;
        }

        else if (action == "r"){
            int ticket_number;
            cout << "What is your ticket number? ";
            cin >> ticket_number;

            cout << endl << "Hello " << car_history[ticket_number - 1].name << "!";
            cout << " Your car with number " << car_history[ticket_number - 1].car_number << ", parked on floor number " << car_history[ticket_number - 1].floor_number << " on the " << car_history[ticket_number - 1].parked_side << ", slot number " << car_history[ticket_number - 1].slot_number + 1 << " has been removed!" << endl;

            switch(car_history[ticket_number - 1].floor_number){
                case 1:
                        if (car_history[ticket_number - 1].parked_side == "r"){
                            floor_one.right_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_one.right_number_normal ++;
                        }
                        else if (car_history[ticket_number - 1].parked_side == "l"){
                            floor_one.left_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_one.left_number_normal ++;
                        }
                        break;
                case 2:
                        if (car_history[ticket_number - 1].parked_side == "r"){
                            floor_two.right_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_two.right_number_normal ++;
                        }
                        else if (car_history[ticket_number - 1].parked_side == "l"){
                            floor_two.left_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_two.left_number_normal ++;
                        }
                        break;
                case 3:
                         if (car_history[ticket_number - 1].parked_side == "r"){
                            floor_three.right_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_three.right_number_normal ++;
                        }
                        else if (car_history[ticket_number - 1].parked_side == "l"){
                            floor_three.left_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_three.left_number_normal ++;
                        }
                        break;
                case 4:
                        if (car_history[ticket_number - 1].parked_side == "r"){
                            floor_four.right_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_four.right_number_normal ++;
                        }
                        else if (car_history[ticket_number - 1].parked_side == "l"){
                            floor_four.left_slot[(car_history[ticket_number - 1].slot_number)/10][(car_history[ticket_number - 1].slot_number)%10] = temp[(((car_history[ticket_number-1].slot_number)%10)+1)*(((car_history[ticket_number-1].slot_number)/10)+1)-1];
                            floor_four.left_number_normal ++;
                        }
                        break;
            }
            myfile << car_history[ticket_number - 1].name << "," << "exit" << "," << car_history[ticket_number - 1].car_number << "," << car_history[ticket_number - 1].floor_number << "," << side(car_history,num_cars) << "," << car_history[ticket_number - 1].slot_number+1 << "," << num_cars << "," << disabled_parking(car_history , num_cars) << ","<< __DATE__ << "," << __TIME__<< endl;   
            cout << endl << endl;
            receipt(car_history, ticket_number-1);
        }
    }
    cout << "Bye!";
    return 0;
}





b
