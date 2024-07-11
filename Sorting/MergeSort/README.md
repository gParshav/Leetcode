Time Complexity: O(nlogn)
Space Complexity: O(n)

Quite interesting. 
If we have an array, the idea is to break into two parts, sort both of them and then merge both the sorted parts.
It simply uses recursion to do all of this.

One interesting thing is that while we divide the array into two, at no point do we actually make two seperate arrays. We just break it imaginarily with the help of index pointers. So we define that the first imaginary array is arr[start] to arr[mid], and the second imaginary array is from arr[mid] to arr[end]. 

While merging two sorted arrays, we use a temporary data structure(array, vector or whatever) to temporarily hold the elements in a sorted way. Mind you, we were trying to sort the elements from arr[start] to arr[end], so we finally push all those elements from temp to arr. That temp array makes up the space complexity;