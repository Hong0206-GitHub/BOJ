#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 길이 찾을 때 사용할 함수 선언
int search(const vector<int>& vec, int start, int end, int key);
long long count(const vector<int>& vec, int mid);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 배열 길이와, 나무 길이 입력 받기
    int N, M;
    cin >> N >> M;

    // 벡터 선언 및 원소 채우기
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) cin >> vec[i];
    
    // max값 도출
    int maxVal = *max_element(vec.begin(), vec.end());

    // 문제 답 담을 변수
    int answer = search(vec, 0, maxVal, M);

    // 답안 출력
    cout << answer << '\n';

    return 0;
}

// 길이 탐색
int search(const vector<int>& vec, int start, int end, int key) {

    // 리턴 변수 선언
    int answer = 0;
    // 조건에 맞을때까지 반복
    while (start <= end) {
        int mid = (start + end) / 2;
        // 문제 조건에 맞게 잘린 나무 총 길이 저장할 변수
        long long temp = count(vec, mid);

        // 나무 길이가 원하는 길이 이상이면
        // 값 갱신해주고 나무 길이가 최소가 될때 까지 탐색해야함
        if (temp >= key) {
            answer = mid;
            start = mid + 1; 
        }
        // temp가 key보다 작은 경우
        else end = mid - 1;
    }
    return answer;
}

long long count(const vector<int>& vec, int mid) {
    long long sum = 0;
    // 모든 원소에 대해
    for (int x : vec) {
        long long temp = x - mid;
        // 나무길이가 짧아 잘리지 않은 경우는 배제
        if (temp > 0) sum += temp;
    }
    return sum;
}