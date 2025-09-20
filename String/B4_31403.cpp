#include <iostream>
// 문자열 조작을 위해 사용
#include <string>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 문자열로 받기
    string a, b, c;
    cin >> a >> b >> c;

    // 문자열 덧셈으로 산술 덧셈이 아닌
    // 그냥 합치는 작업
    string ab = a + b;
    // 이후 문자열을 int형으로 형변환
    int int_a = stoi(a);
    int int_b = stoi(b);
    int int_c = stoi(c);
    int int_ab = stoi(ab);

    // 문제의 답안 출력
    cout << int_a + int_b - int_c << '\n';
    cout << int_ab - int_c << '\n';

    return 0;
}
