/*В данной действительной квадратной матрице порядка n найти наибольший по модулю элемент. 
Получить квадратную матрицу порядка n-1 путем выбрасывания из исходной какой-нибудь строки или столбца, 
на пересечении которых расположен элемент с найденным значением.*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	float n;
	int k = 0; //счетчик макс эл-тов
	float maxl = 0; //максимальный эл-т массива
	int str = -1;//строка макс эл-та
	int stb = -1;//столбец макс эл-та
	const int size = 10;//макс размерность массива 
	int NewSize;//введенная размерность
	float matrix[size][size];//массив исходный
	float NewMatrix[size][size];//массив новый
	printf("Введите размерность матрицы\n");
	scanf_s("%d", &NewSize);

	if (NewSize > size) {
		printf("ERROOR: Превышен лимит заполнения матрицы\n");
		return 1;
	}
	printf("Значения:\n");
	//for (int i = 0; i < NewSize; i++) { //заполняем массив вручную
		//for (int j = 0; j < NewSize; j++) {
			//scanf_s("%f", &matrix[i][j]);
		//}
	//}
	srand(time(NULL)); //заполнение массива случайными числами
	for (int i = 0; i < NewSize; i++) {
		for (int j = 0; j < NewSize; j++) {
			n = rand() % 1000;
			matrix[i][j] = n / 10;
		}
	}
	printf("\n");
	for (int i = 0; i < NewSize; i++) { //вывод значений
		for (int j = 0; j < NewSize; j++) {
			printf("%.1f\t", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < NewSize; i++) { //сравнение по модулю
		for (int j = 0; j < NewSize; j++) {
			if (abs(matrix[i][j]) > maxl) {
				maxl = abs(matrix[i][j]);
				str = i; //строка
				stb = j; //столбец
			}
		}
	}
	for (int i = 0; i < NewSize; i++) { //проверка на несколько максимумов в массиве
		for (int j = 0; j < NewSize; j++) {
			if (matrix[i][j] == maxl) {
				k += 1;
				if (k == 2) {
					break;
				}
			}
		}
	}
	if (k == 2) {
		printf("ERROOR: Невозможно выполнить программу, из-за того, что содержится более одного маскимального эл-та");
		return 1;
	}
	printf("Модуль максимального эл-та: %.1f\n Строка: %d\n Столбец: %d\n", maxl, str + 1, stb + 1);

	for (int i = 0; i < str; i++) { //сохраняем часть где индекс строки < str и столб-ца < stb, формируем матрицу порядка n-1
		for (int j = 0; j < stb; j++) {
			NewMatrix[i][j] = matrix[i][j];
		}
	}
	for (int i = str; i < NewSize - 1; i++) { //"удаление" строки, формируем матрицу порядка n-1
		for (int j = 0; j < NewSize; j++) {
			NewMatrix[i][j] = matrix[i + 1][j];
		}
	}
	for (int i = 0; i < NewSize - 1; i++) { //"удаление" столбца, формируем матрицу порядка n-1
		for (int j = stb; j < NewSize; j++) {
			NewMatrix[i][j] = matrix[i][j + 1];
		}
	}

	for (int i = 0; i < NewSize - 1; i++) { //вывод значений
		for (int j = 0; j < NewSize - 1; j++) {
			printf("%.1f\t", NewMatrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
