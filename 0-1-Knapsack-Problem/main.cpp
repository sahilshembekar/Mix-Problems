
#include <iostream>

#include<bits/stdc++.h>
using namespace std;
#include <vector>

//Time Complexity = Exponential
//Space Complexity = O(N)
//Where N is the size of the vector weight.

int helper(vector<int> v, vector<int> w, int c, int index, int profit)  {
    //base logic
    
    if (index == v.size()) {
        return profit;
    }
    if (c-w[index] < 0) {
        return profit;
    }
    
    
    //logic
    //Not Choose
    int case1 = helper(v, w, c, index + 1,  profit);
    
    //Choose
    int case2 = helper(v, w, c - w[index], index + 1,  profit + v[index]);
    
    return max(case1,case2);
    
}
int main() {
    //vector<int> v{1,2,6},w{2,3,5};
    vector<int> v{60,100,120}, w{10,20,30};

    //int c=8;
    int c = 50;
    cout<< helper(v,w,c,0,0) <<endl;
    return 0;
}


// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#


//Time Complexity = O(M*N)
//Space Complexity = O(M*N) 
//Where M is the capacity of knapsack provided and N is the size of the vector weight.

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int columns = W;
       int row = n;
       
       int dp[row+1][columns+1];
       
       for (int i=0; i<=row; i++) {
           dp[i][0] = 0;
       }
       
       for (int j=0; j<=columns; j++) {
           dp[0][j] = 0;
       }
       
       // Matrix Insertion
       
       for (int i=1; i<=row; i++) {
           for (int j =1 ; j<=columns; j++) {
               
               if (j < wt[i-1]) {
                   dp[i][j] = dp[i-1][j];
               }
               else {
                   dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i-1]] + val[i-1]); 
               }
        
           }
       }
       return dp[row][columns];
       
    }
};



// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends