class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {

        unordered_map<string,int>taken;
        vector<string>ans;
        for(auto it:names){
            if(taken.find(it)==taken.end()){
                ans.push_back(it);
                taken[it]=1;
            }
            else{
                int k=taken[it];
                string temp=it;
                temp+='(';
                temp+=to_string(k);
                temp+=')';
                while(taken.find(temp)!=taken.end()){
                    k++;
                    temp=it+"("+to_string(k)+")";
                }

                ans.push_back(temp);
                taken[it]=k+1;
                taken[temp]=1;
            }
        }
        return ans;


    }
};