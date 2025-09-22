#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N, K 입력 받기
    long N, K;
    cin >> N >> K;

    // 인덱스를 1번부터 시작하므로, start = 1
    long start = 1, end = K;
    long ans = 0;

    // 이분 탐색
    while (start <= end) {
        long middle = (start + end) / 2;
        long cnt = 0;

        // 중앙 값보다 작은 수 계산
        for (int i = 1; i <= N; ++i) cnt += min(middle / i, N); // 작은 수 카운트
        
        if (cnt < K) start = middle + 1;
        
        else {
            ans = middle;  // 중앙 값 정답 변수에 저장
            end = middle - 1;
        }
    }
    // 답안 출력
    cout << ans << '\n';
    
    return 0;

}
