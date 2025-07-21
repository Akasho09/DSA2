/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/


#include <iostream>
using namespace std;

    bool isPalindrome(string s){

    int i = 0;
    int j = s.size();

    while(i<=j){
    if(s[i]>=65 && s[i]<=90){  s[i] = s[i]+32; }  // capital to small
    if(s[j-1]>=65 && s[j-1]<=90){  s[j-1] = s[j-1]+32; }  // capital to small

        if((s[i]<48 || s[i]>122) || (s[i]<97 && s[i]>57)) i++;
        else if((s[j-1]<48 || s[j-1]>122) || (s[j-1]<97 && s[j-1]>57)) j--;
        else if (s[i]!=s[j-1]) return false;
        else {
            i++; j--;
        }
    }
    return true ;
}

int main (){


    
}