#pragma once
#include "class_B.h"

class classPharmacy_C :public classPharmacy_B {
    protected:
        structPharmacy *data_sname;
        structPharmacy *data_sdate;
        int size_sname, size_sdate;
    
    public:
        classPharmacy_C() {
            data_sdate = NULL; size_sdate = 0;
            data_sname = NULL; size_sname = 0;
        };
        classPharmacy_C(classPharmacy_C &objectPharmacy);
        ~classPharmacy_C() {
            if (data_sdate!=NULL) delete [] data_sdate;
            if (data_sname!=NULL) delete [] data_sname;
        }
        classPharmacy_C& operator = (classPharmacy_C &objectPharmacy); 

        //   Методы класса  
        void outputData(string &id); 
        void outputFile(string &id);
        void sortNumber();
        void sortName();
        void makeSearch(string &id);

        // Дружественные функции класса
        friend string& operator << (string &id, classPharmacy_C &objectPharmacy);  
};

