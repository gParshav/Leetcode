The solution 1 in the code.cpp file doesn't work because, I was adding the element to the queue every time I get a distance equal to or less than the best distance. 
As far as I understand, the thinking is pretty correct. But its definitely not the most efficient way in terms of time complexity to solve the problem.
You can't keep adding the vertice to the priority queue every single time.

Steps:
1. Use a ways array that indicates the total number of routes to a particular node such that it takes the minimum distance.
2. ways[n-1] is your answer.
3. How do you compute the ways?
 - Everytime you reach at a node, there are two possibilities:-
    - You found the new minimum distance. Pass it to the queue, and ways[current] = ways[from]
    - The current_distance is equal to the minimum distance you already have. Don't push it to the queue. ways[current] += ways[from]. 