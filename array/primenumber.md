## Here’s the logic breakdown:
1. Handle special cases: 0, 1, and 2.
2. Check divisibility by 2 and 3.
3. Then check from 5 to √n, only for numbers of the form 6k ± 1, since all primes > 3 can be represented this way.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

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
```

## Closest Prime nums in Range vs Count ?
