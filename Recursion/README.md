Recurusion trees are just a simple way to represent recursive function calls.

Lets understand backtracking vs recursion through a simple example.

Print 1 to N

1. Recursion:

    void f(){
        if(i>N){
            return;
        }
        
        print(i);
        f(i+1, N)
    }

    main(){
        f(1, N);
    }


2. Backtracking:

    void f(){
        if(i<1){
            return;
        }
        
        f(i-1, N);
        print(i);
        
    }

    main(){
        f(N, N);
    }

Two kinds of recursion:
1. Parameterized Recursion
2. Functional Recursion

In very simple terms, parameterized recursion is when our actual answer is contained as a parameter passed to the function.
In functional recursion the value returned by the function is essentially our answer.


Very important - The space complexity for all recursion trees is the height of the recursion tree.

One of the most important things in recursion:
 - The number of recursions in a function having multiple recursions, determines the number of branches attached to\
 every node in the recursion tree.
 
I classify recursion problems into two groups:
Level 0: 1 Dimensional Recursion - Only has one single option. Just keep going until you hit a wall and then return all the way back.
Level 1: 2 Dimensional Recursion - Doesn't have a for loop. Only has two options, take it or leave it.
Level 2: N Dimensional Recursions(More than 2 at every node) - Has a for loop



Basics:
- Every recursion call is a node in the recursion tree.
- The parameters passed in the recursion call are the parameters of that node in the recursion tree.
- The recursion calls inside the function correspond to all the nodes that will be connected to that node.(Branches coming out from that node).

15 done