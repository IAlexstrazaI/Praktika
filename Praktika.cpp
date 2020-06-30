#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#define N 5
void input_matr(int a[N][N]) {
	int i, j;
	printf("Введите элементы матрицы a: \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("a[%d][%d]:", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}
void input_matr2(int a[N][N]) {
	int i, j;
	FILE* fp;
	fp = fopen("C:\test\Lab7.txt", "r");
	if (fp) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				fscanf(fp, "%d", &a[i][j]);
			}
		}
		fclose(fp);
	}
}
int minMassiva(int x[N], int const arraySize, int min, int i)
{
	if (x[i] < min)
		min = x[i];
	i++;
	if (i < N) {
		minMassiva(x, arraySize, min, i);
	}
	else {
		return min;
	}
}

int* mas_x(int(*a)[N], int* x, void(*pfunc)(int[N][N])) {
	int i, j, max;
	pfunc(a);
	for (i = 0; i < N; i++) {
		max = a[i][0];
		for (j = 0; j < N; j++) {
			if (a[i][j] >= max) {
				x[i] = a[i][j];
				max = a[i][j];
			}
		}
	}
	printf("min = %d", minMassiva(x, N, x[0], 1));
	printf("\n");
	return x;
}

void output(const int x[], const int a[N][N])
{
	int i, j;
	printf("Матрица А:\n");
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("Массив Х:\n");
	for (i = 0; i < N; i++)
		printf("%5d", x[i]);
	printf("\n");
}

void output2(const int x[], const int a[N][N]) {
	int i, j;
	FILE* fp;
	fp = fopen("Lab72.txt", "w");
	if (fp) {
		fprintf(fp, "Матрица А:\n");
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				fprintf(fp, "%5d", a[i][j]);
			fprintf(fp, "\n");

		}
		fprintf(fp, "Массив Х:\n");
		for (i = 0; i < N; i++)
			fprintf(fp, "%5d", x[i]);
		fprintf(fp, "\n");
		fclose(fp);
	}
}

int main() {
	setlocale(LC_CTYPE, "");
	int a[N][N], x[N], c;
	void(*pfunc)(int[N][N]);
	do
	{
		printf("Ввод матрицы:\n1 - с клавиатуры\n2- Из файла\n");
		scanf("%d", &c);
	} while (c != 1 && c != 2);
	switch (c)
	{
	case 1: pfunc = &input_matr;
		break;
	case 2: pfunc = &input_matr2;
	}
	output(mas_x(a, x, pfunc), a);
	output2(mas_x(a, x, pfunc), a);
	_getch();
}
