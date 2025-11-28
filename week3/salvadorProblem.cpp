#include<iostream>

using namespace std;


void Solution(){
    int initial = 100;
    int quantity = initial; 
    for(int i=0; i<=100; i++){
        if((quantity-i)%6 == 0){
            if((quantity-i-8)%11 == 0){
                quantity = quantity-i-8;
                cout<<"Salvador have sold "<<initial-quantity<<" flower pots";
                break;
            } 
        }
    }
}

int main(){
    Solution();
}