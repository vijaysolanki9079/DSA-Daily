class Solution {
public:
    string multiply(string num1, string num2) {
        /*  -------1 -------*/
        // int a = stoi(num1), b = stoi(num2);
        // string result = to_string(a*b);
        // return result;

        /* ------ 2 -------------*/
        // long long a = stoll(num1), b = stoll(num2);
        // long long product = a * b;
        // return to_string(product);

        /* ----- 3 -------*/
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);

        // Reverse iteration for multipli..
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert vector -> string
        string ans;
        for (int num : result) {
            if (!(ans.empty() && num == 0)) ans.push_back(num + '0');
        }
        return ans.empty() ? "0" : ans;
    }
};