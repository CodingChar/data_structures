

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
        through the non-biased-shuffle algorithm.

        


    */
    /*
        Despues de medio dia, porfin un algoritmo de generacion
        con eficiencia de tiempo O(1) o mas bien O(6)
    */

    int numbers[6] = {1, 2, 3, 4, 5, 6};

    std::default_random_engine generator; // Defines the generator

    generator.seed(time(0)); // Sets the seed, different seed each time the program runs


    for (int i = 0; i < 6; i++)
    {
        // Temporary variable, helps to the shuffle proccess
        int temp = numbers[i];
        // generates a random number based in the distribution
        std::uniform_int_distribution<int> distribution(0, i); // Sets the range
        int swapIndex = distribution(generator);
        numbers[i] = numbers[swapIndex];
        numbers[swapIndex] = temp;
    }
    arrPtr[0] = numbers[0];
    arrPtr[1] = numbers[1];
    arrPtr[2] = numbers[2];
    arrPtr[3] = numbers[3];
}

void converIntToArray(int (&arr)[], int number, int size)
{

    size = size -1; 
    while (size >= 0)
    {
        arr[size] = number % 10;
        number = number / 10;
        size = size - 1;
    }
}   

int main()
{
    int code[4] = {0, 0, 0, 0};
    int guess[4] = {0, 0, 0, 0}; 

    int attemptsLeft = 10;
    int userInput = 0;

    int totalC = 0; //If totalC reaches 3, conclude that the user guessed right;

    cout << "\t\t \n \n Welcome To MasterMind \n \n \t\t";

    cin.clear();


    genCode(code); 

    cout << "\n\n Code Generated \n\n";
    cout<<"Code:"<<endl<<code[0]<<code[1]<<code[2]<<code[3]<<endl;
    cout<<"\n\nGuess the 4 digits code to win\n\n";
    do
    {
        cout<<"\n\nCode(Attempts Left: "<<attemptsLeft<<")"<<":";        
        while(!(cin>>userInput))
        {
            cout << "\n\n Invalid code, not a number\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            userInput=0;
        }

        if(userInput <= 0){
            cout << "\n\n Must be greater than 0\n\n";            
        }else{
            converIntToArray(guess, userInput, 4); //O(n);
            cout<<'\n';
            for(int gi=0; gi<4; gi++){ //O(4) 

                for(int ci=0; ci<4; ci++){ //O(4)
                    cout<<endl<<"Guess:"<<guess[gi]<<endl<<"Code:"<<code[ci]<<endl;
                    if(gi==ci && guess[gi]==code[ci]){
                        cout<<'C';
                        totalC+=1; 
                        break;
                    }else if(guess[gi] == code[ci]){
                        cout<<'F';
                        break;
                    }else if(ci==3){
                        cout<<'X';
                        break;
                    }
                }
            }              
        }
        
        userInput = 0;

        
        if(totalC >= 3){
            cout<<"\n You Scored ( "<<10-(10-attemptsLeft)<<" )"<<" points out of ( 10 )";
            break;
        }else{
            cout<<"\n";
            totalC=0;
            attemptsLeft-=1;
        }
    } while (attemptsLeft > 0);
}