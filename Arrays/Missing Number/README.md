Solutions:

1. Brute
    - Iterate a for loop from 0 to n. For every number, check whether or not it is present in the array. If not return it.
    Time Complexity - O(N^2)
    Space Complexity - O(1)
    
2. Better
    - Use a hash map to keep a counter for all the values in the array. Iterate for all values from 0 to n. Return the element that has a count of 0 in the map.
    Time Complexity - O(N)
    Space Complexity - O(N)
    
3. Optimal 1
    - Sum method. Find the sum of the first n elements - n(n+1)/2. Then find the sum of all elements in your array.
    Subtract the two. That's your answer.
    Time Complexity - O(N^)
    Space Complexity - O(1)
    
4. Optimal 2
    Find the xor of the first n elements. Find the xor of all elements in your array.
    Find the xor of both of those values. That's the answer.Bit more explaination below.
    Time Complexity - O(N)
    Space Complexity - O(1)
    
Why is Optimal 2 better than Optimal 1?
In a very extreme case, say N = 10^5. Our sum will store an integer having the size to an order of 10^10. That may not be storable in an integer, and will require long long int. Which will occupy slightly more space. Whereas, the max value a xor value can have is the number itself, which will be 10^5 in this case. Therefore, optimal 2 is better.


XOR operation:
1. a XOR a = 0
2. 0 XOR a = a
This will help us solve this problem in the best possible way.(Optimal 2)