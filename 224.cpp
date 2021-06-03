class Solution {
public:
    int calculate(string s) {
        stringstream ss(s);
        
        queue<pair<int, int>> terms;
        queue<pair<int, int>> fixed_terms; //<type, value>, 0 = num, 1 = not number

        stack<pair<int, int>> convert_stk;
        queue<pair<int, int>> postfix;

        stack<int> calculate_stk;

        char c;
        while (ss.get(c)) {
            if (c == ' ') continue;//스페이스 무시

            if (c >= '0' && c <= '9') {//숫자인 경우
                int num;
                ss.unget();
                ss >> num;
                terms.push(pair<int, int>(0, num));
            }
            else { //괄호, 연산기호의 경우
                terms.push(pair<int, int>(1, c));
            }
        }

        int prev = -1;//-1은 시작점, 0은 숫자, 1 = 여는 괄호, 2 = +-)
        while (!terms.empty()) {//부호 있는 수를 위해서 항 수정 필요
            auto current = terms.front();
            terms.pop();

            if((prev == -1 || prev == 1) && current.first == 1 && (current.second == '+' || current.second == '-')){//시작 시 부호가 있는 경우
                if (terms.front().first == 0) {//그 다음이 숫자인 경우
                    auto modified = terms.front();
                    terms.pop();
                    if (current.second == '-') modified.second = -modified.second;
                    fixed_terms.push(modified);
                    prev = 0;
                }
                else {//숫자 아니면 그냥 다시 집어넣기
                    fixed_terms.push(pair<int, int>(0, 0));
                    fixed_terms.push(current);
                    prev = 2;
                }
            }
            else if (current.first == 1 && (current.second == '+' || current.second == '-')) {//현재가 부호인 경우
                if (prev == 2) {//이전도 부호였던 경우
                    if (terms.front().first == 0) {//그 다음이 숫자인 경우
                        auto modified = terms.front();
                        terms.pop();
                        if (current.second == '-') modified.second = -modified.second;
                        fixed_terms.push(modified);
                        prev = 0;
                    }
                    else {//숫자 아니면 그냥 다시 집어넣기
                        fixed_terms.push(current);
                        prev = 2;
                    }
                }
                else {//그냥 집어넣기
                    fixed_terms.push(current);
                    prev = 2;
                }
            }
            else {//괄호/숫자
                fixed_terms.push(current);
                if (current.second == '(') prev = 1;
                else if (current.second == ')') prev = 0;
                else prev = 0;
            }
        }

        while (!fixed_terms.empty()) {
            auto current = fixed_terms.front();
            fixed_terms.pop();

            if (current.first == 0) {//숫자
                postfix.push(current);
            }
            else if (current.second == '(') {//여는 괄호는 스택에 무조건 들어감
                convert_stk.push(current);
            }
            else if (current.second == ')') {
                while (convert_stk.top().second != '(') {//여는 괄호 나올때 까지
                    postfix.push(convert_stk.top());
                    convert_stk.pop();
                }
                convert_stk.pop();//여는 괄호 pop 해버림
            }
            else {//다른 기호들
                if (convert_stk.empty()) convert_stk.push(current);//비어있으면 무조건 push
                else {
                    if (convert_stk.top().second == '(') {
                        convert_stk.push(current);//비어있으면 무조건 push
                    }
                    else {
                        //원래는 우선순위를 확인해야 하지만, 여기는 덧셈 뺄셈만 있어서 그냥 pop 후 push
                        postfix.push(convert_stk.top());
                        convert_stk.pop();
                        convert_stk.push(current);
                    }
                }
            }
        }

        while (convert_stk.size() != 0) {
            postfix.push(convert_stk.top());
            convert_stk.pop();
        }

        while (postfix.size() != 0) {
            auto current = postfix.front();
            postfix.pop();

            if (current.first == 0) {//number
                calculate_stk.push(current.second);
            }
            else {//operator

                //extract two operands
                int a = (int)calculate_stk.top();
                calculate_stk.pop();
                int b = (int)calculate_stk.top();
                calculate_stk.pop();
                int result;

                //calculate
                switch (current.second) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = b - a;//be aware! since we use stack, the order must be flipped
                    break;
                }

                calculate_stk.push(result);//result will be pushed again to stack
            }
        }

        return calculate_stk.top();
    }
};
