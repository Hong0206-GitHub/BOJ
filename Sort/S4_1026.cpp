#include <bits/stdc++.h>

using namespace std;

int main(void) {

    // 입출력 고속화
    ios::sync_with_stdio(false), cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;
    // 원소 개수만큼의 두 개 벡터 선언
    vector<int> temp1(N);
    vector<int> temp2(N);

    // 벡터 채우기
    for (int i = 0; i < N; i++) cin >> temp1[i];
    for (int i = 0; i < N; i++) cin >> temp2[i];
    
    // 하나는 오름차순, 하나는 내림차순 정렬
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    reverse(temp2.begin(), temp2.end());

    // 답안 저장 변수
    int sum = 0;

    // 답안 구하기
    for (int i = 0; i < N; i++) sum += temp1[i] * temp2[i];

    // 답안 출력
    cout << sum << '\n';

    return 0;
}