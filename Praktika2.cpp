#include <iostream>

#include <locale>

#include <fstream>

#include <iomanip>

#include <stdio.h>

using namespace std;

//Заполнение массива [n][n]

int zapolnenie(int **matr, int &n)

{
	cout << "\n";

for (int i = 0; i < n; i++)

{

for (int j = 0; j < n; j++)

{

cout << " " << i + 1 << " строка";

cout << " " << j + 1 << " столбец ";

cin >> matr[i][j];

}

cout << "\n";

}

return **matr;

}

//

//Вывод массива [n][n]

void vivod_matr(int **matr, int &n)

{

for (int i = 0; i < n; i++)

{

for (int j = 0; j < n; j++)

{

cout << setw(5) << matr[i][j];

}

cout << "\n";

}

cout << "\n";

}

//

//Вывод максимального индекса в строках

void Vivod_max_v_strok(int *maxim, int &n)

{

cout << " i максимальных элементов в каждой из строк массива: \n\n";

for (int i = 0; i < n; i++)

{

cout << setw(4) << maxim[i];

}

cout << "\n\n";

}

//

//Максимум в строках массива и их вывод

int Max_v_strokax(int **matr, int *maxim, int &n)

{

int j;

for (int i = 0; i < n; i++)

{

int max = matr[i][0];

maxim[i] = 0;

for (j = 0; j < n; j++)

if (matr[i][j] > max)

{

max = matr[i][j];

maxim[i] = j;

}

}

Vivod_max_v_strok(maxim, n);

return *maxim;

}

//

//Зануление элементов в массиве

int Zanyl(int **matr, int *maxim, int &n)

{

int index_max, s4, i;

int *mas = new int[n];

for (i = 0; i < n; i++)

{

s4 = 0;

index_max = maxim[i];

for (int j = 0; j < index_max; j++)

{

matr[i][j] = 0;

s4++;

}

mas[i] = s4;

}

cout << "число замен в каждой из строк массива\n";

for (i = 0; i < n; i++)

cout << mas[i] << " ";

delete[]mas;

cout << "\n";

cout << " Новый массив с зануленными элементами:\n\n";

vivod_matr(matr, n);

return **matr, *maxim;

}

//

int main()

{

setlocale(LC_ALL, "");

int n, max;

std::cout << " Введите размер вашего массива [n][n] = ";

cin >> n;

int *maxim = new int[n];

int **matr = new int*[n];

for (int i = 0; i < n; i++)

matr[i] = new int[n];

zapolnenie(matr, n);

vivod_matr(matr, n);

Max_v_strokax(matr, maxim, n);

Zanyl(matr, maxim, n);

for (int i = 0; i < n; i++)

delete[] matr[i];

delete[] maxim;

return 0;

}