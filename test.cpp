int go(string s1, string s2, int i, int j, int** dp){
    int m = s1.size();
    int n = s2.size();

    //cout << m<<" "<<n << '\n';

    if (i > m-1)
    {
        return n-j;
    }

    if (j > n-1)
    {
        return m-i;
    }

    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if (s1[i] == s2[j])
    {
        dp[i][j] = 1 + go(s1, s2, i+1, j+1, dp);
        return dp[i][j];
    }else{
        dp[i][j] = min(1+go(s1, s2, i+1, j, dp), 1+go(s1, s2, i, j+1, dp));
        return dp[i][j];
    }

}