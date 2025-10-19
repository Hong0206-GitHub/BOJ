#include <iostream>
// sort 함수 사용하기 위함
#include <algorithm>
// 값 저장용 벡터
#include <vector>

using namespace std;

int main() {
  // 벡터 크기 5칸 미리 선언
    vector<int> vec(5);
  // 평균 구하기 위한 전체합 변수
    int sum = 0;
  // 값 넣음과 동시에 전체합 구하기
    for (int i = 0; i < 5; ++i) {
        cin >> vec[i];
        sum += vec[i];
    }
  // 정렬
    sort(vec.begin(), vec.end());

  // 답안출력
    cout << sum / 5 << '\n';
    cout << vec[2] << '\n';
    return 0;
}
