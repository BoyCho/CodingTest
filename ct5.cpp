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
    ������ �켱 ������ �� �ľ��Ͽ� �켱 ������� ������

    �ǵ��� �߰� �迭�� ���� ����غ���

    for(itr : )�� �迭�� ���� �ε����� ����� �� �������
*/