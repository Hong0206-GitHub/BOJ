#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 입력 값 입력받기
    int N, M, K;
    cin >> N >> M >> K;

    // 벡터 선언
    vector<vector<long long>> D(201, vector<long long>(201));

    // 초기값 설정
    for (int i = 0; i <= 200; i++) {
        D[i][i] = 1;
        D[i][0] = 1;
    }

    // 조합 2차원 벡터 채우기
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j - 1] + D[i - 1][j];

            // K의 최댓값이 넘어가는 경우 조정
            if (D[i][j] > 1000000000) D[i][j] = 1000000001;
        }
    }

    // K번째 문자열이 존재하지 않는 경우
    if (D[N + M][M] < K) {
        cout << "-1";
        return 0;
    }
    else {
        // 둘 중 하나가 0이 될 때 까지 반복
        while (N > 0 && M > 0) {

            // 'a'를 선택할 수 있는 경우
            if (D[N - 1 + M][M] >= K) {
                cout << 'a';
                N -= 1; // 'a'하나 사용
            }
            // 'z'를 선택해야하는 경우
            else {
                cout << 'z';
                // 'a'로 가능한 경우를 제외
                K -= D[N - 1 + M][M];
                M -= 1; // 'z' 하나 사용
            }
        }
    }

    while (N-- > 0) {
        cout << 'a';
    }

    while (M-- > 0) {
        cout << 'z';
    }

    cout << '\n';
    return 0;
}