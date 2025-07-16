class Solution {
public:
    int strStr(string txt, string pat) {
        int m=pat.size();
        int n=txt.size();
        for(int i=0;i<txt.size();i++){
            if(txt[i]==pat[0]){
                int j=i+1;
                int k=1;
                while(j<n && txt[j]==pat[k]){
                    j++;
                    k++;
                }
                if(k==m) return i;
            }
        }
        return -1;
    }
};