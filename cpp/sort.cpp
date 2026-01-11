#include <bits/stdc++.h>

using namespace std;


void generate_random_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = 5 + rand() % 96;
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection_sort(int * arr, int size){

    int minloc, temp;

    for (int i = 0; i < size - 1; i++){

        minloc = i;

        for (int j = i+1 ; j < size ; j++)
            if (arr[j] < arr[minloc]) minloc = j;

        temp = arr[i];
        arr[i] = arr[minloc];
        arr[minloc] = temp;

    }

}

void insertion_sort(int *arr, int size)
{
    int i, j, temp;

    for (i = 1; i < size ; i++)
    {
        temp = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (temp < arr[j])
                arr[j + 1] = arr[j];
            else
                break;
        }

        arr[j + 1] = temp;
    }
}

void bubble_sort(int *arr , int size)
{
    int i, j, temp, flag;

    j = 1;

    do
    {
        flag = 0;

        for (i = 0; i < size - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag++;
            }
        }

        j++;

    } while (flag);
}




int main() {
    int size;
    cin >> size ;
    int arr[size];

    generate_random_array(arr, size);

    selection_sort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }


}