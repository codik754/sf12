//Файл main.cpp
#include <iostream>
#include "checkstr.h"

using std::cout;
using std::endl;
using std::string;

int main(){
    setlocale(LC_ALL, "");
    //Проверка работы исключения
    try {
        IsKPeriodic("abcabcabcabc", -1); 
    }
    catch(const char *e) {
        cout << e << endl;
    }
    catch (...) {
        cout << "UNKNOWN Exception!" << endl;
    }

    //Тестируем работу программы
    try {
        string str = "abcabcabcabc";
        cout << "Исходная строка: " << str << endl;
        for (int i = 1; i < 100; ++i) {
            if (IsKPeriodic(str, i)) {
                cout << "Строка кратна " << i << endl;
            }
        }
        /*У меня получилось
         
          Исходная строка: abcabcabcabc
          Строка кратна 3
          Строка кратна 6
        */
        
        cout << endl;
        str = "foobarfoobar";
        cout << "Исходная строка: " << str << endl;
        for (int i = 1; i < 100; ++i) {
            if (IsKPeriodic(str, i)) {
                cout << "Строка кратна " << i << endl;
            }
        }
        /*У меня получилось

         Исходная строка: foobarfoobar
         Строка кратна 6
       */

        cout << endl;
        str = "abcdabcd";
        cout << "Исходная строка: " << str << endl;
        for (int i = 1; i < 100; ++i) {
            if (IsKPeriodic(str, i)) {
                cout << "Строка кратна " << i << endl;
            }
        }
        /*У меня получилось

        Исходная строка: abcdabcd
        Строка кратна 4
        */
    }
    catch (const char* e) {
        cout << e << endl;
    }
    catch (...) {
        cout << "UNKNOWN Exception!" << endl;
    }
    return 0;
}
