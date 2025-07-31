/*
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.*/


#include <iostream>
using namespace std;

    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int m = s+(e-s)/2;

        while(s<=e){
            m = s+(e-s)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target) e=m-1;
            else s=m+1;
        }

        return -1;
    }


    /*
    Problem Statement: Given a sorted array of N integers and an integer x, 
    write a program to find the lower bound of x.
    */
    int lowerBound(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size(); // IMP
        while (s < e) {
            int m = s + (e - s) / 2;
            if (arr[m] < target)
                s = m + 1;
            else
                e = m;
        }
        return s;
    }


    int upperBound(vector<int>& arr, int target) {
    int s = 0;
    int e = arr.size(); // IMP
    while (s < e) {
        int m = s + (e - s) / 2;
        if (arr[m] <= target) {
            s = m + 1;
        } else {
            e = m; // m as s<e
        }
    }
    return s; // First index where arr[s] > target
}

int main (){


    
}
