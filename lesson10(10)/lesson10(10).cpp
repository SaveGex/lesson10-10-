#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <locale>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char sentence[] = "About No description, website, or topics provided.";
	char *ptr = sentence;
	int count_letters = 0, any_symbols = 0;
	while (*ptr != '\0') {
		if  (isalpha(*ptr)){//(isalpha(static_cast<unsigned char>(*ptr))) НЕ ПРАЦЮЄ
			count_letters++;
		}
		else {
			any_symbols++;
		}
		ptr++;
	}
	cout << "Letters: " << count_letters << endl << "any symbols: " << any_symbols;
	return 0;
}



