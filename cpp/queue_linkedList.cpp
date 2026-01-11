#include <bits/stdc++.h>
using namespace std;

struct queueNode{

    int data;

    queueNode * next;

};


class LinkedListQueue

{

    private:

        queueNode * front,* rear;

    public:

        LinkedListQueue(){

        front = rear = NULL;

        }

        void enqueue(int dd){

            queueNode * temp = new queueNode;

            temp -> data = dd;

            temp -> next = NULL;

            if (rear == NULL) front = rear = temp;

            else{

                rear -> next = temp;

                rear = temp;

            }

        }

        int dequeue(void){

            queueNode * temp = front;

            int dd = front -> data;

            front = front -> next;

            delete temp;

            if (front == NULL) rear = NULL;

            return dd;

        }

        bool isEmpty(void){

            return front == NULL;

        }

        void printQueue(void){

            cout << "All data in queue : ";

            for (queueNode * temp = front; temp != NULL; temp = temp -> next)

                cout << temp -> data << "\t";

            cout << "\n";

        }

        int getNumberOfElements(void){

            int counter = 0;

            for (queueNode * temp = front; temp != NULL; temp = temp -> next)

                counter++;

            return counter;

        }

};

int main() {
    LinkedListQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);


    return 0;
}
