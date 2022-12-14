#include <cstring>
#include <algorithm>

#define trieBranchCount 26

std::string ToLowerCase(std::string value)
{
    std::for_each(value.begin(), value.end(), [](char &c){ c = ::tolower(c);});

    return value;
}

class Trie
{
private:
    struct TrieNode
    {
        TrieNode* child[trieBranchCount];
        bool isLeafNode;
    };

    TrieNode* root;

    TrieNode* createNode()
    {
        TrieNode* node = new TrieNode;
        node->isLeafNode = false;
        for(int i = 0;i < trieBranchCount; i ++)
            node->child[i] = NULL;

        return node;
    }

    void getMatchValue(TrieNode* node, std::string value)
    {
        if(node->isLeafNode)
            std::cout<<value<<std::endl;

        for(int i = 0; i < trieBranchCount; i ++)
        {
            if(node->child[i])
            {
                char child = 'a' + i;
                getMatchValue(node->child[i], value + child);
            }
        }
    }

public:
    Trie() : root(createNode()){};

    void insert(std::string value)
    {
        TrieNode* node = root;
        value = ToLowerCase(value);

        for(int i = 0; i < value.length(); i ++)
        {
            int index = tolower(value[i]) - 'a';
            if(!node->child[index])
                node->child[index] = createNode();

            node = node->child[index];
        }

        node->isLeafNode = true;
    }

    void getAutoSuggest(std::string value)
    {
        TrieNode* node = root;
        value = ToLowerCase(value);
        for(char c : value)
        {
            int index = c - 'a';

            if(!node->child[index])
            {
                std::cout<<"No match found"<<std::endl;
                return;
            }

            node = node->child[index];
        }

        if(node->isLeafNode)
        {
            std::cout<<value<<std::endl;
        }

        getMatchValue(node, value);
    }
};