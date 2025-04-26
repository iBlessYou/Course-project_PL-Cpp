#pragma once
#include "class_A.h"

class classPharmacy_B :public classPharmacy_A {
    protected:
        structPerechNumber *data_pnumber;
        structPerechDate *data_pdate;
        structPerechName *data_pname;
        int size_pnumber, size_pdate, size_pname;
    
    public:
        classPharmacy_B() {
            data_pnumber = NULL; size_pnumber = 0;
            data_pdate = NULL; size_pdate = 0;
            data_pname = NULL; size_pname = 0;
        };
        classPharmacy_B(classPharmacy_B &objectPharmacy);
        ~classPharmacy_B() {
            if (data_pnumber!=NULL) delete [] data_pnumber;
            if (data_pdate!=NULL) delete [] data_pdate;
            if (data_pname!=NULL) delete [] data_pname;
        }
        classPharmacy_B& operator = (classPharmacy_B &objectPharmacy); 

        //   Методы класса  
        void outputData(string &id); 
        void outputFile(string &id);
        void sortNumber();
        void sortCount();
        void sortDate();
        void makePerech(string &id);

        // Дружественные функции класса

        friend string& operator << (string &id, classPharmacy_B &objectPharmacy);  
};

