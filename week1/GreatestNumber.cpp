#include <iostream>

using namespace std;

int GreatestNumber(int* array, unsigned int arrSize /*Recieves a int* pointer and the arr size*/) 
{
    if(array == nullptr){
        std::cerr<<"\nNull Pointer\n";
        return 0;
    }

    /*
        I'm Learning about Pointers
        and how does the memory model of C++ works

        Understanding aspects such as:

        Pointers, Dereferencing, Referencing

    */

    //Time Complexity: 0(n) , Memory Complexity: 0(1)

    int greatestNumber = array[0];



    
    for (int i = 0; i < arrSize; i++)
    {
        if (array[i] >= greatestNumber)
        {
            greatestNumber = array[i];
        }
    }
    return greatestNumber;
}

int main()
{
    int numbers[5] = {1, 2, 3, 5, 6};
    std::cout<<std::endl<<GreatestNumber(numbers, 5);
}