#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>

//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;

int size;

int *Return_Pointer(int *array) {
	int entry_counter = 0;

	for (int i = 0; i < ::size; i++) {
		if (array[i] % 2 == 0) {
			entry_counter++;
		}
	}

	if (entry_counter > 0) {
		int index = 0;
		int* even_array = new int[entry_counter];

		for (int i = 0; i < ::size; i++) {
			if (array[i] % 2 == 0) {
				even_array[index] = array[i];
				index++;
				
			}
		}
		::size = index;
		return even_array;
	}

	::size = 0;
	return array;
}



int main() {
	srand(time(nullptr));

	int size, size2;

	cout << "Write size of array: ";
	cin >> size;
	::size = size;

	int* array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 99;
	}
	
	int *array2 = Return_Pointer(array);


	for (int i = 0; i < ::size; i++) {
		cout << array2[i] << ' ';
	}

	cout << endl << array2;

	return 0;
}