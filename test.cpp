#include<bits/stdc++.h>
using namespace std;
#define N 10
bool is_space(char grid[N][N],int & row,int & col,string & s,int & a)
{
    int k;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            a=-1;
            if(grid[i][j]!='+')
            {
                row=i;
                col=j;
                s=s+grid[i][j];
                k=col+1;
                while(grid[row][k]!='+' && k<N)
                {
                    s=s+grid[row][k];
                    if(grid[row][k]=='-')
                    {
                        a=0;
                    }
                    k++;
                }
                if(a==0)
                {
                    return true;
                }
                k=row+1;
                while(grid[k][col]!='+' && k<N)
                {
                    s=s+grid[k][col];
                    if(grid[k][col]=='-')
                    {
                        a=1;
                    }
                    k++;
                }
                if(a==1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool solve_crossword(char grid[N][N],vector<string> v)
{
    int row,col,a;
    string s="";
    if(!is_space(grid,row,col,s,a))
    {
        return true;
    }
    bool flag=false;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='-')
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
     	for(int i=0;i<v.size();i++)
    	{
        	if(s.size()==v[i].size() && !visit[i])
        	{
                bool flag_1=false;
            	for(int j=0;j<s.size();j++)
            	{
                	if(s[j]!='-' && s[j]==v[i][j])
                    {
                       flag_1=true; 
                    }
                    
            	}
                if(flag_1)
                {
                    if(a==0)
                        {
                            for(int k=0;k<s.size();k++)
                            {
                                grid[row][k+col]=v[i][k];
                            }
                        	visit[i]=true
                            if(solve_crossword(grid,v,visit))
                            {
                                return true;
                            }
                        	visit[i]=false;
                        	for(int k=0;k<s.size();k++)
                            {
                                grid[row][k+col]=s[k];
                            }
                        }
                        else if(a==1)
                        {
                            for(int k=0;k<s.size();k++)
                            {
                                grid[k+row][col]=v[i][k];
                            }
                            visit[i]=true;
                            if(solve_crossword(grid,v,visit))
                            {
                                return true;
                            }
                            visit[i]=false;
                            for(int k=0;k<s.size();k++)
                            {
                                grid[k+row][col]=s[k];
                            }
                        }
                }
        	}
    	}   
    }
    else
    {
        for(int i=0;i<v.size();i++)
    	{
        	if(s.size()==v[i].size() && !visit[i])
        	{
                if(a==0)
                {
                    for(int k=0;k<s.size();k++)
                    {
                        grid[row][k+col]=v[i][k];
                    }
                    visit[i]=true;
                    if(solve_crossword(grid,v,visit))
                    {
                        return true;
                    }
                    visit[i]=false;
                    for(int k=0;k<s.size();k++)
                    {
                        grid[row][k+col]=s[k];
                    }
                }
                else if(a==1)
                {
                    for(int k=0;k<s.size();k++)
                    {
                        grid[k+row][col]=v[i][k];
                    }
                    visit[i]=true;
                    if(solve_crossword(grid,v,visit))
                    {
                        return true;
                    }
                    visit[i]=false;
                    for(int k=0;k<s.size();k++)
                    {
                        grid[k+row][col]=s[k];
                    }
                }
            }
        }
    }
    return false;
    
}
int main()
{
    char grid[N][N];
    for(int i=0;i<N;i++)
    {
     	for(int j=0;j<N;j++)
        {
            cin>>grid[i][j];
        }
    }
    string s;
    cin>>s;
    vector<string> v;
    string a;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==';')
        {
            v.push_back(a);
            a="";
        }
        else if(i==s.size()-1)
        {
            a=a+s[i];
            v.push_back(a);
        }
        else
        {
            a=a+s[i];
        }
    }
    bool * visit=new bool[v.size()];
    for(int i=0;i<count;i++)
    {
        visit[i]=false;
    }
	solve_crossword(grid,v,visit);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}