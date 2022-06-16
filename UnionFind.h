#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_

#include <iostream>
#include <vector>

using namespace std;


class UnionFind{
public:
    UnionFind(int size){
        capacity = size;
        root.resize(size);
        rank.resize(size);

        for(int i=0; i<size; i++){
            rank[i] = 0;
            root[i] = i;
        }
    }

    int find(int x){
        if(root[x] == x)  return x;
        else  return root[x] = find(root[x]);
    }

    void Union(int x, int y){
        
    }

    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
private:
    vector<int> root;
    vector<int> rank;
    int capacity;
};
#endif