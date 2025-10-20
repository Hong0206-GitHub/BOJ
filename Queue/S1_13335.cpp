#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 가속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받기
    // n 은 트럭 개수
    // w 는 다리 길이
    // L 은 다리의 최대 하중
    int n, w, L;
    cin >> n >> w >> L;

    // 트럭은 선입선출이므로, 큐를 선언해서 모두 입력 받음
    queue<int> truck;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >>temp;
        truck.push(temp);
    }

    // 다리를 표현할 벡터 선언, 다리 길이만큼의 크기의 벡터를 선언해서 0으로 초기화
    vector<int> bridge(w, 0);

    // 답안용 단위시간 저장 변수
    int time = 0;

    // 갈 트럭이 있거나, 다리 위에 트럭이 있는 경우 반복
    while (!truck.empty() || accumulate(bridge.begin(), bridge.end(), 0) > 0) {
        // 단위 시간 증가
        time++;

        // 마지막 트럭 빠져나옴
        bridge[w - 1] = 0;

        // 모든 트럭 한 칸씩 앞으로 이동
        bridge.insert(bridge.begin(), 0);

        // 다리위에 추가 트럭이 올라갈 수 있는지를 판단하여, 들어갈 수 있으면 넣고 트럭 대기열에서 트럭 하나 팝
        if (!truck.empty() && accumulate(bridge.begin(), bridge.end(), 0) + truck.front() <= L) {
            bridge[0] = truck.front();
            truck.pop();
        }
    }

    // 답안 출력
    cout << time << '\n';
    return 0;

}