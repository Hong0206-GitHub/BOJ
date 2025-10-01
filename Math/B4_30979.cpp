#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 문제에서 주는 값들 입력하기
    int T;
    cin >> T;
    int N;
    cin >> N;
    
    int sum = 0;

    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        sum += temp;
    }

    // 조건에 맞게 답안 출력 조정
    if (sum - T >= 0) cout << "Padaeng_i Happy" << '\n';
    else cout << "Padaeng_i Cry" << '\n';

    return 0;
}