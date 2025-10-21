#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스 횟수
    int N;
    cin >> N;

    // 최대힙
    priority_queue<int> pq;

    while (N--) {
        // 값 입력
        int x;
        cin >> x;

        // 0이면 출력 -> 큐가 비었으면 0, 아니면 탑 출력 후 팝
        if (x == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        // 0이 아니면 푸시
        else pq.push(x);
    }

    return 0;
}