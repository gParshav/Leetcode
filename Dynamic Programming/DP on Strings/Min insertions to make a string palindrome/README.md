You can make any string in this world a palindrome by simply attaching the reverse of that string to that string. 
Thats sort of the most brute force way to convert any string into a palindrome.

s+reverse(s) will always be a palindrome.

So the most number of insertions to convert a string into a palindrome is the size of that string.

Non DP way:(Later found out this is BS)
Find out the number of elements that are occuring odd number of times.(say n)
Ans is n-1, unless n == 0 or n == size of the string


DP way to do this:
If you think about it - you have to insert all those elements which are not a part of the longest palindromic subsequence in the string.
For ex - If the string is - abcaa, the longest palindromic subsequence is aba, aca, aaa. In any case, you will have to add the other two (5-3) elements to make it a palindrome.