class Solution {
public:
int solveusingrecursion(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
    int ans=0;
    if(i>=text1.length()){
        return 0;
    }
    if(j>=text2.length()){
        return 0;
    }
    if(dp[i][j]!=-1){
       return dp[i][j];
    }
    if(text1[i]==text2[j]){
        ans=1+solveusingrecursion(text1,text2,i+1,j+1,dp);
    }
    else{
        ans=0+max(solveusingrecursion(text1,text2,i+1,j,dp),solveusingrecursion(text1,text2,i,j+1,dp));
    }
    dp[i][j]=ans;
    return dp[i][j];
}
    int longestPalindromeSubseq(string s) {
        string first=s;
        reverse(s.begin(),s.end());
        string second=s;
       int i=0;
       int j=0;
       vector<vector<int>>dp(first.length(),vector<int>(second.length(),-1));
       return solveusingrecursion(first,second,i,j,dp);
    }
};
// vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));