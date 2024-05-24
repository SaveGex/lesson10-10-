#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;

template <typename T1>
T1 Fill_Array(T1 &array) {
	for (int i = 0; i < 20; i++) {
		int digit = 1 + rand() % (20 - 1 + 1);
		array.push_back(digit);
	}
	return array;
}

vector <int> Scatter_the_element(vector<int> array);



int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251); 
	srand(time(nullptr));

	vector <int> array;

	array = Fill_Array(array);

	for (int i : array) {
		cout<<i<<' ';
	}

	array = Scatter_the_element(array);


	return 0;
}

vector<int> Scatter_the_element(vector<int> array) {
	int element;
	vector <int> buffer_array;
	cout << "Оберіть елемент: ";	
	cin >> element;
	auto check_element = find(array.begin(), array.end(), element);
	if (check_element == array.end()) {
		while (true) {
			cout << "\nОберіть елемент: ";	
			cin >> element;
			auto check_element = find(array.begin(), array.end(), element);
			if (check_element != array.end())	break;
		}
	}
	int index = distance(array.begin(), check_element);
	reverse(array.begin(), array.end());
	for (short i = 0; i < index; i++) {
		buffer_array.push_back(array[i]);
	}
	for (short i = 0; i < index; i++) {
		array.erase(array.begin());
	}
	sort(array.begin(), array.end());
	//array.insert(0, buffer_array.begin(), buffer_array.end());


	return buffer_array;
}



