#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 받을 문자열 저장 변수 및 입력 받기
    string str;
    cin >> str;

    // 입력받은 문자열에 따라 출력할 문자열 출력
    if (str == "NLCS") cout << "North London Collegiate School\n";
    else if (str == "BHA") cout << "Branksome Hall Asia\n";
    else if (str == "KIS") cout << "Korea International School\n";
    else if (str == "SJA") cout << "St. Johnsbury Academy\n";

    return 0;
}