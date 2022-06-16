#include <iostream>
#include <time.h>
#include <algorithm>
#include <locale.h>
using namespace std;
const int NUM = 50000;
void CreateArray(int* arr, int* arr2) {
	srand(1);
	for (int i = 0; i < NUM; i++)
		arr[i] = arr2[i] = (int)rand();
}
void RestoreArray(int* arr, int* arr2) {
	for (int i = 0; i < NUM; i++)
		arr[i] = arr2[i];
}
void fastSearch(int* mas, int size) {
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];
	do {
		while (mas[i] < mid) {
			i++;
		} while (mas[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		fastSearch(mas, j + 1);
	}
	if (i < size) {
		fastSearch(&mas[i], size - i);
	}
}
int main() {
	setlocale(LC_ALL, "ukr");
	int arr[NUM];
	int arr2[NUM];
	CreateArray(arr, arr2);
	clock_t begt, endt;
	begt = clock();
	for (int i = 1; i < NUM; i++) {
		int j = i;
		while (arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			if (--j == 0)
				break;
		}
	}
	RestoreArray(arr, arr2);
	endt = clock();


printf("Сортування вставками: %d\n", endt - begt);
begt = clock();
fastSearch(arr, NUM);
endt = clock();
printf("Швидке сортування: %d\n", endt - begt);
}
