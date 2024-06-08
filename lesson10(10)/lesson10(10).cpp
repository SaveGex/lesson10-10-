#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>


//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;

vector <int> Count_Digit(int* array, int* array2, int& size, int& size2) {
	vector <int> vector_array;
	for (int i = 0; i < size; i++) {

		bool ticket = true;

		for (int j = 0; j < size; j++) {
			if (j != size - 1 && j == i)	j++;
			if (j == size - 1)	break;
			if (*(array + i) == *(array + j)) {
				ticket = false;
				break;
			}
		}
		if (ticket) {
			for (int j = 0; j < size2; j++) {
				if (*(array + i) == *(array2 + j)) {
					ticket = false;
					break;
				}
			}
		}
		if (ticket) {
			vector_array.push_back(*(array + i));
		}
	}


	return vector_array;
}

void Make_array(int* array, int* array2, int& size, int& size2) {
	vector <int> vector_array;
	int index = 0;
	int counter = 0;
	vector_array = Count_Digit(array, array2, size, size2);
	counter = vector_array.size();
	int* array3 = new int[counter];

	cout << endl;

	for (int i = 0; i < counter; i++) {
		*(array3 + i) = vector_array[i];
		cout << *(array3 + i) << ' ';
		if (*(array3 + i) < 10) {
			cout << ' ';
		}

	}


	delete[] array3;
}

int main() {
	srand(time(nullptr));
	int size, size2;

	cout << "Write first amount: ";
	cin >> size;

	int* array = new int[size];

	cout << "Write second amount: ";
	cin >> size2;
	int* array2 = new int[size2];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 20;
	}
	for (int i = 0; i < size2; i++) {
		array2[i] = rand() % 10;
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
		if (array[i] < 10)		cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << array2[i] << ' ';
		if (array2[i] < 10)		cout << ' ';
	}



	Make_array(array, array2, size, size2);




	delete[] array;
	delete[] array2;

	return 0;
}
