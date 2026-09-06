class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged {""};
        int l1 {0} , l2 {0};
        while(l1 < word1.size() && l2 < word2.size()){
            merged += word1[l1];
            merged += word2[l2];

            l1++;
            l2++;
        }

        if(l1 == word1.size()){
            while(l2 < word2.size()){
                merged += word2[l2]; 
                l2++;
            }
        }else{
            while(l1 < word1.size()){
                merged += word1[l1]; 
                l1++;
            }
        }

        return merged;
    }
};