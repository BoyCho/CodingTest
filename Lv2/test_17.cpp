#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    char friends[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
    do {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int a, b;
            for (int j = 0; j < 8; j++) {
                if (friends[j] == data[i][0]) a = j;
                if (friends[j] == data[i][2]) b = j;
            }
            if (data[i][3] == '=' && abs(b - a) - 1 != data[i][4] - '0' || data[i][3] == '>' && abs(b - a) - 1 <= data[i][4] - '0' || data[i][3] == '<' && abs(b - a) - 1 >= data[i][4] - '0') {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    } while (next_permutation(friends, friends + 8));
    return answer;
}