#include <iostream>
#include <vector>

int GreatestNumber(const std::vector<int> &vector /*Using T&, no copy, using original*/)
{

    // I'm using vector because it allows me to recieve dynamic sized arrays
    /*
        I'm Learning about Pointers
        and how does the memory model of C++ works

        Understanding aspects such as:

        Pointers, Dereferencing, Referencing

    */

    //Time Complexity: 0(n) , Memory Complexity: 0(1)

    int greatestNumber = vector[0];

    int vectorSize = vector.size();
    for (int i = 0; i < vectorSize; i++)
    {
        if (vector[i] >= greatestNumber)
        {
            greatestNumber = vector[i];
        }
    }
    return greatestNumber;
}

int main()
{
    std::vector<int> numbers = {1, 2, 3, 5, 0};

    std::cout<<std::endl<<GreatestNumber(numbers);
}