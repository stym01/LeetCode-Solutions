class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mpp;
        int n=s.size();
        if(n<=10) return {};
        string res;
        for(int i=0;i<10;i++){
            res+=s[i];
        }

        mpp[res]++;

        for(int i=10;i<n;i++){
            res.erase(res.begin());
            res+=s[i];
            mpp[res]++;
            cout<<res<<endl;
        }

        for(auto it:mpp){
            if(it.second>1) ans.push_back(it.first);
        }
        return ans;


    }
};