#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 이 문제의 핵심 아이디어
// 건물의 높이가 높아지면 새로운 건물이 있다고 판단하여
// 건물 수를 증가 시킴

// 반대로 작아질 경우, 이미 건물수는 세 놓았기 때문에,
// 스택에서 빼기만 하면 됨.

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 개수 입력 받기
    int N;
    cin >> N;

    // 스택 선언
    stack<int> s;

    // 답안 저장용 변수
    int answer = 0;

    // 입력 개수만큼 반복
    for (int i = 0; i < N; i++) {
        // 두 개의 입력을 받으나 두 번째 입력만 사용
        int _, n;
        cin >> _ >> n;

        // 스택이 빌 때까지 스택의 최상단 보다 입력값이 작으면 팝
        while (!s.empty() && s.top() > n) s.pop();
        // 스택이 비어있거나, 탑이 입력값보다 작으면 푸시하고 건물 하나 추가
        if (n && (s.empty() || s.top() < n)) {
            s.push(n);
            answer++;
        }
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}