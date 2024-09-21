Kind of DP on Strings:
1. Comparison
2. Replacement
3. Edit


What's the recursion Story?
If s[i]==t[j], ans = 1+f(i-1, j-1);

else, ans = max(f(i-1, j), f(i, j-1));

Basically, since its a subsequence, you have to simply take the character if s[i]==t[j], you don't have to worry if its consecutive as in the case of a substring.