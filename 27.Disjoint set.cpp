#include<bits/stdc++.h>
using namespace std;
int main()
{
    int parent[100];
    int rankArr[100];

void makeSet(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}
int findParent(int node) {
    if (parent[node] == node)
        return node;
    parent[node] = findParent(parent[node]);
    return parent[node];
}
void unionSet(int u, int v) {
    int parentU = findParent(u);
    int parentV = findParent(v);

    if (parentU != parentV) {
        if (rankArr[parentU] < rankArr[parentV])
            parent[parentU] = parentV;
        else if (rankArr[parentV] < rankArr[parentU])
            parent[parentV] = parentU;
        else {
            parent[parentV] = parentU;
            rankArr[parentU]++;
        }
    }
}
int main() {
    int n = 5;
    makeSet(n);

    unionSet(1, 2);
    unionSet(3, 4);
    unionSet(2, 3);

    if (findParent(1) == findParent(4))
        cout << "1 and 4 belong to the same set.\n";
    else
        cout << "1 and 4 belong to different sets.\n";

    if (findParent(1) == findParent(5))
        cout << "1 and 5 belong to the same set.\n";
    else
        cout << "1 and 5 belong to different sets.\n";

    return 0;
}
