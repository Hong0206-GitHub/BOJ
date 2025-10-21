#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 소수계산 위해 double 자료형으로 입력받기
    double w, h;
    cin >> w >> h;

    // 소수점 1자리까지만 출력해야하므로, 출력형식 지정후 답안 출력
    cout << fixed << setprecision(1) << w * h / 2 << '\n';

    return 0;
}