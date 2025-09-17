#include <iostream>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 반복 횟수 입력 받기
    int N;
    cin >> N;

    // 답안 저장용 변수
    int count = 0;

    // N번 실행
    while (--N >= 0) {
        
        // 단어 입력 받기
        string word;
        cin >> word;

        // 조건 검사용 스택 선언
        stack<char> stk;
        
        // 조건 검사용 불타입 변수 선언
        bool check = true;

        // 단어의 한 글자씩
        for (int i = 0; i < word.size(); ++i) {

            // 스택이 비어있거나, 스택의 top부분과 글자의 내용이 다르다면,
            // 스택에 해당 글자 push
            if (stk.empty() || stk.top() != word[i]) stk.push(word[i]);
            // 스택의 최상단과 해당 글자가 같은 경우 스택에서 빼기
            else if (stk.top() == word[i]) stk.pop();
            // 두 경우에 해당되지 않으면, 반복문 종료 후 조건에서 제외
            else {
                check = false;
                break;
            }
        }

        // 스택에 내용물이 남아있는 경우에도 조건에서 제외
        if (!stk.empty()) check = false;
        // 모든 조건 통과시 카운터 증가
        if (check) count++;
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}