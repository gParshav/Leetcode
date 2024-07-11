Brute Force:
Iterate across all the pairs, push the ones matching our condition into the answer array.
Time Complexity: O(N^2)
Space Complexity: O(1)

Optimal Case:
Its important to understand that the logic for count inversions can't exactly be applied here.
Lets try to understand the exact problem and why not.
We have two sorted arrays, and in the count inversion problem, we calculate the inversions while merging the two sorted arrays. One thing which helped us do that is the fact that in the left array, if nums[left]>nums[right], then all elements in the left array from the left ptr to the mid ptr will also be > nums[right]. With this understanding, we can do cnt+=mid-left+1, and then do right++. SO now the element on the right array is now gone. We can't do that in this case, it may happen that nums[left]<2*nums[right], but all the elements in the first array, on the right side of the left ptr are > nums[right], in this case we will lose the element on the current right pointer as we do right++, and push it into the temp array.
So basically, we will have to count it seperately, before we merge the two sorted arrays. Therefore, we write a seperate function to count the reverse pairs after we have sorted the two arrays and before we have merged them. 
Time Complexity: O(N*logN)
Space Complexity: O(N)

