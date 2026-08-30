class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr = "";
        string res = "";

        path += '/';

        for (char c : path) {
            if (c == '/') {
                if (curr == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else if (curr != "" && curr != ".") {
                    st.push(curr);
                }

                curr = "";
            }
            else {
                curr += c;
            }
        }

        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        return res.empty() ? "/" : res;
    }
};