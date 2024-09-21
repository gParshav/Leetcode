Shortest common supersequence

What's a supersequence of two strings?

A string having both the given strings as a subsequence. 

What's the shortest length a supersequence can have in any case?
 - Max(n1, n2)

What's the longest length a supersequence can have in any case?
 - n1+n2


What's the length of the shortest common subsequence between two strings?

 - n1+n2-LCS(It will basically contain everything that s1 and s2 has but with subtracting the LCS once, cause it has been added twice)
 
 
I understood all this, but how to actually print the string was a challenge.
- You have to traverse the LCS matrix in a particular way to get the shortest supersequence.