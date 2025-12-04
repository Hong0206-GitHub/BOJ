#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    vector<long long> F(21);
    vector<int> S(21);
    vector<bool> visited(21, false);

    // 팩토리얼 채우기
    F[0] = 1;
    for (int i = 1; i < 21; i++) F[i] = F[i - 1] * i;

    // 순열 자릿수 입력 받기
    int N;
    cin >> N;

    // 질의 번호 입력 받기
    int Q;
    cin >> Q;

    long long K;

    // 1번 질의인 경우
    if (Q == 1) {

        // 순서 입력 받고
        cin >> K;
        
        // i 번째 자리에는 (N - i)! 의 순열 묶음이 있음
        for (int i = 1; i <= N; i++) {
            for (int j = 1, count = 1; j <= N; j++) {
                // 이미 사용한 숫자는 사용할 수 없음
                if (visited[j]) continue;

                // 주어진 K에 따라 각 자리에 들어갈 수 있는 수 찾기
                if (K <= count * F[N - i]) {
                    S[i] = j;
                    K -= ((count - 1) * F[N - i]);
                    visited[j] = true;
                    break;
                }
                count++;
            }
        }
        // 답안 출력
        for (int i = 1; i <= N; i++) cout << S[i] << ' ';
        cout << '\n';
    }
    
    else if (Q == 2) {
        K = 1;

        // 순열 자리 수 만큼
        for (int i = 1; i <= N; i++) {
            cin >> S[i];
            long long count = 0;
            // 현재 자리 수보다 작은 숫자중 아직 사용하지 않은 숫자 찾기
            for (int j = 1; j < S[i]; j++) {
                if (visited[j] == false) count++;
            }

            // 건너뛰어야 하는 순열 개수에 따라 갱신
            K += count * F[N - i];

            // 방문처리
            visited[S[i]] = true;
        }
        // 최종 K 값 출력
        cout << K << '\n';
    }
    return 0;
}