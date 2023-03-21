// IMPLEMENT 0/1 KNAPSACK

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weights, vector<int> profits, int w, int n) {
    if(n==weights.size() || w==0) return 0;
    if(weights[n]>w) return knapsack(weights, profits, w, n+1);
    return max(profits[n]+knapsack(weights, profits, w-weights[n], n+1), knapsack(weights, profits, w, n+1));
}

int main() {
    vector<int> weights={10,20,30}, profits={60,100,120};
    int w=50;

    cout<<knapsack(weights, profits, w, 0)<<endl;

    return 0;
}