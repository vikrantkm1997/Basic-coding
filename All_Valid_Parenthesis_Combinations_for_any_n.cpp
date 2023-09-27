//Simpl Interview round 1 DSA question
#include <iostream>
#include<string>
#include<vector>
using namespace std;
bool checkString(string st)
{
    if(st == "")
      return true;
    int n = st.length();
    int  k =0;
    for(int i=0;i<n;i++)
    {
        if(st[i] == '[')
        {
            k++;
        }
        else
        {
            k--;
            if(k<0)
              return false;
        }
    }
    
    if(k==0) 
     return true;
    
    return false;
}
void getValidCombination (vector<string> &res,int size,int index,string currString,int parenthesisCheck)
{
    if(index == size)
    {
        // cout<<"sc"<<checkString(currString)<<endl;
        // if(checkString(currString)) //checking if its valid parenthesis
        //  res.push_back(currString);
        if(parenthesisCheck == 0)
         res.push_back(currString);
        return;
    }
    if(parenthesisCheck<0)
      return;
    currString = currString + "[";
    parenthesisCheck++;
    getValidCombination(res,size,index+1,currString,parenthesisCheck);
    parenthesisCheck--;
    currString.pop_back();

    currString = currString + "]";
    parenthesisCheck--;
    getValidCombination(res,size,index+1,currString,parenthesisCheck);
    parenthesisCheck++;
    currString.pop_back();
    
}
int main()
{
    
    vector<string> res;
    // N=1 rex = ["[]"]
    // n=2 res 
    int n;
    cin>>n;
    string currString;
    int parenthesisCheck = 0; 
    getValidCombination(res,2*n,0,currString,parenthesisCheck);
    int sz = res.size();
    for(int i=0;i<sz;i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}
