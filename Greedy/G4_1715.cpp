#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 카드 묶음 개수 입력 받기
    int N;
    cin >> N;

    // 우선순위 큐 선언
    priority_queue<int, vector<int>, greater<>> pq;
    // 카드 묶음 수 집어 넣기
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    // 답안 저장 변수
    int answer = 0;

    // 큐 사이즈가 1일 때까지
    while (pq.size() > 1) {
        // 두 개 꺼내서 더함
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        pq.push(a + b);
        
        answer += a + b;
    }

    // 답안 출력
    cout << answer << '\n';    

    return 0;
}