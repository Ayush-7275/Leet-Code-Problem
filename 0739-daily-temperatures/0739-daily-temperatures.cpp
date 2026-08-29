class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int> result(temperatures.size(),0);// 0 default value since we want to have 0 for the end values

        for(int i = 0 ; i< temperatures.size() ; i++){
            //st.top() -> (temp , index)
            while (!st.empty() && st.top().first < temperatures[i]) {
                result[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }

        return result;
    }
};