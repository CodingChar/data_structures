#include<iostream>

using namespace std;


/*

    A program that displays the number between 1 and X 

    if the number is a multiple of 3, print COCA
    if the number is a multiple of 5 print COLA

    if the number is multiple of 3 and 5 print COCA COLA

    if not:

    print number 
*/

void DisplayMultiples(int x){
    for(int i=1; i<=x; i++){
        cout<<endl;
        if(i%3 == 0){
            cout<<"COCA";
        }
        if(i%5 == 0){
            cout<<"COLA";
        }
        if(i%5!=0 && i%3!=0){
            cout<<i;
        }
    }
}

int main(){
    DisplayMultiples(100);
}


