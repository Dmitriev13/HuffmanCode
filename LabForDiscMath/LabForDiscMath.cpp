#include <iostream>
#include <map>
#include <string>
#include <iomanip>  
#include <sstream>  
#include "Windows.h"

using namespace std;

// Функция для удаления незначащих нулей
string RemZer(double value) {
    ostringstream oss;
    oss << setprecision(15) << value;
    string str = oss.str();

    // Удаляем незначащие нули после точки
    size_t dotPos = str.find('.');
    if (dotPos != string::npos) {
        // Удаляем нули с конца строки
        str.erase(str.find_last_not_of('0') + 1, string::npos);
    }

    return str;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text = "ВАШ ТЕКСТ";

    map<char, int> frequencyMap;
    int totalCharacters = 0;

    // Подсчет количества каждого символа и общего количества символов
    for (char ch : text) {
        frequencyMap[ch]++;
        totalCharacters++;
    }

    // Вывод частот символов с удалением незначащих нулей
    cout << "Частота каждого символа:\n";
    for (const auto& pair : frequencyMap) {
        double frequency = static_cast<double>(pair.second) / totalCharacters;
        string frequencyStr = RemZer(frequency);
        cout << "Символ: '" << pair.first << "', Частота: " << frequencyStr << endl;
    }

    return 0;
}
