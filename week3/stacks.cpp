
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

public:
    Node<T> *topNode()
    {
        if (_topNode == nullptr)
        {
            return nullptr;
        }
        else
        {
            return _topNode;
        }
    }

    T top()
    {
        if (_topNode == nullptr)
        {
            return 0;
        }
        else
        {
            return _topNode->value;
        }
    }

    // Stack Operations
    void push(T value)
    {
        if (_topNode == nullptr)
        {                                                   // If no element at all
            Node<T> *newNode = new Node<T>{value, nullptr}; // Creates a new Node into the heap
            _topNode = newNode;
        }
        else
        {                                                   // If there is a element in the topNode
            Node<T> *newNode = new Node<T>{value, nullptr}; // Creates a new Node into the heap
            _auxNode = _topNode;
            newNode->next = _auxNode;
            _topNode = newNode;
        }
    }
    void pop()
    {
        if (_topNode == nullptr)
        { // If no element in the stack
            return;
        }
        else if (_topNode->next == nullptr)
        { // If only one element in the stack
            delete _topNode;
            _topNode = nullptr;
        }
        else
        { // If there are 2 or more elements in the stack;
            _auxNode = _topNode->next;
            delete _topNode;
            _topNode = _auxNode;
        }
    }
    ~Stack()
    {
        Node<T>* curr = _topNode;
        while(curr != nullptr){
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main()
{
    Stack<int> stack;
    cout<<endl<<"Stack Program"<<endl;
    stack.push(2);
    cout<<endl<<stack.top()<<endl; // 2
    stack.push(3);
    cout<<endl<<stack.top()<<endl; // 3 
    stack.pop(); 
    cout<<endl<<stack.top()<<endl; // 2    
}