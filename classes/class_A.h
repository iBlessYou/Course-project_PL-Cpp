#pragma once
#include "../structs.h"

class classPharmacy_A {
    protected: 
        structPharmacy *data;
        int size;

    public:
        // Специальные методы класса
        classPharmacy_A();
        classPharmacy_A(classPharmacy_A &objectPharmacy);
        ~classPharmacy_A();
        classPharmacy_A& operator = (classPharmacy_A &objectPharmacy); 

        //   Методы класса   
        void inputFile();
        void outputData();
        void outputFile();
        void addPharmacy();
        void deletePharmacy();
        void sortNumber();
        void sortName();
        void sortDate();
        void exitProgram();

        // Дружественные функции класса
        friend ostream& operator << (ostream &out, classPharmacy_A &objectPharmacy);  
};

