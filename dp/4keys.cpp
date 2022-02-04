long long int optimalKeys(int N){
        
        //1. Observational approach
       if(N<=6)
        return N;//if n<=6,then the max length we can get is by printing all the A's by using the 1st operation
        
        // code here
        
        vector<int>v(N+1);
        
        for(int i=1;i<=6;i++)
        {
            v[i]=i;//for n<=6,max len would be n
        }
        for(int i=7;i<=N;i++)
        {
            v[i]=max(2*v[i-3],max(3*v[i-4],4*v[i-5]));//now the logic here is through observation that there isnt any need to use ctrl-v more than thrice from the end ...it's better to use ctrl-a,ctrl-c,ctrl-v before that
//Eg:n=11..Optimal operations are
//A,A,A,ctrl-a,ctrl-c,ctrl-v,ctrl-v,ctrl-a,ctrl-c,ctrl-v,ctrl-v
//1,2,3,3,3,6,9,9,9,18,9  ->lengths on each stage...so you can see that in any stage its of no use to apply ctrl-v op more than thrice

            
        }
        return v[N];
        
        
        //2. recursion approach...We will get a tle in this case
        //T.C -> O(n^2)
        //By observation we came to the conclusion that there exists a breakpoint after which you will only find the ops ctrl-a,ctrl-c,ctrl-v(multiple times) and that breakpoint will come only after n-3,cuz atleast ctrl-a,ctrl-c
        //ctrl-v once
        
       /* if(N<=6)
        return N;
        int maxi=0;
        for(int i=N-3;i>=1;i--)
        {
            int curr=(N-i-1)*optimalKeys(i);
            maxi=max(maxi,curr);
            
        }
        return maxi;*/
        
        //3.)Recursion+memoization
       /* if(N<=6)
        return N;
        vector<int>dp(N+1,-1);
        if(dp[N]!=-1)
        return dp[N];
        
        for(int i=1;i<=6;i++)
        dp[i]=i;
        
        
        for(int i=7;i<=N;i++)
        {
            dp[i]=0;
            for(int j=i-3;j>=1;j--){
                int curr=(N-j-1)*optimalKeys(j);
            dp[i]=max(dp[i],curr);
            }
        }
        
        return dp[N];*/
        
        
    }
