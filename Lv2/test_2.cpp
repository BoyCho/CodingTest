// 주식가격 (스택/큐)

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] > prices[j] || j == prices.size() - 1) {
                answer[i] += j - i;
                break;
            }
        }
    }
    return answer;
}