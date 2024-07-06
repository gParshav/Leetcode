Brute Force:

Better:

Optimal:
Pretty hard to develop the intuition for solving this in O(N).
We need to find the next permutation.
In simple sense, since its an array, we need to find the next number which is just greater than the number we currently have. 
Just greater. 
For that there are several steps and an order in which you need to think. 
Firstly, we need to maintain a prefix that is as long as possible, to find the exact next permutation.

Take this for an example - 25718

25781 and 25817 both of them are greater than 25718. But the immediate greater number which is 25781 happens to have the first 3 numbers same, and 25817 has just 2 of them same(2 and 5).

So lesson No 1 is that, we want as many prefixes same as possible to find the next permutation(Higher the better).

Now, only question is how do you know, exactly how many number of prefixes are to be kept the same, to have the next permutation?
 - Find the pivot.
 
When you find the first element, that is lesser than the previous element. You have found the pivot.
In 25718, that is 1. Therefore, everything before 1 will be kept as it is. (257)

Next step is to swap those two elements.(1 and 8 in this case) Swap the first smaller next element you got with the least greater element thats on the right. For this iterate the entire array on the right, and swap the element that is greater but closest to 1 or whatever the first smaller element we found was.

After this sort all the remaining elements.

Steps:
1. Find the number of prefixes you can keep the same.
2. Swap those two elements.(First smaller element and the least greater element on the entire right side).
3. Sort all the other elements. 
Done
