#include <bits/stdc++.h>

using namespace std;

class stack_using_array

{

    private:

        int top, size, * arr;

    public:

        stack_using_array(void){

            size = 10;

            arr = new int[size];

            top = 0;

        }

        stack_using_array(int ss){

            size = ss;

            arr = new int[size];

            top = 0;

        }

        void push(int data){

            if (top >= size){

                cout << "Stack is full, so size will be double\n";

                double_size();

            }

            arr[top] = data;

            top++;

        }

        int pop(void){

            if (top == 0){

                cout << "Stack is empty\n";

                return -1;

            }

            top--;

            return arr[top];

        }

        int read_top_data(void){

            if (top == 0) return -1;

            else return arr[top - 1];

        }

        bool is_full(void){

            return top == size;

        }

        bool is_empty(void){

            return top == 0;

        }

        int get_max_size(void){

            return size;

        }

        int get_nuumber_of_item(void){

            return top;

        }

        void double_size(void){

            int *temparr = new int[size * 2];

            for (int k = 0; k < top; k++)
                temparr[k] = arr[k];

            delete[] arr;

            size *= 2;

            arr = temparr;

        }

        
        void delete_stack_data(){

            top = 0;

        }

        ~stack_using_array(void){

            delete arr;

        }

};


int main() {
    stack_using_array st;


    return 0;
}