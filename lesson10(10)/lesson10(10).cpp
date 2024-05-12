#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>

#include <algorithm>
using namespace std;
vector<int> Sort(vector <int> &arr) {
	int quest_sort;
	cout << "How you want to sort this array? From lower To Biggest[1] opposite[2]";
	cin >> quest_sort;
	if (quest_sort == 1) {
		sort(arr.begin(), arr.end());
		return arr;
	}
	else{
		reverse(arr.begin(), arr.end());
		return arr;
	}
}
int main() {
	int lenght;
	int sym;

	cout << "write lenght of array: ";
	cin >> lenght;
	vector <int> array(lenght);

	cout << "Write symbol which be fill array: ";
	for (short i = 0; i < lenght; i++) {
		cin >> sym;
		array[i] = sym;
	}
	for (auto i : array) {
		cout << i << ' ';
	}
	array=Sort(array);
	for (auto i : array) {
		cout << i<<' ';
	}


}