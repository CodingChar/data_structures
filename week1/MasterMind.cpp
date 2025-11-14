

#include <iostream>
#include <random>

using namespace std;

/*

    MasterMind Game Recreation
    guess a number combination with a length of 4 digits
    the digits shouldn't be repeated in two different positions

    Let's do this :)

*/

void genCode(int (&arrPtr)[4])
{

    /* 

        Shuffling Based 4 digits Code Generator Algorithm, digits between 1-6 

        void genCode(int *arrPtr) -> recieves an array  as a argument
        then modifies the array using the arrays original reference, so the array obtaints the code
        through the biased-shuffle algorithm.

        Not the most efficient and proportional, nothing special


    */
    /*
        Despues de medio dia, porfin un algoritmo de generacion
        con eficiencia de tiempo O(1) o mas bien O(6)
    */



    int numbers[6] = {1, 2, 3, 4, 5, 6};

    std::default_random_engine generator; //Defines the generator 
    
    generator.seed(time(0)); //Sets the seed, different seed each time the program runs  
    
    std::uniform_int_distribution<int> distribution(0, 1); //Sets the range 

    for (int i = 0; i < 6; i++)
    {
        //Temporary variable, helps to the shuffle proccess
        int temp = numbers[i]; 
        
        //generates a random number based in the distribution
        int directionShuffle = distribution(generator);

        // Debug: std::cout<<std::endl<<directionShuffle<<std::endl;
        if (directionShuffle == 1 /*the same as " if(directionShuffle) "*/) 
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
void calculatePoints(){
}

int main()
{
    int code[4] = {};
    int play[4] = {};

    genCode(code);
    for (int i = 0; i < 4; i++){
        cout << code[i];
    }

    int attempts = 10; 
    do{



    }while(attempts>0);
}