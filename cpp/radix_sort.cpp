#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

int main() {
    int number[SIZE], temp[SIZE], counter[10];
    int num, k = 1; // ✅ لازم نبدأ k من 1

    for (int i = 0; i < SIZE; i++)
        number[i] = rand() % 1000;

    cout << "Original numbers:\n";
    for (int i = 0; i < SIZE; i++)
        cout << number[i] << " ";
    cout << "\n\n";

    for (int digit = 1; digit <= 3; digit++, k *= 10) { 
        cout << "Digit round " << digit << " (k = " << k << "):\n";

        for (int i = 0; i < 10; i++) counter[i] = 0;
        
        for (int i = 0; i < SIZE; i++) {
            num = (number[i] / k) % 10;
            counter[num]++;
        }
        
        for (int i = 1; i < 10; i++)
            counter[i] += counter[i - 1];
        
        for (int i = SIZE - 1; i >= 0; i--) {
            num = (number[i] / k) % 10;
            temp[--counter[num]] = number[i];
        }

        for (int i = 0; i < SIZE; i++) {
            number[i] = temp[i];
            cout << number[i] << " ";
        }
        cout << "\n\n";
    }

    cout << "Final sorted numbers:\n";
    for (int i = 0; i < SIZE; i++)
        cout << number[i] << " ";
    cout << endl;
}
