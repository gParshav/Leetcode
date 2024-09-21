Whenever you are trying to count ways to do anything via recursion/dp, simple thing to remember is to always return 1 in the base case where the base condition is fulfilled.

Also if you have recursions such as,

l = f();
r = f();
Your final answer will always be the sum of all these individual recursions, which is l+r in this case.

One important thing to understand and remember is that you always go one dimension lower while you go from tabulation to space optimization.

Its always just one dimension.

If you are using a 2D array in tabulation, you will use 1D array in space optimized solution.

If you are using a 1D array in tabulation, you will use simple variables in the space optimized solution.