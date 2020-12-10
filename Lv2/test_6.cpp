#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int bridge_weight, vector<int> wait_queue) {
    int answer = 0, b_front = 0, w_front = 0, truck_weight = 0;
    vector<int> bridge_queue, bridge_n_queue;
    while (true) {
        if (w_front < wait_queue.size()) {
            if (bridge_weight >= truck_weight + wait_queue[w_front]) {
                bridge_queue.push_back(bridge_length);
                bridge_n_queue.push_back(wait_queue[w_front]);
                truck_weight += wait_queue[w_front++];
            }
        }

        for (int i = b_front; i < bridge_queue.size(); i++)
            bridge_queue[i]--;
        answer++;

        if (b_front == bridge_queue.size()) break;

        if (!(bridge_queue[b_front])) {
            truck_weight -= bridge_n_queue[b_front];
            b_front++;
        }
    }
    return answer;
}