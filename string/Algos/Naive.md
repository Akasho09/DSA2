

# 1. String Matching / Pattern Searching Algorithms

## Naïve Pattern Searching (O(n·m))
The simplest algorithm to find whether a pattern P of length m exists in a text T of length n.

### 🔸 Idea

- Try all possible alignments of P in T.

- For each shift, check character by character if P matches the substring of T.

### 🔸 Algorithm (Steps)

1. Loop i from 0 to n - m
(i.e., check every possible substring of length m in T).

2. For each i, compare substring T[i … i+m-1] with P[0 … m-1].

3. If all characters match → pattern found.

Otherwise, move to next i.

### PseudoCode
NaivePatternSearch(T, P):
    n = length(T)
    m = length(P)
    for i from 0 to n - m:
        for j from 0 to m - 1:
            if T[i + j] != P[j]:
                break
        if j == m:   // all chars matched
            print "Pattern found at index", i

### 🔸 Time Complexity

1. Worst case: O(n * m)
(Example: T = "AAAAAAAAA", P = "AAAAB")
- when all chars are same or only last is diff.

2. Best case: O(n)
(Pattern mismatches early each time)
- thats first char never matches the text .
(Example: T = "ABCDEFGHI", P = "JABC")

- Space complexity: O(1)

```c++
void naiveSearch(string T, string P) {
    int n = T.size(), m = P.size();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (T[i + j] != P[j]) break;
        }
        if (j == m) cout << "Pattern found at index " << i << "\n";
    }
}
```

