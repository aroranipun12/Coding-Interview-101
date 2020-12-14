// FINAL

#include <bits/stdc++.h>

using namespace std;

void RCB(int numBoxes, int *start, int *end, int *queries, int q)
{
    int *coins = new int[numBoxes+1];
    
    coins[1] = start[1];
    
    for(int i=2; i<= numBoxes; i++)
    {
        coins[i] = coins[i-1] + start[i] - end[i-1];
    }
    
    int *numberOfCoins = new int[numBoxes+1];   
    
    for(int i=1; i<=numBoxes; i++)
    {
        numberOfCoins[i] = 0;
    }
    
    for(int i=1; i<=numBoxes; i++)
    {
        numberOfCoins[coins[i]]++;
    }
    
    for(int i=numBoxes; i>=2; i--)
    {
        numberOfCoins[i-1] += numberOfCoins[i];
    }
    
    for(int i=0; i<q; i++)
    {
        if(queries[i] > numBoxes){
            cout<<0<<endl;
        }
        else
            cout << numberOfCoins[queries[i]] << endl; 
    }
    
    delete coins;
    delete numberOfCoins;
    
    return;    
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    
    int *start = new int[n+1];
    int *end = new int[n+1];
    int s, e;
    
    for(int i=1; i<=n; i++)
    {
        start[i] = 0;
        end[i] = 0;
    }
    
    for(int i=0; i<m; i++)
    {
        cin >> s >> e;
        start[s]++;
        end[e]++;
    }
    
    int q;
    cin >> q;
    int *queries = new int[q];
    
    for(int i=0; i<q; i++)
    {
        cin >> queries[i];
    }
    
    RCB(n, start, end, queries, q);
    
    delete queries;
    delete start;
    delete end;
    
    return 0;
}