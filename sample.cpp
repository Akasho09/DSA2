#include <iostream>
using namespace std;

int main (){
string a="a";
int n = 1000;
a+=n;
cout <<a.size() <<endl;
a+=to_string(n);
cout <<a.size() ;
}