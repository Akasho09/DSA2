

## istringstream = input string stream

std::istringstream is a class from the <sstream> header that allows you to treat a string like a stream — just like reading from cin.

### ✅ Purpose:
It helps you extract individual words or tokens from a string, automatically skipping over any whitespace.
 

## String find() in C++
- 
s.find(sub, pos);            // For substring
s.find(sub, pos, n);        // For n character of sub
s.find(c, pos);                 // For character
- Parameters
s: String which is to be searched.
sub: Substring to search. Can be C++ or C style string.
pos: Position from where the string search is to begin. By default, it is 0.
n: Number of characters to match.

| Case         | Complexity |
| ------------ | ---------- |
| Best case    | O(1)       |
| Average case | O(n)       |
| Worst case   | O(n²)      |


// ALGOS 
🔹 1. String Matching / Pattern Searching Algorithms

Used to find if a pattern exists inside a text.

Naïve Pattern Searching – O(n·m)

Rabin-Karp Algorithm – Uses hashing, O(n + m) average

Knuth-Morris-Pratt (KMP) Algorithm – Prefix function (LPS array), O(n + m)

Boyer-Moore Algorithm – Uses bad character & good suffix heuristics, O(n/m)

Z-Algorithm – Pattern matching using Z-array, O(n + m)

Finite Automata Pattern Matching – Preprocessing pattern into automaton