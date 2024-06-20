#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <map>

//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;
int size;
int check;
#pragma region Задумка непогана, реалізувати неможливо(з моїми знаннями)
//template<typename T>
//T Add_Array_To_Array(vector<T> array);
//
//
//template<typename T>
//int main() {
//	srand(time(nullptr));
//	int spaces, size = 5;
//	vector<T> array(size);
//
//	cout << "How many dimensional array do you want to create: ";
//	cin >> spaces;
//	array = Add_Array_To_Array(array);
//
//
//
//
//	return 0;
//}
//
//
//template<typename T>
//T Add_Array_To_Array(vector<T> array) {
//	vector<T>Second_Array();
//	return 
//}
void Add_Digits_2D(int** array);

int main() {
	srand(time(nullptr));
	int size = 10, quest;
	::size = size; 
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = 0;
		cout << array[i] << ' ';
	}

	cout << "\nConversion to [1]two-dimensional or [2]third-dimensional: ";
	cin >> quest;
	if (quest == 1) {
		delete[]array;
		int** array = new int*[size];
		for (int i = 0; i < size; i++) {
			array[i] = new int[size];
		}
		for (int a = 0; a < size; a++) {
			for (int s = 0; s < size; s++) {
				array[a][s] = 0;
			}
		}

		Add_Digits_2D(array);

		for (int a = 0; a < size; a++) {
			for (int s = 0; s < size; s++) {
				if (a == ::check)		cout << "\033[31m";
				cout << array[a][s] << ' ';
				if (a == ::check)	cout << "\033[0m";
			}
			cout << endl;
		}

		for (int i = 0; i < size; i++) {
			delete[] array[i];
		}
		delete[]array;
	}
	else {
		delete[]array;
		int*** array = new int** [size];
		for (int i = 0; i < size; i++) {
			array[i] = new int* [size];
			for (int a = 0; a < size; a++) {
				array[i][a] = new int[size];
			}
		}
		for (int i = 0; i < size; i++) {
			for (int a = 0; a < size; a++) {
				for (int s = 0; s < size; s++) {
					array[i][a][s] = 0;
				}
			}
		}


		for (int i = 0; i < size; i++) {
			for (int a = 0; a < size; a++) {
				delete[] array[i][a];
			}
			delete[] array[i];
		}
		delete[]array;

	}
	return 0; 
}



void Add_Digits_2D(int** array) {
	int columns = 0;
	::check = columns;
	
	for (int a = 0; a < ::size; a++) {
		for (int s = 0; s < ::size; s++) {
			if (a == columns) {
				array[a][s] = rand() % 10;
			}
		}
	}
}

