class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++) {
            int a = i, b = n - i;
            string sa = to_string(a), sb = to_string(b);
            if(sa.find('0') == string::npos && sb.find('0') == string::npos)
                return {a, b};
        }
        return {};
    }
};
