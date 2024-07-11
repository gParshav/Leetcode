Brute Force:
For all the elements, iterate through the entire array to check its count. If > n/2, return. We will have two for loops.
Time Complexity - O(N^2)
Space Complexity - O(1)

Better:
Sort the array. Find the element at arr[n/2]. If a majority element exists, it will be this element. So now, find the number of times this element is occuring in the array. If > n/2, return this element.
Time Complexity - O(N*logn) + O(N) = O(N*logN) 
Space Complexity - O(N)

Even Better:
Use hashing. Key is the element, value is the number of times it is occuring. FIrst fill the hashmap. Then, iterate through the map, and check if any element occurs more than n/2 times. If yes, return that element.
Time Complexity - O(N)+O(N) = O(N) 
Space Complexity - O(N)

Optimal:(Moore's voting algorithm)
- You have to maintain two variables throughout. Count and element.
Basically, everytime the count is zero, you need to update the element, and if the count is already something > 0, and you iterate through a number other than the element, you decrease the count. If it is the same element again you increase the count.
After getting the majority element, just check again the count of that element in the array, and if it is > n/2, return.
We have to do check again, because in some cases, we can have with us an element which is not the majority element, after the initial majority element is cancelled. Example - [1, 1, 2, ,2, 3]. We will have three with us at the end.
Also note that if its given that we have a majority element for sure, we will directly get the answer with this algorithm. You don't need to check again.
Time Complexity - O(N)
Space Complexity - O(1)

Note:
sort(arr.begin(), arr.end())

Time Complexity - O(N*logN)
Space Complexity - O(N)

The space complexity is O(N) because the sort function uses merge sort which uses a temporary array of total size equal to n inorder to sort elements.