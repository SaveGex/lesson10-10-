#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <initializer_list>

//bonk2 = find(array.begin(), array.end(), bot1);
//index_bot = distance(array.begin(), bonk2);

using namespace std;

int** Create_Array(int rows, int columns);
int** Fill_Array(int **array, int rows, int columns);
vector<int> Common_Value(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3);
vector<int> Serch_Unique(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3);
vector<int> Check_Arrays(int** array, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3);
vector<int> Serch_Unique(int** array1, int** array3, int rows1, int rows3, int columns1, int columns3);
vector<int> Negative_Unique_Digits(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3);
vector<int> Check_Arrays_Negative(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3);

int main() {
	srand(time(nullptr));
	int rows1, rows2, rows3;
	int columns1, columns2, columns3;

	cout << "Enter the number of rows1: ";
	cin >> rows1;
	cout << "Enter the number of columns1: ";
	cin >> columns1;


	int** array1 = Create_Array(rows1, columns1);

	cout << "Enter the number of rows2 ";
	cin >> rows2;
	cout << "Enter the number of columns2: ";
	cin >> columns2;


	int** array2 = Create_Array(rows2, columns2);

	cout << "Enter the number of rows3: ";
	cin >> rows3;
	cout << "Enter the number of columns3: ";
	cin >> columns3;


	int** array3 = Create_Array(rows3, columns3);

	cout << endl;

	array1 = Fill_Array(array1, rows1, columns1);
	array2 = Fill_Array(array2, rows2, columns2);
	array3 = Fill_Array(array3, rows3, columns3);



	//int args[][3] = {
	//	{rows1, rows2, rows3},
	//	{columns1, columns2, columns3}
	//}; //ваша теорія не працює. Я дивився теорію про функції з необмеженою кількістю параметрів. Там не написано як звернутись до елемента va_arg за індексом. 
	// ШІ мені також не надали відповідь, 
	// хоча за їхніми словами елементи впорядковані і можна звертатись за індексом(на скільки я побачив це не на пряму)


	vector<int> Common_Array = Common_Value(array1, array2, array3, rows1, rows2, rows3, columns1, columns2, columns3);
	vector<int> Unique_Array = Serch_Unique(array1, array2, array3, rows1, rows2, rows3, columns1, columns2, columns3); //ну як на мене працює
	vector<int> A_And_C = Serch_Unique(array1, array3, rows1, rows3, columns1, columns3);
	vector<int> Negative_Unique = Negative_Unique_Digits(array1, array2, array3, rows1, rows2, rows3, columns1, columns2, columns3);


	if (Common_Array.size() > 0) {
		cout << endl << "Common digits: ";
		for (int i = 0; i < Common_Array.size(); i++) {
			cout << Common_Array[i] << ' ';
		}
	}
	if (Unique_Array.size() > 0) {
		cout << endl << "Unique digits: ";
		for (int i = 0; i < Unique_Array.size(); i++) {
			cout << Unique_Array[i] << ' ';
		}
	}
	if (A_And_C.size() > 0) {
		cout << endl << "A and C digits: ";
		for (int i = 0; i < A_And_C.size(); i++) {
			cout << A_And_C[i] << ' ';
		}
	}
	if (Negative_Unique.size() > 0) {
		cout << endl << "Negative unique digits: ";
		for (int i = 0; i < Negative_Unique.size(); i++) {
			cout << Negative_Unique[i] << ' ';
		}
	}





	for (int i = 0; i < rows1; i++) {
		delete[] array1[i];
	}
	delete[] array1;
	for (int i = 0; i < rows2; i++) {
		delete[] array2[i];
	}
	delete[] array2;
	for (int i = 0; i < rows3; i++) {
		delete[] array3[i];
	}
	delete[] array3;

	return 0;
}



vector<int> Check_Arrays_Negative(int** array, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3) {
	vector<int> Negative_Unique;
	bool ticket1 = false, ticket2 = false;
	for (int i = 0; i < rows1; i++) {
		for (int i2 = 0; i2 < columns1; i2++) {
			if (array[i][i2] > -1) {
				continue;
			}
			for (int s = 0; s < rows2; s++) {
				if (ticket1) 	break;

				for (int s2 = 0; s2 < columns2; s2++) {
					if (array[i][i2] == array2[s][s2]) {
						ticket1 = true;
						break;
					}
				}
			}
			for (int s = 0; s < rows3; s++) {
				if (ticket2) 	break;

				for (int s2 = 0; s2 < columns3; s2++) {
					if (array[i][i2] == array3[s][s2]) {
						ticket2 = true;
						break;
					}
				}
			}
			auto have_or_not = find(Negative_Unique.begin(), Negative_Unique.end(), array[i][i2]);
			bool ticket_repetition = true;
			int index;
			if (have_or_not != Negative_Unique.end()) {
				index = distance(Negative_Unique.begin(), have_or_not);
				int amount = Negative_Unique[index];
				if (amount == array[i][i2]) {
					ticket_repetition = false;
				}
			}

			if (!ticket1 && !ticket2 && (Negative_Unique.size() < 1 || ticket_repetition)) {
				Negative_Unique.push_back(array[i][i2]);
			}
			ticket1 = false;
			ticket2 = false;
		}
	}

	return Negative_Unique;
}




vector<int> Negative_Unique_Digits(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3) {
	vector<int> Negative_Unique;

	vector<int> Buffer1 = Check_Arrays_Negative(array1, array2, array3, rows1, rows2, rows3, columns1, columns2, columns3);
	vector<int> Buffer2 = Check_Arrays_Negative(array2, array3, array1, rows2, rows3, rows1, columns2, columns3, columns1);
	vector<int> Buffer3 = Check_Arrays_Negative(array3, array2, array1, rows3, rows2, rows1, columns3, columns2, columns1);

	if (Buffer1.size() > 0) {
		for (int i = 0; i < Buffer1.size(); i++) {
			Negative_Unique.push_back(Buffer1[i]);
		}
	}
	if (Buffer2.size() > 0) {
		for (int i = 0; i < Buffer2.size(); i++) {
			Negative_Unique.push_back(Buffer2[i]);
		}
	}
	if (Buffer3.size() > 0) {
		for (int i = 0; i < Buffer3.size(); i++) {
			Negative_Unique.push_back(Buffer3[i]);
		}
	}



	return Negative_Unique;
}


#pragma region Перевантаження, ТОМУ що я не знаю як зробити 1 функцію так щоб вона була універсальна. Я трохи думав над цим, але навіть в теорії не розумію що для чого потрібно. Мені здається щоб повертало булеве значення...
vector<int> Check_Arrays(int** array1, int** array3, int rows1, int rows3, int columns1, int columns3) {
	vector<int> A_And_C;

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < columns1; j++) {

			int element = array1[i][j];

			for (int k = 0; k < rows3; k++) {
				for (int l = 0; l < columns3; l++) {

					if (element == array3[k][l]) {
						if (find(A_And_C.begin(), A_And_C.end(), element) == A_And_C.end()) {
							A_And_C.push_back(element);
						}
						break;
					}
				}
			}
		}
	}
	return A_And_C;

}

vector<int> Serch_Unique(int** array1, int** array3, int rows1, int rows3, int columns1, int columns3) {
	vector<int> A_And_C;

	vector<int> Buffer1 = Check_Arrays(array1, array3, rows1, rows3, columns1, columns3);
	vector<int> Buffer3 = Check_Arrays(array3, array1, rows3, rows1, columns3, columns1);
	
	for (int i = 0; i < Buffer1.size(); i++) {
		A_And_C.push_back(Buffer1[i]);
	}
	for (int i = 0; i < Buffer3.size(); i++) {
		A_And_C.push_back(Buffer3[i]);
	}

	for (int i = 0; i < A_And_C.size(); i++) {
		int digit = A_And_C[i];
		for (int a = 0l; a < A_And_C.size(); a++) {
			if (i == a) {
				a++;
			}
			else if (a == A_And_C.size()) {
				break;
			}
			if (digit==A_And_C[a]) {

				A_And_C.erase(A_And_C.begin() + a);
				a--;
			}
		}
		
	}


	return A_And_C;
}




vector<int> Serch_Unique(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3) {
	vector<int> Unique_Array;

	vector<int> Buffer1 = Check_Arrays(array1, array2, array3, rows1, rows2, rows3, columns1, columns2, columns3);
	vector<int> Buffer2 = Check_Arrays(array2, array3, array1, rows2, rows3, rows1, columns2, columns3, columns1);
	vector<int> Buffer3 = Check_Arrays(array3, array2, array1, rows3, rows2, rows1, columns3, columns2, columns1);

	if (Buffer1.size() > 0) {
		for (int i = 0; i < Buffer1.size(); i++) {
			Unique_Array.push_back(Buffer1[i]);
		}
	}
	if (Buffer2.size() > 0) {
		for (int i = 0; i < Buffer2.size(); i++) {
			Unique_Array.push_back(Buffer2[i]);
		}
	}
	if (Buffer3.size() > 0) {
		for (int i = 0; i < Buffer3.size(); i++) {
			Unique_Array.push_back(Buffer3[i]);
		}
	}
	return Unique_Array;
}





vector <int> Check_Arrays(int** array, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3) {
	vector<int> Buffer;
	bool ticket1 = false, ticket2 = false;
	for (int i = 0; i < rows1; i++) {
		for (int i2 = 0; i2 < columns1; i2++) {

			for (int s = 0; s < rows2; s++) {
				if (ticket1) 	break;

				for (int s2 = 0; s2 < columns2; s2++) {
					if (array[i][i2] == array2[s][s2]) {
						ticket1 = true;
						break;
					}
				}
			}
			for (int s = 0; s < rows3; s++) {
				if (ticket2) 	break;

				for (int s2 = 0; s2 < columns3; s2++) {
					if (array[i][i2] == array3[s][s2]) {
						ticket2 = true;
						break;
					}
				}
			}
			auto have_or_not = find(Buffer.begin(), Buffer.end(), array[i][i2]);
			bool ticket_repetition = true;
			int index;
			if (have_or_not != Buffer.end()) {
				index = distance(Buffer.begin(), have_or_not);
				int amount = Buffer[index];
				if (amount == array[i][i2]) {
					ticket_repetition = false;
				}
			}

			if (!ticket1 && !ticket2 && (Buffer.size() < 1 || ticket_repetition)) {
				Buffer.push_back(array[i][i2]);
			}
			ticket1 = false;
			ticket2 = false;
		}
	}
	return Buffer;
}






vector<int> Common_Value(int** array1, int** array2, int** array3, int rows1, int rows2, int rows3, int columns1, int columns2, int columns3) {
	vector<int> Common_Array;
	bool ticket1 = false, ticket2 = false;
	for (int i = 0; i < rows1; i++) {
		for (int i2 = 0; i2 < columns1; i2++) {

			for (int s = 0; s < rows2; s++) {
				if (ticket1) 	break;
				
				for (int s2 = 0; s2 < columns2; s2++) {
					if (array1[i][i2] == array2[s][s2]) {
						ticket1 = true;
						break;
					}
				}
			}
			for (int s = 0; s < rows3; s++) {
				if (ticket2) 	break;

				for (int s2 = 0; s2 < columns3; s2++) {
					if (array1[i][i2] == array3[s][s2]) {
						ticket2 = true;
						break;
					}
				}
			}
			
			auto have_or_not = find(Common_Array.begin(), Common_Array.end(), array1[i][i2]);
			bool ticket_repetition = true;
			int index;
			if (have_or_not != Common_Array.end()) {
				index = distance(Common_Array.begin(), have_or_not);
				int amount = Common_Array[index];
				if (amount == array1[i][i2]) {
					ticket_repetition = false;
				}
			}

			if (ticket1 && ticket2 && (Common_Array.size() < 1 || ticket_repetition)) {
				Common_Array.push_back(array1[i][i2]);
			}
			ticket1 = false;
			ticket2 = false;
			
		}
	}
	


	return Common_Array;
}





int** Fill_Array(int** array, int rows, int columns) {
	for (int row = 0; row < rows; row++) {

		for (int col = 0; col < columns; col++) {
			array[row][col] = -10 + rand() % (10 + 10 -1);
			if (array[row][col] < 10 && array[row][col]> -10)	cout << ' ';
			cout << array[row][col] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < columns*2; i++) {
		cout << "_";
	}
	cout << endl;
	return array;
}




int** Create_Array(int rows, int columns) {

	int** array = new int* [rows];

	for (int i = 0; i < rows; ++i) {
		array[i] = new int[columns];
	}

	return array;
}