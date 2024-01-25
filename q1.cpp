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
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
     int ans=   solveusingrecursion(text1,text2,i,j,dp);
     return ans;
    }
};
EXPLANATION
in this problem we just need to figure out the length,here two case can be there in first ne if s1[i]==s2[j] then we just need to pass rest strings ,also add one
if not then we need to get the max ofs1 string by passing it recursion and s2 string
