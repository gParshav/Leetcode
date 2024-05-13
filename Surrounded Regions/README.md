Leetcode 130

Problem Link - https://leetcode.com/problems/surrounded-regions/description/

In a matrix of dimensions m*n, there are m rows and n columns.

So generally, in 2D matrices, 
num_rows = matrix.size();
num_columns = matrix[0].size();

You can solve this problem by BFS and by DFS.

Notes:
1. The crux of this problem is the O's on the borders will always stay O's. And all the zeroes that are directly connected to the border zeroes will also stay O's. All others will be 'X'.

2. The insight we found during the previous problems can also be applied over here. We for sure know that all the O's on the border will stay O's. So therefore, those are the ones we push into the queue if we are doing a BFS. Or those are the source vertices we call if we are doing a DFS.

3. Now read point 1 again and you can solve this problem either by basic BFS or DFS.

4. Also, I have used an answer array to temporarily store 1's and -1's and to understand which O's will be converted to X's finally. We can actually skip that and only use the visited array to understand the same. If you look carefully, we are only visiting the border O's and O's directly connected to those. Therefore, we are only visiting the O's that are going to stay as O's. Thus all the visited elements will only be O's that are not going to change. We can use this information to alter the given matrix and form the answer matrix.