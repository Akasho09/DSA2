
#include <iostream>
using namespace std;


  
    void helper(int num , vector<string>&ans , string s , char lastChar){
       if(num==0){
           ans.push_back(s); return ;
       }
       helper(num-1, ans , s+'0', '0');
       if(lastChar!='1') helper(num-1, ans , s+'1' , '1');
    }
    
    vector<string> generateBinaryStrings(int num) {
        vector<string>ans;
        string curr = "";
        char lastChar = '0';
        helper(num , ans , curr ,  lastChar);
        
        return ans ;
    }
    



int main (){

    
}