//Файл checkstr.h
#pragma once
#include <iostream>
#include <string>

using std::string;

constexpr int SIZE_BAD = 256;

//Функция реализующая метод плохой эвристики символа
void badHeuristic(const string& str, int* badchar);

//Функция поиска подстрок по алгоритму Бойера-Мура
int searchSubstr(const string& str, const string& substr, int K);

//Функция для проверки строки кратности числу K
bool IsKPeriodic(const string& str, int K);