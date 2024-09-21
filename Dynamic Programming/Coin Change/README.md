Start with understanding why greedy fails.
This Test Case will help understand.
coins = [9,6,5,1], target = 11

Again messed up the base function.
Had written this, 
if(amt==0){
    return 0;
}

if(i==0){
    if(coins[i]==amt){
        return 0;(This is very clearly wrong because you can take coins[0] more than once)
    }

    else{
        return 1e9;
    }
}


This is the correct one.(This makes it hard to convert it to tabulation)
if(i<0){
    if(amt==0){
        return 0;
    }

    return 1e9;
}




