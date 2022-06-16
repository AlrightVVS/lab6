#include <iostream>
using namespace std;
struct INF {
	int key;
	char info;
	INF(int key, char info) {
		this->key = key;
		this->info = info;
	}
};
void Print(INF* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i].key << ";" << arr[i].info << " ";
	}
	cout << endl;
}
int findrepeat(INF* arr, int i, int j) {
	int firstkey;
	firstkey = arr[i].key;
	for (int k = i + 1; k <= j; k++) {
		if (arr[k].key > firstkey)
			return k;
		else if (arr[k].key < firstkey)
			return i;
	}


return -1;
}
int partition(INF* arr, int i, int j, int pivot) {
	int l, r;
	l = i;
	r = j;
	do {
		swap(arr[l], arr[r]);
		while (arr[l].key < pivot)
			l++;
		while (arr[r].key >= pivot)
			r--;
	} while (l <= r);
	return l;
}
void quicksort(INF* arr, int i, int j) {
	int pivot;
	int pivotindex;
	int k;
	pivotindex = findrepeat(arr, i, j);
	if (pivotindex != -1) {
		pivot = arr[pivotindex].key;
		k = partition(arr, i, j, pivot);
		quicksort(arr, i, k - 1);
		quicksort(arr, k, j);
	}
}
int main() {
	INF arr[] = { INF(1, 'a'), INF(12, 'b'), INF(7, 'c'), INF(9,
   'd') };
	Print(arr, 4);
	quicksort(arr, 0, 3);
	Print(arr, 4);
}