#include <bits/stdc++.h>

using namespace std;
struct edge {int u, v, w;};

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 정점 개수, 간선 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 기본 자료형 선언 및 초기화
    vector<edge> mlist;
    vector<long long> mdistance(N + 1, LONG_LONG_MAX);

    // 그래프 채우기
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
    
        mlist.push_back({u, v, w});
    }

    // 1을 출발점으로 벨만 포드 알고리즘 수행
    mdistance[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            edge medge = mlist[j];
            int start = medge.u;
            int end = medge.v;
            int time = medge.w;

            // 모든 값에 대해 탐색하므로 맥스값이 아니면서 최단 거리로 갱신 가능 할 경우에 대해
            // 값 갱신을 수행해야 함
            if (mdistance[start] != LONG_LONG_MAX && mdistance[end] > mdistance[start] + time) {
                mdistance[end] = mdistance[start] + time;   
            }
        }
    }

    // 음수 사이클 발생 여부 탐색
    bool mCycle = false;
    for (int i = 0; i < M; i++) {
        edge medge = mlist[i];

        int start = medge.u;
        int end = medge.v;
        int time = medge.w;

        // 한 번더 갱신이 가능한 경우, 음수 사이클이 존재하는 경우임
        if (mdistance[start] != LONG_LONG_MAX && mdistance[end] > mdistance[start] + time) {
            mCycle = true;
            break;
        }
    }

    // 음수 사이클이 존재하면 -1 출력
    if (mCycle) {
        cout << -1 << '\n';
    }

    // 존재하지 않는 경우
    else {
        // 연결되지 않은 경우 -1 출력하고 나머지는 시간 출력
        for (int i = 2; i <= N; i++) {
            if (mdistance[i] == LONG_LONG_MAX) cout << -1 << '\n';
            else cout << mdistance[i] << '\n';
        }
    }

    return 0;
}