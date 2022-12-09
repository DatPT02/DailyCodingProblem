#include<iostream>
#include <sstream>
using namespace std;

struct node
{
    node() : data(0), left(NULL), right(NULL) {};
    node(int value) : data(value), left(NULL), right(NULL) {};
    node(int value, node* leftNode, node* rightNode) : data(value), left(leftNode), right(rightNode) {};

    int data;
    node* left;
    node* right;
};

class BinaryTree
{
private:
    node* root;

    node *insert(node* leaf, int data)
    {
        if(leaf == NULL)
        {
            node* temp = new node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        else {
            if(data < leaf->data)
            {
                leaf->left = insert(leaf->left, data);
            }
            else {
                leaf->right = insert(leaf->right, data);
            }
        }

        return leaf;
    }

    void printTree(node* leaf)
    {
        if(leaf!=NULL){
            printTree(leaf->left);
            cout<<leaf->data<< " ";
            printTree(leaf->right);
        }
    }

public: 
    BinaryTree() {};
    
    void add(int data)
    {
        root = insert(root, data);
    }

    void printTree()
    {
        printTree(root);
    }
};
  