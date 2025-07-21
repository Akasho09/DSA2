#include <iostream>
using namespace std ;

// complexity :  ~ sqrt(n)*log(n) = sqrt(n)
// sqrt(n) + ((2*sqrt(n))*(log(2*sqrt(n))))

vector<int> divisors (int n ) {
    vector<int>ans;
    int s = sqrt(n);
    for(int i=0;i<s-1;i++) {
        if(n%i==0){
            ans.push_back(i);
            ans.push_back(n/i);
        }
    }
    if(n%s==0) ans.push_back(s);
    sort(ans.begin(),ans.end());
    return ans ;
}

int main () {

    vector<int>v = divisors(16);
    vector<int>v2 = divisors(17);
    vector<int>v3 = divisors(18);
    vector<int>v4 = divisors(19);
    vector<int>v5 = divisors(25);
    vector<int>v6 = divisors(36);


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

for(int i=0;i<v4.size();i++){
    cout <<v4[i] << " ";
}
cout<<endl;


for(int i=0;i<v5.size();i++){
    cout <<v5[i] << " ";
}
cout<<endl;


for(int i=0;i<v6.size();i++){
    cout <<v6[i] << " ";
}
cout<<endl;

}