#include <bits/stdc++.h>

using namespace std;
/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
int findPar(int par[],int n,int x)
{
    if(par[x] == x)
      return x;
    
    int y = par[x];
    return findPar(par,n,y);
}
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int par[n];
    for(int i=0;i<n;i++)
    {
        par[i] = i;
    }
    
    // 0 -> 0
    // 1-> 1
    // 2-> 2
    // 3-> 3
    // 4-> 4
    
    int pairsNum = astronaut.size();
    map<int,vector<int>> mapOfParChild;
    for(int i=0;i<pairsNum;i++)
    {
        if(par[astronaut[i][1]]==astronaut[i][1])
          par[astronaut[i][1]] = par[astronaut[i][0]];
        else
         {
            int parA = par[astronaut[i][0]];
            int parB = par[astronaut[i][1]];
            if(parA == astronaut[i][0])
              par[astronaut[i][0]] = parB;
            else
              {
                  int tempPar = findPar(par,n,astronaut[i][0]);
                  par[tempPar] = parB;
              }
            
         }
    }
    // par[2] =0;
    // par[8] = 1;
    // par[4] = 1;
    // par[2] = 1;
    // par[6] = 1;
    // par[5] = 3;
    // par[9] = 1
    for(int i=0;i<n;i++)
    {
        int parent;
        parent = findPar(par,n,i);
        par[i] = parent;
        cout<<i<<" "<<par[i]<<endl;
        mapOfParChild[parent].push_back(i);
    }
    long long sizeOfMap = mapOfParChild.size();
    long long ans = 0;
    vector<int> sizeArray;
    for(auto itr:mapOfParChild)
    {
       vector<int> v = itr.second;
       sizeArray.push_back(v.size());
    }
    // 6 4 5
    // 6 * 4
    // 5 * 6
    // 5 * 4
    for(int i=1;i<sizeOfMap;i++)
    {
        for(int j=0;j<i;j++)
        {
            ans += sizeArray[j] * sizeArray[i];
        }
    }
    return ans;
}

// 5 3
// 0 1
// 2 3
// 0 4


// par[n] = {-1}
// par[1] = 0;
// par[3] = 2;
// par[4] = 0;
// par[0] = 0;
// par[2] = 2;

// 0 -> 0
// 1 -> 0;
// 2 -> 2;
// 3 -> 2;
// 4 -> 0;

int main()
{
    // cout<<"Hello World";
    vector<vector<int>> astronaut;
    // test case 1
    // astronaut.push_back({0,2});
    // astronaut.push_back({1,8});
    // astronaut.push_back({1,4});
    // astronaut.push_back({2,8});
    // astronaut.push_back({2,6});
    // astronaut.push_back({3,5});
    // astronaut.push_back({6,9});
    // cout<<journeyToMoon(10,astronaut);
    // answer 23
    
    // astronaut.push_back({0,1});
    // astronaut.push_back({2,3});
 
    astronaut.push_back({0,2});
    cout<<journeyToMoon(4,astronaut);
    // (0,2) (1) (3)
    //(0,1,2,4,6,8,9), (3,5) (7) -> 2*7 + 7*1+2*1
    // 2 -> 1 
    // 8 -> 1 
    // 4 -> 1 
    // 
    return 0;
}


