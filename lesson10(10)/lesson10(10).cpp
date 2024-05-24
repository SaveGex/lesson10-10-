#include <iomanip>
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

template <typename T1>
vector <vector<vector<vector<int>>>> Fill_Array(T1& array, vector<vector<int>>& array_two, vector<vector<vector<int>>>& array_third) {
	vector <vector<vector<vector<int>>>> four_array;

	vector <vector<vector<int>>>empty_array_third;
	vector <vector<int>> empty_array_two;

	vector <int> row;

	vector <vector<int>> col;
	vector <int> row2;

	bool ticket1 = true, ticket2 = true;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 20; k++) {
				int digit = 1 + rand() % (999);// -1 + 1);
				if (ticket1)	array.push_back(digit);
				digit = 1 + rand() % (999);// -1 + 1);
				if (ticket2)	row.push_back(digit);
				digit = 1 + rand() % (999);// -1 + 1);
				row2.push_back(digit);
			}
			if (ticket2) array_two.push_back(row);
			col.push_back(row2);
			ticket1 = false;
			row.clear();
			row2.clear();
		}
		array_third.push_back(col);
		col.clear();
		ticket2 = false;
	}


	empty_array_two.push_back(array);
	empty_array_third.push_back(empty_array_two);
	four_array.push_back(empty_array_third);

	empty_array_third.clear();

	empty_array_third.push_back(array_two);
	four_array.push_back(empty_array_third);

	four_array.push_back(array_third);

	return four_array;
}

vector<int> Max_Digits(vector<vector<vector<vector<int>>>> &four_array) {
	bool ticket1 = true, ticket2 = true;
	int digit1 = four_array[0][0][0][0], digit2 = four_array[0][0][0][0], digit3 = four_array[0][0][0][0];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 10; k++) {
				for (int h = 0; h < 20; h++) {
					if (ticket1 && four_array[i][j][k][h] > digit1)			digit1 = four_array[i][j][k][h];
					if (ticket2 && four_array[i+1][j][k][h] > digit2)	digit2 = four_array[i + 1][j][k][h];
					if (four_array[i+2][j][k][h] > digit3)		digit3 = four_array[i + 2][j][k][h];
				}
				ticket1 = false;
			}
			ticket2 = false;
		}
		break;
	}
	vector<int>digits;
	digits.push_back(digit1);
	digits.push_back(digit2);
	digits.push_back(digit3);
	return digits;
}
void Print(vector <vector<vector<vector<int>>>>& four_array) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < four_array[i].size(); j++) {
			for (int k = 0; k < four_array[i][j].size(); k++) {
				for (int h = 0; h < four_array[i][j][k].size(); h++) {
					cout <<' ' << four_array[i][j][k][h];
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
}
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(nullptr));
	vector <int> digits_array;
	vector <vector<vector<vector<int>>>> four_array;
	vector <vector<vector<int>>> array_third;
	vector <vector<int>> array_two;
	vector <int> array;
	vector <string> names = { "Одновимірний: ", "Двовимірний: ", "Трьохвимірний: " };
	four_array = Fill_Array(array, array_two, array_third);
	digits_array = Max_Digits(four_array);
	Print(four_array);
	for (short i = 0; i < digits_array.size(); i++) {
		cout << endl << names[i] << digits_array[i];
	}



	return 0;
}



