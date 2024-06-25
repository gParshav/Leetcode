This is in itself a normal BFS problem. But is just slightly confusing and interesting.

Notes:
1. Firstly, a slight insight. Assume we have a BFS problem with a 2D matrix.(This may work with others too but not sure). So now, whenever you feel that answers to certain indexes are confirmed in O(1) time according to the question and without any major computation, those are the elements to be pushed into the queue. 
This is interesting as quite a few times we may be confused and may not clearly understand whats to be pushed in the queue. That happened in this question initially. I was not understanding if I have to push the 0's or the 1's.
But then by the above logic and also by basic intuition, its easy to understand that we have to push the 0's.

2. Alright now, another interesting thing. In BFS problems, like this one we don't always need a visited array. Our answer array initialized with -1's can do the job of the visited array.


Steps:
1. First initialize the queue and push all indices which are 0.
2. Now pop all the elements one by one until the queue is empty. So now, all the zeroes are visited, you can understand that either by the visited array or the answer array. You push the elements to the queue that you are visiting for the first time. And all these elements are essentially non zero, so in the answer array set their answer to +1 from wherever they are coming from.
3. That's it. Problem Solved.