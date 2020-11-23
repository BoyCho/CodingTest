#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    vector<int> div = d;
    sort(div.begin(), div.end());
    while (answer != div.size()) {
        if (budget - div[answer] < 0)
            return answer;
        budget -= div[answer];
        answer++;
    }
    return answer;
}