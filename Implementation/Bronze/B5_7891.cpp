#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스 입력 받기
    int t;
    cin >> t;

    // t 만큼 반복
    while (t--) {
        // 두 개의 변수 선언 및 입력 받기
        int x, y;
        cin >> x >> y;
        // 더한 결과 출력
        cout << x + y << '\n';
    }

    return 0;
}