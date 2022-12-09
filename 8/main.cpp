#include<iostream>

#include "binaryTree.cpp"

bool is_unival_tree(node* node)
{
    if(node == NULL)
        return true;

    if(node->left != NULL && node->left->data != node->data)
        return false;
    if(node->right != NULL && node->right->data != node->data)
        return false;
    
    return is_unival_tree(node->left) && is_unival_tree(node-> right);
    
}

int get_num_unival_subtrees(node* root)
{
    if(root == NULL)
        return 0;

    int unival_subtrees_count = get_num_unival_subtrees(root-> left) + get_num_unival_subtrees(root->right);

    if(is_unival_tree(root)) 
        unival_subtrees_count++;

    return unival_subtrees_count;
}


int main()
{
    std::cout<<"Daily Coding Problem 8"<<std::endl;

    //     0
    //    / \
    //   1   0
    //      / \
    //     1   0
    //    / \
    //   1   1

    node* root = new node(0);

    node* a = new node(1);
    root->left = a;

    node* b = new node(0);
    root->right = b;
    b->right = new node(0);

    node* c = new node(1);
    b->left = c;
    c->left = new node (1);
    c->right = new node(1);

    std::cout<<get_num_unival_subtrees(root)<<std::endl;

    return 0;
}