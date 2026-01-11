#include <bits/stdc++.h>
using namespace std;

void quickSort(int *arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int L = left + 1;
    int R = right;
    int temp;

    while (L <= R) {
        while (L <= right && arr[L] <= pivot) L++;
        while (R > left && arr[R] >= pivot) R--;
        if (L < R) {
            temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;
        }
    }

    arr[left] = arr[R];
    arr[R] = pivot;

    quickSort(arr, left, R - 1);
    quickSort(arr, R + 1, right);
}

int main() {
    int arr[] = {6, 3, 8, 5, 2, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "After sorting: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
