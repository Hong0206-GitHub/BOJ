#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 탑 개수 입력 받기
    int N;
    cin >> N;

    // 탑 넣을 스택 선언
    stack<pair<int, int>> s;

    // 답안 저장용 변수 선언
    vector<int> answer(N, -1);

    // 입력 개수 만큼 반복
    for (int i = 0; i < N; i++) {
        // 입력 받기
        int temp;
        cin >> temp;

        // 스택이 비어있으면 무조건 푸시
        if (s.empty()) {
            s.push({i, temp});
        }

        // 입력값이 더 큰 경우
        // 스택의 탑이 입력값보다 더 클 때까지 팝
        // 스택이 비어있지 않다면 해당 탑이 수신 받는 탑이므로 답안 벡터에 해당 탑 인덱스 저장
        else if (s.top().second < temp) {
            while (!s.empty() && s.top().second <= temp) s.pop();
            if (!s.empty()) answer[i] = s.top().first; 
            s.push({i, temp}); // 이후 해당 탑도 스택에 푸시
        }

        // 입력값이 더 작은 경우
        // 바로 왼쪽의 탑에서 직접 수신 가능함
        else {
            answer[i] = s.top().first;
            s.push({i, temp});
        }
    }

    // 답안 출력
    for (int x : answer) cout << x + 1 << ' ' ;
    cout << '\n';

    return 0;
}