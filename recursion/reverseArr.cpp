

#include <iostream>
using namespace std;

void reverseHelper(int arr[], int start, int end) {
    if (start >= end) return;

    swap(arr[start], arr[end]);
    reverseHelper(arr, start + 1, end - 1);
}

void reverseArray(int arr[], int size) {
    reverseHelper(arr, 0, size - 1);
}

int main (){

    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);

    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
    cout <<arr[i] << " ";
    }
cout<<endl;

}