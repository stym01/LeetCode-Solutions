class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j=1;
        int n=chars.size();
        if(chars.size()==1) return 1;
        char c=chars[0];
        int cnt=1;
        while(j<n){
            
            while(j<n && chars[j]==c){
                cnt++;
                j++;
            }
            char next;
            if(j<n)
                next=chars[j];
            
            chars[i++]=c;
            string s=to_string(cnt);
            cout<<s<<" "<<i<<"\n";

            for(int k=0;k<s.size();k++){
                if(cnt!=1)
                    chars[i++]=s[k];
            }
            if(j<n){
                c=next;
                cnt=0;
            }
        }
        return i;

    }
};