class Solution {
public:
    string multiply(string num1, string num2) {
        /*  -------1 -------*/
        int a = stoi(num1), b = stoi(num2);
        string result = to_string(a*b);
        return result;

        /* ------ 2 -------------*/
        // long long a = stoll(num1), b = stoll(num2);
        // long long product = a * b;
        // return to_string(product);
    }
};