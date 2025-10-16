#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스 입력
    int N;
    cin >> N;

    // 답안 저장용 변수
    int count = 0;

    // 테스트 케이스만큼 반복
    while (N--) {
        // 변수 초기화 및 새로운 값 저장
        string str;
        cin >> str;

        // 분기 확인용 변수
        bool check = true;

        // 스택 초기화
        stack<char> s;

        // 짝수가 아니면 애당초 성립이 안됨
        if (str.size() % 2 != 0) {
            continue;
        }

        // 모든 글자에 대해 반복
        for (size_t i = 0; i < str.size(); i++) {
            // 스택이 비어있거나, 스택의 탑과 값이 다르면 푸시
            if (s.empty() || s.top() != str[i]) {
                s.push(str[i]);
            }
        
            // 스택이 비어있지 않으면서 스택의 탑과 값이 같은 경우
            // 스택에서 팝
            else if (str[i] == s.top()) s.pop();

            // 이외의 케이스는
            // 조건에 해당하지 않는 경우이므로 분기 조절 후 브레이크
            else {
                check = false;
                break;
            }
        }
        // 조건에 따라 카운트 증가
        if (check && s.empty()) count++;
    }

    // 답안 출력
    cout << count << '\n';
    
    return 0;
}