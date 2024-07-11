Since you have to count the number of pairs, in the present state of the array, you can't first sort and do something to find out the answer. This is something that applies to all the questions. 
In this case, the best way to solve it is to find the answer while sorting the array. 

Brute Force:
Simply iterate through all the pairs in the array. If nums[i]>nums[j], cnt++. Return cnt.
Time Complexity: O(N^2)
Space Complexity: O(1)

Optimal Case:
We use the mergesort technique to effectively count inversions and reduce time complexity. If you carefully look at the merge function, we have two sorted arrays, and we check if nums[i]>nums[j] or not. We do this to merge them in a sorted fashion. We can simply put a counter variable at this step and return that at the end. At this, step we have twp sorted arrays, and two pointers say i and j. If nums[i]>nums[j](Inversion!), it is very easy to understand that all elements from i to mid will be > nums[j], so we do cnt+=mid-i+1. 
I - cnt+=mergeSort(arr, start, mid);
II - cnt+=mergeSort(arr, mid+1, end);
III - cnt+=merge(arr, start, mid, end);
return cnt;

This was slightly confusing at first, but then understood it clearly by dry running it. 
I and II sorts an unsorted array. III merges two sorted arrays. We can have exclusive inversions in all of them. That's why we increment the cnt variable in such a way. 

Btw, we can also keep one global cnt variable and just increment that all the time inside the merge function. That also works.

Time Complexity: O(N*logN)
Space Complexity: O(1)

