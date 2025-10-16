#include <iostream>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;

    // 스택 선언
    stack<int> s;

    // 스택에 집어넣되
    // 입력이 0이면 팝, 아니면 푸시
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if (temp == 0) s.pop();
        else s.push(temp);
    }

    // 결과 저장 변수
    int sum = 0;

    // 스택의 모든 원소를 꺼내 더함
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    // 답안 출력
    cout << sum << '\n';

    return 0;
}