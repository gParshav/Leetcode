The problem is that we need to return all the permutations of an array.
Need not be sorted. Need not be unique.

We use a visited array for the same.
They call this backtracking(I don't know what exactly it means).
Idea is that we iterate through all the possibilities.
We always pass addresses to arrays(variables) and not an entirely new array. We basically keep moving with the same array always.
keep making changes, until the boundary condition.

general pattern:
Make Changes
Call Function
Undo Changes


For this, we use a visited array.
We are trying to find all the possible permutations for an array.
So, at every step, we pick one element. visited[element] = 1;
Now, we pick the next available element. For this, always iterate the entire array from i = 0, and pick up the first available element.
After this, undo the changes and repeat.


                                               [                        ]
                                            /               |                          \
                                         [1]               [2]                        [3]
                                    /      \              /     \                    /       \
                                [1, 2]     [1, 3]       [2, 1]   [2, 3]           [3, 1]     [3, 2]
                                /             |          /           \              /          \ 
                          [1, 2, 3]        [1, 3, 2]    [2, 1, 3]    [2, 3, 1]    [3, 1, 2]   [3, 2, 1]