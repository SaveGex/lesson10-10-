#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <Windows.h>

using namespace std;

void Add_row(vector<vector<int>>* ptr);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(time(nullptr));

	int rows = 3, columns = 5;
	vector<vector<int>> array(rows);


	for (int i = 0; i < array.size(); i++) {
		for (int a = 0; a < columns; a++) {
			array[i].push_back(rand() % 9);
			cout << array[i][a] << ' ';
		}
		cout << endl;
	}
	cout << "\033[36m";
	for (int i = 0; i < 5; i++) {
		cout << "_ ";
	}
	cout << "\033[0m" << endl;
	Add_row(&array);

	for (int i = 0; i < array.size(); i++) {
		for (int a = 0; a < columns; a++) {
			cout << array[i][a] << ' ';
		}
		cout << endl;
	}

	return 0;
}


void Add_row(vector<vector<int>>* ptr) {
	vector<int> buffer((*ptr)[0].size());
	for (int i = 0; i < (*ptr)[0].size(); i++) {
		buffer[i] = 9 + rand() % (20 + 9 - 1);
	}
	(*ptr).push_back(buffer);
}



