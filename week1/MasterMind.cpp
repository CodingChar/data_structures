#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

/*

    MasterMind Game Recreation
    guess a number combination with a length of 4 digits
    the digits shouldn't be repeated in two different positions

    Let's do this :)

*/

int dev_genCode(int t)
{
    int code[4] = {0, 0, 0, 0};

    srand(t);
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            code[0] = (rand() % 6) + 1;
        }
        else if (i >= 1)
        {
            code[i] = (rand() % 6) + 1;
            for (int u = i - 1; u >= 0; u--)
            {
                cout << endl
                     << "u:->" << u;
                if (code[i] == code[u])
                {

                    /*
                    evaluates if the actual number equals
                    to the numbers
                    before
                    */
                    code[i] = (rand() % 6) + 1;
                    if (code[i] == code[u])
                    {
                        cout << endl
                             << "Equals" << endl

                            ;
                        u += 1;
                        continue;
                    }
                }
            }
        }
    }

    for (int k = 0; k < 4; k++)
    {
        cout << code[k];
    }
    return 0;
}

int genCode(int t)
{
    /* Shuffling Based 4 digits code Generator Algorithm */
    /* 
        Despues de medio dia, porfin un algoritmo de generacion 
        con eficiencia O(n)
    */
    int numbers[6] = {1, 2, 3, 4, 5, 6};
    srand(t);
    for (int u = 0; u <= 2; u++)
    {
        for (int i = 0; i < 6; i++)
        {
            int temp = numbers[i];
            int directionShuffle = (rand() % 2)-1; // 0: left, 1: right
            if (directionShuffle)
            {
                // Shuffle to the right
                if (i <= 5)
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
    }
    for (int k = 0; k < 4; k++)
    {
        cout << numbers[k];
    }

    return 0;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        cout << endl;
        genCode(i);
    }
}
