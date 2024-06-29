What does it mean to rotate an array by K positions?

Array - [1, 2, 3, 4, 5], k = 2

Left Rotate:- (Offset every element to the left by 2 places. If an element goes before index 0 in this process, take it to the back.)

[3, 4, 5, 1, 2]

Right Rotate:- (Offset every element to the right by 2 places. If an element goes after index n-1 in this process, take it to the front.)

[4, 5, 1, 2, 3]


Brute Force - 
- You know, the elements that have be taken to the other side of the array. Either front->back or back->front.(These are the ones that are going either before 0 or after n-1, upon shifting/offsetting them.) Push all of them into a seperate array.
- Offset all the others either to the left or to the right. Whatever the question is.
- Put all the elements from the temp array to our actual array, wherever they are supposed to be. Either the front or the back.

Slightly better version:
- Put all the elements of our array into a seperate array.
- Then, do this for all n elements - nums[i] = temp[(n+i-k) % n];

Both the above methods take O(n) Time Complexity and O(n) Space Complexity.

The optimal case doesn't use any additional memory.
Optimal:

 - Reverse the entire array
 - Then reverse the first half and the second half according to the k.

# Rotate Array Explanation

Here is the diagram explaining the rotation of the array:

<img src="https://github.com/gParshav/Leetcode/blob/main/Images/Rotate%20Array.jpeg" alt="Rotate Array" height="400">

        
