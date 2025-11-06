#include <bits/stdc++.h>
using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 2 x 2 벡터 선언
    vector<vector<int>> v(2, vector<int>(2));

    // 입력 받기
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> v[i][j];
        }
    }

    // 답안 저장 변수
    int answer = 0;

    // 최댓값 저장 변수
    double mx = (double)v[0][0] / v[1][0] + (double)v[0][1] / v[1][1];

    for (int i = 0; i < 3; i++) {
        
        // 회전시키기
        int a = v[0][0], b = v[0][1], c = v[1][0], d = v[1][1];
        v[0][0] = c;
        v[0][1] = a;
        v[1][1] = b;
        v[1][0] = d;

        // 최댓값 갱신 가능하면, 답안 갱신 및 최댓값 갱신
        double temp = (double)v[0][0] / v[1][0] + (double)v[0][1] / v[1][1];
        if (temp > mx) {
            mx = temp;
            answer = i + 1; 
        }
    }

    // 답안 출력
    cout << answer << '\n';
    return 0;
}
