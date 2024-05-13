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
int Counter(vector <int> &array);

int main() {
	srand(time(nullptr));
	int lenght = 20;
	vector <int> array(lenght);

	for (short i = 0; i < lenght; i++) {
		array[i] = -100+rand()%(100+100+1);
	}
	for (auto i : array) {
		cout << i << ' ';
	}
	cout << endl;

	int counter_pos = Counter(array);
	int counter_neg = Counter(array);
	int counter_zero = Counter(array);
	cout << "\nAmount positive digits: " << counter_pos;
	cout << "\nAmount negetive digits: " << counter_neg;
	cout << "\nAmount zero digits: " << counter_zero;

}
int Counter(vector <int> &array) {
	static int counter_pos=-1;
	static int counter_neg=-1;
	static int counter_zero=-1;

	if (counter_pos == -1) {
		counter_pos++;
		for (int i = 0; i < array.size(); i++) {
			if (array[i] > 0) {
				counter_pos++;
			}
		}
		return counter_pos;
	}
	else if (counter_neg == -1) {
		counter_neg++;
		for (int i = 0; i < array.size(); i++) {
			if (array[i] < 0) {
				counter_neg++;
			}
		}
		return counter_neg;
	}
	else if (counter_zero == -1) {
		counter_zero++;
		for (int i = 0; i < array.size(); i++) {
			if (array[i] == 0) {
				counter_zero++;
			}
		}
		return counter_zero;
	}
}

