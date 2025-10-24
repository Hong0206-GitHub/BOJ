#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// N의 범위가 1,000,000이므로 이보다 크게 잡아야 함
const ll SIZE = 10000001;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 문제에서 제시한 범위만큼의 bool 타입 벡터 선언
    vector<bool> v(SIZE, true);
    v[0] = false;   // 0은 소수가 아님
    v[1] = false;   // 1은 소수가 아님

    // 2부터 시작하여, 소수 판별
    // 에라토스테네스의 체 알고리즘
    for (ll i = 2; i * i <= SIZE - 1; i++)
        if (v[i])
            for (ll j = i * i; j <= SIZE - 1; j += i)
                v[j] = false;
    
    // 값 입력 받기
    int N;
    cin >> N;

    // 소수에 대해서
    for (ll i = N; i <= SIZE - 1; i++) {
        if (v[i]) {
            // string 으로 형변환
            string str = to_string(i);

            // 역순으로 다시 재정렬할 임시 벡터 선언
            vector<char> temp(str.size());

            // 벡터의 인덱스
            int j = 0;
            
            // string의 역순으로 벡터에 삽입
            for (int i = str.size() - 1; i >= 0; i--) {
                temp[j++] = str[i];
            }

            // 분기 조절 변수
            bool check = true;

            // 모든 값이 같은지 확인
            for (size_t i = 0; i < str.size(); i++) {
                if (temp[i] != str.at(i)) {
                    check = false;  // 다르면 분기 조정
                    break;  // 반복문 탈출
                }
            }
            // 분기에 따라
            if (check) {
                // 답안 출력
                cout << i << '\n';
                break;
            }
            // 다음으로 넘어감
            else continue;
        }
    }

    return 0;
}