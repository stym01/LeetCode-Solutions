class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mpp;
        int cnt=0;
        int flag=0;
        for(int i=0;i<words.size();i++){
            string s = words[i];
            reverse(s.begin(),s.end());

            if(mpp[s]!=0){
                mpp[s]--;
                cnt+=4;
            }
            else{
                mpp[words[i]]++;
            }
        }

        for(auto it:mpp){
            if(it.second>0){
                string s=it.first;
                reverse(s.begin(),s.end());
                if(s==it.first){
                    cnt+=2;
                    break;
                }
            }

        }

        // if(flag%2==1) cnt+=2;
        return cnt;

    }
};