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

string serializeTree(node* leaf)
{
    if(leaf == NULL) return " ";
    return to_string(leaf->data) + " " + serializeTree(leaf->left) + " "  + serializeTree(leaf-> right);
}

node* deserializeTree(string serializedtree)
{
    stringstream ss;
    ss << serializedtree;

    node* leaf = NULL;

    string temp;
    while(!ss.eof())
    {
        ss >> temp;
        int data;
        if(stringstream(temp) >> data)
        {
            leaf = insert(leaf, data);
        }
        temp = "";
    }

    return leaf;
}