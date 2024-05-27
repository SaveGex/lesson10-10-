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

int find_max(int digit, int digit2) {
	return digit > digit2 ? digit : digit2;
}
short find_max(short digit, short digit2, short digit3) {
	return digit > digit2 && digit > digit3 ? digit : digit2 > digit && digit2 > digit3 ? digit2 : digit3;
}


int main() {
	cout << find_max(12, 13) << endl;
	cout << find_max(2, 52, 10);





	return 0;
}