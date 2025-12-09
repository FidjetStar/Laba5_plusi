#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include "h.h"
#ifdef _WIN64
#include <windows.h>
#endif
using namespace std;

int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    string myString;
    int choice, taskChoice;
    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1. Выбрать задание (1-7)" << endl;
        cout << "2. Выбрать способ заполнения строки" << endl;
        cout << "3. Вывести строку" << endl;
        cout << "4. Очистить строку" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "\nВыберите задание (1-7): ";
                cin >> taskChoice;
                switch (taskChoice) {
                    case 1: task53(myString); break;
                    case 2: task16(myString); break;
                    case 3: task23(myString); break;
                    case 4: task36(myString); break;
                    case 5: task28(myString); break;
                    case 6: {
                        task6(); 
                        break;
                    }
                    case 7: task3(); break;
                    default: cout << "Неверный номер задания!" << endl;
                }
                break;
            }
            case 2: {
                cout << "\n=== СПОСОБЫ ЗАПОЛНЕНИЯ ===" << endl;
                cout << "1. С клавиатуры" << endl;
                cout << "2. Из файла" << endl;
                cout << "3. Рандом: для задания 53" << endl;
                cout << "4. Рандом: для задания 16" << endl;
                cout << "5. Рандом: для задания 28" << endl;
                cout << "6. Рандом: все символы" << endl;
                cout << "Выбор: ";
                cin >> taskChoice;
                int length;
                string filename;
                switch (taskChoice) {
                    case 1:
                        fillFromKeyboard(myString);
                        break;

                    case 2:
                        cout << "Введите имя файла: ";
                        cin >> filename;
                        fillFromFile(myString, filename);
                        break;

                    case 3:
                        cout << "Введите длину строки: ";
                        cin >> length;
                        fillRandom53(myString, length);
                        break;

                    case 4:
                        cout << "Введите длину строки: ";
                        cin >> length;
                        fillRandom16(myString, length);
                        break;

                    case 5:
                        cout << "Введите длину строки: ";
                        cin >> length;
                        fillRandom28(myString, length);
                        break;

                    case 6:
                        cout << "Введите длину строки: ";
                        cin >> length;
                        fillRandomAll(myString, length);
                        break;

                    default:
                        cout << "Неверный выбор!" << endl;
                }
                break;
            }
            case 3:
                printString(myString);
                break;

            case 4:
                clearString(myString);
                break;
            case 0:
                cout << "Выход из программы" << endl;
                break;

            default:
                cout << "Неверный выбор!" << endl;
        }

    } while (choice != 0);
    return 0;
}
