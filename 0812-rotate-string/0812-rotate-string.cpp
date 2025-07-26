class Solution {
public:

    void rotate(string &temp){
        char c=temp[0];
        for(int i=1;i<temp.size();i++){
            char x=temp[i];
            temp[i-1]=x;
        }
        int n=temp.size();
        temp[n-1]=c;
    }

    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        string res=s+s;
        return (res.find(goal)==string::npos)?0:1;
    }
};