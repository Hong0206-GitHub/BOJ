#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false); cin.tie(NULL);

    // 개수 입력 받기
    int N, M;
    cin >> N >> M;

    // 벡터 선언 및 이분탐색 인덱스들 선언
    vector<int> v(N);
    int start = INT_MIN, end = 0;

    // 벡터에 원소 집어넣으면서 start는 원소들 중 최댓값 , end는 원소의 총합으로 갱신
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        if (start < v[i]) start = v[i];
        end += v[i];
    }

    // 이분탐색
    while (start <= end) {
        int sum = 0;        // 저장한 강의 길이
        int count = 0;      // 사용한 블루레이 개수
        int mid = (start + end) / 2;    // 중앙값

        // 모든 강의들(원소) 탐색
        for (int i = 0; i < N; i++) {
            if (v[i] + sum > mid) count++, sum = 0; // 해당 블루레이에 담을 수 있는지를 먼저 판단
            sum += v[i];    // 블루레이에 담기
        }

        // 강의가 남아있는 경우 새로운 블루레이를 더 사용해야함
        if (sum != 0) count++;

        // M보다 count가 크다면,
        // 저장 가능한 영상길이를 더 늘려서 탐색해야함
        if (count > M) start = mid + 1;

        // 그렇지 않다면, 오히려 줄여서 탐색을 계속 진행함
        else end = mid - 1;
    }

    // start 에 최소 녹화 가능 길이가 담아져있으므로 이를 출력
    cout << start << '\n';

    return 0;
}