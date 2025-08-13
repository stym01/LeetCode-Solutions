class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mpp;
        int cnt=0;
        for(auto it:chars) mpp[it]++;
        for(auto it:words){
            unordered_map<char,int>mpp2=mpp;
            int flag=0;
            for(auto c:it){
                if(mpp2[c]<=0) {
                    flag=1;
                    break;
                }
                mpp2[c]--;
            }
            if(flag==0) cnt+=it.size();

        }
        return cnt;
    }
};