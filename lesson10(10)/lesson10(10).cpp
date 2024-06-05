#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>

//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;

void Reversee(int *array, int& size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = *(array + size - i - 1);
	}
	for (int i = 0; i < size; i++) {
		*(array+i) = arr[i];
	}
	delete[] arr;
}

int main() {
	srand(time(nullptr));
	int size = 10;
	int* array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 99;
	}
	for (int i = 0; i<size; i++) {
		if (array[i] < 10)	cout << ' ';
		cout << ' ' << array[i];
	}
	cout << endl;
	Reversee(array, size);
	for (int i = 0; i < size; i++) {
		if (array[i] < 10)	cout << ' ';
		cout << ' ' << array[i];
	}

	delete[] array;


	return 0; 
}
