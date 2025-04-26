#pragma once
#include <string>

using namespace std;

struct structDate {
    int day, month, year;
};

struct structPharmacy {
    int number;
    structDate date;
    string name;
};

struct structPerechNumber {
    int number;
    int n;
};

struct structPerechDate {
    structDate date;
    int n;
};

struct structPerechName {
    string name;
    int n;
};



