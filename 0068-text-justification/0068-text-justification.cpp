class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len=0;
        int i=0;
        int n=words.size();
        vector<vector<string>>temp(n+1);
        for(auto it:words){
            int size=it.size();
            if (temp[i].empty()) {
                if (len + size <= maxWidth) {
                    temp[i].push_back(it);
                    len += size;
                }
            } 
            else if(len+size+1<=maxWidth){
                temp[i].push_back(it);
                len+=size+1;
            }
            else{
                i++;
                temp[i].push_back(it);
                len=size;
            }
        }

        for(auto it:temp){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        vector<string>ans;

        for(int i=0;i<temp.size();i++){
            int wordCnt=temp[i].size();
            if(wordCnt==1){
                string word=temp[i][0];
                for(int j=word.size();j<maxWidth;j++){
                    word+=' ';
                }
                ans.push_back(word);
            }
            else if(wordCnt==0) continue;
            else{
                int lenSentence=0;
                for(int j=0;j<wordCnt;j++){
                    lenSentence+=temp[i][j].size();
                }
                int spaces=maxWidth-lenSentence;
                int oldSpace=spaces;
                spaces=(spaces)/(wordCnt-1);
                string word;
                int extra=oldSpace%(wordCnt-1);
                string space;
                for(int j=0;j<spaces;j++) space+=' ';
                for(int j=0;j<wordCnt;j++){
                    word+=temp[i][j];
                    word+=(j < extra ? " ": "");
                    if(j!=wordCnt-1)
                        word+=space;
                    
                }
                
                ans.push_back(word);

            }
        }

        string word=ans.back();

        vector<string> res;
        string s;
        for(int i=0;i<=word.size();i++){
            if(i>0 && word[i]==' '&& word[i-1]==' ') continue;
            if(i==word.size() || word[i]==' '){
                res.push_back(s);
                s="";
                continue;
            }
            else{
                s+=word[i];
            }
        }
        
        s="";

        for(int i=0;i<res.size();i++){
            s+=res[i];
            if(i!=res.size()-1){
                s+=' ';
            }
        }

        for(int i=s.size();i<maxWidth;i++){
            s+=' ';
        }
        ans.pop_back();
        ans.push_back(s);




        return ans;

    }
};