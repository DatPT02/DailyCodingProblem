#include <cstdint>

struct node
{
    int data;
    node* XORBoth;
};

class XORList
{
private:
    node* head;
    int length;

    node* XOR(node* x, node* y)
    {
        return (node*)((uintptr_t)(x) ^ (uintptr_t)(y));
    }

public:
    XORList() : length(0) {};

    void add(int data)
    {
        node* newNode = new node();
        newNode->data = data;

        newNode->XORBoth = XOR(head, nullptr);

        if(head)
        {
            head->XORBoth = XOR(newNode, XOR(head->XORBoth, nullptr));
        }

        head = newNode;
        length ++;
    }

    void traverse()
    {
        node* curr = head;
        node* prev = nullptr;
        node* next = nullptr;
    
        while (curr != nullptr)
        {
            std::cout << curr->data << " ";
    
            // `next` node would be xor of the address of the previous node
            // and current node link
            next = XOR(prev, curr->XORBoth);
    
            // update `prev` and `curr` pointers for the next iteration of the loop
            prev = curr;
            curr = next;
        }
    }

    node* get(int index)
    {
        node* curr = head;
        node* prev = nullptr;
        node* next = nullptr;

        for(int i = 0; i < length - index; i ++)
        {
            next = XOR(prev, curr->XORBoth);

            prev = curr;
            curr = next;
        }

        return curr;
    }
};