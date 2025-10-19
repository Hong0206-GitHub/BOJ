#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 변수 선언
    int N, S;
        
    // cin은 EOF를 만나면 false 반환
    while (cin >> N >> S)
        cout << S / (N + 1) << '\n';

    return 0;
}