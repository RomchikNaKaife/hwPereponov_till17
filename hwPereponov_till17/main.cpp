//
//  main.cpp
//  hwPereponov_till17
//
//  Created by Роман Перепонов on 15.12.2023.
//

#include <iostream>
#include <string>
using namespace std;

class Company {
public:
    string companyName;
    int companyPeopleNumber;
    bool isIPO;
    int stocksPrice;

    Company() : companyName("Default Company"), companyPeopleNumber(1), isIPO(false), stocksPrice(0) {}

    Company(string name, int number, bool ipo, int dollars) : companyName(name), companyPeopleNumber(5), isIPO(ipo), stocksPrice(dollars) {}

    void printCompanyInfo() {
        cout << "Company: " << companyName << ", People: " << companyPeopleNumber << ", Did IPO: " << (isIPO ? "Yes" : "No") << ", Stocks $: " << stocksPrice << endl;
    }
};

class Employee {
public:
    string employeeName;
    int employeeAge;
    bool truckLicense;
    int drivingExperience;

    Employee() : employeeName("Default Employee"), employeeAge(0), truckLicense(false), drivingExperience(0) {}

    Employee(string name, int age, bool have, int years) : employeeName(name), employeeAge(age), truckLicense(have), drivingExperience(years) {}

    void printEmployeeInfo() {
        cout << "Employee: " << employeeName << ", Age: " << employeeAge << ", Drives trucks: " << (truckLicense ? "Yes" : "No") << ", Years of driving: " << drivingExperience << endl;
    }
};

class Vehicle {
public:
    string vehicleType;
    int vehicleYear;
    bool hadAccident;

    Vehicle() : vehicleType("Default Vehicle"), vehicleYear(0), hadAccident(true) {}

    Vehicle(string type, int year, bool accident) : vehicleType(type), vehicleYear(year), hadAccident(accident) {}

    void printVehicleInfo() {
        cout << "Vehicle Type: " << vehicleType << ", Year: " << vehicleYear << ", Had accidents: " << (hadAccident ? "Yes" : "No")  << endl;
    }
};

class Truck : public Vehicle {
public:
    float cargoCapacity;
    int axlesNumber;

    Truck() : cargoCapacity(0.0), axlesNumber(2) {}

    Truck(float capacity, int axles, string type, int year, bool accident) : cargoCapacity(capacity), axlesNumber(axles), Vehicle(type, year, accident) {}

    Truck(float capacity, int axles, Vehicle& vehicle) : cargoCapacity(capacity), axlesNumber(axles), Vehicle(vehicle) {}

    void printTruckInfo() {
        cout << "Capacity: " << cargoCapacity << " tons, Axles: " << axlesNumber << endl;
    }
};

class Car : public Vehicle {
public:
    int numberOfSeats;
    string fuelType;

    Car() : numberOfSeats(5), fuelType("Petrol") {}

    Car(int seats, string fuel, string type, int year, bool accident) : numberOfSeats(seats), fuelType(fuel), Vehicle(type, year, accident) {}


    Car(int seats, string fuel, Vehicle& vehicle) : numberOfSeats(seats), fuelType(fuel), Vehicle(vehicle) {}

    void printCarInfo() {
        cout << "Seats: " << numberOfSeats << ", Fuel: " << fuelType << endl;
    }
};

int main() {
    Company c1("FedEX", 1000, true, 500);
    c1.printCompanyInfo();

    Employee e1("Edward", 34, false, 13);
    e1.printEmployeeInfo();

    Truck t1(11.3, 3, "Truck", 2007, false);
    Car car1(7, "Petrol", "Sedan", 2021, true);

    if (e1.truckLicense){
        t1.printVehicleInfo();
        t1.printTruckInfo();
    }
    else {
        car1.printVehicleInfo();
        car1.printCarInfo();
    }
    


    return 0;
}
