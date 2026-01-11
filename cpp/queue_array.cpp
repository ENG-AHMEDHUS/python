#include <bits/stdc++.h>

using namespace std;

class queue_using_array {
private:

    int *arr, front, rear, size, counter;

public:
    // Constructor with size
    queue_using_array(int ss) {
        size = ss;
        arr = new int[size];
        front = rear = counter = 0;
    }

    // Default constructor
    queue_using_array() {
        size = 10;
        arr = new int[size];
        front = rear = counter = 0;
    }

    // Enqueue
    void enqueue(int data) {
        if (isfull()){
            cout << "Queue is full, so size will be double\n";
            double_size();
        }
        arr[rear] = data;
        rear = (rear + 1) % size;
        counter++;
    }

    // Dequeue
    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        int temp = arr[front];
        front = (front + 1) % size;
        counter--;
        return temp;
    }

    bool isempty() {
        return counter == 0;
    }

    bool isfull() {
        return counter == size;
    }

    int get_number_of_elements() {
        return counter;
    }

    int get_max_size() {
        return size;
    }

    int get_front() {
        if (isempty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[front];
    }

    void double_size() {
        int *temp = new int[size * 2];

        for (int k = 0; k < counter; k++)
            temp[k] = arr[(front + k) % size];

        delete[] arr;   
        arr = temp;
        size *= 2;
        front = 0;
        rear = counter;
    }

    // Destructor
    ~queue_using_array() {
        delete[] arr;
    }
};

int main() {
    queue_using_array q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.get_front() << endl; // 20

    return 0;
}
