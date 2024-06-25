Leetcode 733

Problem Link - https://leetcode.com/problems/flood-fill/
This is a plain, simple BFS problem.

Steps:
1. Make a queue, and to start, push the element given in the input into the queue.
2. Push all the neighbours, after popping elements from the queue and keep changing them to the new colour.
3. DO this until the queue is empty, and then return the matrix with the new colour.

Super easy and plain vanilla BFS.