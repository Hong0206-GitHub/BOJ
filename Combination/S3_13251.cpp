#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // N = 전체 조약돌 개수
    // M = 색상 개수
    // K = 뽑는 조약돌 개수
    double N = 0.0;
    int M, K;

    cin >> M;

    // 먼저 색상 별 조약돌 개수 저장 벡터 선언
    vector<double> D(M);

    // 입력 받으면서 전체 조약돌 개수 구함
    for (int i = 0; i < M; i++) {
        cin >> D[i];
        N += D[i];
    }

    // 뽑는 조약돌 개수 입력 받기
    cin >> K;

    // 답안 저장 변수 선언
    double answer = 0;

    // 확률로 개산함.
    for (int i = 0; i < M; i++) {
        // 뽑는 조약돌 개수보다 적은 수의 조약돌 개수를 가진 조약돌은 무시
        if (D[i] < K) continue;

        // (Ci K) / (N K) = Ci / N * C(i - 1) / N - 1 * ... * C(i - K - 1) / N - K - 1
        double temp = 1.0;
        for (int j = 0; j < K; j++) {
            temp *= (D[i] - j) / (N - j);
        }
        answer += temp;
    }

    // 소수점 조정
    cout << fixed << setprecision(9) << answer << '\n';
    return 0;
}