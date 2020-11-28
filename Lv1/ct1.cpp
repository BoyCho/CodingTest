#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> queue;

    for (int itr : moves) {
        itr--;
        for (int i=0; i < board.size(); i++) {
            if (board[i][itr] != 0) {
                if (!queue.empty() && queue.top() == board[i][itr]) {
                    queue.pop();
                    answer += 2;
                }
                else  // 큐가 비었거나, 새로운 인형을 잡거나
                    queue.push(board[i][itr]);
                board[i][itr] = 0;
                break;
            }
        }
    }
    return answer;
}