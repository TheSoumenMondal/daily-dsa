#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int m, vector<int>& brr, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (arr[i] > brr[j]) {
            arr[k--] = arr[i--];
        } else {
            arr[k--] = brr[j--];
        }
    }

    while (j >= 0) {
        arr[k--] = brr[j--];
    }
}

void print_arr(const vector<int>& arr) {
    for (int it : arr) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1,2,3,0,0,0};
    int m = 3;
    vector<int> brr = {2,5,6};
    int n = 3;

    merge(arr, m, brr, n);
    print_arr(arr);

    return 0;
}
