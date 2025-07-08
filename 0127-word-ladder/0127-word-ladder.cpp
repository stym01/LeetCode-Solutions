class Solution {
public:
    int len(string current,string end,unordered_map<string,int>&mpp){
        if(current==end) return 0;
        cout<<current<<endl;
        mpp[current]=0;
        int n=current.size();
        
        int mini=1e9;
        for(int i=0;i<n;i++){
            char ch=current[i];
            for(int j=0;j<26;j++){
                if(ch!=j+'a')
                    current[i]=j+'a';
                if(mpp[current]>0){
                    int length=1+len(current,end,mpp);
                    mini=min(mini,length);
                    mpp[current]=0;
                }
            }
            current[i]=ch;
        }
        return mini;

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mpp;
        for(auto it:wordList){
            mpp[it]++;
        }
        if(mpp[endWord]==0) return 0;
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word=q.front().first;
            int no=q.front().second;
            q.pop();

            if(word==endWord) return no;

            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(int j=0;j<26;j++){
                    word[i]=j+'a';
                    if(mpp[word]>0){
                        mpp[word]=0;
                        q.push({word,no+1});
                    }
                }
                word[i]=ch;
            }


        }
        return 0;

    }
};