

#include<iostream>

using namespace std;

template <typename T> //Generic Type 


class Stack{
    public: 
        int stackSize=0;
        T stack[stackSize];         
        Stack(T const& val, int _stackSize){
            stackSize=_stackSize;
        }
};