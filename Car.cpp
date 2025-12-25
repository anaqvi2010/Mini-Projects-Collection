#include <iostream>

using namespace std;

    enum {Honda_speed = 137, Buggati_speed = 304 , Lamborghini_speed = 271 , Mercedes_speed = 130 , BMW_speed = 155 , Porche_speed = 182, Ferrari_speed = 220, Tesla_speed = 250};
    enum {Honda_price = 30150, Buggati_price = 330000 , Lamborghini_price = 550542 , Mercedes_price = 105550 , BMW_price = 164295 , Porche_price = 122095 , Ferrari_price = 4650000 , Tesla_price = 250000};

struct car_model {
    string car_name;
    int car_speed;
    long long car_price;
};

int main() {
    car_model new_car;

    cout << "Enter car name: ";
    cin >> new_car.car_name;

    if (new_car.car_name == "Honda"){
        new_car.car_speed = Honda_speed;
        new_car.car_price = Honda_price;
    }

    else if (new_car.car_name == "Buggati"){
        new_car.car_speed = Buggati_speed;
        new_car.car_price = Buggati_price;
    }

    else if (new_car.car_name == "Lamborghini"){
        new_car.car_speed = Lamborghini_speed;
        new_car.car_price = Lamborghini_price;
    }

    else if (new_car.car_name == "Mercedes"){
        new_car.car_speed = Mercedes_speed;
        new_car.car_price = Mercedes_price;
    }

    else if (new_car.car_name == "BMW"){
        new_car.car_speed = BMW_speed;
        new_car.car_price = BMW_price;
    }
    else if (new_car.car_name == "Porche"){
        new_car.car_speed = Porche_speed;
        new_car.car_price = Porche_price;
    }

    else if (new_car.car_name == "Ferrari"){
        new_car.car_speed = Ferrari_speed;
        new_car.car_price = Ferrari_price;
    }
    else if (new_car.car_name == "Tesla"){
        new_car.car_speed = Tesla_speed;
        new_car.car_price = Tesla_price;
    }
    
    else{
        cout << "Invalid Car";
        return 0;
    }

    cout << endl;
    cout << "Car Name: " << new_car.car_name << endl;
    cout << "Car Speed: " << new_car.car_speed << " mph" << endl;
    cout << "Car Price: " << "$" << new_car.car_price << endl;



    return 0;
}