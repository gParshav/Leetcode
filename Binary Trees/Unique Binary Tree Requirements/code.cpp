class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        if(a+b==3 || a+b==5){
            return true;
        }
        
        return false;
    }
};