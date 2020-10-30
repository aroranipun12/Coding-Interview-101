class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return intervals;
        sort(intervals.begin(),intervals.end());
	 pair<int,int> p;
	int ptr = 0;
	p.first = intervals[ptr][0];
	p.second = intervals[ptr][1];
	/*cout<<p.first<<endl;
	cout<<p.second<<endl;
	*/
	ptr++;
	vector<vector<int>> solution;
		int flag=0;
		while(ptr<intervals.size())
		{
			if(intervals[ptr][0] <= p.second)//means overlapping
			{
				p.second = max(p.second,intervals[ptr][1]);
				ptr++;
				flag=1;
			}
			else{
				
				solution.push_back({p.first,p.second});
				//cout<<p.first<<" "<<p.second<<endl;
				p.first = intervals[ptr][0];
				p.second = intervals[ptr][1];
				ptr++;
				
				
			}
		}
		solution.push_back({p.first,p.second});
return solution;
        
    }
};