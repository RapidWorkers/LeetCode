class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                    case '(':
                    case '{':
                    case '[':
                    brackets.push(s[i]);
                    break;
                    case ')':
                    if(brackets.empty()) return false;//empty
                    if(brackets.top() != '(') return false;//last bracket incorrect
                    brackets.pop();
                    break;
                    case '}':
                    if(brackets.empty()) return false;//empty
                    if(brackets.top() != '{') return false;//last bracket incorrect
                    brackets.pop();
                    break;
                    case ']':
                    if(brackets.empty()) return false;//empty
                    if(brackets.top() != '[') return false;//last bracket incorrect
                    brackets.pop();
                    break;
            }
        }
        
        if(brackets.empty()) return true;
        else return false;
        
    }
};