In some cases, where base cases have index<0, its slightly challenging to convert it into tabulation.

In these cases, include an extra row and a column, for empty test cases. 

if(i<0){
    
}

This is the base case in the recursion.(imagine i is a index string)
Its literal translation, in the tabulation is the case where that string is empty.
vector<vector<long long>> dp(n1+1, vector<long long>(n2+1, 0)); -> This is how you will initialize the dp array.
0 indexes in the dp array, means when the string is empty.

That's how you solve the problem and convert memoization into tabulation.(When bases cases are index<0)

For index=0, you can normally convert it into tabulation as we have been doing all along.