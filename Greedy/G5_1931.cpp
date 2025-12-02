#include <bits/stdc++.h>

using namespace std;

int main(void) {
    
    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 개수 입력 받기
    int N;
    cin >> N;

    // 회의 정보 저장할 벡터 선언
    vector<pair<int, int>> v(N);

    // 시작시간, 종료시간으로 저장
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    // 정렬 수행
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        // 종료 시간이 같은 경우, 시작시간이 짧은 걸로
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second; // 아니면 종료시간이 짧은걸로
    });

    // 답안 저장 변수 및 종료 시간 저장 변수 선언
    int answer = 0;
    int endTime = 0;

    // 모든 회의에 대해
    for (auto &c : v) {
        // 회의 시작시간이 종료시간 보다 크거나 같은 경우,
        // 회의를 시작할 수 있음
        if (c.first >= endTime) {
            answer++;   // 답 1 증가
            endTime = c.second; // 해당 회의를 시작했으므로, 종료시간 갱신
        }
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}