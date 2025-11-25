
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *next;
};

template <typename T> // Generic Type
class Stack
{
private:
    Node<T> *_topNode = nullptr;
    Node<T> *_auxNode = nullptr;
    int _stackLength = 0;

    void _ClearStackMemory()
    {

        Node<T> *curr = _topNode;
        while (curr != nullptr)
        {
            Node<T> *next = curr->next;
            delete curr;
            curr = next;
        }
    }

public:
    Node<T> *topNode()
    {
        if (_topNode == nullptr)
        {
            throw runtime_error("Empty stack");
        }
        else
        {
            return _topNode;
        }
    }

    T *top()
    {
        if (_topNode == nullptr)
        {
            return nullptr;
        }
        else
        {
            return &_topNode->value;
        }
    }

    // Stack Operations
    void push(T value)
    {
        if (_topNode == nullptr)
        {                                                   // If no element at all
            Node<T> *newNode = new Node<T>{value, nullptr}; // Creates a new Node into the heap
            _topNode = newNode;
            _stackLength += 1;
        }
        else
        {                                                   // If there is a element in the topNode
            Node<T> *newNode = new Node<T>{value, nullptr}; // Creates a new Node into the heap
            _auxNode = _topNode;
            newNode->next = _auxNode;
            _topNode = newNode;
            _stackLength += 1;
        }
    }
    void pop()
    {
        if (_topNode == nullptr)
        { // If no element in the stack
            throw runtime_error("Empty stack");
        }
        else if (_topNode->next == nullptr)
        { // If only one element in the stack
            delete _topNode;
            _topNode = nullptr;
            _stackLength -= 1;
        }
        else
        { // If there are 2 or more elements in the stack;
            _auxNode = _topNode->next;
            delete _topNode;
            _topNode = _auxNode;
            _stackLength -= 1;
        }
    }
    int getLength()
    {
        return _stackLength;
    }
    ~Stack()
    {
        _ClearStackMemory();
    }
};

int main()
{
    int opc = -1;
    Stack<int> stack;

    stack.push(5);
    stack.pop();
}