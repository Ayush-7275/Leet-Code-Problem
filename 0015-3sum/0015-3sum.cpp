class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int l, int r, int target) {
        vector<vector<int>> duplets{};

        while (l < r) {
            int sum{nums[l] + nums[r]};

            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                duplets.push_back({l, r});

                int leftValue{nums[l]};
                int rightValue{nums[r]};

                while (l < r && nums[l] == leftValue) {
                    l++;
                }

                while (l < r && nums[r] == rightValue) {
                    r--;
                }
            }
        }

        return duplets;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int size{static_cast<int>(nums.size())};
        vector<vector<int>> result{};

        for (int i{0}; i < size - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int required_num{-nums[i]};

            int l{i + 1};
            int r{size - 1};

            vector<vector<int>> duplets{twoSum(nums, l, r, required_num)};

            for (const auto& duplet : duplets) {
                result.push_back({nums[i], nums[duplet[0]], nums[duplet[1]]});
            }
        }

        return result;
    }
};