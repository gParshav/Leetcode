Leetcode 994

Problem Link - https://leetcode.com/problems/rotting-oranges/

This is a proper BFS problem.

Steps:
1. Push all the rotten oranges to a queue.
2. Iterate the elements of the queue until empty. 
3. At every step you need to pop all the existing elements in the queue, and then push the neighbouring fresh elements.
4. At all these steps, increment the counter, and then once the queue is empty, return the counter.