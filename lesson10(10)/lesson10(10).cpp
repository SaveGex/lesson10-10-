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



void Odd_Print(short size, short* array) {
	short counter = 0;
	for (short i = 0; i < size; i++) {
		if (*(array + i) % 2 != 0) {
			counter++;
		}
	}

	short* odd_array = new short[counter];
	short index = NULL;

	for (short i = 0; i < size; i++) {
		if (*(array + i) % 2 != 0) {
			odd_array[index] = *(array + i);
			index++;
		}
	}

	for (short i = 0; i < index; i++) {
		cout << odd_array[i] << ' ';
	}

	delete[] odd_array;

}



void Even_Print(short size, short* array) {

	short counter = 0;

	for (short i = 0; i < size; i++) {
		if (*(array + i) % 2 == 0) {
			counter++;
		}
	}

	short* even_array = new short[counter];
	short index = NULL;

	for (short i = 0; i < size; i++) {
		if (*(array + i) % 2 == 0) {
			even_array[index] = *(array + i);
			index++;
		}
	}

	for (short i = 0; i < index; i++) {
		cout << even_array[i] << ' ';
	}

	delete[] even_array;
}



bool Check(char *amount) {

	bool ticket = true;
	if (!isdigit(*amount)) {
		ticket = false;
	}

	return ticket;
}



void Cleaning_array(short *array, short& size) {
	short digit;
	char amount;
	bool ticket;


	cout << "\nWrite you want to find neodd[1] or even[2]: ";
	cin >> amount;

	ticket = Check(&amount );

	if (!ticket) {

		while (!ticket) {
			cout << "\nWrite you want to find neodd[1] or even[2]: ";
			cin >> amount;
			ticket = Check(&amount);
		}

	}
	if (ticket) {

		digit = amount - '0';

		if (digit == 1) {

			Odd_Print(size, array);
			
		}
		else if (digit == 2) {

			Even_Print(size, array);

		}
		else cout << "impossible variant";
	}
}




int main() {
	srand(time(nullptr));

	bool repeat = false;
	short size, size2, digit=0, to_random = 99;
	bool ticket = false, first_ticket = true;

	do {
		//it's as second main

		char amount = 0;

		if (!first_ticket) {
			cout << "\nOne more time? Yes[1] Not[2]";
			cin >> amount;

			ticket = Check(&amount);
			if (!ticket) {
				while (!ticket) {
					ticket = Check(&amount);
				}
			}
		}
		if (ticket || first_ticket) {
			digit = amount - '0';
			if (digit == 1 || first_ticket) {

				cout << "Write size array: ";
				cin >> size;

				short* array = new short[size];

				for (short i = 0; i < size; i++) {
					array[i] = rand() % to_random;
				}

				cout << endl;

				for (short i = 0; i < size; i++) {
					cout << array[i] << ' ';
				}
				repeat = true;

				Cleaning_array(array, size);
				delete[] array;
				first_ticket = false;
			}
			else {
				repeat = false;
			}
		}
	} while (repeat);

	return 0;
}
