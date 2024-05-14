Gives a TLE on leetcode, but this is the best I can do.
Passes 32/36 test cases.

Steps:-
It is definitely similar to the previous problem but just slightly more challenging. We need to make a few small changes.

Instead of the number of conversions we actually need all the conversions.

Changes:-
1. The queue consists of the entire array of words you have until now and not just the last word.
2. You only remove words from the set once you have traversed all the elements of a particular level.

Otherwise its almost the same.