#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 필요변수 입력 받기
    int N, M;
    cin >> N >> M;

    // 빼야할 원소 큐에 저장
    queue<int> q;
    
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        q.push(temp);
    }

    // 덱 선언
    deque<int> dq;

    // 1부터 N까지 덱에 저장
    for (int i = 1; i <= N; i++) dq.push_back(i);

    // 답안 저장용 변수
    int answer = 0;


    // 모든 원소를 다 뺄 때까지 반복
    while (!q.empty()) {
        // 빼야할 원소 저장
        int key = q.front();


        // 덱의 맨 앞에 있는 경우 그냥 빼버리고 다음으로 넘어감
        if (key == dq.front()) {
            dq.pop_front();
            q.pop();
        }

        // 그렇지 않으면
        else {
            // 일단 원소의 위치를 찾음
            auto it = find(dq.begin(), dq.end(), key);
            int dist = it - dq.begin(); // 그 거리가

            // 중앙 기준 왼쪽인지 오른쪽인지 판별
            bool is_left = dist <= dq.size() / 2 ? true : false;
            
            // 왼쪽에 있다면
            if (is_left) {
                // 계속 빼고 넣어서 답 증가 시킴
                for (int i = 0; i < dist; i++) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                    answer++;
                }
            } 
            // 오른쪽에 있다면
            else {
                // 거리 갱신해주고
                dist = dq.size() - dist;
                // 마찬가지로 계속 빼서 넣음
                for (int i = 0; i < dist; i++) {
                    dq.push_front(dq.back());
                    dq.pop_back();
                    answer++;
                }
            }
            // 위 두 반복문을 다 돌면 덱의 맨 앞에 뺄 원소가 있으므로,
            // 덱에서 빼주고 큐에서 빼줌
            dq.pop_front();
            q.pop();
        }
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}