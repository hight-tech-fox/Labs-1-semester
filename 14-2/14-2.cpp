﻿/*Даны фиксированные границы интегрирования. Вычислить интеграл ∫_0^1▒dx/(1+x) по методу Симпсона.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
double f(double x) { //функция, определяющая сам интеграл
	return 1 / (1 + x);
}
double Sympson(double a, double b, int n) { //функция для подсчета площади интеграла
	double h = (b - a) / n; //находим шаг h
	double sum = f(a) + f(b); //сумма начально и конечного значения
	int k; //к нужно как определитель четности/нечетности индекса при f
	for (int i = 0; i <= n - 1; i++) { //цикл для подсчета остальных частей интеграла, кроме sum = f(a) + f(b)
		k = 2 + 2 * (i % 2); //проверка четности
		sum += k * f(a + i * h); //суммируем значения f(x) при всех х
	}
	sum *= h / 3; //согласно формуле, домножаем сумму на h / 3
	return sum; //возвращаем значение суммы площадей интеграла
}
int main()
{
	setlocale(LC_CTYPE, "Russian");
	double a, b; //переменные для начала и конца интеграла 
	long double eps; //переменная, определяющая допустимую погрешность
	printf("Введите значение eps =\n");
	scanf_s("%lf", &eps);
	int n;
	a = 0;
	b = 1;
	int k = 2; //начальное число разбиений интеграла на части
	int i = 0;
	double diff; //переменная для вычисления разницы между соседними измерениями значения интеграла при разных значениях к

	do {
		i++;
		diff = fabs(Sympson(a, b, k * i) - Sympson(a, b, k * (i + 1))); //рассчет модуля разности между соседними измерениями значения интеграла при разных значениях к
	} while (diff > eps); //пока разность больше допустимой погрешности цикл продолжается
	printf("K = %d\n", k * (i + 1)); //вывод К (числа разбиений)  
	printf("Значение интеграла по методу Симпсона = %f", Sympson(a, b, k * (i + 1))); //вывод значения интеграла 
	return 0;
}