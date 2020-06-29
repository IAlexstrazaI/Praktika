
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
