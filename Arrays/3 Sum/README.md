Brute Force:
Iterate through all the triplets, check the sum for all of them, if the sum is zero, sort it and push them into a set. Empty the set and push everything into the answer array. We are using sets because only need all the unique once.
Time Complexity: O(N^3)
Space Complexity: O(1)

Better:
Firstly in this we will have two pointers, i and j(starts from i+1). These will form 2 out of 3 elements in the triplet. FOr the third element, we will use the map. So, we will push all elements between i and j into the map, and check if we have the third element such that nums[i]+nums[j]+nums[k] == 0.
Time Complexity: O(N^2)
Space Complexity: O(N)

Optimal:
We use three pointers, i, j and k. All of these form an element in the triplet. 
Really simple and intuitive, now that I think about it. We start i with 0 index, j at i+1 and k and n-1. We have fixed i, and we will now iterate j and k inside that sorted window. Our triplet is nums[i], nums[j], nums[k]. We will check the sum, and accordingly move j and k. If sum>target, we do k--, if sum<target, we do j++. We iterate now for i=0 to n-3, and j=i+1 until n-2, and k can at max be n-1.
Time Complexity: O(N^2)
Space Complexity: O(1)