#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 각도 입력 받기
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    // 삼각형인 경우
    if (a1 + a2 + a3 == 180) {
        // 정삼각형인 경우
        if (a1 == 60 && a2 == 60 && a3 == 60) cout << "Equilateral" << '\n';
        // 이등변 삼각형인 경우
        else if (a1 == a2 || a2 == a3 || a3 == a1) cout << "Isosceles" << '\n';
        // 일반 삼각형인 경우
        else cout << "Scalene" << '\n';
    }
    // 삼각형이 아닌 경우
    else cout << "Error" << '\n';

    return 0;
}
