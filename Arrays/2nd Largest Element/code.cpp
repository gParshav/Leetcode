class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int m1 = -1;
	    int m2 = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>m1){
	            m2 = m1;
	            m1 = arr[i];
	        }
	        
	        else if(arr[i]>m2 && arr[i]<m1){
	            m2 = arr[i];
	        }
	    }
	    
	    return m2;
	}
};