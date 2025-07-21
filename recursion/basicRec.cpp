#include <iostream>
using namespace std;
/*
Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.

You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in increasing order from 1 to n.
*/

// 1 to n
void printNumbers(int n)
{
    if (n == 0)
        return;
    printNumbers(n - 1);
    cout << n << " ";
}

void printNumbersRev(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printNumbersRev(n - 1);
}

int NnumbersSum(int N)
{
    if (N == 1)
        return 1;
    // if(N==2) return 3;
    return N + NnumbersSum(N - 1);
}

int factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

vector<int> factorialOfNNums(int n)
{
    if (n == 1) return {1};

    vector<int> v = factorialOfNNums(n - 1);
    int lastFact = v.back();   // (n-1)!
    v.push_back(lastFact * n); // n!
    return v;
}

int main()
{

    cout << NnumbersSum(10) << endl;
    cout << factorial(5) << endl;

    vector<int> v = factorialOfNNums(6);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // printNumbers(10);
    // cout <<endl ;
    // printNumbers(12);

    // cout <<endl ;
    // printNumbersRev(10);
    // cout <<endl ;
    // printNumbersRev(12);
}