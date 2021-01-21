#include<iostream>
using namespace std;
bool checkCurrentPos(int a[][10],int i, int j, int k)
{
    int t;
    //for row check
    for(t=1;t<=9;t++)
    {
        if(a[i][t]==k)
            return false;
    }
    
    //for column
    for(t=1;t<=9;t++)
    {
        if(a[t][j]==k)
            return false;
    }
    
    //for sub-2D array check
    int i1,i2,j1,j2;
    if(i%3==0)
    {
        i1=i-2;
        i2=i;
    }
    else if(i%3==1)
    {
        i1=i;
        i2=i+2;
    }
    else if(i%3==2)
    {
        i1=i-1;
        i2=i+1;
    }
    
    
    if(j%3==0)
    {
        j1=j-2;
        j2=j;
    }
    if(j%3==1)
    {
        j1=j;
        j2=j+2;
    }
    if(j%3==2)
    {
        j1=j-1;
        j2=j+1;
    }
    
    for(int t1=i1;t1<=i2;t1++)
    {
        for(int t2=j1;t2<=j2;t2++)
        {
            if(a[t1][t2]==k)
            return false;
            
        }
    }
    
    return true;
}
bool solveSuduko(int a[][10],int i, int j)
{
    if(i>9)
    {
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
			    cout<<a[i][j]<<" ";
        		if(j%3==0 && j!=9)
        		cout<<"| ";
			}
			cout<<endl;
			if(i%3==0)
			{
				for(int k=0;k<21;k++)
					cout<<"-";
				cout<<endl;
			}
				
        }
        return true;
    }
    if(j>9)
    {
        return solveSuduko(a,i+1,1);
    }
    
    if(a[i][j]!=0)
        return solveSuduko(a,i,j+1);
    
    for(int k=1;k<=9;k++)
    {
        if(checkCurrentPos(a,i,j,k))
        {
            a[i][j]=k;
            bool checkNextPos = solveSuduko(a,i,j+1);
            if(checkNextPos)
            {
                return true;
            }
            a[i][j]=0;
        }
    }
    return false;
    
}

int main()
{
    int a[10][10]={{0,0,0,0,0,0,0,0,0,0},
                   {0,5,3,0,0,7,0,0,0,0},
                   {0,6,0,0,1,9,5,0,0,0},
                   {0,0,9,8,0,0,0,0,6,0},
                   {0,8,0,0,0,6,0,0,0,3},
                   {0,4,0,0,8,0,3,0,0,1},
                   {0,7,0,0,0,2,0,0,0,6},
                   {0,0,6,0,0,0,0,2,8,0},
                   {0,0,0,0,4,1,9,0,0,5},
                   {0,0,0,0,0,8,0,0,7,9}};
    solveSuduko(a,1,1);
    return 0;
}
