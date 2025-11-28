
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node *next;
    Node(T &_value, Node *_next)
    {
        value = _value;
        next = _next;
    }
};

template <typename T> // Generic Type
class Stack
{
private:
    Node<T> *_topNode = nullptr;
    Node<T> *_auxNode = nullptr;
    int _stackLength = 0;

public:
    Node<T> *topNode()
    {
        return _topNode;
    }

    T top()
    {
        if (_topNode == nullptr)
        {
            return;
        }
        else
        {
            return *(&_topNode->value);
        }
    }

    // Stack Operations

    void push(T value)
    {
        Node<T> *newNode = new Node{value, _topNode};
        _topNode = newNode;
        _stackLength += 1;
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
            _stackLength -= 1;
        }
        else
        { // If there are 2 or more elements in the stack;
            _auxNode = _topNode->next;
            delete _topNode;
            _topNode = _auxNode;
            _auxNode = nullptr;
            _stackLength -= 1;
        }
    }
    int getLength()
    {
        return _stackLength;
    }
    void ClearStackMemory()
    {
        if (_topNode == nullptr)
        {
            return;
        }
        while (_topNode != nullptr)
        {
            pop();
        }
    }
    ~Stack()
    {
        ClearStackMemory();
    }
};

template <typename T> // Generic Type
class StackManager
{

public:
    Stack<T> stack;
    void deployManager()
    {
        int userOpc = -1;
        do
        {
            cout << endl
                 << "\n1 - Push into the top of the stack\n2 - Pop an element from the top\n3 - Top Element\n4 - Clear Stack\n5 - Close Manager" << endl;

            if (!(cin >> userOpc))
            {
                cout << endl
                     << "Invalid input" << endl;
                cin.clear();
                cin.ignore(1000);
                userOpc = 0;
                continue;
            }
            switch (userOpc)
            {
            case 1:
            {

                T pushValue;
                cout << endl
                     << "Enter a value:" << ">" << endl;
                if (!(cin >> pushValue))
                {
                    cout << "\n\n Invalid input\n\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    userOpc = 0;
                }
                else
                {
                    cout << endl
                         << "Element Added";
                    stack.push(pushValue);
                }
                break;
            }
            case 2:
            {
                if (stack.getLength() <= 0)
                {
                    cerr << endl
                         << "Cannot perform this operation without elements inside the stacks";
                }
                else
                {
                    stack.pop();
                }
                break;
            }
            case 3:
            {
                if (stack.getLength() <= 0)
                {
                    cerr << endl
                         << "Couldn't obtain the top, no elements in the stacks avaliable";
                }
                else
                {
                    cout << endl
                         << "Stack Top Element: "
                         << stack.topNode()->value;
                }

                break;
            }
            case 4:
            {
                stack.ClearStackMemory();
                break;
            }
            case 5:
            {
                cout << endl
                     << "Thanks for using this manager" << endl;
                break;
            }
            }

        } while (userOpc != 5);
    }
};

int main()
{

    /*

        Stack Management Program

    */

    bool running = true;
    int userOpc = -1;

    cout << endl
         << "Welcome to the Stack Management Program";
    cout << endl
         << "What does a Stack do?";
    cout << endl
         << "\tAn Stack is a type of a data structure that stores elements using  the principle LIFO( Last In, First Out )";

    cout << endl
         << "\nSetup Console\n"
         << endl;
    while (running)
    {

        cout << endl
             << "\n1-Whole Numbers( +  - )\n2-Floating Point Numbers, 1 digit precision (+ -)\n3-Characters";
        cout << endl
             << "With what type of elements will you use for the Stack? ->";
        if (!(cin >> userOpc))
        {
            cout << "\n\n Invalid option\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            userOpc = 0;
            continue;
        }
        switch (userOpc)
        {
        case 1:
        {
            cout << endl
                 << "\nSetting up, a Stack of Whole Numbers\n"
                 << endl;
            StackManager<int> manager;
            manager.deployManager();
            break;
        }
        case 2:
        {
            cout << endl
                 << "\nSetting up, a Stack of Floating Point Numbers\n"
                 << endl;
            StackManager<float> manager;
            manager.deployManager();
            break;
        }
        case 3:
        {
            cout << endl
                 << "\nSetting up, a Stack of Individual Characters\n"
                 << endl;
            StackManager<char> manager;
            manager.deployManager();
            break;
        }
        default:
            cout << endl
                 << "\n Invalid Option\n"
                 << endl;
        }
    }
}