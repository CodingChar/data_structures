#include <iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

/*

    MasterMind Game Recreation 
    guess a number combination with a length of 4 digits
    the digits shouldn't be repeated in two different positions 

    Let's do this :) 

*/


int genCode(){
    int code[4] = {0, 0, 0, 0};
    
    srand(time(0));
    for(int i=0; i<4; i++){
        if(i=0) code[0] = (rand() % 6)+1; 


    }
    for(int u=0; u<4; u++){
        cout<<code[u];
    }
    return 0;
}


int main(){
    for(int i=0; i<1000; i++){
        cout<<endl;
        genCode();
    }
}
