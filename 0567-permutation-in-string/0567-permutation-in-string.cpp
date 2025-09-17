class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int>mpp(26,0);

        int m=s1.size();
        int n=s2.size();
        int cnt=0;
        int left=0;
        int right=0;
        for(auto it:s1){
            mpp[it-'a']++;
        }
        vector<int>mpp2(26,0);        
        while(right<n){
            mpp2[s2[right]-'a']++;
            if(right-left+1>=m){
                if(mpp2==mpp) return true;
                mpp2[s2[left++]-'a']--;
            }
            right++;
        }
        return false;

    }
};