class Solution {
  public:
    void print_divisors(int n) {
        vector<int>v;
        int i;
        for( i=1;i*i<n;i++){
            if(n%i==0){
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        for(int i=0;i<v.size();i+=2) cout <<v[i] <<" ";
        if(i*i==n) cout <<i <<" ";
        for(int i=v.size()-1;i>=1;i-=2) cout <<v[i] <<" ";
    }
};