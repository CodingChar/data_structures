#include<iostream>
#include<cmath>

using namespace std;

 
int NarcisisticCubes(int from, int to){ //Prints the narcisistic cubes between a range specified
    int acc = 0;
    int narcisisticCubes = 0;
    for(int i=0; i<=999; i++){
        int temp = i;
        while(temp > 0){
            acc  +=  pow(temp%10, 3);
            temp /= 10;
        }
        if(acc==i){
            narcisisticCubes+=1;
        }
        acc=0;
    }

    return narcisisticCubes;
}

int main(){
    int result = NarcisisticCubes(1, 999);
    cout<<endl<<"Hay "<<result<<" cubos narcisistas";
}