#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 스택 선언
    stack<char> s;
    // 입력 값 저장 변수 선언
    string str;

    // 입력 받기
    cin >> str;

    // 답안 변수 및 분기 변수 선언
    // open은 여는 괄호일 경우 true
    int answer = 0;
    bool open = false;

    // 모든 문자에 대해
    for (size_t i = 0; i < str.size(); i++) {

        // 검사할 문자 변수에 저장
        char temp = str[i];

        // 여는 괄호인 경우
        if (temp == '(') {
            open = true; // 분기 true
            s.push(temp); // 스택에 삽입
        }

        // 닫는 괄호인 경우
        else {
            // 레이저인 경우
            if (open) {
                s.pop(); // 하나 빼고
                answer += s.size(); // 스택 사이즈만큼의 막대가 발생
            }
            // 레이저가 아닌 경우
            else {
                answer++; // 레이저 다음에 막대가 남으니 한 조각 추가
                s.pop(); // 꺼내기
            }
            // 닫는괄호 이므로 분기 false
            open = false;
        }
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}