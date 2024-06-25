// Parameterized Recursion
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	void f(int i, int n, int arr[], int sum, int K, int &ans){
	   
	   if(sum>K){
	       return;
	   }  
	   if(i==n){
	       if(sum==K){
	           ans++;
	       }
	       
	       return;
	   }
	   
	   sum = sum+arr[i];
	   f(i+1, n, arr, sum, K, ans);
	   sum = sum-arr[i];
	   f(i+1, n, arr, sum, K, ans);
	   
	       
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int ans = 0;
        f(0, n, arr, 0, sum, ans);
        int MOD = 1e9+7;
        return ans%MOD;
        
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
// Functional Recursion

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int f(int i, int n, int arr[], int sum, int K, int &ans){
	    
	   if(i==n){
	       if(sum==K){
	           return 1;
	       }
	       
	       return 0;
	   }
	   
	   return f(i+1, n, arr, sum+arr[i], K, ans) + f(i+1, n, arr, sum, K, ans);
	   
	       
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int ans = f(0, n, arr, 0, sum, ans);
        int MOD = 1e9+7;
        return ans%MOD;
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends