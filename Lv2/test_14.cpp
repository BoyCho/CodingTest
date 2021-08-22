#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, leaf;
    while (true) {

        if (scoville.size() == 1) return scoville[0] >= K ? answer : -1;

        for (int i = 1; true; i++) {
            if (scoville.size() < pow(2, i)) {
                leaf = i > 2 ? pow(2, i - 2) - 1 : 1;
                break;
            }
        }
        for (int i = leaf; i < scoville.size(); i++) {
            int child = i;
            do {
                int root = (child - 1) / 2;
                if (scoville[child] < scoville[root])
                    swap(scoville[child], scoville[root]);
                child = root;
            } while (child != 0);
        }
        if (scoville[0] >= K) return answer;
        answer++;

        scoville[0] += scoville[1] < scoville[2] ? scoville[1] * 2 : scoville[2] * 2;
        scoville.push_back(scoville[0]);
        scoville.erase(scoville.begin(), scoville.begin() + 2);
    }
}