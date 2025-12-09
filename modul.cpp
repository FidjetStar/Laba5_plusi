#include "h.h"
#include <iostream>
#include <fstream>
#include <set>
#include <ctime>
#include <cctype>

using namespace std;

// ====================== Задания =======================
// unsigned char гарантирует что лежит в диапазоне от 0 до 255

void task53(string& str) {
    for (unsigned char c : str) { // char c = str[i]
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            cout << "Строка содержит английские буквы ";
        }
    }
    int count = 0;
    for (unsigned char c : str) {
        if (c == '.' || c == ',' || c == ';' || c == ':' || 
            c == '?' || c == '!') { count++;
        }
    }
    cout << "Количество знаков препинания " << count << endl;
}

void task16(string& str) {
    int p = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ') {
            str[i] = char(35);
            p = p + 1;
        }
    }
    str += char(33);
    cout << "В конец добавлен !" << endl;
    if (p > 0) {
        cout << "Пробелы заменены на # " << endl;
    } else {
        cout << "Пробелов не было" << endl;
    }
}

void task23(string& str) {
    int gamma;
    cout << "Введите значение гаммы от 127 до 255" << endl;
    cin >> gamma;
    if (!(127 <= gamma && gamma <= 255)) {
        cout << "Неправильное значение гаммы " << endl;
        return;
    }
    cout << "Изначальная строка: \"" << str << "\"" << endl;
    string str1 = str;
    for (int i = 0; i < str.length(); i++) {
        str1[i] = str[i] ^ gamma;
    }
    cout << "Шифр: \"" << str1 << "\"" << endl;
    string check = str1;
    for (int i = 0; i < str1.length(); i++) {
        check[i] = str1[i] ^ gamma;
    }
    cout << "Проверка: \"" << check << "\"" << endl;
}

void task36(string& str) {
    set<unsigned char> chars; //Контейнер set типа char
    for (unsigned char c : str) {
        if (!ispunct(c) && c != ' ') {
            chars.insert(c);
        }
    }
    cout << "Количество уникальных элементов: " << chars.size() << endl;
    cout << "Уникальные элементы: ";
    for (unsigned char c : chars) {
        cout << "'" << c << "' ";
    }
    cout << endl;
}

void task28(string& str) {
    string up = str;
    for (char& c : up) {
        c = toupper(c);
    }
    for (char c : up) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            cout << "Не 16ричная сс" << endl;
            return;
        }
    }
    cout << "16ричная сс" << endl;
    int decimal = 0;
    for (char c : up) {
        int digit;
        if (isdigit(c)) {
            digit = c - '0';
        } 
        else {
            digit = c - 'A' + 10;
        }
        decimal = decimal * 16 + digit;
    }
    cout << "в десятичной: " << decimal << endl;
    string oct;
    int t = decimal;
    while (t > 0) {
        oct = char('0' + t % 8) + oct; //сдвигаемся от '0' в ASCII-таблице
        t /= 8;
    }
    if (oct.empty()) {
        cout << "В 8ричной сс строка равна: 0" << endl;
    } else {
        cout << "В 8ричной сс : " << oct << endl;
    }
}

void task6() {
    cout << "\n=== ГЕНЕРАТОР ПАРОЛЕЙ ===" << endl;
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string digits = "0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    int level;
    cout << "Выберите уровень сложности:" << endl;
    cout << "1 - Простой (5 символов, только буквы)" << endl;
    cout << "2 - Средний (10 символов, буквы + цифры)" << endl;
    cout << "3 - Сложный (25 символов, буквы + цифры + символы)" << endl;
    cin >> level;
    int length;
    string charPool;
    string description;
    switch (level) {
        case 1:
            length = 5;
            charPool = lowercase + uppercase;
            description = "Простой (5 символов, только буквы)";
            break;
        case 2:
            length = 10;
            charPool = lowercase + uppercase + digits;
            description = "Средний (10 символов, буквы + цифры)";
            break;
        case 3:
            length = 25;
            charPool = lowercase + uppercase + digits + symbols;
            description = "Сложный (25 символов, буквы + цифры + символы)";
            break;
        default:
            cout << " Выберите уровень 1-3" << endl;
            break;
    }
    string password;
    for (int i = 0; i < length; i++) {
        password += charPool[rand() % charPool.length()];
    }
    cout << "\n--- ПАРОЛЬ СГЕНЕРИРОВАН ---" << endl;
    cout << "Уровень: " << level << endl;
    cout << "Пароль: " << password << endl;
}

void task3() {
    ifstream in("FN1.txt");
    ofstream out("FN2.txt");
    string s; 
    while (getline(in, s)) {
        if (s.empty()) {
            out << s << " // ошибка" << endl;
            continue;
        }
        bool ok = true;
        int p = 0, e = 0; // е для подсчета =
        for (char c : s) {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
                (c >= '?' && c <= '?') || (c >= '?' && c <= '?')) {
                ok = false;
                break;
            }
            if (c == '+' || c == '-') p++;
            if (c == '=') e++;
        }
        if (!ok || p != 1 || e != 1 || s.back() != '=') {
            out << s << " // ошибка" << endl;
            continue;
        }
        int sum = 0, n = 0;
        char z = '+';
        bool f = true; 
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0'); 
            }
            else if (c == '+' || c == '-' || c == '=') {
                if (f) {
                    sum = n;
                    f = false;
                } 
                else {
                    if (z == '+') sum += n;
                    else sum -= n;
                }
                n = 0;
                if (c != '=') z = c;
            }
        }
        out << s << sum << endl;
    }
    cout << "Ответы записаны в FN2.txt!" << endl;
}
// ====================== Вводы строки =======================

void fillFromKeyboard(string& str) {
    clearString(str);
    cout << "Введите с клавиатуры: ";
    cin.ignore();
    getline(cin, str);
}

bool fillFromFile(string& str, const string& filename) {
    clearString(str);
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Файл не открылся!" << endl;
        return false;
    }
    string line;
    while (getline(file, line)) {
        str += line;
    }

    cout << "Строка загружена из файла!" << endl;
    return true;
}

void fillRandom53(string& str, int length) {
    clearString(str);
    srand(time(0));
    string symbols;
    for (int i = 224; i <= 255; i++) {
        symbols += char(i);
    }
    for (int i = 192; i <= 223; i++) {
        symbols += char(i); 
    }
    symbols += "!@#$%^&*()_+-=[]{}|;:,.<>?~` ";
    for (int i = 0; i < length; i++) {
        str += symbols[rand() % symbols.size()];
    }
}

void fillRandom16(string& str, int length) {
    clearString(str);
    srand(time(0));
    string symbols;
    for (int i = 250; i <= 255; i++) { 
        symbols += char(i);
    }
    symbols += " ";
    for (int i = 0; i < length; i++) {
        str += symbols[rand() % symbols.size()];
    }
}

void fillRandom28(string& str, int length) {
    clearString(str);
    srand(time(0));
    string hex = "0123456789ABCDEFabcdef";
    for (int i = 0; i < length; i++) {
        str += hex[rand() % hex.size()];
    }
}

void fillRandomAll(string& str, int length) {
    clearString(str);
    srand(time(0));
    string set;
    for (int i = 224; i <= 255; i++) {
        set += char(i);
    }
    for (int i = 192; i <= 223; i++) {
        set += char(i);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        set += c;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        set += c;
    }
    for (char c = '0'; c <= '9'; c++) {
        set += c;
    }
    set += "!@#$%^&*()_+-=[]{}|;:,.<>?~` ";
    for (int i = 0; i < length; i++) {
        str += set[rand() % set.size()];
    }
}

void printString(const string& str) {
    if (str.empty()) {
        cout << "Строка пустая!" << endl;
    } 
    else {
        cout << "Строка: " << str << endl;
    }
}

void clearString(string& str) {
    str.clear();
    cout << "Строка очищена!" << endl;
}


