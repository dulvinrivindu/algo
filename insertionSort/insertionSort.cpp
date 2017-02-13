#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int* array = (int*) malloc(sizeof(int) * n);

	int itr = 0;
	for(int arr_i = 0; arr_i < n; arr_i++) {
		cin >> array[arr_i];
	}
	
	for (int arr_j = 1; arr_j < n; arr_j++) {
		int key = array[arr_j];

		int arr_i = arr_j - 1;
		while (arr_i >= 0 && array[arr_i] > key) {
			array[arr_i + 1] = array[arr_i];
			arr_i--;
		}
		array[arr_i + 1] = key;
	}
	
	//output
	cout << endl;
	for (int arr_i = 0; arr_i < n; arr_i++) {
		cout << array[arr_i];
	}
	return 0;
}
