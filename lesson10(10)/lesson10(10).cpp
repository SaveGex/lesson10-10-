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
	int words = 0;
	bool ticket = false;
	while (*ptr != '\0') {
		if (isalpha(*ptr)) {
			ticket = true;
		}
		if (ticket && (*ptr == ',' || *ptr == ' ' || *ptr == '.')) {//(isalpha(static_cast<unsigned char>(*ptr))) НЕ ПРАЦЮЄ
			words++;
			ticket = false;
		}
		ptr++;
	}
	cout << "Letters: " << words;
	return 0;
}



