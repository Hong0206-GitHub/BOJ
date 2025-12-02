#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 동전 종류 수와, 금액 입력 받기
    int N, K;
    cin >> N >> K;

    // 동전 저장할 벡터 선언
    vector<int> v(N);
    // 역순 정렬
    for (int i = N - 1; i >= 0; i--) cin >> v[i];

    // temp는 동전을 선택했을 때의 금액
    int temp = 0;
    // count는 동전의 개수
    int count = 0;

    int i = 0;
    // 원하는 금액에 도달할 때 까지
    while (temp != K) {
        // 선택할 수 있는 동전의 최대값을 선택
        if (v[i] + temp > K) i++;
        else {
            temp += v[i];
            count++;
        }
    }

    // 답안 출력
    cout << count << '\n';
    return 0;
}