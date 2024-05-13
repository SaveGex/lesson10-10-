#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;

vector <int> Average_Value(vector <int> average_value_user, vector <int> average_value_bot) {
	int result_average, average_int=0;
	vector <int> result_array;
	for (short i = 0; i < average_value_user.size(); i++) {
		average_int += average_value_user[i];
	}

	result_average = average_int / average_value_user.size();
	result_array.push_back(result_average);

	for (short i = 0; i < average_value_bot.size(); i++) {
		average_int += average_value_bot[i];
	}
	result_average = average_int / average_value_bot.size();
	result_array.push_back(result_average);
	return result_array;
}



string Result_Text(int result_bot, int result_user) {
	string win_text;
	if (result_bot > result_user) {
		win_text = "\n\033[31mYou lose\033[0m\nscore bot : " + to_string(result_bot) + "\nscore user : " + to_string(result_user);

	}
	else if (result_bot < result_user) {
		win_text = "\033[32mYou win\033[0m\nscore bot: " + to_string(result_bot) + "\nscore user: " + to_string(result_user);
	}
	else {
		win_text = "\n\033[33mIt's a tie!\033[0m\nscore bot: " + to_string(result_bot) + "\nscore user: " + to_string(result_user);
	}
	return win_text;
}



void Paint_Cube(int cube1, int cube2, string symbol_width, string symbol_heigth) {
	bool ticket = true, thats_all = false;
	int number_of_cubes=2;
	int height = 6;
	int width = 20;
	cout << ' ';
	for (short i = 0; i < number_of_cubes; i++) {
		for (short j = 0; j < width; j++) {

			cout << symbol_width;

		}
		cout << "  ";
	}
	for (short i = 0; i < number_of_cubes; i++) {
		for (short j = 0; j < height; j++) {
			if (j % 2 == 0) cout << endl;

			cout << symbol_heigth;

			for (short k = 0; k < width; k++) {

				if (k == width / 2 && i == 1 && ticket == true && thats_all==false){
					
					k++;
					cout << cube1;
					ticket = false;
				}
				else if (k == width / 2 && i == 1&& thats_all==false){
					k++;
					cout << cube2;
					thats_all = true;
				}
				cout << " ";
			}
			cout << symbol_heigth;
		}
	}
	cout << endl;
	for (short i = 0; i < number_of_cubes; i++) {
		cout << "|";
		if (i == 1) {
			cout << "|";
		}
		for (short j = 0; j < width; j++) {

			cout << symbol_width;

		}

	}
	cout << "|" << endl;

	
}






int main() {

	srand(time(nullptr));
	int quest_choice_symbols, quest_first, roll_dice, counter = 0;
	int result_bot = 0, result_user = 0;
	int cube1, cube2;

	vector <int> average_value_user;
	vector <int> average_value_bot;


	cout << "Who roll dice first? My[1] bot[2]: ";
	cin >> quest_first;

	string symbol_heigth;
	string symbol_width;
	
	cout << "Want to choose what symbols the dice will draw? yes[1] no[2]";
	cin >> quest_choice_symbols;

	if (quest_choice_symbols == 1) {

		cout << "example \033[34m _ \033[0m (width), \033[34m | \033[0m (height)\
		         \nWhich symbols you want use for border cube: ";
		cin >> symbol_width >> symbol_heigth;

		if (symbol_width.size() > 1) {
			while (symbol_width.size() > 1) {
				cout << "\n\033[31mplease write just one symbol for width\033[0m";
				cin >> symbol_width;
			}
		}
		if (symbol_heigth.size() > 1) {
			while (symbol_heigth.size() > 1) {
				cout << "\n\033[31mplease write just one symbol for height\033[0m";
				cin >> symbol_heigth;
			}
		}
	}
	else {
		symbol_width = "_";
		symbol_heigth = "|";
	}
	cout << "\nRoll dice[1], exit[2]";
	cin >> roll_dice;
	while (true) {
		if (counter<7) {

			if (quest_first != 1) {
				cube1 = 1 + rand() % (6 - 1 + 1);
				cube2 = 1 + rand() % (6 - 1 + 1);
				average_value_bot.push_back(cube1);
				average_value_bot.push_back(cube2);

				result_bot += cube1 + cube2;
				cout << "\Bot: \n";

				Paint_Cube(cube1, cube2, symbol_width, symbol_heigth);


				cube1 = 1 + rand() % (6 - 1 + 1);
				cube2 = 1 + rand() % (6 - 1 + 1);
				average_value_user.push_back(cube1);
				average_value_user.push_back(cube2);
				result_user += cube1 + cube2;

				cout << "You: \n";


				Paint_Cube(cube1, cube2, symbol_width, symbol_heigth);

			}
			else {
				if (roll_dice == 1) {
					cube1 = 1 + rand() % (6 - 1 + 1);
					cube2 = 1 + rand() % (6 - 1 + 1);
					average_value_user.push_back(cube1);
					average_value_user.push_back(cube2);
					result_user += cube1 + cube2;

					cout << "You: \n";

					Paint_Cube(cube1, cube2, symbol_width, symbol_heigth);


					cube1 = 1 + rand() % (6 - 1 + 1);
					cube2 = 1 + rand() % (6 - 1 + 1);
					average_value_bot.push_back(cube1);
					average_value_bot.push_back(cube2);
					result_bot += cube1 + cube2;


					cout << "Bot: \n";

					Paint_Cube(cube1, cube2, symbol_width, symbol_heigth);


				}
				else	return 0; //if user want exit
			}
			counter++;
		}
		else {
			string win_text=Result_Text(result_bot, result_user);
			cout << win_text;
			vector <int> result_array=Average_Value(average_value_user, average_value_bot);
			for (auto i : result_array) {
				if (i == result_array[0]) {
					cout << "\nUser value average: " << i;
				}
				else {
					cout << "\nBot value average: " << i;

				}
			}
			return 0;
			
		}

	}

}


