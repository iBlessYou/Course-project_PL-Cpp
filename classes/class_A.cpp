#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "class_A.h"
#include "../functions.h"

classPharmacy_A::classPharmacy_A(): data(NULL), size(0) {};

classPharmacy_A::~classPharmacy_A() {if (data!=NULL) delete [] data;}

// Конструктор копирования для класса classPharmacy_A
classPharmacy_A::classPharmacy_A(classPharmacy_A &objectPharmacy) {
    size = objectPharmacy.size;
    if (size==0) data=NULL;
    else {
        data = new structPharmacy[size];
        if (data == NULL) {
            std::cout << "нет памяти.\n";
            std::cout << "Конструктор копирования.\n";
            getch(); exit(1);
        }
        for (int i=0; i<size; i++)
            data[i]=objectPharmacy.data[i];
    }
}

// Операция присваивания для класса classPharmacy_A
classPharmacy_A& classPharmacy_A::operator = (classPharmacy_A &objectPharmacy) {
    if (this == &objectPharmacy) return *this;
    if (data != NULL) delete [] data;
    size = objectPharmacy.size;
    if (objectPharmacy.data == NULL) data = NULL;
    else {
        data = new structPharmacy [size];
        if (data == NULL) {
            std::cout << "Нет памяти для копирования.\n";
            getch(); return objectPharmacy;
        }
        for (int i = 0; i < size; i ++)
            data[i]=objectPharmacy.data[i];
    }
    return *this;
}

// Операция вывода массива в терминал
ostream& operator << (ostream &out, classPharmacy_A &objectPharmacy) {
    string str(64, '_');
    
    out << str + "\n";
    out << "|    |                |     Дата открытия    |                 |" << "\n";
    out << "|  № |  Номер аптеки  |______________________|  ФИО владельца  |" << "\n";
    out << "|    |                | День | Месяц |  Год  |                 |" << "\n";
    out << str + "\n";

    for (int i = 0; i < objectPharmacy.size; i++) 
        out << "|" << setw(3) << i+1 << " |" << setw(15) 
        << objectPharmacy.data[i].number << " |" << setw(5) 
        << objectPharmacy.data[i].date.day << " |" << setw(6) 
        << objectPharmacy.data[i].date.month << " |" << setw(6)
        << objectPharmacy.data[i].date.year << " |"  << setw(17) 
        << objectPharmacy.data[i].name << "\n";
    out << str << "\n";

    getch();
    return out;
}

// 1. Ввод массива из файла
void classPharmacy_A::inputFile() {
    ifstream fin;
    string file;
    string iniz;
    structPharmacy pharmacy;
    std::cout << "\nИмя входного файла: ";
    cin >> file;
    fin.open(file.c_str());

    if (fin.fail()) {
        std::cout << "Файл не открывается.\n";
        getch(); return;
    }
    size=0;
    if (data!=NULL) {
        delete []data;
        data=NULL;
    }

    while (true) {
        fin >> pharmacy.number >> pharmacy.date.day
        >> pharmacy.date.month >> pharmacy.date.year 
        >> pharmacy.name >> iniz;
        if (fin.fail()) break;
        size++;
    }

    fin.close();
    fin.open(file.c_str());

    data=new structPharmacy[size];
    if (data==NULL) {
        std::cout << "Нет памяти.\n";
        fin.close();
        std::cout << "Ввести файл не удается.\n";
        getch(); size=0; return;
    }
    for (int i = 0; i < size; i++) {
        fin >> data[i].number >> data[i].date.day >> data[i].date.month
        >> data[i].date.year >> data[i].name >> iniz;

        data[i].name = data[i].name + " " + iniz;
    }
    fin.close();
    std::cout<<"Файл введен"<<endl;
    getch();
}

// 2. Вывод массива в терминал
void classPharmacy_A::outputData() {
    
    string str(64, '_');
    
    std::cout << str + "\n";
    std::cout << "|    |                |     Дата открытия    |                 |" << "\n";
    std::cout << "|  № |  Номер аптеки  |______________________|  ФИО владельца  |" << "\n";
    std::cout << "|    |                | День | Месяц |  Год  |                 |" << "\n";
    std::cout << str + "\n";

    for (int i = 0; i < size; i++) 
        std::cout << "|" << setw(3) << i+1 << " |" << setw(15) << data[i].number << " |"
        << setw(5) << data[i].date.day << " |" << setw(6) << data[i].date.month << " |" << setw(6)
        << data[i].date.year << " |"  << setw(17) << data[i].name << "\n";
    std::cout << str << "\n";

    getch();
}

// 3. Вывод массива в текстовый файл
void classPharmacy_A::outputFile() {
    ofstream fout;
    string file;
    
    std::cout << "\nВведите имя выходного файла: ";
    cin >> file;
    fout.open(file.c_str());

    if (fout.fail()) {
        std::cout << "Файл не создается.\n";
        getch(); return;
    }

    string str(64, '_');
    
    fout << str + "\n";
    fout << "|    |                |     Дата открытия    |                 |" << "\n";
    fout << "|  № |  Номер аптеки  |______________________|  ФИО владельца  |" << "\n";
    fout << "|    |                | День | Месяц |  Год  |                 |" << "\n";
    fout << str + "\n";

    for (int i = 0; i < size; i++) 
        fout << "|" << setw(3) << i+1 << " |" << setw(15) << data[i].number << " |"
        << setw(5) << data[i].date.day << " |" << setw(6) << data[i].date.month << " |" << setw(6)
        << data[i].date.year << " |"  << setw(17) << data[i].name << "\n";
    fout << str << "\n";

    fout.close();

    std::cout << "Массив структур сохранен в файле.\n";
    getch();
}

// 4. Добавление записи
void classPharmacy_A::addPharmacy() {
    structPharmacy pharmacy, *local_data;
    string iniz;
    local_data = new structPharmacy[size+1];

    if (local_data==NULL) {
        std::cout << "Нет памяти для новой записи";
        std::cout << "Добавить не удается.\n";
        getch();
        return;
    }

    std::cout << "Введите номер аптеки: "; 
    while (true) {
        cin >> pharmacy.number;
        if (validateInput() == 0)
             std::cout << "Неверный формат номера аптеки. Введите еще раз: "; else break;
    }
    
    std::cout << "Введите дату открытия в числовом формате:\n";
    std::cout << "День: "; 
    while (true) {
        cin >> pharmacy.date.day;
        if (validateInput() == 0 || pharmacy.date.day < 1 || pharmacy.date.day > 31)
            std::cout << "Неверный формат дня. Введите еще раз: ";  else break;
    }

    std::cout << "Месяц: ";
    while (true) {
        cin >> pharmacy.date.month;
        if (validateInput() == 0 ||  pharmacy.date.month < 1 || pharmacy.date.month > 12)
            std::cout << "Неверный формат месяца. Введите еще раз: "; else break;
    }

    std::cout << "Год: ";
    while (true) {
        cin >> pharmacy.date.year;
        if (validateInput() == 0 || pharmacy.date.year < 1961 || pharmacy.date.year > 2025) 
            std::cout << "Неверный формат года. Введите еще раз: "; else break;
    }

    std::cout << "Введите фамилию и инициалы: ";
    cin >> pharmacy.name >> iniz;
    pharmacy.name = pharmacy.name + " " + iniz;

    for (int i=0; i<size; i++)
        local_data[i]=data[i];
    local_data[size]=pharmacy;
    size++;
    if (data!=NULL) delete []data;
        data=local_data;
    std::cout << "Запись добавлена.\n";
    getch();
}

// 5. Удаление записи
void classPharmacy_A::deletePharmacy() {
    int number, index;
    char letter;
    structPharmacy *local_data;
    outputData();
    std::cout << "Введите номер удаляемой строки: ";
    cin >> number;

    if (cin.fail()) {
        string s;
        cin.clear();
        cin >> s;
        std::cout << "Это не номер строки\n";
        getch();
        return;
    }

    if (number < 0 || number > size) {
        std::cout << "Ошибка: нет такой строки.\n";
        getch();
        return;
    }

    index = number - 1;
    std::cout << number << "-я строка:\n";
    std::cout << data[index].number << " " 
    << data[index].date.day << " " << data[index].date.month << " "
    << data[index].date.year << " " << data[index].name  << endl;

    std::cout << "Удалить?[Y/n] ";
    cin >> letter;

    if (letter == 'n') {
        std::cout << "Отмена удаления строки.\n";
        getch(); return;
    } else if (letter != 'Y') {
        std::cout << "Ошибка ответа на вопрос.\n";
        getch(); return;
    } else if (size==1) {
        delete []data; data=NULL; size=0;
    } else {
        local_data = new structPharmacy[size-1];
        if (local_data==NULL) {
            std::cout << "Нет памяти.\n";
            std::cout << "Удалить не удается.\n";
            getch; return;
        }
        for (int i=0; i < number; i++) 
            local_data[i] = data[i];
        for (index; index < size-1; index++) 
            local_data[index] = data[index+1];
        delete []data;
        data = local_data;
        size--;
    }
    std::cout << "Запись удалена.\n";
    getch();
}

// 6. Сортировка по номеру аптеки
void classPharmacy_A::sortNumber() {
    int fl, count;
    structPharmacy pharmacy;
    count = size;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (data[i].number > data[i+1].number) {
                fl = 1; pharmacy = data[i];
                data[i] = data[i+1];
                data[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
    std::cout << "Массив структур упорядочен по номеру аптеки\n";
    getch();
}

// 7. Сортировка по ФИО
void classPharmacy_A::sortName() {
    int fl, count;
    structPharmacy pharmacy;
    count = size;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (data[i].name > data[i+1].name) {
                fl = 1; pharmacy = data[i];
                data[i] = data[i+1];
                data[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
    std::cout << "Массив структур упорядочен по ФИО в алфавитном порядке\n";
    getch();
}

// 8. Сортировка по дате открытия
void classPharmacy_A::sortDate() {
    int fl, count;
    structPharmacy pharmacy;
    count = size;
    do {
        fl = 0; count--;
        for (int i = 0; i < count; i++) {
            if (datecomp(data[i].date, data[i+1].date) > 0) {
                fl = 1; pharmacy = data[i];
                data[i] = data[i+1];
                data[i+1] = pharmacy;
            }
        } 
    } while (fl==1);
    std::cout << "Массив структур упорядочен по дате открытия.\n";
    getch();
}

// 24. Выход из программы
void classPharmacy_A::exitProgram() {
    char letter;

    std::cout << "Завершить работу программы?[Y/n]" << endl;
    cin >> letter;

    if (letter == 'n') {
        std::cout << "Отмена завершения.\n";
        getch(); return;
    } else if (letter != 'Y') {
        std::cout << "Ошибка ответа на вопрос.\n";
        getch(); return;
    } else {
        std::cout << "Программа завершила свою работу\n" << endl;
        exit(0);
    }
}

