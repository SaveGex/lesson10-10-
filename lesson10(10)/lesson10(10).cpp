#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>

<<<<<<< HEAD
//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

=======
#include <algorithm>
>>>>>>> 1c2fd62 (Revert "task1")
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
<<<<<<< HEAD
	srand(time(nullptr));
	int lenght=10;
	int min, max;
=======
	int lenght;
	int sym;

	cout << "write lenght of array: ";
	cin >> lenght;
>>>>>>> 1c2fd62 (Revert "task1")
	vector <int> array(lenght);

	cout << "Write symbol which be fill array: ";
	for (short i = 0; i < lenght; i++) {
		cin >> sym;
		array[i] = sym;
	}
	for (auto i : array) {
		cout << i << ' ';
<<<<<<< HEAD
	}
	cout << endl;
	min=Min(array, lenght);
	max = Max(array, lenght);
	auto amount = find(array.begin(), array.end(), min);
	int index = distance(array.begin(), amount);
	cout << "\n" << "min: " << min << '(' << index+1 << ')';
	
	auto amount1 = find(array.begin(), array.end(), max);
	int index1 = distance(array.begin(), amount1);
	cout << "\n" << "max: " << max << '(' << index1+1 << ')';
=======
	}
	array=Sort(array);
	for (auto i : array) {
		cout << i<<' ';
	}
>>>>>>> 1c2fd62 (Revert "task1")


}