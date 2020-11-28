// 스킬트리 (Summer/Winter Coding(~2018))

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int cnt;
    for (int i = 0; i < skill_trees.size(); i++) {
        answer++;
        cnt = -1;
        for (int j = 0; j < skill_trees[i].size(); j++) {
            for (int k = 0; k < skill.size(); k++) {
                if (skill[k] == skill_trees[i][j]) {
                    if (k - cnt == 1)
                        cnt = k;
                    else {
                        k = skill.size();
                        j = skill_trees.size();
                        answer--;
                    }
                }
            }
        }
    }
    return answer;
}