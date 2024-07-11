class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> ans;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }

            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }
        
        nums1 = ans;

    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=0, j=0;
        while(i<m && j<n){

            if(nums1[i]<=nums2[j]){
                i++;
            }

            else{
                int temp = nums2[j];
                nums2[j] = nums1[i];
                nums1[i] = temp;
                i++;
                int k = j;
                while(k+1<n && nums2[k]>nums2[k+1]){
                    int temp = nums2[k+1];
                    nums2[k+1] = nums2[k];
                    nums2[k] = temp;
                    k++;
                }

                // sort(nums2.begin(), nums2.end());
            }

        }

        while(j<n){
            nums1[i] = nums2[j];
            i++;
            j++;
        }
        

        return;
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int l = m-1;
        int r = 0;
        while(l>=0 && r<n){
            if(nums1[l]>nums2[r]){
                int temp = nums1[l];
                nums1[l] = nums2[r];
                nums2[r] = temp;
                l--;
                r++;
            }

            else{
                break;
            }
        }

        sort(nums1.begin(), nums1.begin()+m);
        sort(nums2.begin(), nums2.end());
        int j = 0, i = m;
        while(j<n){
            nums1[i] = nums2[j];
            i++;
            j++;
        }

    }
};