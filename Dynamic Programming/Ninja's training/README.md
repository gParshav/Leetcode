Main takeaway was head recursion vs tail recursion.

Always prefer tail recursion, head recursion is dangerous and can cause stack overflows if you are dealing with big test cases.

Head Recursion: f() + x;
Tail Recursion: x+f();

Always follow tail recursion.