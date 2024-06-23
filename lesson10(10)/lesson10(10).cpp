#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <locale>
#include <Windows.h>

using namespace std;

bool Step_by_Step(int counter, int counter_end, char sentence[]);

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char sentence[] = "TIKKIT";
	bool ticket = true;
	int counter = 0, counter_from_end = strlen(sentence)-1;
	
	for (int i = 0; i<strlen(sentence)-1; i++) {
		ticket = Step_by_Step(counter, counter_from_end, sentence);
		if (!ticket) {
			cout << "Word not is palindrome";
			return 0;
		}
		counter++;
		counter_from_end--;
	}
	cout << "Word is palindrome";
	return 0;
}


bool Step_by_Step(int counter, int counter_end, char sentence[]) {
	if (sentence[counter] != sentence[counter_end]) {
		return false;
	}
	return true;
}

