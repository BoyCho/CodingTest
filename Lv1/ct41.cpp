#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct stage {
    int stage_n;
    float nume;
    float deno;
    float fail_price;
};

bool cmp(stage a, stage b) {
    if (a.fail_price != b.fail_price)
        return a.fail_price > b.fail_price;
    else
        return a.stage_n < b.stage_n;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<stage> stg(N);

    for (int i = 1; i <= N; i++) {
        stg[i - 1].stage_n = i;
        stg[i - 1].deno = 0;
        stg[i - 1].nume = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] == i) stg[i-1].nume++;
            if (stages[j] >= i) stg[i-1].deno++;
        }
        if (stg[i - 1].deno == 0) stg[i - 1].fail_price = 0;
        else stg[i - 1].fail_price = stg[i - 1].nume / stg[i - 1].deno;
    }
    sort(stg.begin(), stg.end(), cmp);
    for (int i = 0; i < N; i++)
        answer.push_back(stg[i].stage_n);
    return answer;
}

int main() {
    int n = 5;
    vector<int> stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
    for (int i = 0; i < n; i++)
        cout << solution(n, stages)[i] << endl;
}