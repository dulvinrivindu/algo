#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

tuple<int, int, int> get_max_through_array(vector<int>& array, int low, int mid, int high);
tuple<int, int, int> get_max_array(vector<int>& array, int low, int high);

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> array;
    for(int arr_i = 0; arr_i < N; arr_i++) {
        int inNum;
        cin >> inNum;
        array.push_back(inNum);
    }

    //getting maximum values
    int maxLeft;
    int maxRight;
    int maxSum;

    tie(maxLeft, maxRight, maxSum) = get_max_array(array, 0, N - 1);

    cout << maxLeft << ", " << maxRight << ", " << maxSum << endl;
}

tuple<int, int, int> get_max_through_array(vector<int>& array, int low, int mid, int high) {
    int leftMaxSum = INT_MIN;
    int sum = 0;
    int maxLeft;
    for(int arr_i = mid; arr_i >= low; arr_i--) {
        sum += array[arr_i];
        if(sum > leftMaxSum) {
            leftMaxSum = sum;
            maxLeft = arr_i;
        }
    } 

    int rightMaxSum = INT_MIN;
    sum = 0;
    int maxRight;
    for(int arr_i = mid + 1; arr_i <= high; arr_i++) {
        sum += array[arr_i];
        if(sum > rightMaxSum) {
            rightMaxSum = sum;
            maxRight = arr_i;
        }
    }

    return make_tuple(maxLeft, maxRight, leftMaxSum + rightMaxSum);
}

tuple<int, int, int> get_max_array(vector<int>& array, int low, int high)
{
    if(low == high)
        return make_tuple(low, high, array[low]);
    else
    {
        int mid = (low + high) / 2;
        int leftLow, leftHigh, leftSum;
        int crossLow, crossHigh, crossSum;
        int rightLow, rightHigh, rightSum;

        tie(leftLow, leftHigh, leftSum) = get_max_array(array, low, mid);
        tie(crossLow, crossHigh, crossSum) = get_max_through_array(array, low, mid, high);
        tie(rightLow, rightHigh, rightSum) = get_max_array(array, mid + 1, high);

        if(leftSum >= rightSum && leftSum >= crossSum)
            return make_tuple(leftLow, leftHigh, leftSum);
        else if(rightSum >= leftSum && rightSum >= crossSum)
            return make_tuple(rightLow, rightHigh, rightSum);
        else
            return make_tuple(crossLow, crossHigh, crossSum);
    }
}
