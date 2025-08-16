
## 🔹 KMP Algorithm (Knuth-Morris-Pratt)

Naïve approach takes O(n·m) in the worst case.
KMP reduces it to O(n + m).

### 🔸 Idea
- When a mismatch happens, instead of shifting pattern by 1, we use information from previous matches to skip unnecessary checks.

- Precompute an array called LPS (Longest Prefix Suffix) for the pattern.

- Use LPS to avoid re-checking characters that we know will match.

### 🔸 LPS (Longest Prefix Suffix) Array

For each index i in pattern, lps[i] = length of the longest proper prefix of pattern[0..i] which is also a suffix.

### 🔸 Steps

1. Preprocess pattern → compute lps[] in O(m).

Search in text:
Traverse T with two pointers (i for text, j for pattern).
If T[i] == P[j], move both forward.
If mismatch:
If j > 0, set j = lps[j-1] (skip comparisons).
Else, move i++.

### 🔸 Complexity

Preprocessing: O(m)

Search: O(n)

Total: O(n + m)

Space: O(m)