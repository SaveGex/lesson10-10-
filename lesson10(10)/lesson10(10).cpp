#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
//vector<int> Sort(vector <int> &arr) {
//	int quest_sort;
//	cout << "How you want to sort this array? From lower To Biggest[1] opposite[2]";
//	cin >> quest_sort;
//	if (quest_sort == 1) {
//		sort(arr.begin(), arr.end());
//		return arr;
//	}
//	else{
//		reverse(arr.begin(), arr.end());
//		return arr;
//	}
//}
int Max(vector <int> arr, int lenght) {
	int big;
	big = arr[0];
	for (short i = 0; i < lenght; i++) {
		if (big <= arr[i]) {
			big = arr[i];
		}
	}
	return big;
}
int Min(vector <int> arr, int lenght) {
	int low;
	low = arr[0];
	for (short i = 0; i < lenght; i++) {
		if (low >= arr[i]) {
			low = arr[i];
		}
	}
	return low;
}
int main() {
	srand(time(nullptr));
	int lenght = 3;
	int min, max;
	vector <int> array(lenght);

	for (short i = 0; i < lenght; i++) {
		array[i] = rand() % 50;
	}
	for (auto i : array) {
		cout << "\n" << i << ' ';
	}
	min = Min(array, lenght);
	max = Max(array, lenght);
	cout << "\n" << "min: " << min << "\n" << "max: " << max;


}