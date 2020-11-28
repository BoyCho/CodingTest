#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int i;

bool compare (string a, string b) {
        return a[i] == b[i] ? a < b : a[i] < b[i];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    i = n;
    sort(strings.begin(), strings.end(), compare);
    return  strings;
}

// 삼항 조건 활용