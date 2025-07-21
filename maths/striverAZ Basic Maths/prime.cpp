

#include <iostream>
using namespace std;



    bool isPrime(int n) {

        for(int i=2;i<sqrt(n)+1;i++){
            if(n%i==0){
                return false;
            }
        }

        return true;
    }

    vector<int>allprimes(int n) {
        vector<int>v(n,true) ;

        for(int i=2;i<sqrt(n);i++){
            if(v[i]){
                // start from higher multiples like 4*4 , 4*5 .....
            for(int j=i*i;j<=n;j+=i){
                v[j]=false;
            }
            }
        }

        vector<int>ans;
    for(int i=2 ;i<v.size();i++) {
        if(v[i]) ans.push_back(i);
    }
    return ans;
   }


int main (){


    cout<<isPrime(4) <<endl;
    cout<<isPrime(6) <<endl;
    cout<<isPrime(7) <<endl;
    cout<<isPrime(9) <<endl;
    cout<<isPrime(11) <<endl;

    vector<int>v = allprimes(16);
    vector<int>v2 = allprimes(17);
    vector<int>v3 = allprimes(18);


    for(int i=0;i<v.size();i++){
    cout <<v[i] << " ";
}
cout<<endl;

for(int i=0;i<v2.size();i++){
    cout <<v2[i] << " ";
}
cout<<endl;
for(int i=0;i<v3.size();i++){
    cout <<v3[i] << " ";
}
cout<<endl;

    
}