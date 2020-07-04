// [https://leetcode.com/submissions/detail/362035602/]
class Solution {
    #define LM 15
    int prerequisite[LM];
    int n,k;
    int dp[1<<LM];
    
    int sol(int mask) {
        if(mask == (1<<n) - 1) {
            return 0;
        }
        
        int &ret = dp[mask];
        if(~ret) {
            return ret;
        }
        
        ret = 15;
        
        int candidate = 0;
		
        //mask for courses which can be taken in current semester.
        for(int course = 0;course<n;++course) {
            if(((mask&(1<<course)) == 0 && (prerequisite[course]&mask) == prerequisite[course])) {
                candidate |= (1<<course);
            }
        }
        
		//trying all possible way (sum mask) of the candidate mask.
        //sub masking [https://cp-algorithms.com/algebra/all-submasks.html]
        for(int subMask = candidate; subMask>0; subMask = (subMask-1)&candidate) {
            if(__builtin_popcount(subMask)<=k){
                ret = min(ret,sol(subMask|mask)+1);
            }
        }
        
        return ret;
    }
    
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        memset(dp,-1,sizeof(dp));
        for(auto edge: dependencies) {
            prerequisite[edge.back()-1] |= (1 << (edge.front()-1));
        }
        this->n = n, this->k = k;
        return sol(0);
    }
};