Brute Force:
We simply try out all the quads. We push all the quads matching our target to the answer array. That's it. Iterate over everything.
Time Complexity: O(N^4)
Space Complexity: O(1)

Better:
We use hashing. We keep three pointers, i, j and k. i starts from 0, j starts from i+1, and k starts from i+2. These are our 3 elements. Our forth element is between j and k. We put all the elements between j and k into a map while we are iterating, and check if the required 4th element is in the hashmap. If yes, we have a quad. We push it into the answer array.
Time Complexity: O(N^3)
Space Complexity: O(N)

Optimal: 
We try to eliminate the hashmap, by sorting the array, and using 4 pointers, a, b, c and d. a starts from 0, b from a+1, c from a+2 and d from n-1. So now we fix a and b as we iterate and our window is from c to d. Sorting really makes our life easy. Our tempSum is now nums[a]+nums[b]+nums[c]+nums[d]. If this tempSum>target, we do d-- or else c++. We iterate the entire array and collect all the quads where the sum matches our target.
Time Complexity: O(N^3)
Space Complexity: O(1)