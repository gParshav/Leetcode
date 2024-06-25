For finding the 2nd Largest integer in O(N) keep two possibilities in mind:
Every integer you encounter in the array falls in these three categories:
1. Greater than m1(Largest Integer)
2. Greater than m2(2nd Largest Integer) but less than m1
3. Lesser than both

In 1, we update m1 to be that integer, and m2 to be the old m1.
In 2, we update m2 to be that integer.
We just ignore 3.