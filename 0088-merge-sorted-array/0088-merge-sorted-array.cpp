class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy {nums1};
        int l1 {0} , l2{0} ,l3 {0};//l1->nums1_copy,l2->nums2,l3->nums1

        while(l1 < m && l2 < n){
            if(nums1_copy[l1] < nums2[l2]){ 
                nums1[l3] = nums1_copy[l1];
                l1++;
            }else{ 
                nums1[l3] = nums2[l2];
                l2++;
            }
            l3++; 
        }

        if(l1 == m){
            while(l2 < n){
                nums1[l3] = nums2[l2];
                l2++;
                l3++;
            }
        }else{
            while(l1 < m){
                nums1[l3] = nums1_copy[l1];
                l1++;
                l3++;
            }
        }
    }
};