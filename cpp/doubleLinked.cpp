#include <iostream>
#include <conio.h>
using namespace std;

// -------- Node --------
struct node
{
    int dd;
    node *prev, *next;
    node() : prev(NULL), next(NULL) {}
};

// -------- Double Linked List --------
class double_linked_list
{
private:
    node *first, *last;

public:
    double_linked_list() { first = last = NULL; }

    bool is_empty() { return first == NULL; }
    int get_size()
    {
        node *temp;
        int counter = 0;
        for (temp = first; temp != NULL; temp = temp->next) counter++;
        return counter;
    }

    // --- Insertion Functions ---
    void insert_first(int data)
    {
        node *newNode = new node;     newNode->dd = data;
        if (!first) first = last = newNode;
        else
        {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
    }

    void insert_last(int data)
    {
        node *newNode = new node; newNode->dd = data;
        if (!first) first = last = newNode;
        else
        {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    void insert_at_index(int index, int data)
    {
        if (index <= 0) { insert_first(data); return; }
        else
        {
            node *before = first;
            for (int k = 0; before != NULL && k < index - 1; k++)   before = before->next;

            if (!before || before->next == NULL)  insert_last(data);
            
            else
            {
                node *newNode = new node;    newNode->dd = data;

                node *after = before->next;

                newNode->next = after;
                newNode->prev = before;
                before->next = after->prev = newNode;
            }
        }
    }

    void insert_data_inorder(int data)
    {
        if(!first || data <= first->dd) { insert_first(data); return;}

        if (data >= last->dd) { insert_last(data); return; }

        else{
            node *after = first;
            while (after->dd < data)  after = after->next;

            node *before = after->prev;

            node *newNode = new node;  newNode->dd = data;

            newNode->next = after;
            newNode->prev = before;
            before->next = after->prev = newNode;

        }
    }

    // --- Deletion Functions ---
    int delete_last()

    {
        if (!first)  { cout << "Empty Linked List\n";  return -1; }

        int data = last->dd;
        node *temp = last;

        last = last->prev;

        if (last == NULL) first = NULL;
        else         last->next = NULL;

        delete temp;
        return data;

    }

    int delete_first()
    {
        if (!first)  { cout << "Empty Linked List\n";  return -1; }

        int data = first->dd;
        node *temp = first;

        first = first->next;

        if (first == NULL) last = NULL;
        else        first->prev = NULL;

        delete temp;
        return data;
    }

    int delete_index(int index)
        {
            if ( !first ) { cout << "Empty Linked List\n"; return -1; }

            if (index <= 0) return delete_first();
            else {
                node *before = first;
                for (int k = 0; before != NULL && k < index - 1; k++)   before = before->next;

                if (!before || before->next == NULL)  return delete_last();
                else
                {
                    node *temp = before->next;
                    int data = temp->dd;
                    node *after = temp->next;

                    before->next = after;
                    if (after) after->prev = before;
                    else last = before; // if deleting last node

                    delete temp;
                    return data;
                }
            }
        }

    int delete_first_data_occur(int data){
        if (!first)  { cout << "Empty Linked List\n"; return -1; }
        node *temp;   int k = 1;
        for (temp = first; temp != NULL; temp = temp->next)
        {
            if (temp->dd == data)
            {
                if (temp == first) { delete_first(); return k; }
                if (temp == last)  {  delete_last(); return k; }

                node *before = temp->prev;
                node *after = temp->next;

                before->next = after;
                after->prev = before;

                delete temp;

                // cout << data << " is found at index " << k << " and is deleted\n";
                return k;
            }
            else k++;
        }
        cout << data << " could not be found\n";
        return -1;
    }

    void delete_list()
    {
        node *temp;
        while (first != NULL) 
        { temp = first; first = first->next; delete temp; }
        last = NULL;
    }

    // --- Utility Functions ---
    int search(int data)
    {
        node *temp;   int k = 1;
        for (temp = first; temp != NULL; temp = temp->next){
            if (temp->dd == data) {
                cout << data << " is found at index " << k << "\n";
                return k;
            }
            k++;
        }
        cout << data << " could not be found\n";
        return -1;
    }

    void print_first_to_last()
    {
        node *temp;
        for (temp = first; temp != NULL; temp = temp->next) cout << temp->dd << "\t";
        cout << "\n";
    }

    void print_last_to_first()
    {
        node *temp;
        for (temp = last; temp != NULL; temp = temp->prev) cout << temp->dd << "\t";
        cout << "\n";
    }

};

// -------- main (زي الملف) --------
int main()
{
    double_linked_list soso;
    int k;

    for (k = 1; k <= 10; k++)
        soso.insert_last(k * k);

    cout << "\n Print First to Last \t";
    soso.print_first_to_last();

    cout << "\n Print Last to First \t";
    soso.print_last_to_first();
    cout << "\n Size of Linked List is: " << soso.get_size() << "\n";

    soso.insert_at_index(5, 55);
    cout << "\n After Inserting 55 at index 5 \n";
    soso.print_first_to_last();
    cout << "\n Size of Linked List is: " << soso.get_size() << "\n";
    soso.insert_data_inorder(37);
    cout << "\n After Inserting 37 in order \n";
    soso.print_first_to_last();
    cout << "\n Size of Linked List is: " << soso.get_size() << "\n";
    soso.delete_index(4);
    cout << "\n After Deleting at index 4 \n";
    soso.print_first_to_last();
    cout << "\n Size of Linked List is: " << soso.get_size() << "\n";
    soso.delete_first_data_occur(100);
    soso.delete_first_data_occur(55);
    cout << "\n After Deleting first occurrence of 55 \n";
    soso.print_first_to_last();
    cout << "\n Size of Linked List is: " << soso.get_size() << "\n";
    soso.search(81);
    soso.search(100);
    cout << "\n Deleting all elements from Last to First: \n";
    soso.print_last_to_first();
    soso.delete_list();
    cout << "\n Size of Linked List is: " << soso.get_size() << "\n";

    getch();
    return 0;
}