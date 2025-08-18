#include <iostream>
using namespace std;


int main (){




}

    int integerReplacement(int n) {
        if(n==2147483647) return 32;
        if(n<=3) return n-1;

        int c  = 0 ;
        while(n>4){
            if(n&1){
                if(n&2) n++;
                else n--;
            } else n>>=1;
            c++;
        }
        c+=2;
        return c ;
    }