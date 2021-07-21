class Solution {
public:
    bool isPalindrome(string s) {
    string stripped;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (!isalnum(*it)) continue;
        stripped += tolower(*it);
    }

    auto front = stripped.begin();
    auto back = stripped.end() - 1;

    while (front <= back) {
        if (*front != *back) return false;
        front++; back--;
    }

    return true;
    }
};
