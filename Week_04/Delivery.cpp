class Solution {
public:
int findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int gindex = 0, sindex = 0;
	while (gindex != g.size() && sindex != s.size())
	{
		if (g[gindex] <= s[sindex])
		{
			gindex++;
			sindex++;
		}
		else
			sindex++;
	}
	return gindex;
}
};