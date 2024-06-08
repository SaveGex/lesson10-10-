int main() {
	srand(time(nullptr));
	int size, size2;
	cin >> quest_sort;
	if (quest_sort == 1) {
		sort(arr.begin(), arr.end());
		return arr;
	}
	else{
		reverse(arr.begin(), arr.end());
		return arr;
	}
}
<<<<<<< HEAD
	srand(time(nullptr));
	int lenght=10;
	int min, max;
=======
	int lenght;
	int sym;
	cin >> quest_sort;
	if (quest_sort == 1) {
		sort(arr.begin(), arr.end());
		return arr;
	}
	else{
		reverse(arr.begin(), arr.end());
		return arr;
	}
}
<<<<<<< HEAD
	srand(time(nullptr));
	int lenght=10;
	int min, max;
=======
	int lenght;
	int sym;
	cin >> quest_sort;
	if (quest_sort == 1) {
		sort(arr.begin(), arr.end());
		return arr;
	}
	else{
		reverse(arr.begin(), arr.end());
		return arr;
	}
}
<<<<<<< HEAD
	srand(time(nullptr));
	int lenght=10;
	int min, max;
=======
	int lenght;
	int sym;
#include <Windows.h>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>


	cout << "Write first amount: ";
	cin >> size;

	int* array = new int[size];

	cout << "Write second amount: ";
	cin >> size2;
	int* array2 = new int[size2];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % 20;
		bool ticket = true;
	for (int i = 0; i < size2; i++) {
		array2[i] = rand() % 10;
	}
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
		if (array[i] < 10)		cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << array2[i] << ' ';
		if (array2[i] < 10)		cout << ' ';
		cout << i << ' ';



	Make_array(array, array2, size, size2);



	}
	delete[] array;
	delete[] array2;
	cout << endl;
	return 0;
}	max = Max(array, lenght);
	auto amount = find(array.begin(), array.end(), min);
	int index = distance(array.begin(), amount);
	cout << "\n" << "min: " << min << '(' << index+1 << ')';
	
	auto amount1 = find(array.begin(), array.end(), max);
	int index1 = distance(array.begin(), amount1);
	cout << "\n" << "max: " << max << '(' << index1+1 << ')';
=======
	}
	array=Sort(array);
	for (auto i : array) {
		cout << i<<' ';
		cout << i << ' ';
>>>>>>> 1c2fd62 (Revert "task1")
	}
	cout << endl;
}	auto amount = find(array.begin(), array.end(), min);
	int index = distance(array.begin(), amount);
	cout << "\n" << "min: " << min << '(' << index+1 << ')';
	
	auto amount1 = find(array.begin(), array.end(), max);
	int index1 = distance(array.begin(), amount1);
	cout << "\n" << "max: " << max << '(' << index1+1 << ')';
=======
	}
	array=Sort(array);
	for (auto i : array) {
		cout << i<<' ';
	for (short i = 0; i < lenght; i++) {
>>>>>>> 1c2fd62 (Revert "task1")
		array[i] = sym;
		array2[i] = rand() % 10;
}
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
		if (array[i] < 10)		cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < size2; i++) {
		cout << array2[i] << ' ';
		if (array2[i] < 10)		cout << ' ';
		array2[i] = rand() % 10;
>>>>>>> 1c2fd62 (Revert "task1")
	cout << endl;
	delete[] array;
	delete[] array2;
		if (array2[i] < 10)		cout << ' ';
	return 0;
}

	Make_array(array, array2, size, size2);




	delete[] array;
	delete[] array2;

	return 0;
}
