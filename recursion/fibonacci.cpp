#include <iostream>
using namespace std;

int nthFNum(int n) {
    if (n == 0) return 0;     
    if (n == 1) return 1;     

    return nthFNum(n - 1) + nthFNum(n - 2); 
}

vector<int>Fseries (int n) {
    if(n==0) return {0};

}

int main (){

cout <<nthFNum(5);
cout <<nthFNum(6);
cout <<nthFNum(7);
cout <<nthFNum(0);


}