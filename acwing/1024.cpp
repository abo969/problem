#include<iostream>
using namespace std;
const int N = 39;
const int M = 20009;

int n;      // 物品个数
int V;      // 箱子体积
int v[N];   // 每个物品体积

int f[N][M]; // f[i]：体积为j的物品最大体积

int input() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
}

// 01背包
void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= V; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i-1][j - v[i]] + v[i]);
        }
    }

    cout << V - f[n][V] << endl;
}

int main() {
    input();
    solve();
    return 0;
}