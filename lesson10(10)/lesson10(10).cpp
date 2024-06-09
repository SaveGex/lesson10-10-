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

//Написати такі функції для роботи з динамічним масивом :
int size;
bool Check(char* amount) {
	bool ticket = true;

	if (!isdigit(*amount)) {
		ticket = false;
	}

	return ticket;
}




bool Chech_String(string amount_for_array) {
	bool ticket = true;
	for (auto i : amount_for_array) {
		if (!isdigit(i)) {
			if (i == ' ')		continue;
			ticket = false;
			break;
		}
	}
	return ticket;
}




vector <int> Create_Array() {
	bool ticket;
	string amount_for_array;
	int size;

	cout << "Write size of array: ";
	cin >> amount_for_array;

	ticket = Chech_String(amount_for_array);

	while (!ticket) {
		cout << "\nWrite you want to find neodd[1] or even[2]: ";
		cin >> amount_for_array;
		ticket = Chech_String(amount_for_array);
	}

	size = stoi(amount_for_array);
	::size = size;
	vector <int> array(size);

	return array;
}





void Less_Digits(vector <int> *array, int *inx) {
	cout << "You need to write " << ::size - *inx << " digits\n";

	string less_amount_array;
	getline(cin, less_amount_array);

	bool ticket = Chech_String(less_amount_array);

	while (!ticket) {
		cout << "\nWrite digit all at once: ";
		cin.ignore();
		getline(cin, less_amount_array);
		ticket = Chech_String(less_amount_array);
	}

	string result;
	for (int i = 0; i <= less_amount_array.length(); i++) {
		result += less_amount_array[i];
		if (!isdigit(less_amount_array[i]) && *inx < ::size) {
			int digit = stoi(result);
			(*array)[*inx] = digit;
			*inx += 1;
			result = "";
		}
	}
}




void Initialization_Array(vector <int> *array) {
	bool ticket;
	int digit, counter_adds = 0;
	char amount;

	cout << "\nFill the array automatically[1] manually[2]: ";
	cin >> amount;

	ticket = Check(&amount);

	while (!ticket) {
		cout << "\nFill the array automatically[1] manually[2]: ";
		cin >> amount;
		ticket = Check(&amount);
	}

	digit = amount - '0';

	if (digit == 1) {
		for (int i = 0; i < ::size ; i++) {
			(*array)[i] = rand() % 99;
		}
	}
	else if (digit == 2) {
		string amount_for_array;
		cout << "need " << ::size << " digits " << "\nWrite digit all at once: ";

		cin.ignore();
		getline(cin, amount_for_array);

		ticket = Chech_String(amount_for_array);

		while (!ticket) {
			cout << "need " << ::size << " digits " << "\nWrite digit all at once: ";
			cin.ignore();
			getline(cin, amount_for_array);
			ticket = Chech_String(amount_for_array);
		}

		string result;
		int index = 0;

		for (int i = 0; i <= amount_for_array.length(); i++) {
			result += amount_for_array[i];
			if (!isdigit(amount_for_array[i]) && index < ::size) {
				digit = stoi(result);
				(*array)[index] = digit;
				index++;
				result = "";

			}
		}
		int *inx = &index;
		while(*inx < ::size) {
			Less_Digits(array, inx);
		}
	}
	else	cout << "Impossible amount";	
}


void Printing_Array(vector <int> *array) {
	for (int i = 0; i < ::size; i++) {
		cout << (*array)[i] << ' ';
	}
	cout << endl;
}

void Delete_Array(vector <int>*array) {
	delete[] array;
}

void Push_End(vector <int> *array) {
	int digit;
	string amount, result;

	cout << "Write digit: ";
	cin.ignore();
	getline(cin, amount);
	bool ticket = Chech_String(amount);

	while (!ticket) {
		cout << "Write digit: ";
		cin.ignore();
		getline(cin, amount);
		ticket = Chech_String(amount);
	}
	for (int i = 0; i <= amount.length(); i++) {
		result += amount[i];
	}
	
	digit = stoi(result);
	array->push_back(digit);


}


void Insert_el_INarray(vector<int>* array) {
	int index;
	string amount, result;

	cout << "Write which index use: ";
	cin >> amount;

	bool ticket = Chech_String(amount);

	while (!ticket) {
		cout << "Write which index use: ";
		cin >> amount;
		getline(cin, amount);
		ticket = Chech_String(amount);
	}
	for (int i = 0; i <= amount.length(); i++) {
		result += amount[i];
	}

	index = stoi(result);
	result = "";



	cout << "Write digit for insert: ";
	cin >> amount;

	ticket = Chech_String(amount);

	while (!ticket) {
		cout << "Write which index use: ";
		cin >> amount;
		ticket = Chech_String(amount);
	}
	for (int i = 0; i <= amount.length(); i++) {
		result += amount[i];
	}

	int digit = stoi(result);


	(*array)[index] = digit;
}



void Erase_El_Array(vector <int> *array) {
	char quest;
	string amount, result;
	int index;

	cout << "Show array Yes[1] No[2]: ";
	cin >> quest;
	if (quest == '1') {
		Printing_Array(array);
		for (int i = 0; i < array->size(); i++) {
			(i < 10) ? cout << ' ' :
			cout << i << ' ';
		}
	}

	cout << "Which element 0 to " << array->size()<<": ";
	cin.ignore();
	getline(cin, amount);

	bool ticket = Chech_String(amount);

	while (!ticket) {
		cout << "Write which index use: ";
		cin.ignore();
		getline(cin, amount);
		ticket = Chech_String(amount);
	}
	for (int i = 0; i <= amount.length(); i++) {
		result += amount[i];
	}

	index = stoi(amount);
	array->erase(array->begin() + index);
	::size--;
}




int main() {

	/*Функція розподілу динамічної пам'яті.
	на скільки я зрозумів це зробити сирий динамічний масив*/

	char quest;
	vector <int> array;
	array = Create_Array();
	while (true) {
		cout << "\
\nCreate array[1]\n\
Fill array[2]\n\
Print array[3]\n\
Delete array[4]\n\
Add element in end of array[5]\n\
Insert element by index in array[6]\n\
Erase element by index[7]\n\
Exit[8]";
		cin >> quest;
		switch (quest) {
		/*Заповнення числами*/
		case '1':array.clear(), array = Create_Array(); break;
		case '2':Initialization_Array(&array); break;
		case '3':Printing_Array(&array); break;
		case '4':Delete_Array(&array); break;
		case '5':Push_End(&array); break;
		case '6':Insert_el_INarray(&array); break;
		case '7':Erase_El_Array(&array); break;
		case '8': return 0;
		}
	}


	return 0;
}