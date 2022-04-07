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
    friend Fraction operator*(const Fraction &d1, const Fraction &d2);
};

Fraction operator*(const Fraction &d1, const Fraction &d2) {
    return Fraction(d1.numerator * d2.numerator,d1.denominator * d2.denominator);
}

/* task 004 */
class Card {
protected:
    enum suit {hearts = 1, Spades, Clubs, Diamonds};
    enum value {ace = 1, two , three, four, five, six, seven, eight, nine, ten, jack, queen, king, joker};
    bool position = false;
public:
    Card(){};
    Card(enum suit,enum value){
        // я не разобрался как работать с этим типом данных, посмотрю на разборе
    };
    void Flip(){
        position =! position;
    };

    int GetValue() {return value();
    }

    void info (){
        std::cout << "Card = " << suit()  << " " <<  value() << " " << position << std::endl;
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

    //Fraction f3 = Fraction f1 * Fraction f2;
    //f3.printer();

    // с перегрузкой я не совсем разобрался, сомтрел по методичке
    // но видимо что-то упустил - посмотрю на разборе и потом поправлю

    std::cout << "\n";
    std::cout << "Task 4" << std::endl;
    Card k1;
    k1.info();
    k1.Flip();
    k1.info();

    return 0;
}
