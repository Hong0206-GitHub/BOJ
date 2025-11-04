#include <bits/stdc++.h>

using namespace std;

// 입력 값 저장 변수
int N, K;

const int MAX = 100001;

// 방문 여부 및 연산 횟수 저장 벡터
vector<int> visited(MAX, 0);
    
// 너비우선탐색 알고리즘 사용
int BFS() {
    
    // 너비우선탐색 용 큐 선언
    queue<int> q;
    q.push(N);
    
    // 큐가 빌 때까지
    while (!q.empty()) {
        // 큐에서 꺼내고
        int curPosition = q.front();
        q.pop();

        // 도착했으면 반복문 종료
        if (curPosition == K) break;

        // 각각의 조건에 따라 변수 선언
        int minusPosition = curPosition -1;
        int plusPosition = curPosition + 1;
        int multiPosition = curPosition * 2;

        // - 1 인 경우
        if (minusPosition < MAX && minusPosition >= 0 && visited[minusPosition] == 0) {
            q.push(minusPosition);
            visited[minusPosition] = visited[curPosition] + 1;
        }

        // + 1 인 경우
        if (plusPosition < MAX && plusPosition >= 0 && visited[plusPosition] == 0) {
            q.push(plusPosition);
            visited[plusPosition] = visited[curPosition] + 1;
        }

        // * 2 인 경우
        if (multiPosition < MAX && multiPosition >= 0 && visited[multiPosition] == 0) {
            q.push(multiPosition);
            visited[multiPosition] = visited[curPosition] + 1;
        }

    }

    // 답안 리턴
    return visited[K];
}


int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 받기
    cin >> N >> K;

    // 답안 출력
    cout << BFS() << '\n';

    return 0;
}