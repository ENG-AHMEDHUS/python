#include <iostream>
using namespace std;

// -------- Node --------
struct binary_node
{
    int data;
    binary_node *left, *right;
};

// -------- BST Class --------
class binary_search_tree
{
private:
    binary_node *root;

    binary_node* make_new_node(int dd){
        
        binary_node *temp = new binary_node;
        temp -> data = dd;
        temp -> left = NULL;
        temp -> right = NULL;
        return temp;
    }

    void rec_insertion(binary_node *ptr, int dd)
    {
        if (dd < ptr -> data){

            if (ptr -> left == NULL) ptr -> left = make_new_node(dd);

            else rec_insertion(ptr -> left, dd);
        }

        else if (dd > ptr -> data){

            if (ptr -> right == NULL) ptr -> right = make_new_node(dd);
            
            else rec_insertion(ptr -> right, dd);
        }
        // لو dd == ptr -> data الدكتور ما كانش بيعمل إدخال للـ duplicates
    }

    bool rec_search(binary_node * ptr, int dd)
    {
        if (ptr == NULL)
        { cout << dd << " could not be found\n"; return false; }

        if (ptr -> data == dd)
        { cout << "We find " << dd << " in the tree\n"; return true; }

        if (ptr -> data < dd) return rec_search(ptr -> right, dd);
        else return rec_search(ptr -> left, dd);
    }

    bool rec_delete_data(binary_node *&pt, int key)
    {
        if (pt == NULL)
        { cout << "The number " << key << " could not be deleted\n"; return false; }

        if ((pt) -> data > key)
            return rec_delete_data(((pt) -> left), key);
        else if ((pt) -> data < key)
            return rec_delete_data(((pt) -> right), key);
            
        else { // found
        
            binary_node *temp = pt;

            // الحالة 1: مفيش شمال
            if (pt->left == NULL)
            {
                pt = pt->right;
                delete temp;
            }
            // الحالة 2: مفيش يمين
            else if (pt->right == NULL)
            {
                pt = pt->left;
                delete temp;
            }
            // الحالة 3: الشمال موجود بس ملوش يمين
            else if (pt->left->right == NULL)
            {
                pt->left->right = pt->right;
                pt = pt->left;
                delete temp;
            }
            // الحالة 4: اليمين موجود بس ملوش شمال
            else if (pt->right->left == NULL)
            {
                pt->right->left = pt->left;
                pt = pt->right;
                delete temp;
            }
            // الحالة 5: أصعب حالة (شمال ويمين)
            else
            {
                temp = pt->left;

                while (temp->right->right != NULL)
                    temp = temp->right;

                pt->data = temp->right->data;

                temp->right = temp->right->left;

            }

            return true;
        }
    }

	void rec_pre_order(binary_node *ptr)
	{
	    if (ptr == NULL) return;
	    cout << ptr -> data << "\t";
	    rec_pre_order(ptr -> left);
	    rec_pre_order(ptr -> right);
	}
	
    void rec_in_order(binary_node *ptr)
	{
	    if (ptr == NULL) return;
	    rec_in_order(ptr -> left);
	    cout << ptr -> data << "\t";
	    rec_in_order(ptr -> right);
	}
	
    void rec_post_order(binary_node *ptr)
	{
	    if (ptr == NULL) return;
	    rec_post_order(ptr -> left);
	    rec_post_order(ptr -> right);
	    cout << ptr -> data << "\t";
	}

public:
    binary_search_tree() {
        root = NULL;
    }

    void insert_data(int dd)
    {
        if (root == NULL) root = make_new_node(dd);
        else rec_insertion(root, dd);
    }
    bool search_data(int dd)
    {
        if (root == NULL) { cout << "an empty tree\n"; return false; }
        return rec_search(root, dd);
    }
    bool remove_data(int dd)
    {
        if (root == NULL) { cout << "an empty tree\n"; return false; }
        return rec_delete_data(root, dd);
    }
    void print_pre_order()
    {
        if (root == NULL) cout << "Empty tree, pre order print canceled\n";
        else { cout << "Nodes by Pre order:\t"; rec_pre_order(root); cout << "\n"; }
    }
    void print_in_order()
    {
        if (root == NULL) cout << "Empty tree, in order print canceled\n";
        else { cout << "Nodes by In order:\t"; rec_in_order(root); cout << "\n"; }
    }

    void print_post_order()
    {
        if (root == NULL) cout << "Empty tree, post order print canceled\n";
        else { cout << "Nodes by Post order:\t"; rec_post_order(root); cout << "\n"; }
    }
};
