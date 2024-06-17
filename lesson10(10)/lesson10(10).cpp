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

int main() {
	srand(time(nullptr));

	int check_int, index;
	bool ticket = true; //цикл
	string digits; 
	vector <int> array;


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

	/*cout << "Which numbers you want to move: ";
	getline(cin, digits);*/


	



	return 0;
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




void Fill_Array(string digits, vector <int>* array){
	string result;
	for (int i = 0; i <	digits.length() + 1; i++) {
		if (isdigit(digits[i])) {
			result += digits[i];
		}
		else if(digits[i] == ' ') {
			(*array).push_back(stoi(result));
			result = "";
		}
	}
}
