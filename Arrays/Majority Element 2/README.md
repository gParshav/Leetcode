One nice thing to know is that the answer can't have more than 2 integers.

Brute Force:
Check the number of times every single element occurs, push all the elements having count>n/3 to the answer array
Time Complexity: O(N^2)
Space Complexity: O(1)

Better 1:
Use hashing. Store the count of every element in the map. Iterate the map, and check the counts. Push all the elements having count>n/3 to the answer array.
Time Complexity: O(N)
Space Complexity: O(N)

Better 2:
Sort the array. Use sliding window, to calculate counts. Once element changes, update the element and the count. Everytime while changing the element and the count, check the count. If its greater than n/3, push it into the answer array.
Time Complexity: O(N*logN)
Space Complexity: O(1)

Optimal:
Idea is taken from the moore voting algorithm used in the Majority Element Problem. We have cnt1, cnt2, ele1, ele2. The idea is almost the same, you do the same thing with 2 elements and 2 counters. At the end, you check manually.
Time Complexity: O(N)
Space Complexity: O(1)