#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;

    // 원본 원소 채울 벡터 선언
    vector<int> v(N);

    // 원소 벡터에 채우기
    for (int i = 0; i < N; i++) cin >> v[i];

    // 왼쪽에서 오른쪽으로 값을 더해 나갈 벡터랑
    // 오른쪽에서 왼쪽으로 값을 더해 나갈 벡터 선언
    // 인덱스 n은 0~n까지의 원소의 합
    vector<int> l(N);
    vector<int> r(N);

    // 초기값 세팅
    l[0] = v[0];
    int result = l[0];

    for (int i = 1; i < N; i++) {
        l[i] = max(v[i], l[i - 1] + v[i]);
        // 하나도 제거 하지 않았을 때를 기본 최대값으로 저장
        result = max(result, l[i]);
    }

    r[N - 1] = v[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        r[i] = max(v[i], r[i + 1] + v[i]);
    }

    // 두 개의 구간합 배열을 더해 주면 i번째 값을 제거한 효과를 얻음
    for (int i = 1; i < N - 1; i++) {
        int temp = l[i - 1] + r[i + 1];
        // 그 값이 더 크다면 result에 갱신
        result = max(result, temp);
    }

    // 답안 출력
    cout << result << '\n';

    return 0;
}