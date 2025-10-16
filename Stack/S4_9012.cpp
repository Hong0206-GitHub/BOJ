#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스
    int N;
    cin >> N;

    // 테스트 케이스 만큼 반복
    while (N--) {

        // 변수 초기화 및 입력 받기
        string str;
        cin >> str;
        
        bool check = true;
        stack<char> s;

        // 입력 받은 문자열 길이만큼 반복
        for (size_t i = 0; i < str.size(); i++) {
                
            // 여는 괄호일 경우 스택에 푸시
            if (str[i] == '(') s.push(str[i]);
            // 닫는 괄호일 경우 스택이 비어있거나 스택의 탑이 여는 괄호가 아니면
            // 조건에 해당하지 않음
            else {
                if (s.empty() || s.top() != '(') {
                    check = false;
                    break;
                } 
                // 조건에 해당하는 경우 스택의 탑에서 팝
                else s.pop();
            }
        }

        // 조건에 따라 출력
        if (check && s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}