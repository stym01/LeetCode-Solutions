/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:



    int getImportance(vector<Employee*> employees, int id) {
        map<int,Employee*>mpp;
        for(auto it:employees){
            mpp[it->id]=it;
        }
        queue<Employee*>q;
        int cnt=0;
        q.push(mpp[id]);
        while(!q.empty()){
            Employee*temp=q.front();
            q.pop();
            cnt+=temp->importance;

            for(auto it:temp->subordinates){
                q.push(mpp[it]);
            }

        }
        return cnt;
    }
};