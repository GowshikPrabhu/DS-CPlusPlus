/*
* Given a limited range array contains both positive and non-positive numbers,
* i.e., elements are in the range from -MAX to +MAX. Our task is to search if
* some number is present in the array or not in O(1) time.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int table[MAX+1][2] {0};

void create_hash(int arr[], int n) {
    for (int i=0; i<n; i++) {
        if (arr[i] < 0) {
            table[abs(arr[i])][1] = 1;
        } else {
            table[arr[i]][0] = 1;
        }
    }
}

bool check_value(int x) {
    if (x < 0) {
        return table[abs(x)][1];
    } else {
        return table[x][0];
    }
}

int main() {
    int n = 5;
    int arr[n], x;
    bool res;

    cout << "Enter any 5 integer between -1000 and 1000" << endl;
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    cout << endl;
    cout << "Entered numbers are: ";
    for (int a: arr) {
        cout << a << ' ';
    }
    cout << endl;

    create_hash(arr, n);

    cout << "Enter the number to check: ";
    cin >> x;
    cout << endl;
    res = check_value(x);
    if (res == true) {
        cout << "Number is present in array";
    } else {
        cout << "Number is not present in array";
    }
    cout << endl;

    return 0;
}
