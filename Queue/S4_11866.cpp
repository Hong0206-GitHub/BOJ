#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 순열 개수와 얼만큼 건너뛸 것인지 입력 받기
    int N, K;
    cin >> N >> K;

    // 큐 선언
    queue<int> q;

    // 답안 저장용 벡터 선언
    vector<int> answer(N);

    // 1~N 까지 큐에 삽입
    for (int i = 1; i <= N; i++) q.push(i);

    // 답안 저장 인덱스
    int j = 0;
    
    // 큐가 빌 때까지
    while (!q.empty()) {
        // 몇 번 꺼내고 집어넣을 것인지
        for (int i = 0; i < K - 1; i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        // 맨 앞에 있는 값이 순열에 포함되어야 함
        answer[j++] = q.front();
        q.pop();
    }

    // 출력형식
    cout << '<';
    for (size_t i = 0; i < N - 1; i++) cout << answer[i] << ", ";
    cout << answer[N - 1] << ">\n";

    return 0;
}