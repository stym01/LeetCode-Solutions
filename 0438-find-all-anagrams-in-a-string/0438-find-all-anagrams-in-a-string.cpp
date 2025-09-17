class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        cout<<pat;
        int k=pat.size();
        int n=txt.size();
        int i=0;
        vector<int>freq(26,0);
        vector<int>freqW(26,0);
        
        for(int l=0;l<k;l++){
            freqW[pat[l]-'a']++;
        }
        vector<int>ans;
        
        int cnt=0;
        int j=0;
        while(j<n){
            
            freq[txt[j]-'a']++;
            
            if(j-i+1==k){
                
                if(freq==freqW){
                    ans.push_back(i);
                }
                
                freq[txt[i]-'a']--;
                
                i++;
                
                
            }
            
            j++;
            
        }
        return ans;
    }
};