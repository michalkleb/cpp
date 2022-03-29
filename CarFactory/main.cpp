#include <iostream>
#include <fstream>
#include <string>
#include "Factory.h"
#include "UsedVehicle.h"
#include "Painter.h"
#include "Exception.h"

using namespace std;


void create(Factory &car_factory, Factory &motor_factory, Factory &bicycle_factory, istream &strum);

void print_factory(Factory &car_factory, Factory &motor_factory, Factory &bicycle_factory, istream &strum);

void sell(Factory &car_factory, Factory &motor_factory, Factory &bicycle_factory, Owners &owners, Owners &b_owners, istream &strum);

void sell_vehicle(Factory & factory,Owners &owner, istream &strum);

void buy_vehicle_from_dealer(UsedVehicle &dealer, Owners &owners,istream &strum);

void sell_vehicle_to_dealer(UsedVehicle &dealer, Owners &owners,istream &strum);

void vehicle_painter(Owners &bicycle_owners, Owners &owners, Painter &painter, istream &strum);

void drive_in_factory(Factory &car_factory, Factory &motor_factory, istream &strum);

int read_int(istream &strum);
string read_string(istream &strum);

//Funkcja szablonowa sprawdzająca poprawność wprowadzanych danych
template<typename T>
void check(int index, T &t)
{
    if (index < 0 || index > t.get_size()) throw index_error("Niewlasciwy numer pojazdu!");
    if (t.is_valid(index)) throw index_error("Nie istnieje pojazd o takim numerze!");
}

//Funkcja szablonowa wyśiwtlająca zawartość komisu, fabryki i właścicieli
template<typename T>
void print(T &t, istream &strum)
{
    t.print();
    if(t.get_size()) {
        cout << "O ktorym pojezdzie wyswietlic wiecej informacji?" << endl;
        int index= read_int(strum);

        try { check(index, t); }
        catch(index_error & ex){
            std::cout << ex.message << std::endl;
            return;
        }
        t.more_info(index);
    }
}

//Funkcja szablonowa umożliwiająca jazdę pojazdem w komisie,w fabryce i przez właścicieli
template <typename T>
void drive(T t, istream &strum)
{
    t.print();
    cout << "Ktorym pojazdem odbedzie sie jazda? Proszę podac numer pojazdu." << endl;
    int index= read_int(strum);

    try { check(index, t); }
    catch(index_error & ex){
        std::cout << ex.message << std::endl;
        return;
    }

    cout << "Jak dluga bedzie jazda probna?" << endl;
    int length = read_int(strum);
    t.drive(index, length);
}


int main(int argc,char* argv[]) {
    Factory car_factory;
    Factory motor_factory;
    Factory bicycle_factory;
    UsedVehicle dealer;
    Owners owners;
    Owners bicycle_owners;
    Painter painter;


    string s ="0";
    if(argc == 2)  s = argv[1];
    ifstream strum(s);

int x=1;
    while (x) {
        cout << "\nMENU:" << endl <<"*****W FABRYCE:*****"<<endl<< "1.Stworz nowy pojazd" << endl << "2.Wyswietl asortyment fabryki"
             <<endl << "3.Sprzedaj pojazd" << endl << "4.Jazda probna" << endl
             <<endl<<"*****POZA FABRYKA:*****"<<endl<< "5.Rowery i ich lasciciele"<< endl << "6.Pojazdy i ich wlasciciele"
             <<endl<<"7.Jazda pojazdem"<<endl<<"8.Lakiernik"<<endl
             <<endl<<"*****KOMIS*****"<<endl<<"9.Sprzedaj pojazd do komisu"<< endl << "10.Kup pojazd z komisu"
             <<endl<<"11.Jazda probna w komisie"<<endl<<"12.Wyswietl asortyment komisu"<<endl<<"13.Wyjscie"
             <<endl << "Dokonaj wyboru akcji:" << endl;

        x = read_int(strum);

        switch (x) {
            case 1:create(car_factory, motor_factory, bicycle_factory,strum);break;

            case 2:print_factory(car_factory, motor_factory, bicycle_factory,strum);break;

            case 3:sell(car_factory, motor_factory, bicycle_factory, owners, bicycle_owners,strum); break;

            case 4:drive_in_factory(car_factory, motor_factory,strum);break;

            case 5:print(bicycle_owners, strum);break;

            case 6: print(owners, strum);break;

            case 7: drive(owners,strum);break;

            case 8: vehicle_painter(bicycle_owners,owners , painter, strum); break;
            case 9: sell_vehicle_to_dealer(dealer, owners,strum); break;

            case 10: buy_vehicle_from_dealer(dealer, owners,strum);break;
            case 11: drive(dealer,strum);break;
            case 12: print(dealer, strum);break;
            case 13: return 0;
            default: cout << "Niepoprawna odpowiedz" << endl;
        }

    }
    strum.close();
    return 0;
}

void create(Factory &car_factory, Factory &motor_factory, Factory &bicycle_factory, istream &strum) {

    cout << "\nJaki pojazd chcesz stworzyc?\nSamochod:\n1.Audi\n2.Volkswagen\nMotocykl:\n3.Honda\n"
            "4.Yamaha\nRower:\n5.Rower z koszykiem\n6.Rower bez koszyka\nWybierz numer od 1 do 6.\n";
    int vehicle= read_int(strum);
    if (vehicle < 1 || vehicle >6 ) {
        cout << "Niepoprawna odpowiedz" << endl;
        return;
    }

    cout << "\nJaki  kolor ma miec pojazd?\n";
    string color=read_string(strum);
    try {
        int doors = 0;
        if (vehicle < 3)
        {
            cout << "Ile drzwi ma miec samochod? Podaj wartosc z zakresu 2-5.\n";
            doors = read_int(strum);
        }

        switch (vehicle) {
            case 1:
                car_factory.create_vehicle("Audi", color, doors, 2); //x przyjmuje wartość 2 aby funkcja create_vehicle
                break;                                                         //wiedziała że dany obiekt nie będzie rowerem
            case 2:
                car_factory.create_vehicle("Volkswagen", color, doors, 2);
                break;
            case 3:
                motor_factory.create_vehicle("Honda", color, doors, 2);
                break;
            case 4:
                motor_factory.create_vehicle("Yamaha", color, doors, 2);
                break;
            case 5:
                bicycle_factory.create_vehicle("Bicycle", color, doors, 1); //x=1 ma być koszyk
                break;
            case 6:
                bicycle_factory.create_vehicle("Bicycle", color, doors, 0); //x=0 brak koszyka
                break;
        }
    }
    catch(create_error & ex)
    {
        std::cout << ex.message << std::endl;
        return;
    }
}

void print_factory(Factory &car_factory, Factory &motor_factory, Factory &bicycle_factory, istream &strum) {
    cout << "Asortyment ktorej fabryki chcesz wyswietlic?\n1.Samochodow\n2.Motocykli\n3.Rowerow\n";
    int number = read_int(strum);
    switch (number) {
        case 1: print(car_factory, strum);break;
        case 2: print(motor_factory, strum);break;
        case 3: print(bicycle_factory, strum);break;
        default: cout << "Niepoprawna odpowiedz" << endl;
    }
}

void sell(Factory &car_factory, Factory &motor_factory, Factory &bicycle_factory, Owners &owners, Owners &b_owners,istream &strum) {
    cout<< "Z ktorej fabryki chcesz sprzedac pojazd?\n1.Samochodow\n2.Motocykli\n3.Rowerow\nDokonaj wyboru podajac liczbe z zakresu 1-3";
    int number =read_int(strum);

    switch (number) {
        case 1:sell_vehicle(car_factory,owners, strum); break;
        case 2: sell_vehicle(motor_factory,owners, strum); break;
        case 3: sell_vehicle(bicycle_factory,b_owners, strum); break;
        default: cout << "Nie ma takiej fabryki!\n"; break;
    }
}

void sell_vehicle(Factory & factory,Owners &owner, istream &strum)
{
    cout << "Imie i nazwisko kupujacego:\n";
    string customer= read_string(strum);

    cout << "Pojazd z ktorej pozycji chcesz sprzedac? Podaj wartosc od 0 do 9.\n";
    int index= read_int(strum);

    try { check(index, factory); }
    catch(index_error & ex){
        std::cout << ex.message << std::endl;
        return;
    }

    factory.sell(customer, index,owner);
}


void drive_in_factory(Factory &car_factory, Factory &motor_factory, istream &strum) {
    cout<< "Jakim pojazdem chcesz dokonac jazdy probnej?\n1.Samochodem\n2.Motocyklem\n\nDokonaj wyboru podajac liczbe z zakresu 1-2\n";
    int number = read_int(strum);

    switch (number) {
        case 1:drive(car_factory, strum);break;
        case 2:drive(motor_factory, strum);break;
        default: cout << "Nie ma takiej fabryki!\n";break;
    }
}


void sell_vehicle_to_dealer(UsedVehicle &dealer, Owners &owners, istream &strum) {
    owners.print();
    cout << "Ktory pojazd chcesz sprzedac do komisu? Podaj numer pojazdu. " << endl;
    int index= read_int(strum);

    try { check(index, owners); }
    catch(index_error & ex){
        std::cout << ex.message << std::endl;
        return;
    }

    dealer.add(owners.sell(index));

}
void buy_vehicle_from_dealer(UsedVehicle &dealer, Owners &owners,istream &strum) {
    dealer.print();
    cout << "Ktory pojazd kupić z komisu? Podaj numer pojazdu: " << endl;
    int index= read_int(strum);

    try { check(index, dealer); }
    catch(index_error & ex){
        std::cout << ex.message << std::endl;
        return;
    }
    cout << "Imie i nazwisko kupujacego:\n";
    string customer= read_string(strum);

    owners.add(dealer.sell(index,customer));
}


void vehicle_painter(Owners &bicycle_owners, Owners &owners, Painter &painter,istream &strum)
{
    cout<<"Jaki pojazd chcesz pomalowac:\n 1.Rower\n2.Motocykl lub samochod\n";
    int number= read_int(strum);
    if (number <= 0 || number > 2) {
        cout << "Błędna odpowiedź!\n";
        return;
    }
    if(number == 1) bicycle_owners.print();
    else  owners.print();

    cout<<"Ktory pojazd chcesz pmalowac? Podaj numer.\n";
    int index= read_int(strum);

    try { check(index, owners); }
    catch(index_error & ex)
    {
        std::cout << ex.message << std::endl;
        return;
    }

    cout<<"Na jaki kolor chcesz pomalowac pojazd?\n";
    string color= read_string(strum);

    if(number ==1) painter.paint(bicycle_owners.get_vehicle(index),color);
    else painter.paint(owners.get_vehicle(index),color);

}


int read_int(istream & strum) {
    if(!strum)
    {
    string line;
    getline(cin, line);
    return atoi(line.c_str());
    }
    else
    {
        int index;
        strum>>index;
        cout<<index<<endl;
        return index;
    }
}

string read_string(istream &strum) {
    string line;
    if(!strum) {
        getline(cin, line);
        return line;
    }
    else
    {
        strum>>ws;getline(strum,line);
        cout<<line<<endl;
        return line;
    }
}

