We have two ways to solve this:
1. Use Sets
2. Two pointers approach

1. Use sets
 - Since we need to remove duplicates, using sets is the most obvious way to do it.
 - We push all elements into the set, and it will only take the unique elements.
 - You simply need to pop all of them and assign them to the array starting from the 0th index.

 Time Complexity - Pushing all elements in the set = n*logn
                 - Iterating the set = n
                 Total = n+n*logn
 Space Complexity - n
                 
2. Two pointers approach
 - In this, we use to pointers. One starts from 0(i) and the next from 1(j).
 Two cases:
  - Both of them have equal values.
    Simply increase j and do nothing else.
  - Both have different values.
    First increase i.
    num[i] = num[j];
    Increase j
Time Complexity = n
Space Complexity = None(No extra space used)