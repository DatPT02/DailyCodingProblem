#define MAX_SIZE 10


class OrderLog
{
private:
    long elements[MAX_SIZE];
    int size;
    int current_element;

    int next(int index)
    {
        return index + 1 < size ? index + 1 : 0;
    }

    int previous(int index)
    {
        return index == 0 ? size - 1 : index - 1;
    }

public:
    OrderLog() : size(MAX_SIZE), current_element(-1) {};

    void record(long orderID)
    {
        current_element = next(current_element);
        elements[current_element] = orderID;
    }

    long getLast(int index)
    {
        if(index < 0 || index > size)
            return -1;

        int current = current_element;
        for(int i = 1; i < index ; i ++)
            current = previous(current);

        return elements[current];
    }

    void printRecord()
    {
        int current = current_element;
        for(int i = 0 ; i < size; i ++)
        {
            std::cout<<"Current index "<<current <<": "<<elements[current]<<std::endl;
            current = previous(current);
        }
    }
};