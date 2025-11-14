

#include <iostream>

using namespace std;

/*

    MasterMind Game Recreation
    guess a number combination with a length of 4 digits
    the digits shouldn't be repeated in two different positions

    Let's do this :)

*/

void genCode(int* arrPtr)
{
    /* Shuffling Based 4 digits code Generator Algorithm, digits between 1-6 */
    /* 
        Despues de medio dia, porfin un algoritmo de generacion 
        con eficiencia de tiempo O(n) o mas bien O(6)
    */
    int numbers[6] =  {1, 2, 3, 4, 5, 6};

    srand(time(nullptr));
        for (int i = 0; i < 6; i++) {
            int temp = numbers[i];
            int directionShuffle = (rand() % 2)+0; // 0: left, 1: right
            //Debug: std::cout<<std::endl<<directionShuffle<<std::endl;
            if (directionShuffle==1)
            {
                // Shuffle to the right
                if (i == 5)
                {
                    numbers[5] = numbers[0];
                    numbers[0] = temp;
                }
                else
                {
                    numbers[i] = numbers[i + 1];
                    numbers[i + 1] = temp;
                }
            }
            else
            {
                // Shuffle to the left
                if (i == 0)
                {
                    numbers[i] = numbers[5];
                    numbers[5] = temp;
                    ;
                }
                else
                {
                    numbers[i] = numbers[i - 1];
                    numbers[i - 1] = temp;
                }
            }
        }
    arrPtr[0] = numbers[0];
    arrPtr[1] = numbers[1];
    arrPtr[2] = numbers[2];
    arrPtr[3] = numbers[3];
}


int main(){
    int code[4]= {};

    genCode(code);
    for(int i=0; i<4; i++){
        cout<<code[i];
    }
}