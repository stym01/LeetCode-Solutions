class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int cnt=0;
        int ind=-1;

        int i=0;
        int j=n-1;

        while(i<j){
            if(people[i]+people[j]<=limit){
                cnt++;
                i++;
                j--;
            }
            else{
                j--;
            }
        }

        return cnt+(n-2*cnt);



    }
};