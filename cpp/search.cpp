#include <bits/stdc++.h>

using namespace std;

int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = 5 + rand() % 96;
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int size, key;
    cin >> size >> key;
    int arr[size];

    generate_random_array(arr, size);

    cout<<"Liner Result: "<<linear_search(arr,size,key)<<endl;
    sort(arr, arr + size);
    cout<<"Binary Result: "<<binary_search(arr,size,key)<<endl;


}