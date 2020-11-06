#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int lost_n = lost.size();

    vector<int> res, los;
    res.assign(n, 0);
    los.assign(n, 0);

    for (int i = 0; i < reserve.size(); i++) {
        if (reserve[i] > 0)
            res[reserve[i] - 1]++;
    }
    for (int i = 0; i < lost.size(); i++) {
        if (lost[i] > 0) {
            los[lost[i] - 1]++;
            if (res[reserve[i] - 1] > 0) {
                los[lost[i] - 1]--;
                res[reserve[i] - 1]--;
                lost_n--;
            }
        }
    }

    for (int i = 0; i < lost.size(); i++) {
        if (res[lost[i] - 2] > 0) {
            lost_n--;
            res[lost[i] - 2]--;
        }
        else if (res[lost[i]] > 0) {
            lost_n--;
            res[lost[i]]--;
        }
    }
    answer = n - lost_n;
    return answer;
}