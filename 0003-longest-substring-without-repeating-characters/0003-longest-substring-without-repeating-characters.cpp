class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int len=0;
        map<char,int>mpp;
        while(j<n){
            cout<<mpp[s[j]]<<"  ";
            if(mpp[s[j]]>0){
                while(i<n && s[i]!=s[j]) {
                    cout<<i<<endl;
                    mpp[s[i]]=0;
                    i++;
                }
                mpp[s[i]]=0;
                i++;
                len=max(len,j-i+1);
    
                mpp[s[j]]=0;
            }
            else{
                mpp[s[j]]++;
                len=max(len,j-i+1);

                j++;
            }
            cout<<len<<" "<<i<<" "<<j<<endl;
        }
        return len;
    }
};