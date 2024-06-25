Leetcode 547

Problem Link - https://leetcode.com/problems/number-of-provinces/

This is a proper DFS problem.

This involves finding the number of connected compnents in a graph, and can most probably only be solved by a DFS.

Steps:
1. DO everything exactly same as what you did for DFS.
2. Only understand that everytime the code goes inside the for loop in the main function, its a new unconnected component.
3. So do ans++, everytime that happens.