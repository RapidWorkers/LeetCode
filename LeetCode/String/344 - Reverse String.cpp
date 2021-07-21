class Solution {
public:
    void reverseString(vector<char>& s) {
        auto front = s.begin();
        auto back = s.end() -1;
        char tmp;
        
        while(front < back){
            tmp = *front;
            *front = *back;
            *back = tmp;
            front++; back--;
        }
    }
};
