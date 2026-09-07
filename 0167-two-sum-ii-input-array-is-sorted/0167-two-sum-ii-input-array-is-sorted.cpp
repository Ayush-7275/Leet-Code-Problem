class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l {0}, r {static_cast<int>(numbers.size()) - 1};
        vector<int> result;
        result.reserve(2);

        while(l < r){
            int sum {numbers[l] + numbers[r]};
            if(sum < target){
                l++;
            }else if(sum > target){
                r--;
            }else{
                result.emplace_back(l+1);
                result.emplace_back(r+1);
                break;
            }
        }

        return result;
    }
};