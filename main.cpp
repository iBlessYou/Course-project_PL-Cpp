#include <iostream>
#include <string>
#include <conio.h>

#include "structs.h"
#include "./classes/class_A.h"
#include "./classes/class_B.h"
#include "./classes/class_C.h"

using namespace std;


int main() {
    classPharmacy_C pharmacyData;
    int choice;

    while (true) {
        cout << "\n";
        cout << "1. Ввод исходного массива из файла;\n";
        cout << "2. Вывод массива в терминал;\n";
        cout << "3. Вывод массива в текстовый файл;\n";
        cout << "4. Добавление записи;\n";
        cout << "5. Удаление записи;\n";
        cout << "6. Сортировка массива по номеру аптеки;\n";
        cout << "7. Сортировка массива по ФИО владельца;\n";
        cout << "8. Сортировка массива по дате открытия;\n";
        cout << "------------------------------------------------------\n";
        cout << "9. Формирование перечня номеров аптек;\n";
        cout << "10. Вывод перечня номеров аптек в терминал;\n";
        cout << "11. Вывод перечня номеров аптек в текстовый файл;\n";
        cout << "------------------------------------------------------\n";
        cout << "12. Формирование перечня дат открытия;\n";
        cout << "13. Вывод перечня дат открытия в терминал;\n";
        cout << "14. Вывод перечня дат открытия в текстовый файл;\n";
        cout << "------------------------------------------------------\n";
        cout << "15. Формирование перечня ФИО владельцев;\n";
        cout << "16. Вывод перечня ФИО владельцев в терминал;\n";
        cout << "17. Вывод перечня ФИО владельцев в текстовый файл;\n";
        cout << "------------------------------------------------------\n";
        cout << "18. Формирование перечня по поиску ФИО владельца;\n";
        cout << "19. Вывод перечня по поиску ФИО владельца в терминал;\n";
        cout << "20. Вывод перечня по поиску ФИО владельца в текстовый файл;\n";
        cout << "------------------------------------------------------\n"; 
        cout << "21. Формирование перечня по поиску даты открытия;\n";
        cout << "22. Вывод перечня по поиску даты открытия в терминал;\n";
        cout << "23. Вывод перечня по поиску даты открытия в текстовый файл;\n";        
        cout << "------------------------------------------------------\n";
        cout << "24. Выход из программы;\n";
        cout << "Ваш выбор (1-24): ";
        cin >> choice;

        if (cin.fail()) {
            string s;
            cin.clear();
            cin >> s;
            cout << "Это не пункт меню.\n";
            getch();
            continue;
        }

        string id;
        switch (choice) {
            case 1: pharmacyData.inputFile(); break;
            case 2: cout << (classPharmacy_A&) pharmacyData; break;
            case 3: pharmacyData.classPharmacy_A::outputFile(); break;
            case 4: pharmacyData.addPharmacy(); break;
            case 5: pharmacyData.deletePharmacy(); break;
            case 6: pharmacyData.classPharmacy_A::sortNumber(); break;
            case 7: pharmacyData.classPharmacy_A::sortName(); break;
            case 8: pharmacyData.classPharmacy_A::sortDate(); break;

            case 9: pharmacyData.makePerech(id="number"); break;
            case 10: {id = "number"; id << (classPharmacy_B&)pharmacyData;} break;
            case 11: pharmacyData.classPharmacy_B::outputFile(id="number"); break;

            case 12: pharmacyData.makePerech(id="date"); break;
            case 13: {id = "date"; id << (classPharmacy_B&)pharmacyData;} break;
            case 14: pharmacyData.classPharmacy_B::outputFile(id="date"); break;
            
            case 15: pharmacyData.makePerech(id="name"); break;
            case 16: {id = "name"; id << (classPharmacy_B&)pharmacyData;} break;
            case 17: pharmacyData.classPharmacy_B::outputFile(id="name"); break; 

            case 18: pharmacyData.makeSearch(id="name"); break;
            case 19: {id = "name"; id << pharmacyData;} break;
            case 20: pharmacyData.classPharmacy_C::outputFile(id="name"); break; 

            case 21: pharmacyData.makeSearch(id="date"); break;
            case 22: {id = "date"; id << pharmacyData;} break;
            case 23: pharmacyData.classPharmacy_C::outputFile(id="date"); break; 

            case 24: pharmacyData.exitProgram(); break;
            default: cout << "Нет такого пункта в меню.\n"; getch();
        }
    }

    return 0;
}

