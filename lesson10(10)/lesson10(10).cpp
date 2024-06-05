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

void Reversee(vector <int> &array, int &size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = array[size - i - 1];
	}
	for (int i = 0; i < size; i++) {
		array[i] = arr[i];
	}
	delete[] arr;
}

int main() {
	srand(time(nullptr));
	vector <int> array;
	int size = 10;

	for (int i = 0; i < size; i++) {
		array.push_back(rand() % 99);
	}
	for (int i = 0; i<array.size(); i++) {
		if (array[i] < 10)	cout << ' ';
		cout << ' ' << array[i];
	}
	cout << endl;
	Reversee(array, size);
	for (int i = 0; i < array.size(); i++) {
		if (array[i] < 10)	cout << ' ';
		cout << ' ' << array[i];
	}



	return 0; 
}
