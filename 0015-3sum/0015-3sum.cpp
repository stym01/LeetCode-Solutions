class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(),a.end());
        
        vector<vector<int>>ans;
        int n=a.size();
        int i=0;
        set<vector<int>>st;
        while(i<n-2){
            if(i>0 && a[i]==a[i-1]) {i++;
            continue;}
            int j=i+1;
            int k=n-1;
            while(j<k){
                int x=a[i]+a[j]+a[k];
                if(x>0)
                k--;
                else if(x<0) j++;
                else{
                    vector<int>temp={a[i],a[j],a[k]};
                    ans.push_back(temp);
                    int last= a[j], last_high_occurrence = a[k];
                    while(j<k && a[j]==last)
                    {j++;}
                    while(j<k && a[k]==last_high_occurrence)
                    {k--;}
                }
            }
            i++;
        }
        return ans;
    }
};