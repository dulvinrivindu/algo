#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void merge(vector<int>& array, int p, int q, int r);
void merge_sort(vector<int>& array, int p, int r);

int main(){
    int n;
    cin >> n;
    vector<int> array;

    for(int arr_i = 0; arr_i < n; arr_i++) {
        int inNum;
        cin >> inNum;
        array.push_back(inNum);
    }

    merge_sort(array, 0, n - 1);

    for (auto each:array)
        cout << each << ", ";
    cout << endl;
    return 0;
}

void merge_sort(vector<int>& array, int p, int r) {
    if(p < r) {
        int q;
        q = (p + r) / 2;
        merge_sort(array, p, q);
        merge_sort(array, q + 1, r);
        merge(array, p, q, r);
    }   
}

void merge(vector<int>& array, int p, int q, int r) {
    vector<int> L;
    vector<int> R;

    for(int arr_i = p; arr_i <= q; arr_i++) {
        L.push_back(array[arr_i]);          
    }
    L.push_back(INT_MAX);
    for(int arr_i = q + 1; arr_i <= r; arr_i++) {
        R.push_back(array[arr_i]);          
    }
    R.push_back(INT_MAX);
    
    int i = 0, j = 0;
    for(int arr_i = p; arr_i <= r; arr_i++) {
        if(L[i] <= R[j]){
            array[arr_i] = L[i];
            i++;
        }
        else{
            array[arr_i] = R[j];
            j++;
        } 
    }
}
