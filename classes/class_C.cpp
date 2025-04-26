#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

#include "../functions.h"
#include "class_C.h"

// Конструктор копирования для класса classPharmacy_C
classPharmacy_C::classPharmacy_C(classPharmacy_C &objectPharmacy):classPharmacy_B(objectPharmacy) {
    size_sdate = objectPharmacy.size_sdate;
    size_sname = objectPharmacy.size_sname;
    
    if (size_sdate==0) data_sdate=NULL;
    else {
        data_sdate = new structPharmacy[size_sdate];
        if (data_sdate == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_sdate; i++)
            data_sdate[i]=objectPharmacy.data_sdate[i];
    }

    if (size_sname==0) data_sname=NULL;
    else {
        data_sname = new structPharmacy[size_sname];
        if (data_sname == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_sname; i++)
            data_sname[i]=objectPharmacy.data_sname[i];
    }
}

// Операция присваивания для класса classPharmacy_B
classPharmacy_C& classPharmacy_C::operator = (classPharmacy_C &objectPharmacy) {
    if (this == &objectPharmacy) return *this;
    classPharmacy_B::operator = (objectPharmacy);

    if (size_sdate==0) data_sdate=NULL;
    else {
        data_sdate = new structPharmacy[size_sdate];
        if (data_sdate == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_sdate; i++)
            data_sdate[i]=objectPharmacy.data_sdate[i];
    }

    if (size_sname==0) data_sname=NULL;
    else {
        data_sname = new structPharmacy[size_sname];
        if (data_sname == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_sname; i++)
            data_sname[i]=objectPharmacy.data_sname[i];
    }
    return *this;
}

// 19/22. Вывод перечня по поиску в терминал
void classPharmacy_C::outputData(string &id) {
    string str(64, '_');
    
    cout << str + "\n";
    cout << "|    |                |     Дата открытия    |                 |" << "\n";
    cout << "|  № |  Номер аптеки  |______________________|  ФИО владельца  |" << "\n";
    cout << "|    |                | День | Месяц |  Год  |                 |" << "\n";
    cout << str + "\n";

    // 22. Вывод перечня по поиску даты открытия в терминал
    if (id == "date") {
        for (int i = 0; i < size_sdate; i++) 
            cout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << data_sdate[i].number << " |" << setw(5) 
            << data_sdate[i].date.day << " |" << setw(6) 
            << data_sdate[i].date.month << " |" << setw(6)
            << data_sdate[i].date.year << " |"  << setw(17) 
            << data_sdate[i].name << "\n";
        cout << str << "\n";

    // 19. Вывод перечня по поиску ФИО владельца в терминал
    } else if (id == "name") {
        for (int i = 0; i < size_sname; i++) 
            cout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << data_sname[i].number << " |" << setw(5) 
            << data_sname[i].date.day << " |" << setw(6) 
            << data_sname[i].date.month << " |" << setw(6)
            << data_sname[i].date.year << " |"  << setw(17) 
            << data_sname[i].name << "\n";
        cout << str << "\n";
    }
    getch();
}


// 20/23. Вывод перечня по поиску в текстовый файл
void classPharmacy_C::outputFile(string &id) {
    ofstream fout;
    string file;
    
    std::cout << "\nВведите имя выходного файла: ";
    cin >> file;
    fout.open(file.c_str());

    if (fout.fail()) {
        fout << "Файл не создается.\n";
        getch(); return;
    }

    string str(64, '_');
    
    fout << str + "\n";
    fout << "|    |                |     Дата открытия    |                 |" << "\n";
    fout << "|  № |  Номер аптеки  |______________________|  ФИО владельца  |" << "\n";
    fout << "|    |                | День | Месяц |  Год  |                 |" << "\n";
    fout << str + "\n";

    // 23. Вывод перечня по поиску даты открытия в текстовый файл
    if (id == "date") {
        for (int i = 0; i < size_sdate; i++) 
            fout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << data_sdate[i].number << " |" << setw(5) 
            << data_sdate[i].date.day << " |" << setw(6) 
            << data_sdate[i].date.month << " |" << setw(6)
            << data_sdate[i].date.year << " |"  << setw(17) 
            << data_sdate[i].name << "\n";
        fout << str << "\n";

    // 20. Вывод перечня по поиску ФИО владельца в текстовый файл
    } else if (id == "name") {
        for (int i = 0; i < size_sname; i++) 
            fout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << data_sname[i].number << " |" << setw(5) 
            << data_sname[i].date.day << " |" << setw(6) 
            << data_sname[i].date.month << " |" << setw(6)
            << data_sname[i].date.year << " |"  << setw(17) 
            << data_sname[i].name << "\n";
        fout << str << "\n";
    }
    fout.close();

    std::cout << "Перечень сохранен в файле.\n";
    getch();
}

// Оператор вывода массива в терминал для класса classPharmacy_B
string& operator << (string &id, classPharmacy_C &objectPharmacy) {
    
    string str(64, '_');
    
    cout << str + "\n";
    cout << "|    |                |     Дата открытия    |                 |" << "\n";
    cout << "|  № |  Номер аптеки  |______________________|  ФИО владельца  |" << "\n";
    cout << "|    |                | День | Месяц |  Год  |                 |" << "\n";
    cout << str + "\n";

    if (id == "date") {
        for (int i = 0; i < objectPharmacy.size_sdate; i++) 
            cout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << objectPharmacy.data_sdate[i].number << " |" << setw(5) 
            << objectPharmacy.data_sdate[i].date.day << " |" << setw(6) 
            << objectPharmacy.data_sdate[i].date.month << " |" << setw(6)
            << objectPharmacy.data_sdate[i].date.year << " |"  << setw(17) 
            << objectPharmacy.data_sdate[i].name << "\n";
        cout << str << "\n";

    } else if (id == "name") {
        for (int i = 0; i < objectPharmacy.size_sname; i++) 
            cout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << objectPharmacy.data_sname[i].number << " |" << setw(5) 
            << objectPharmacy.data_sname[i].date.day << " |" << setw(6) 
            << objectPharmacy.data_sname[i].date.month << " |" << setw(6)
            << objectPharmacy.data_sname[i].date.year << " |"  << setw(17) 
            << objectPharmacy.data_sname[i].name << "\n";
        cout << str << "\n";
    }
    getch();
    return id;
};

// Сортировка по номеру аптеки
void classPharmacy_C::sortNumber() {
    int fl, count;
    structPharmacy pharmacy;

    count = size_sname;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (data_sname[i].number > data_sname[i+1].number) {
                fl = 1; pharmacy = data_sname[i];
                data_sname[i] = data_sname[i+1];
                data_sname[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
}

// Сортировка по ФИО
void classPharmacy_C::sortName() {
    int fl, count;
    structPharmacy pharmacy;

    count = size_sdate;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (data_sdate[i].name > data_sdate[i+1].name) {
                fl = 1; pharmacy = data_sdate[i];
                data_sdate[i] = data_sdate[i+1];
                data_sdate[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
}

// 18/21. Формирование перечня по поиску
void classPharmacy_C::makeSearch(string &id) {
    // 18. Формирование перечня по поиску ФИО владельца
    if (id == "name") {
        string name, iniz;
        size_sname = 0;
        structPharmacy *local_data_sname;
        local_data_sname = new structPharmacy [size];  
        if (local_data_sname == NULL) {
                std::cout << "Нет памяти.\n";
                getch(); return;}
        cout << "Введите фамилию и инициалы для поиска: ";
        cin >> name >> iniz;
        name = name + " " + iniz;

        for(int i=0; i<size; i++) {
            if (data[i].name == name) {
                local_data_sname[size_sname]=data[i];
                size_sname++;
            }
        }

        if (data_sname != NULL) delete [] data_sname;
        data_sname = new structPharmacy [size_sname];
        if (data_sname == NULL) {
            cout << "Нет памяти для записей.\n";
            getch(); size_sname = 0; delete [] local_data_sname; return;
        }

        for (int j=0; j<size_sname; j++)
            data_sname[j]=local_data_sname[j];
        delete [] local_data_sname;

        sortNumber();
        cout << "Массив записей по поиску ФИО владельца сформирован.\n";
    }

    // 21. Формирование перечня по поиску даты открытия
    if (id == "date") {
        structDate date;
        size_sdate = 0;
        structPharmacy *local_data_sdate;
        local_data_sdate = new structPharmacy [size];  
        if (local_data_sdate == NULL) {
                std::cout << "Нет памяти.\n";
                getch(); return;}


        std::cout << "Введите дату открытия в числовом формате для поиска:\n";
        std::cout << "День: "; 
        while (true) {
            cin >> date.day;
            if (validateInput() == 0 || date.day < 1 || date.day > 31)
                std::cout << "Неверный формат дня. Введите еще раз: ";  else break;
        }

        std::cout << "Месяц: ";
        while (true) {
            cin >> date.month;
            if (validateInput() == 0 ||  date.month < 1 || date.month > 12)
                std::cout << "Неверный формат месяца. Введите еще раз: "; else break;
        }

        std::cout << "Год: ";
        while (true) {
            cin >> date.year;
            if (validateInput() == 0 || date.year < 1961 || date.year > 2025) 
                std::cout << "Неверный формат года. Введите еще раз: "; else break;
        }

        for(int i=0; i<size; i++)
            if (data[i].date.day == date.day && 
                data[i].date.month == date.month &&
                data[i].date.year == date.year) {
                local_data_sdate[size_sdate]=data[i];
                size_sdate++;
            }
        if (data_sdate != NULL) delete [] data_sdate;
        data_sdate = new structPharmacy [size_sdate];
        if (data_sdate == NULL) {
            cout << "Нет памяти для записей.\n";
            getch(); size_sdate = 0; delete [] local_data_sdate; return;
        }

        for (int j=0; j<size_sdate; j++)
            data_sdate[j]=local_data_sdate[j];
        delete [] local_data_sdate;

        sortName();
        cout << "Массив записей по поиску даты открытия сформирован.\n";
    }
    getch();
}