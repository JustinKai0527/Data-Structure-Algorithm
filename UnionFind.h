#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_

#include <iostream>
#include <vector>

using namespace std;


class UnionFind{
public:
     UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(root[x] == x)  return x;
        else  return root[x] = find(root[x]);
    }

    void Union(int x, int y){
        if(find(x) == find(y))  return;
        else{
            int rootx = find(x);
            int rooty = find(y);
            if(rank[rootx] > rank[rooty]){
                root[rooty] = root[rootx];
            }
            else if(rank[rootx] < rank[rooty]){
                root[rootx] = root[rooty];
            }
            else{
                root[rooty] = root[rootx];
                rank[rootx]++;
            }
        }
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
private:
    vector<int> root;
    vector<int> rank;
    int count;
};
#endif