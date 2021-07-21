class Solution {
public:
string longestPalindrome(string s) {
    string s_copy = s;
    if (s.length() == 1) return s;//no need to check

    vector<int> resTbl(s.length(), 1);//index means position of start, value means length
    //NOTE: a character itself is a palindrome of size 1

    for (auto it = s.begin(); it != s.end(); it++)
        *it = tolower(*it);//convert to lower case for case consistency

    string result, evenStr, oddStr;

    for (int i = 0; i < s.length(); i++) {
        //even check
        int left = i;
        int right = i + 2;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        evenStr = s_copy.substr(left + 1, right - left - 1);

        //odd check
        left = i;
        right = i + 1;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        oddStr = s_copy.substr(left + 1, right - left - 1);

        if (result.length() < evenStr.length()) result = evenStr;
        if (result.length() < oddStr.length()) result = oddStr;
    }

    return result;
}
};