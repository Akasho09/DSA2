class Solution {
public:

bool isPrime(int n) {
    if (n <= 1) return false;            // 0 and 1 are not prime
    if (n <= 3) return true;             // 2 and 3 are prime

    if (n % 2 == 0 || n % 3 == 0) return false;  // eliminate multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
    vector<int> closestPrimes(int left, int right) {
        int i = left ;
        int a=-1;
        int b=-1;
        int min = INT_MAX;

        while(i<=right){
            if(isPrime(i)){
                left=i;
                i++;
                break;
            }
            i++;
        }
        while(i<=right){
            if(isPrime(i)){
                if(i-left<min){
                    a=left;
                    b=i;
                    min=b-a;
                    if(min==2) return {a,b}; 
                }
                left=i;
            }
            i++;
        }
        return {a,b};
    }
};