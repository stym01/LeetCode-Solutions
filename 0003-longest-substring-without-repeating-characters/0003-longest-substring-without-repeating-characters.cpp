class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int len=0;
        map<char,int>mpp;
        while(j<n){

            if(mpp[s[j]]>0){
                i=max(i,mpp[s[j]]);
            }
            mpp[s[j]]=j+1;

            len=max(len,j-i+1);
            j++;
            cout<<len<<" "<<i<<" "<<j<<endl;
        }
        return len;
    }
};