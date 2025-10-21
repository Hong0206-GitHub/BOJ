#include <bits/stdc++.h>

using namespace std;

int main(void) {
    
    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 최소힙 선언
    priority_queue<int, vector<int>, greater<int>> pq;

    // 반복횟수
    int N;
    cin >> N;
    while (N--) {
        // x 입력 받기
        int x;
        cin >> x;

        // 꺼내는 연산일경우, 큐가 비어있으면 0, 아니면 탑 출력
        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        // 집어넣는 연산 수행
        else pq.push(x);
    }

    return 0;
}