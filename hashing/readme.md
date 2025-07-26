## Hashing 
is a technique used to map data to a fixed-size value (hash code), usually for fast access and lookup in data structures like hash tables.

- synatx: unordered_map<KeyType, ValueType> mapName;

- 🧠 Basic operations: insert, access, delete ( student.erase(101);  )

Operation	            Time Complexity
Insert an element	        O(log n)
Delete an element by key	O(log n)
Access element by key	    O(log n)
Find an element by key      O(log n)
Update element by key	    O(log n)
Traverse the map	        O(n)


## SET
In C++, set is a container from the Standard Template Library (STL) that stores unique elements in sorted order. It is implemented as a self-balancing binary search tree (typically a Red-Black Tree), so insertions, deletions, and lookups take `O(log n)` time.

```python

🧠 Understanding: unordered_set<int> stores integers using a hash table
Think of it like this:

You insert a number, say 42, into an unordered_set<int>.

Internally, C++ computes a hash value of 42, which maps it to a bucket (a place in memory to store it).

When you do s.find(42), it uses the same hash function to quickly go to the bucket and look for the value.

````

