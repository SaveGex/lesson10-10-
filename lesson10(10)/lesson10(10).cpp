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

const int size = 10;


vector <int> Join(vector <int> *array, ...) {
	vector <int> concatenated_array;
	va_list args;
	va_start(args, array);
	for (int i = 0; i < ::size; i++) {
		int digit = va_arg(args, int);
		concatenated_array.push_back(digit);
	}
	va_end(args);
	return concatenated_array;
}

int main() {
	srand(time(nullptr));
	vector <int> array;
	vector <int> array2;
	vector <int> concatenated_array;

	for (int i = 0; i < 10; i++) {
		array.push_back(0 + rand() % (99 + 0 - 1));
		array2.push_back(0 + rand() % (99 + 0 - 1));
	}
	cout << endl;
	for (auto i : array) {
		if (i < 10)	cout << ' ';
		cout << i << ' ';
	}
	cout << endl;

	for (auto i : array2) {
		if (i < 10)	cout << ' ';
		cout << i << ' ';
	}
	cout << endl;

	concatenated_array = Join(&array, &array2);

	for (auto i : concatenated_array) {
		if (i < 10)	cout << ' ';
		cout << i << ' ';
	}





	return 0;
}