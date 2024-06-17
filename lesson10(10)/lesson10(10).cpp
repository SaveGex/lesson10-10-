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

void Fill_Array(string digits, vector <int>* array);
bool Check_Correct_Input(string check);
int Infinite_Question(string check);
void Erase(int index, vector<int>* array);

int main() {
	srand(time(nullptr));

	int check_int, index;
	bool ticket = true; //цикл
	string digits;
	vector <int> array;
	vector<int> digits_which_be_move;
	vector<int> buffer_array;


	while (ticket) {

		cout << "write your digits: ";
		getline(cin, digits);
		Fill_Array(digits, &array);

		cout << "\nComplete add? \n[1]Yes [2]No: ";
		string check;
		getline(cin, check);
		bool ticket_correct = Check_Correct_Input(check);

		if (!ticket_correct) {
			check_int = Infinite_Question(check);
		}
		else {
			check_int = stoi(check);
		}
		if (check_int == 1) {
			ticket = false;
		}

	}

	cout << endl;

	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << ' ';
	}

	cout << "(the numbers must match completely)\nWhich numbers you want to move: ";
	getline(cin, digits);
	Fill_Array(digits, &digits_which_be_move);

	for (int a = 0; a < array.size(); a++) {
		if (digits_which_be_move.size() > 0) {
			for (int i = 0; i < digits_which_be_move.size(); i++) {
				if (digits_which_be_move[i] == array[a]) {
					buffer_array.push_back(digits_which_be_move[i]);
					Erase(a, &array);
					if (a == 0)	a = 0; // Уменьшение индекса a после удаления элемента
					else		a--;
					break;
				}
			}
		}
	}
	cout << "Where to move the numbers: ";
	cin >> index;
	index--;
	if (index > array.size()) {
		index = array.size();
	}
	for (int i = 0; i < buffer_array.size(); i++) {
		array.insert(array.begin() + index + i, buffer_array[i]);
	}

	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << ' ';
	}
	return 0;
}


void Erase(int index, vector<int>* array) {
	array->erase(array->begin() + index);
}



int Infinite_Question(string check) {
	int digit;
	string result;
	for (int i = 0; i < check.length() + 1; i++) {
		if (isdigit(check[i])) {
			result += check[i];
		}
	}

	digit = stoi(result);
	result = "";

	while (digit < 1 && digit > 2) {

		cout << "\n\033[31mComplete add?\033[0m \n[1]Yes [2]No: ";
		getline(cin, check);
		for (int i = 0; i < check.length() + 1; i++) {
			if (isdigit(check[i])) {
				result += check[i];
			}
		}
		digit = stoi(result);
		result = "";
		cin.ignore();
	}

	return digit;
}




bool Check_Correct_Input(string check) {
	bool ticket_correct = true;
	for (int i = 0; i < check.length() + 1; i++) {
		if (!isdigit(check[i])) {
			ticket_correct = false;
			break;
		}
	}
	return ticket_correct;
}




void Fill_Array(string digits, vector <int>* array) {
	string result;
	for (int i = 0; i < digits.length(); i++) {
		if (isdigit(digits[i])) {
			result += digits[i];
		}
		else if (digits[i] == ' ' && result != "") {
			(*array).push_back(stoi(result));
			result = "";
		}
	}
	if (result != "") {
		(*array).push_back(stoi(result));

	}
}
