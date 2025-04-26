#include <iostream>
#include "functions.h"

// Операция сравнения дат
int datecomp(structDate date_1, structDate date_2) {
    if (date_1.year > date_2.year) return 1;
    if ((date_1.year == date_2.year) && (date_1.month > date_2.month)) return 1;
    if ((date_1.year == date_2.year) && (date_1.month == date_2.month) && (date_1.day > date_2.day)) return 1; 
    return 0;
}

// Функция валидации входных данных
int validateInput() {
    if (cin.fail()) {
        string s;
        cin.clear();
        cin >> s;
        return 0;
    } else return 1;
}

