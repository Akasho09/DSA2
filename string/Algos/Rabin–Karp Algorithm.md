
# 🔹 Rabin–Karp Algorithm
The idea is to use hashing so we don’t compare characters one by one for every possible substring.
Instead, we hash the pattern and substrings of the text and compare the hashes.

## 🔸 Idea

- Compute a hash for the pattern P of length m.

- Compute hash for the first window of T of length m.

- Slide the window one character at a time, updating the hash in O(1) using a rolling hash formula.

- If hash matches → do a character-by-character comparison to avoid hash collisions.

- Report the match if confirmed.

### 🔸 Algorithm (Steps)

1. Precompute hash of pattern P.

2. Precompute hash of first window of text T[0..m-1].

3. Slide window from i=0 to n-m:

4. If hashes match, check characters one by one.

5. Update hash for next window using rolling hash.

6. Return indices where match is found.

### 🔸 Time Complexity

- Average case: O(n + m) (fast because of hashing)

- Worst case: O(n·m) 
(when many hash collisions happen, e.g., all characters same)

Space: O(1)

```c++
#define d 256 // number of characters in input

void rabinKarp(string T, string P, int q) {
    int n = T.size();
    int m = P.size();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // The value of h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and first window
    for (i = 0; i < m; i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    // Slide the pattern over text
    for (i = 0; i <= n - m; i++) {
        // If hash values match, check characters
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (T[i + j] != P[j]) break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << "\n";
        }

        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - T[i] * h) + T[i + m]) % q;
            if (t < 0) t += q; // ensure positive
        }
    }
}
```


### Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();  int n  = needle.size();
        int q = 101;

        int hashN = 0 ;
        int hashH = 0 ;
        int mult = 26 ;
        int minuser = 1;
        for(int i=0;i<n;i++){
            hashN=((hashN*mult + (needle[i]-'a'))%q);
            hashH=((hashH*mult + (haystack[i]-'a'))%q);
            if(i>0) minuser = (minuser*26)%q;
        }

        for(int i=0;i<=m-n;i++){
            if(hashN==hashH && haystack[i]==needle[0]){
                int j=1;
                for(;j<n;j++){
                    if(needle[j]!=haystack[i+j]) break;
                }
                if(j==n) return i;
            }

            if(i<m-n){
            hashH= ((mult*(hashH-(minuser*(haystack[i]-'a'))))+(haystack[i+n]-'a'))%q;
            if(hashH<0) hashH+=q;
            }
        }

        return -1;    
    }
};
```