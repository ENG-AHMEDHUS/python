#include <bits/stdc++.h>

using namespace std;


struct stackNode{

    int data;

    stackNode * next;

};



class LinkedListStack

{

    private:

        stackNode * top;

    public:

        LinkedListStack(){

        top = NULL;

        }

        bool isEmpty(void){

            return top == NULL;

        }

        void push(int dd){

            stackNode * temp = new stackNode;

            temp -> data = dd;

            temp -> next = top;

            top = temp;

        }

        int pop(void){  
            
            stackNode * temp = top;

            int dd = top -> data;

            top = top -> next;

            delete temp;

            return dd;

        }

        int getNumberOfElements(void){    

            int counter = 0;

            for (stackNode * temp = top; temp != NULL; temp = temp -> next)

                counter++;

            return counter;

        }

        void printStack(void){

            cout << "Data in stack: ";

            for (stackNode * temp = top; temp != NULL; temp = temp -> next)

                cout << temp -> data << "\t";

            cout << "\n";

        }

        void deleteStack(void){

            while (top != NULL){

                pop();

            }

        }

};




void main(void)

{

    LinkedListStack st1;

    for (int k = 1; k <= 10; k++)

        st1.push(k * k);



    cout << "Number of elements 1 = " << st1.getNumberOfElements() << "\n";



    st1.printStack();

    cout << "Number of elements 2= " << st1.getNumberOfElements() << "\n";



    while (st1.isEmpty() == false)

        cout << st1.pop() << "\n";



    cout << "Number of elements 3= " << st1.getNumberOfElements() << "\n";



}