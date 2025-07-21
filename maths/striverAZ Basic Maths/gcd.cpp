/*
✅ Euclidean Algorithm Logic:

1. gcd(a, b) = gcd(b, a % b)
   Base case: if b == 0, then gcd(a, b) = a

*/


    int GCD(int n1,int n2) {
        if(n1<n2) GCD(n2,n1);

        while(n2!=0){
            int t = n2 ;
            n2=n1%n2;
            n1=t;
        }
        
    return abs(n1); // ensure the GCD is always positive

    }

#include <iostream>
using namespace std;



int main (){

    cout << GCD(6,5);
    cout << GCD(6,1);
    cout << GCD(6,2);
    cout << GCD(6,3);
    cout << GCD(6,9);


    
}