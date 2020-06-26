
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
