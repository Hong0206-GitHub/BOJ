#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 항상 계속 반복
    while (true) {
        // 변수 초기화
        string str;
        stack<char> s;
        bool check = true;

        // 입력 받기
        getline(cin, str);
        
        // . 만 입력된 경우 반복문 빠져나오기
        if (str == ".") break;
        if (str.empty()) continue;

        // 모든 문자에 대해
        for (size_t i = 0; i < str.size(); i++) {
            // 여는 괄호가 나오면 스택에 집어넣기
            if (str[i] == '[' || str[i] == '(') {
                s.push(str[i]);
            }
            // 닫는 괄호가 나오면 스택이 비어있는지와 스택의 탑 부분이 해당 괄호의
            // 여는 괄호인지 판단
            else if (str[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    check = false;
                    break;
                } else s.pop();
            }
            else if (str[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    check = false;
                    break;
                } else s.pop();
            }
        }
        // 조건에 해당하는 결과 출력
        if (s.empty() && check) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}