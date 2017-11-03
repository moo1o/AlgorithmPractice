#include <iostream>
#include <queue>

using namespace std;
const int MAX = 200000;
int dist[MAX + 1];
bool check[MAX + 1];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    queue<int> q;
    q.push(n);
    check[n] = true;
    dist[n] = 0;
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        
        if (now - 1 >= 0) {
            if (check[now - 1] == false) {
                q.push(now - 1);
                check[now - 1] = true;
                dist[now - 1] = dist[now] + 1;
            }
        }
        if (now + 1 < MAX) {
            if (check[now + 1] == false) {
                q.push(now + 1);
                check[now + 1] = true;
                dist[now + 1] = dist[now] + 1;
            }
        }
        if (2 * now < MAX) {
            if (check[2 * now] == false) {
                q.push(2 * now);
                check[2 * now] = true;
                dist[2 * now] = dist[now] + 1;
            }
        }
    }

    
    printf("%d\n", dist[k]);
    
    return 0;
}
