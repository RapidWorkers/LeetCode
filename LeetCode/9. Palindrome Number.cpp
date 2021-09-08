class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;//neg always not palindrome
        if (!x) return true;
        
        vector<int> nArr;
        while(x > 0)
        {
            nArr.push_back(x % 10);
            x /= 10;
        }
        
        auto fr = nArr.begin();
        auto bk = nArr.end() - 1;
        
        while(fr < bk)
        {
            //cout << "Cmp a : " << *fr << " b : " << *bk << endl;
            if(*fr != *bk) return false;
            fr++;bk--;
        }
        
        return true;
    }
};
