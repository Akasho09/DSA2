
#include <iostream>
using namespace std;

    bool isArmstrong(int n) {
        int t = n;
        int t2 = n ;
    int matrix[4][9] = {
        {1,2,3,4,5,6,7,8,9},
        {1, 4, 9, 16, 25, 36, 49, 64, 81},
        {1, 8, 27, 64, 125, 216, 343, 512, 729},
        {1, 16, 81, 256, 625, 1296, 2401, 4096, 6561},
    };
    
    int c = 0;
    while(n>0){
        c++;
        n=n/10;
    }

    int anum = 0;
    int c2 = c;
    while(c>0){
        int d=t%10;
        anum+=matrix[c2-1][d-1];
        t=t/10;
        c--;
    }

    if(anum==t2) return true;
    return false ;

    }

int main (){

cout << isArmstrong(153) ;
    
}