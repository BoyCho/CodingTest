#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> stu(31,0);

    for (int itr : reserve) stu[itr]++;
    for (int itr : lost) stu[itr]--;
    for (int i = 1; i <= n; i++) {
        if (stu[i] == -1) {
            if (stu[i - 1] == 1)
                stu[i] = stu[i - 1] = 0;
            else if (stu[i + 1] == 1)
                stu[i + 1] = stu[i] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (stu[i] == -1) answer--;
    }

    return answer;
}
/*
    조건의 우선 순위를 잘 파악하여 우선 순위대로 나누자

    되도록 추가 배열은 적게 사용해보자

    for(itr : )를 배열의 값을 인덱스로 사용할 떄 사용하자
*/