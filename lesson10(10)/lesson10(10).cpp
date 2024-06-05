#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>


//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;



int main() {


	int  m1 = 5, m2 = 5;

	int** pArr = new int* [m1];

	for (int i = 0; i < m1; i++) {

		pArr[i] = new int[m2];

	}

	// Доступ до елементів масиву виконується як звичайно  

	for (int i = 0; i < m1; i++) {
		for (int a = 0; a < m2; a++) {
			pArr[i][a] = rand() % 100;
			cout << ' ' << pArr[i][a];
			if (pArr[i][a] < 10)	cout << ' ';
		}
		cout << endl;
	}

	// Послідовне видалення двовимірного масиву...  

	for (int i = 0; i < m1; i++) {

		delete[]pArr[i];

	}

	delete[]pArr;

	return 0; 
}
