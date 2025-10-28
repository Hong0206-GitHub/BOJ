#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 수 입력 받기
    int N;
    cin >> N;

    // 에라토스테네스의 체 알고리즘
    // 문제의 최댓값이 4,000,000 까지의 소수를 먼저 구함
    vector<bool> p(4000001, true);
    p[0] = p[1] = false;

    for (int i = 2; i * i <= 4000000; i++)
        if (p[i])
            for (int j = i * i; j <= 4000000; j += i)
                p[j] = false;

    // 구한 소수를 벡터에 따로 저장함.
    // 순차적으로 돌기 때문에 자동으로 오름차순임
    vector<int> v;
    for (int i = 2; i <= N; i++) {
        if (p[i]) v.push_back(i);
    }

    // 투포인터 알고리즘
    // 투포인터는 동일한 위치에서 시작함
    int start = 0, end = 0;
    int count = 0;  // 답 저장 변수
    int sum = 0;     // 누적합

    // 투포인터
    while (true) {
        // sum이 더 크거나 같다면,
        // start 포인터 이동 및 sum 갱신
        if (sum >= N) sum -= v[start++];
        // end포인터가 범위 밖이라면 break
        else if (end == v.size()) break;
        // 그렇지 않다면, end포인터 이동 및 sum 갱신
        else sum += v[end++];

        // 두 값이 같은 경우 조건에 만족하므로 count 1 증가
        if (sum == N) count++;
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}