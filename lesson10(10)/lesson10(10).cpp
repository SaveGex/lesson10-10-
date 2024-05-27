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

int find_position(vector<int>& array) {
	vector<int> amount_ten;
	int min_digit, index;
	for (int i = 0; i < array.size()/10; i++) {
		int result = 0;

		for (int j = 0; j < array.size(); j++) {

			result += array[j];
			if ((j % 10 == 0 || j==99) && j != 0) {
				amount_ten.push_back(result);
				result = 0;
			}
		}
	}
	min_digit = amount_ten[0];
	index = 0;
	for (int i = 0; i < amount_ten.size(); i++) {
		if (amount_ten[i] < min_digit) {
			index = i;
			min_digit = amount_ten[i];
		}
	}
	sort(amount_ten.begin(), amount_ten.end());
	for (auto i : amount_ten) {
		cout << i << ' ';
	}
	cout << endl;
	return index;
}

int main() {
	srand(time(nullptr));
	vector <int> array;
	for (int i = 0; i < 100; i++) {
		array.push_back(0 + rand() % (999 - 0 + 1));
	}
	for (auto i : array) {
		if (i < 10) {
			cout << ' ';
		}
		if (i < 100) {
			cout << ' ';
		}
		cout << i << ' ';
	}
	cout << endl;
	cout << find_position(array);






	return 0;
}