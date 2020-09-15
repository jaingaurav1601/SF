/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define vdsort(v) sort(v.begin(), v.end(),greater<int>())
int gcd(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
   
    if (a == b) 
        return a; 
   
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 

bool cp(int a, int b) 
{    
    return (gcd(a, b) == 1); 
} 
  
void findPair(int a[], int n) 
{  
      
    int count = 0;  
    for (int i = 0; i < n - 1; i++)  
    {
        for(int j=i+1; j<n;j++)
        {
            if(cp(a[i],a[j]))
            {
                cout<<'{'<<a[i]<<","<<a[j]<<"}, ";
            }
        }
    }
                  
} 

void findLargestSum(int a[], int n)
{
    int max_sum= -2e5;
    int i,j;
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=i;j<n;j++)
        {
            sum+=a[j];
            max_sum=max(max_sum,sum);
        }
    }
    cout<<max_sum;
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    findLargestSum(arr,n);
    
}
int main()
{
    solve();
    return 0;
}


