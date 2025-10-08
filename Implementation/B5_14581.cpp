#include <iostream>
#include <string>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 이름 저장할 string 변수 선언
    string str;
    cin >> str;

    // 문제에 맞게 출력
    cout << ":fan::fan::fan:\n";
    cout << ":fan::" << str << "::fan:\n";
    cout << ":fan::fan::fan:\n";

    return 0;
}