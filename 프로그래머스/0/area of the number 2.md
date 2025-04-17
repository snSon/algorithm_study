# area of the number 2
## a problem that finds the leftmost and rightmost of the number 2 in an array.

### solution 1.
Execute the loops for left and right search independently and break if the condition is true.
best case : O(1)
worst case : O(2n)
average : O(n/4)

### solution 2.
Execute a loop, update letfmost at only once and update rightmost on every iteration.
best case : O(n)
worst case : O(n)
average : O(n)

---
In conclustion, solution 1 generally shows better performance.
