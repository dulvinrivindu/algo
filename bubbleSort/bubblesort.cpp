#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> array;
    for(int arr_i = 0; arr_i < N; arr_i++) {
        int inNum;
        cin >> inNum;
        array.push_back(inNum);
    }

    for (int i = 0; i < N; i++){
        for(int j = 0; j < (N - i - 1); j++) {
            if(array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int arr_i = 0; arr_i < N; arr_i++) {
        cout << array[arr_i] << ", ";
    }
    cout << endl;
}
