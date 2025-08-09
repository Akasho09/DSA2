## 🧠 What is XOR?
XOR stands for exclusive OR.

### 🔢 Truth Table of XOR

| A | B | A ^ B |
| - | - | ----- |
| 0 | 0 | 0     |
| 0 | 1 | 1     |
| 1 | 0 | 1     |
| 1 | 1 | 0     |


### Conclusion:
- Result is 1 only if the two bits are different.
- Think of it as: true if exactly one is true.

### 🛠️ Common Use Cases of XOR
1. ✅ Swap Two Numbers Without Temp Variable
```c
a = a ^ b;
b = a ^ b; // now b = a
a = a ^ b; // now a = b
```

2. 🔍 Find the Single Number
In an array where every number appears twice except one:

3. ❓ Check if Two Numbers Have Opposite Signs
  return (x ^ y) < 0;
- XORing positive and negative numbers results in a negative number because their sign bits differ.

### ⚙️ Properties of XOR

- Identity: a ^ 0 = a

- Self-Inverse: a ^ a = 0

- Commutative: a ^ b = b ^ a

- Associative: a ^ (b ^ c) = (a ^ b) ^ c

- Useful Trick: a ^ b ^ a = b (because a ^ a = 0 and 0 ^ b = b)

- a^(a+1)=1

- num & -num = 
extracts the rightmost set bit (the least significant bit that is 1) in the binary representation of num.
```c
 num = 18  → binary:  10010
-num = -18 → binary: 01110 (2's complement)

  10010
& 01110
= 00010 → 2
```

- n & (n - 1) is a bit manipulation trick that removes the rightmost set bit from n.


- ans= ans | (1<<i); 
to set ith bit 