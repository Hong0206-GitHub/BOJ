#include <iostream>
using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 변수 선언
    int hh, mm, ss;
    cin >> hh >> mm >> ss;

    // 증가 시킬 초 선언
    int time;
    cin >> time;

    // 시간 조정
    hh += time / 3600;
    time %= 3600;

    // 분 조정
    mm += time / 60;
    time %= 60;

    // 초 조정
    ss += time;

    // 조정 후 올림 발생시 처리
    if (ss >= 60) {
        mm++;
        ss %= 60;
    }
    if (mm >= 60) {
        hh++;
        mm %= 60;
    }
    if (hh >= 24) hh %= 24;

    cout << hh << ' ' << mm << ' ' << ss << '\n';
    return 0;
}