class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n<=1) return "";
        bool flag=0;
        for(int i=0;i<n/2;i++){
            char ch=palindrome[i];
            for(char c='a';c<ch;c++){
                palindrome[i]=c;
                flag=1;
                break;
            }
            if(flag) break;
        }
        if(!flag){
            palindrome[n-1]++;
        }
        return palindrome;
    }
};