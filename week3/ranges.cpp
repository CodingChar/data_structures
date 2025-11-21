

#include <iostream>
#include <cstdlib>
#include <time.h>


using namespace std;




void GetRangeStats(int arrSize) /* prints the greater and least numbers, the mode and its frequency based in dataset of random numbers betweenn 1-100*/
{

    srand(time(0)); // Different seed each time the program executes
    int numbersArr[arrSize - 1];

    // Stats
    int greaterNumber = 0;
    int mode = 0;
    int greaterFreq = 0;
    

    int leastNumber = 1;
    int acc = 0;

    for (int i = 0; i < arrSize; i++) //O(N)
    {
        int temp = 0;
        numbersArr[i] = (rand() % 99) + 1; // Numbers between 1-100
        acc += numbersArr[i];

        if (i == 0)
        {
            greaterNumber = numbersArr[i];
            leastNumber = numbersArr[i];
            continue;
        }
        if (numbersArr[i] >= greaterNumber)
        {
            greaterNumber = numbersArr[i];
        }
        if (!(numbersArr[i] >= leastNumber))
        {
            leastNumber = numbersArr[i];
        }
    }

    //Verifying the arithmethic frequency of a number 
    
    
    for(int u=0; u<arrSize; u++){  //O(N)
        int frequency=0;
        for(int k=0; k<arrSize; k++){ //O(N)
            if(numbersArr[u] == numbersArr[k]){
                frequency+=1;    
                if(frequency >= greaterFreq){
                    mode = numbersArr[u];
                    greaterFreq = frequency;
                }
            }
        }
    }


    // Finals Modifications
    acc = acc / arrSize;

    //Print Results 
    cout<<"The stats of a set of "<<arrSize<<" random intergers,  ";
    cout << endl
         << "Greater Number: " << greaterNumber;
    cout << endl
         << "Least Number: " << leastNumber;
    cout << endl
         << "Overall based in the summatory of all the numbers: " << acc;
    cout << endl
         << "The aritmethic mode is the number: "<<mode<<", its found "<<greaterFreq<<" times"<<endl; 

} //O(N+N^3)

int main()
{
    GetRangeStats(1000);
}