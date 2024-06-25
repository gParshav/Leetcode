We basically have to try all possibilities and then keep whatever matches our condition.
Only thing is when you literally backtrack in the recursion tree, just reverse all the changes you made in that step, so that you can go to the next step properly.

<!-- if(isValid(newx, newy, n) && m[newx][newy] == 1 && vis[newx][newy]== 0){
                char k = dir[i];
                temp.push_back(k);
                vis[newx][newy] = 1;
                f(newx, newy, n, temp, m, ans, vis);
                vis[newx][newy] = 0;
                temp.pop_back();
            }
         -->
         
See and understand how the changes are undone. We pass all the arrays recursively through the address. So we are passing the same thing everywhere. It is really important to undo the changes we made to check a particular case.