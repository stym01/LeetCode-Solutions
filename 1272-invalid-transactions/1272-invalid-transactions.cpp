class Solution {
public:
    class Transaction{
        public:
        int time,dur;
        string name,city;

        Transaction(string s){
            vector<string>temp;
            int j=0;
            for(int i=0;i<=s.size();i++){
                if(i==s.size() || s[i]==','){
                    temp.push_back(s.substr(j,i));
                    j=i+1;
                }
            }
            name=temp[0];
            time=stoi(temp[1]);
            dur=stoi(temp[2]);
            city=temp[3];
        }
        

    };
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>ans;
        int n=transactions.size();
        map<int,Transaction*>mpp;
        for(int i=0;i<n;i++){
            Transaction *t=new Transaction(transactions[i]);
            mpp[i]=t;
        }
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            string name1,name2;
            int time1,time2;
            int dur1,dur2;
            string city1,city2;
            
            name1=mpp[i]->name;
            time1=mpp[i]->time;
            dur1=mpp[i]->dur;
            city1=mpp[i]->city;

            for(int j=0;j<n;j++){
                if(j==i) continue;

                name2=mpp[j]->name;
                time2=mpp[j]->time;
                dur2=mpp[j]->dur;
                city2=mpp[j]->city;


                if(name1==name2){
                    if(city1!=city2){
                        if(abs(time1-time2)<=60){
                            if(temp[i]==0)
                                ans.push_back(transactions[i]);
                            if(temp[j]==0)
                                ans.push_back(transactions[j]);
                            temp[i]=1;
                            temp[j]=1;
                        }  
                    }
                }
            }
            if(dur1>1000 && temp[i]==0) ans.push_back(transactions[i]);   
        }
        
        return ans;
    }
};