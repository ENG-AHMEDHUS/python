#include <bits/stdc++.h>

using namespace std;

#define size 10

struct st {
    int id;
    char grade;
};

int main() {

    struct st list[size], temp[size];
    int counter[6];
    // char ch;

    for (int i = 0; i < size; i++) {

        list[i].id = i + 1001;
        list[i].grade = 'A' + rand() % 6;

    }

    for (int i = 0; i < size; i++)  cout << i << " " << list[i].id << " " << list[i].grade << endl;


    for (int i = 0; i < 6; i++) counter[i] = 0;


    for (int i = 0; i < size; i++) counter[list[i].grade - 'A']++;

    
    // cout << 0 << " " << "A" << " " << counter[0] << endl;
    for (int i = 1; i < 6; i++) counter[i] += counter[i - 1] ;
        // ch = 'A' + i;
        // cout << i << " " << ch << " " << counter[i] << endl;
    

    for (int i = size - 1; i >= 0; i--) temp[--counter[list[i].grade - 'A']] = list[i];
    
    for (int i = 0; i < size; i++) {
        list[i] = temp[i];
        cout << i << " " << list[i].id << " " << list[i].grade << endl;
    }


}
