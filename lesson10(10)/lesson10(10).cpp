#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char sentence[] = "як отримати рядок з сайту у змінну стрінг у с++ ? ";
	char *ptr = sentence;
	while (*ptr != '\0') {
		if (*ptr == ' ') {
			*ptr = '\t';
		}
		cout << *ptr;
		ptr++;
	}

	return 0;
}



