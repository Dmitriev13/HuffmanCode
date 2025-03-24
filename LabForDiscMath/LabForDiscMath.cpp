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
    string text = "ОНА ЗАБОТЛИВО ПОГЛЯДЫВАЛА НА НЕГО В ТО ВРЕМЯ КАК ОН ПОДОШЕЛ ПОСЛУШАТЬ ТО ЧТО ГОВОРИЛОСЬ ОКОЛО МОРТЕМАРА И ОТОШЕЛ К ДРУГОМУ КРУЖКУ ГДЕ ГОВОРИЛ АББАТ ДЛЯ ПЬЕРА ВОСПИТАННОГО ЗА ГРАНИЦЕЙ ЭТОТ ВЕЧЕР АННЫ ПАВЛОВНЫ БЫЛ ПЕРВЫЙ КОТОРЫЙ ОН ВИДЕЛ В РОССИИ ОН ЗНАЛ ЧТО ТУТ СОБРАНА ВСЯ ИНТЕЛЛИГЕНЦИЯ ПЕТЕРБУРГА И У НЕГО КАК У РЕБЕНКА В ИГРУШЕЧНОЙ ЛАВКЕ РАЗБЕГАЛИСЬ ГЛАЗА ОН ВСЕ БОЯЛСЯ ПРОПУСТИТЬ УМНЫЕ РАЗГОВОРЫ КОТОРЫЕ ОН МОЖЕТ УСЛЫХАТЬ ГЛЯДЯ НА УВЕРЕННЫЕ И ИЗЯЩНЫЕ ВЫРАЖЕНИЯ ЛИЦ СОБРАННЫХ ЗДЕСЬ ОН ВСЕ ЖДАЛ ЧЕГО НИБУДЬ ОСОБЕННО УМНОГО НАКОНЕЦ ОН ПОДОШЕЛ К МОРИО РАЗГОВОР ПОКАЗАЛСЯ ЕМУ ИНТЕРЕСЕН И ОН ОСТАНОВИЛСЯ ОЖИДАЯ СЛУЧАЯ ВЫСКАЗАТЬ СВОИ МЫСЛИ КАК ЭТО ЛЮБЯТ МОЛОДЫЕ ЛЮДИ";

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