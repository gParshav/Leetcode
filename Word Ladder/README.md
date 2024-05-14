We are solving it in the BFS way.

Steps:
1. We need a set and a queue. Set for checking if we have already been to a word in our BFS or no.
2. So start with putting the beginWord in the queue, and then pop the last word of the queue. Do this until the queue is empty.
3. Everytime you pop something out of the queue, you get two peices of information, one is the word you are at, and secondly how    many conversions you have done until them.
4. So from the last word you have, you try all the possible words you can get to by changing one single character, and basically you are doing a BFS in this way.
5. When you get to the endWord, simply return the number of steps it took to get there.
