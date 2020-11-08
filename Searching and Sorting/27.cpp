#include<bits/stdc++.h>
using namespace std;
// O(n^2) 
class job{
public:
    int start;
    int end;
    int profit;
};
bool mycompare(job a, job b){
//sort acc to ascending end time of jobs
    return a.end < b.end;
}

int find(vector<job>& jobs,int i){
    int curr_job_start = jobs[i].start;
    i--;
    while(i >= 0 && jobs[i].end > curr_job_start){
        i--;
    }
    if(i<0)
        return -1;
    return i;
}

int maxProfix(vector<job>& jobs){
    int n = jobs.size();
    //dp[i] stores max profit till ith job (har job pe ek choice hota h ki usse le ya na le)
    int* dp = new int[n];
    dp[0] = jobs[0].profit;
    
    for(int i=1;i<n;i++){
        int latestNonConflictingJobIndex = find(jobs,i);
        if(latestNonConflictingJobIndex == -1)
            dp[i] = max(dp[i-1],jobs[i].profit);
        else 
            dp[i] = max(dp[i-1] , jobs[i].profit + dp[latestNonConflictingJobIndex]);
    }

    int profit = INT_MIN;
    for(int i=0;i<n;i++){
        if(dp[i]>profit)
            profit = dp[i];
    }
    delete [] dp;
return profit;
}

int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 

    int n;//no of jobs
    cin>>n;
    vector<job> jobs;
    for(int i=0;i<n;i++){
        int s,e,p;
        cin>>s>>e>>p;
        job j;
        j.start = s;
        j.end = e;
        j.profit = p;
        jobs.push_back(j);
    }
    //sort acc to ascending end time of jobs
    sort(jobs.begin(),jobs.end(),mycompare);
   
    cout<<maxProfix(jobs)<<endl;
   
    return 0;
}