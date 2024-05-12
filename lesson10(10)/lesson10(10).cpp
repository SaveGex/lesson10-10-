#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>

#include <algorithm>
using namespace std;
void Paint(string str){
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int quest_way, lenght;
	cout << "write way row[1], col[2]";
	
	cin >> quest_way;
	if (quest_way == 1) {
		cout << "write lenght";
		cin >> lenght;
		for (int i = 0; i < lenght; i++) {
			cout << str;
		}
	}
	else {
		cout << "write lenght";
		cin >> lenght;
		for (int i = 0; i < lenght; i++) {
			cout << str<<"\n";
		}
	}
}
int main() {
	string str;
	cin >> str;
	Paint(str);
}