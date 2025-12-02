#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 문자열 통으로 입력 받기
    string str;
    cin >> str;

    // 구분된 문자열 저장할 벡터 선언
    vector<string> strv;
    
    // 임시 문자열 선언
    string temp = "";

    // 문자열 순회하면서
    for (char c : str) {
        // - 만나면 지금까지 저장된 숫자 문자열 벡터에 저장
        if (c == '-') {
            strv.push_back(temp);
            temp = "";
        }
        // 아니면 계속 문자를 더해 문자열 넓힘
        else {
            temp += c;
        }
    }

    // 남아있는 문자열 넣어줌
    strv.push_back(temp);

    // 람다 함수
    auto addSplit([](string str) {
        // 총합(리턴) 변수 선언
        int sum = 0;

        // 임시 문자열 선언
        string num = "";

        // 모든 문자에 대해
        for (char c : str) {

            // + 를 만나면 거기까지 합쳐놓은 숫자를 sum에 더함
            if (c == '+') {
                sum += stoi(num);
                // 그리고 임시 문자열 비움
                num = "";
            }
            // 아니면 계속 문자 합쳐서 문자열 넓힘
            else {
                num += c;
            }
        }

        // 마지막에 한번 더 합쳐줌
        sum += stoi(num);
        return sum;
    });

    // 답안 저장 변수
    int answer = 0;

    // 첫 번째 덩어리 계산
    answer += addSplit(strv[0]);

    // 이후 값들은 더해서 빼주면 됨
    for (int i = 1; i < strv.size(); i++) {
        answer -= addSplit(strv[i]);
    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}