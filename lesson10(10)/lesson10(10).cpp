#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;
vector<int> Sorting(vector <int> &array);

int main() {
	srand(time(nullptr));
	int lenght = 5;
	vector <int> array(lenght);

	for (short i = 0; i < lenght; i++) {
		array[i] = rand() % 50;
	}
	for (auto i : array) {
		cout << i << ' ';
	}
	cout << endl;
	sort(array.begin(), array.end());
	array= Sorting(array);
	for (auto i : array) {
		cout << i << ' ';
	}


}
vector<int> Sorting(vector <int> &array) {
	int size = array.size();
	for (short i = 0; i < array.size() / 2; i++) {
		swap(array[i], array[size-1-i]);
	}
	return array;
}