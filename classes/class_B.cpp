#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "class_B.h"
#include "../functions.h"

// Конструктор копирования для класса classPharmacy_B
classPharmacy_B::classPharmacy_B(classPharmacy_B &objectPharmacy):classPharmacy_A(objectPharmacy) {
    size_pnumber = objectPharmacy.size_pnumber;
    size_pdate = objectPharmacy.size_pdate;
    size_pname = objectPharmacy.size_pname;
    
    if (size_pnumber==0) data_pnumber=NULL;
    else {
        data_pnumber = new structPerechNumber[size_pnumber];
        if (data_pnumber == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_pnumber; i++)
            data_pnumber[i]=objectPharmacy.data_pnumber[i];
    }

    if (size_pdate==0) data_pdate=NULL;
    else {
        data_pdate = new structPerechDate[size_pdate];
        if (data_pdate == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_pdate; i++)
            data_pdate[i]=objectPharmacy.data_pdate[i];
    }

    if (size_pname==0) data_pname=NULL;
    else {
        data_pname = new structPerechName[size_pname];
        if (data_pname == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_pname; i++)
            data_pname[i]=objectPharmacy.data_pname[i];
    }
}

// Операция присваивания для класса classPharmacy_B
classPharmacy_B& classPharmacy_B::operator = (classPharmacy_B &objectPharmacy) {
    if (this == &objectPharmacy) return *this;
    classPharmacy_A::operator = (objectPharmacy);

    if (size_pnumber==0) data_pnumber=NULL;
    else {
        data_pnumber = new structPerechNumber[size_pnumber];
        if (data_pnumber == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_pnumber; i++)
            data_pnumber[i]=objectPharmacy.data_pnumber[i];
    }

    if (size_pdate==0) data_pdate=NULL;
    else {
        data_pdate = new structPerechDate[size_pdate];
        if (data_pdate == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_pdate; i++)
            data_pdate[i]=objectPharmacy.data_pdate[i];
    }

    if (size_pname==0) data_pname=NULL;
    else {
        data_pname = new structPerechName[size_pname];
        if (data_pname == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size_pname; i++)
            data_pname[i]=objectPharmacy.data_pname[i];
    }
    return *this;
}

// 10/13/16. Вывод перечня в терминал
void classPharmacy_B::outputData(string &id) {

    if (id == "number") {
        string str(46, '_');
        std::cout << str + "\n";
        std::cout << "|  № |  Номер аптеки  | Количество владельцев |" << "\n";
        std::cout << str + "\n";

        for (int i = 0; i < size_pnumber; i++) 
            std::cout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << data_pnumber[i].number << " |" << setw(22) 
            << data_pnumber[i].n << " |" << "\n";
        std::cout << str << "\n";

        getch();
    } else if (id == "date") {
        string str(48, '_');
        std::cout << str + "\n";
        std::cout << "|    |     Дата открытия    |                    |" << "\n";
        std::cout << "|  № |______________________|  Количество аптек  |" << "\n";
        std::cout << "|    | День | Месяц |  Год  |                    |" << "\n";
        std::cout << str + "\n";

        for (int i = 0; i < size_pdate; i++) 
            std::cout << "|" << setw(3) << i+1 << " |" << setw(5) 
            << data_pdate[i].date.day << " |" << setw(6) 
            << data_pdate[i].date.month << " |" << setw(5)
            << data_pdate[i].date.year << " |" << setw(20)
            << data_pdate[i].n << " |" << "\n";
        std::cout << str << "\n";

        getch();
    } else if (id == "name") {
        string str(46, '_');
        std::cout << str + "\n";
        std::cout << "|  № |   ФИО владельца   |  Количество аптек  |" << "\n";
        std::cout << str + "\n";

        for (int i = 0; i < size_pname; i++) 
            std::cout << "|" << setw(3) << i+1 << " |" << setw(18) 
            << data_pname[i].name << " |" << setw(19) 
            << data_pname[i].n << " |" << "\n";
        std::cout << str << "\n";

        getch();
    }
}

// 11/14/17. Вывод перечня в текстовый файл
void classPharmacy_B::outputFile(string &id) {
    ofstream fout;
    string file;
    
    std::cout << "\nВведите имя выходного файла: ";
    cin >> file;
    fout.open(file.c_str());

    if (fout.fail()) {
        fout << "Файл не создается.\n";
        getch(); return;
    }

    if (id == "number") {
        string str(46, '_');
        fout << str + "\n";
        fout << "|  № |  Номер аптеки  | Количество владельцев |" << "\n";
        fout << str + "\n";

        for (int i = 0; i < size_pnumber; i++) 
            fout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << data_pnumber[i].number << " |" << setw(22) 
            << data_pnumber[i].n << " |" << "\n";
        fout << str << "\n";

    } else if (id == "date") {
        string str(48, '_');
        fout << str + "\n";
        fout << "|    |     Дата открытия    |                    |" << "\n";
        fout << "|  № |______________________|  Количество аптек  |" << "\n";
        fout << "|    | День | Месяц |  Год  |                    |" << "\n";
        fout << str + "\n";

        for (int i = 0; i < size_pdate; i++) 
            fout << "|" << setw(3) << i+1 << " |" << setw(5) 
            << data_pdate[i].date.day << " |" << setw(6) 
            << data_pdate[i].date.month << " |" << setw(5)
            << data_pdate[i].date.year << " |" << setw(20)
            << data_pdate[i].n << " |" << "\n";
        fout << str << "\n";

    } else if (id == "name") {
        string str(46, '_');
        fout << str + "\n";
        fout << "|  № |   ФИО владельца   |  Количество аптек  |" << "\n";
        fout << str + "\n";

        for (int i = 0; i < size_pname; i++) 
            fout << "|" << setw(3) << i+1 << " |" << setw(18) 
            << data_pname[i].name << " |" << setw(19) 
            << data_pname[i].n << " |" << "\n";
        fout << str << "\n";
    }
    fout.close();
    std::cout << "Перечень сохранен в файле.\n";
    getch();
}

// 10/13/16. Перегруженная операция вывода перечня в терминал для класса classPharmacy_B
string& operator << (string &id, classPharmacy_B &objectPharmacy) {
    
    if (id == "number") {
        string str(46, '_');
        std::cout << str + "\n";
        std::cout << "|  № |  Номер аптеки  | Количество владельцев |" << "\n";
        std::cout << str + "\n";

        for (int i = 0; i < objectPharmacy.size_pnumber; i++) 
            std::cout << "|" << setw(3) << i+1 << " |" << setw(15) 
            << objectPharmacy.data_pnumber[i].number << " |" << setw(22) 
            << objectPharmacy.data_pnumber[i].n << " |" << "\n";
        std::cout << str << "\n";

        getch();
    } else if (id == "date") {
        string str(48, '_');
        std::cout << str + "\n";
        std::cout << "|    |     Дата открытия    |                    |" << "\n";
        std::cout << "|  № |______________________|  Количество аптек  |" << "\n";
        std::cout << "|    | День | Месяц |  Год  |                    |" << "\n";
        std::cout << str + "\n";

        for (int i = 0; i < objectPharmacy.size_pdate; i++) 
            std::cout << "|" << setw(3) << i+1 << " |" << setw(5) 
            << objectPharmacy.data_pdate[i].date.day << " |" << setw(6) 
            << objectPharmacy.data_pdate[i].date.month << " |" << setw(5)
            << objectPharmacy.data_pdate[i].date.year << " |" << setw(20)
            << objectPharmacy.data_pdate[i].n << " |" << "\n";
        std::cout << str << "\n";

        getch();
    } else if (id == "name") {
        string str(46, '_');
        std::cout << str + "\n";
        std::cout << "|  № |   ФИО владельца   |  Количество аптек  |" << "\n";
        std::cout << str + "\n";

        for (int i = 0; i < objectPharmacy.size_pname; i++) 
            std::cout << "|" << setw(3) << i+1 << " |" << setw(18) 
            << objectPharmacy.data_pname[i].name << " |" << setw(19) 
            << objectPharmacy.data_pname[i].n << " |" << "\n";
        std::cout << str << "\n";

        getch();
    }
    return id;
};

// Сортировка по номеру аптеки
void classPharmacy_B::sortNumber() {
    int fl, count;
    structPerechNumber pharmacy;

    count = size_pnumber;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (data_pnumber[i].number > data_pnumber[i+1].number) {
                fl = 1; pharmacy = data_pnumber[i];
                data_pnumber[i] = data_pnumber[i+1];
                data_pnumber[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
}

// Сортировка по ФИО
void classPharmacy_B::sortCount() {
    int fl, count;
    structPerechName pharmacy;

    count = size_pname;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (data_pname[i].n > data_pname[i+1].n) {
                fl = 1; pharmacy = data_pname[i];
                data_pname[i] = data_pname[i+1];
                data_pname[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
}


// Сортировка по дате открытия
void classPharmacy_B::sortDate() {
    int fl, count;
    structPerechDate pharmacy;

    count = size_pdate;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (datecomp(data_pdate[i].date, data_pdate[i+1].date) > 0) {
                fl = 1; pharmacy = data_pdate[i];
                data_pdate[i] = data_pdate[i+1];
                data_pdate[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
}

// 9/12/15. Формирование перечня
void classPharmacy_B::makePerech(string &id) {
    int flag;
    // 9. Формирование перечня номеров аптек
    if (id == "number") {
        size_pnumber = 0;
        structPerechNumber *local_data_pnumber;
        local_data_pnumber = new structPerechNumber [size];  
        if (local_data_pnumber == NULL) {
                std::cout << "Нет памяти.\n";
                getch(); return;}

        for (int i=0; i<size; i++) {
            flag=0;
            for (int j=0; j<size_pnumber; j++) {
                if (data[i].number == local_data_pnumber[j].number) {
                    flag = 1;
                    local_data_pnumber[j].n++;
                }
            }
            if (flag==0) {
                local_data_pnumber[size_pnumber].number = data[i].number;
                local_data_pnumber[size_pnumber].n = 1;
                size_pnumber++;
            }
        }
        if (data_pnumber != NULL) delete [] data_pnumber;
        data_pnumber = new structPerechNumber [size_pnumber];
        if (data_pnumber == NULL) {
            std::cout << "Нет памяти для перечня.\n";
            getch(); size_pnumber = 0; delete [] local_data_pnumber;
            return;
        }
        for (int j=0; j<size_pnumber; j++) 
            data_pnumber[j] = local_data_pnumber[j];
        delete [] local_data_pnumber;

        sortNumber();
        std::cout << "Перечень сформирован.\n";
        getch();

    // 12. Формирование перечня дат открытия
    } else if (id == "date") {
        size_pdate = 0;
        structPerechDate *local_data_pdate;
        local_data_pdate = new structPerechDate [size];  
        if (local_data_pdate == NULL) {
                std::cout << "Нет памяти.\n";
                getch(); return;}

        for (int i=0; i<size; i++) {
            flag=0;
            for (int j=0; j<size_pdate; j++) {
                if (data[i].date.day == local_data_pdate[j].date.day &&
                    data[i].date.month == local_data_pdate[j].date.month &&
                    data[i].date.year == local_data_pdate[j].date.year) {
                    flag = 1;
                    local_data_pdate[j].n++;
                }
            }
            if (flag==0) {
                local_data_pdate[size_pdate].date = data[i].date;
                local_data_pdate[size_pdate].n = 1;
                size_pdate++;
            }
        }
        if (data_pdate != NULL) delete [] data_pdate;
        data_pdate = new structPerechDate [size_pdate];
        if (data_pdate == NULL) {
            std::cout << "Нет памяти для перечня.\n";
            getch(); size_pdate = 0; delete [] local_data_pdate;
            return;
        }
        for (int j=0; j<size_pdate; j++) 
            data_pdate[j] = local_data_pdate[j];
        delete [] local_data_pdate;

        sortDate();
        std::cout << "Перечень сформирован.\n";
        getch();

    // 15. Формирование перечня ФИО владельцев
    } else if (id == "name") {
        size_pname = 0;
        structPerechName *local_data_pname;
        local_data_pname = new structPerechName [size];  
        if (local_data_pname == NULL) {
                std::cout << "Нет памяти.\n";
                getch(); return;}

        for (int i=0; i<size; i++) {
            flag=0;
            for (int j=0; j<size_pname; j++) {
                if (data[i].name == local_data_pname[j].name) {
                    flag = 1;
                    local_data_pname[j].n++;
                }
            }
            if (flag==0) {
                local_data_pname[size_pname].name = data[i].name;
                local_data_pname[size_pname].n = 1;
                size_pname++;
            }
        }
        if (data_pname != NULL) delete [] data_pname;
        data_pname = new structPerechName [size_pname];
        if (data_pname == NULL) {
            std::cout << "Нет памяти для перечня.\n";
            getch(); size_pname = 0; delete [] local_data_pname;
            return;
        }
        for (int j=0; j<size_pname; j++) 
            data_pname[j] = local_data_pname[j];
        delete [] local_data_pname;

        sortCount();
        std::cout << "Перечень сформирован.\n";
        getch();

    }
}

