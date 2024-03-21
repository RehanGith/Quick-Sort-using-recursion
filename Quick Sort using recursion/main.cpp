#include <iostream>

#define max 7
using namespace std;

bool issorted(int* arr, int size) {
	int count{};
	for (int i = 0; i < size-1; i++) {
		if (arr[i] < arr[i +1])
			count++;
	}
	if (count == size - 1)
		return true;
	return false;
}
void quick_sort(int* arr, int i, int j) {
	int pivot = i;
	int size = j;
	i++;
	if (i > j or j == 0)
		return;
	while (i <= j) {
		if (arr[i] > arr[pivot] && arr[j] <= arr[pivot])
			swap(arr[i], arr[j]);
		else if (arr[i] <= arr[pivot])
			i++;
		else if (arr[j] > arr[pivot])
			j--;
	}
	swap(arr[pivot], arr[j]);
	quick_sort(arr, 0, j - 1);
	quick_sort(arr, j + 1, size);
}
int main() {
	int arr[max]{5,2,4,5,1, 3,1 };
	quick_sort(arr,0, max -1);
	for (int i = 0; i < max; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}