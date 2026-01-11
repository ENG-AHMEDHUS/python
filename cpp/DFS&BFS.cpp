#include <iostream>
using namespace std;

struct treeNode
{
    char name, father;
    int order;
};

class mystack
{
private:
    char *arr;
    int top, size;

public:
    mystack(int ss) { top = 0; size = ss; arr = new char[size]; }
    mystack(void)   { top = 0; size = 10; arr = new char[size]; }

    void push(char data)
    {
        if (top < size)
            arr[top++] = data;
    }

    char pop(void)
    {
        return arr[--top];
    }

    bool is_empty(void) { return (top == 0); }
    bool is_full(void)  { return (top == size); }
};

class myqueue
{
private:
    char *arr;
    int front, rear, size, counter;

public:
    myqueue(int ss)
    {
        front = rear = counter = 0;
        size = ss;
        arr = new char[size];
    }

    myqueue(void)
    {
        front = rear = counter = 0;
        size = 10;
        arr = new char[size];
    }

    void enqueue(char data)
    {
        if (counter < size)
        {
            arr[rear] = data;
            rear = (rear + 1) % size;
            counter++;
        }
    }

    char dequeue(void)
    {
        char root = arr[front];
        front = (front + 1) % size;
        counter--;
        return root;
    }

    bool is_empty(void) { return (counter == 0); }
    bool is_full(void)  { return (counter == size); }
};

void print_DFS(treeNode*, int);
void print_BFS(treeNode*, int);

int main(void)
{
    treeNode treeArray[12] =
    {
        {'A','M',2},{'B','M',1},{'C','A',1},
        {'D','H',3},{'F','H',1},{'G','H',2},
        {'H','M',3},{'K','B',2},{'M','0',0},
        {'P','K',2},{'X','K',1},{'Y','B',1}
    };

    cout << "DFS: ";
    print_DFS(treeArray, 12);

    cout << "\nBFS: ";
    print_BFS(treeArray, 12);

    return 0;
}

void print_DFS(treeNode *tree, int size)
{
    int i, counter;
    char *sons = new char[size];
    mystack st(size);

    for (i = 0; i < size; i++)
        if (tree[i].order == 0)
        {
            st.push(tree[i].name);
            break;
        }

    char root;

    while (!st.is_empty())
    {
        root = st.pop();
        cout << root << "\t";
        counter = 0;
        
        for (i = 0; i < size; i++)
            if (tree[i].father == root)
                sons[tree[i].order] = tree[i].name, counter++;

        for (i = counter; i >= 1; i--)
            st.push(sons[i]);
    }

    delete[] sons;
}

void print_BFS(treeNode *tree, int size)
{
    int i, counter;
    char *sons = new char[size];
    myqueue qu(size);

    for (i = 0; i < size; i++)
        if (tree[i].order == 0)
        {
            qu.enqueue(tree[i].name);
            break;
        }

    char root;

    while (!qu.is_empty())
    {
        root = qu.dequeue();
        cout << root << "\t";
        counter = 0;
        
        for (i = 0; i < size; i++)
            if (tree[i].father == root)
                sons[tree[i].order] = tree[i].name, counter++;

        for (i = 1; i <= counter; i++)
            qu.enqueue(sons[i]);
    }

    delete[] sons;
}
