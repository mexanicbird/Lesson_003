// Created by Алексей Куликов on 03.04.2022//
/* Lesson 002 */
#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;



/* task 001 */
class Figure {
public:
    virtual int area() = 0;
};

class Paralelogram : public Figure {
protected:
    int sides_A = 0;
    int sides_B = 0;
public:
    Paralelogram(){};
    Paralelogram(int sides_A, int sides_B) {
        this->sides_A = sides_A;
        this->sides_B = sides_B;
    };
    int area() override { return (sides_A * sides_B);}
};

class Square : public Paralelogram {
protected:
public:
    Square(){};
    Square(int sides_A) : Paralelogram(sides_A, sides_B) {
        this->sides_B = this->sides_A = sides_A ;
    };
    int area() override { return (pow(sides_A, 2));}
};



/* task 002 */
class Car {
protected:
    std::string company = "NoName";
    std::string model= "NoModel";
public:
    Car(){
        std::cout << "Car: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
    Car(std::string company,std::string model){
        this->company = company;
        this->model = model;
        std::cout << "Car: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
    void info() { std::cout << "Company = "<< company << " Model = " << model <<std::endl;}
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(){
        std::cout << "PassengerCar: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
    PassengerCar(std::string company,std::string model) : Car(company, model){
        this->company = company;
        this->model = model;
        std::cout << "PassengerCar: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
};

class Bus : virtual public Car {
public:
    Bus(){
        std::cout << "Bus: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
    Bus(std::string company,std::string model) : Car(company, model){
        this->company = company;
        this->model = model;
        std::cout << "Bus: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(){
        std::cout << "Minivan: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
    Minivan(std::string company,std::string model) : PassengerCar(company, model), Bus(company, model) {
        this->company = company;
        this->model = model;
        std::cout << "Minivan: " << "Company = "<< company << ", Model = " << model <<std::endl;
    };
};



/* task 003 */
class Fraction {
protected:
    int numerator = 1;
    int denominator = 1;
public:
    Fraction(){};
    Fraction(int numerator, int denominator){
        this->numerator = numerator;
        if (denominator > 0)
        {this->denominator = denominator;}
        else {std::cout << "can't divide by zero" <<std::endl;};
    }
    void printer() {std::cout << numerator << "/"<< denominator << std::endl;}

    Fraction operator*(Fraction const &rhs) const {
        Fraction result((numerator * rhs.numerator),
                     denominator * rhs.denominator);
        return result;}

    Fraction operator/(Fraction const &rhs) const {
        Fraction result((numerator * rhs.denominator),
                     denominator * rhs.numerator);
        return result; }

};



/* task 004 */
enum eCardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
enum eCardValue {
    ACE   = 1,
    TWO   = 2,
    THREE = 3,
    FOUR  = 4,
    FIVE  = 5,
    SIX   = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE  = 9,
    TEN   = 10,
    JACK  = 10,
    QUEEN = 10,
    KING  = 10
    };

class Card {
protected:
    eCardSuit suit;
    eCardValue value;
    bool isCoverUp = false;
public:
    Card(){};
    Card(eCardSuit _suit, eCardValue _value) : suit(_suit), value(_value) {
        isCoverUp = true;
    }
    void Flip(){
        isCoverUp =! isCoverUp;
    };

    eCardValue getValue() const {
        return value;
    }

    void info (){
        std::cout << "Card = " << suit  << " " <<  value << " " << isCoverUp << std::endl;
    }
};



int main() {
    std::cout << "Lesson 003" << std::endl;
    std::cout << "Task 1" << std::endl;
    Square s1 (3);
    Square s2;
    std::cout << "Square area s1 = " << s1.area() << " units " "\n";
    std::cout << "Square area s2 = " << s2.area() << " units " "\n";
    std::cout << "\n";

    std::cout << "Task 2" << std::endl;
    Car с1("Reno", "Captur");
    PassengerCar p1 ("BMW", "M5");
    Bus b1 ("LIAZ", "R1");
    Minivan m1("Gazel", "F1");
    std::cout << "\n";

    std::cout << "Task 3" << std::endl;
    Fraction f1(3, 4);
    Fraction f2(2, 2);
    f1.printer();
    f2.printer();
    Fraction f3 =  f1 * f2;
    f3.printer();

    std::cout << "\n";
    std::cout << "Task 4" << std::endl;
    Card k1(HEARTS, QUEEN);
    k1.info();
    k1.Flip();
    k1.info();
    return 0;
}
