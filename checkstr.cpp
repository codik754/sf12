//Файл checkstr.h
#include "checkstr.h"

//Функция реализующая метод плохой эвристики символа
void badHeuristic(const string& str, int* badchar) {
 
    //Заполняем массив -1
    for (int i = 0; i < SIZE_BAD; ++i) {
        badchar[i] = -1;
    }

    //Записываем значения
    for (int i = 0; i < str.size(); ++i) {
        badchar[static_cast<int>(str[i])] = i;
    }
}

//Функция поиска подстрок по алгоритму Бойера-Мура
int searchSubstr(const string& str, const string& substr, int K) {
    int l1 = static_cast<int>(str.size());    //длина строки
    int l2 = static_cast<int>(substr.size()); //длина подстроки

    int badchar[SIZE_BAD];//массив со значениями, найденных по методу плохой эвристики
    badHeuristic(substr, badchar);//подсчитываем значения

    int amount = 0;//количество совпадений

    //Реализуем алгоритм
    int s = 0;
    while (s <= l1 - l2) {
        int j = l2 - 1;

        while (j >= 0 && substr[j] == str[s + j]) {
            j--;
        }

        if (j < 0) {
            if (s % K == 0) {
                ++amount;//подсчитываем количество совпадений
            }
            s += (s + l2 < l1) ? l2 - badchar[str[s + l2]] : 1;
        }
        else {
            int bc = badchar[str[s + j]];
            s += std::max(1, j - bc);
        }
    }

    return amount;
}

//Функция для проверки строки кратности числу K
bool IsKPeriodic(const string& str, int K) {
    //Проверяем K
    if (K <= 0) {
        throw "Exception! K равен или меньше 0!";//Выбрасываем исключение
    }
    size_t l = str.size(); //длинна исходной строки
    //Если K больше половины строки
    if (K > (l / 2)) {
        //Значит строка уже не имеет такую кратность
        return false;
    }

    //Берем подстроку длинной от K символов
    string substr = str.substr(0, K);

    //Высчитываем количество повторений этой подстроки в строке
    int n = searchSubstr(str, substr, K);

    //Если количество повторений подстроки умноженное на длину подстроки равняется самой
    //длине строки, то строка кратна K
    if (n * K == l) {
        return true;
    }

    return false;
}