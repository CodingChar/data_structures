#include<iostream>
#include<cmath>

using namespace std;

void printPyramid(long balls){
    long acc = 0;
    for(int i=1; i<=balls; i++){
        acc += pow(i, 2);
        if(acc >= balls){
            acc = acc-pow(i,2);
            cout<<endl<<"Se usaron "<<acc<<" bolas";
            cout<<endl<<"Quedan "<<balls-acc<<" bolas";
            break;
        }
    }
}

int main(){
    int param = 10000;
    printPyramid(param);
}