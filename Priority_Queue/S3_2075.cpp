#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 최소힙 선언
    priority_queue<int, vector<int>, greater<int>> pq;

    // 크기와 몇 번째로 큰 수 출력할지
    int N;
    cin >> N;

    // 일단 큐에 집어넣되,
    for (int i = 0; i < N * N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);

        // 최소힙이므로 큰 수는 힙에 남아있게 되고,
        // 작은 수들만 넣어졌다 빠졌다 반복하게 됨.

        // 따라서 size 가 N보다 클때 작은 값을 팝해주면
        // 큐에는 N번째로 큰 수 부터 가장 큰 수까지만 저장되게 됨
        if (pq.size() > N) pq.pop();
    }

    // 따라서 마지막에 N번째로 큰 수가 최소힙의 최상단에 있으므로
    // 이를 출력
    cout << pq.top() << '\n';
}