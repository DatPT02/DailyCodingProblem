#include"binaryTree.cpp"


int main()
{
    std::cout<<"Daily Coding Problem 3"<<std::endl;

    node* tree = new node();
    tree->data = 1;
    tree = insert(tree, 2);
    tree = insert(tree, 3);
    cout<<"Original tree: \n";
    printTree(tree);

    cout<<"\nDeserialized tree:\n";
    node* testTree = deserializeTree(serializeTree(tree));
    printTree(testTree);
    cout<<testTree->left->data;
    //printTree(deserializeTree(serializeTree(tree)));

    return 0;
}