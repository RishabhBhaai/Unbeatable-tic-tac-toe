/*
  Created by: RISABH
  College   :Delhi technological University
*/
//#include<bhaai.h>
#include<bits/stdc++.h>
using namespace std;
#define to int64_t
#define mo 1000000007
#define fr(a,e) for(int i=a;i<=e;i++)
#define yah_faster_baby ios_base::sync_with_stdio(0);cin.tie(0);

char s;
struct we{
  char a[3][3]={{'O','2','3'},{'4','5','6'},{'7','8','9'}};
  int next;
  char u;
};

void show(we x)
{
 cout<<x.a[0][0]<<" | "<<x.a[0][1]<<" | "<<x.a[0][2]<<"\n";
 cout<<"_________\n";
 cout<<x.a[1][0]<<" | "<<x.a[1][1]<<" | "<<x.a[1][2]<<"\n";
 cout<<"_________\n";
 cout<<x.a[2][0]<<" | "<<x.a[2][1]<<" | "<<x.a[2][2]<<"\n\n\n";
}
int check_winner(we x,char q)
{int y=0;
 fr(0,2)
 for(int j=0;j<3;j++)
 y+=((x.a[i][j]<='9'&&x.a[i][j]>='1')?1:0);
 
 for(int i=0;i<3;i++)
  if(x.a[i][0]==q&&x.a[i][1]==q&&x.a[i][2]==q)
  return y+1;
 
 for(int i=0;i<3;i++)
  if(x.a[0][i]==q&&x.a[1][i]==q&&x.a[2][i]==q)
  return y+1;
 
 if(x.a[0][0]==q&&x.a[1][1]==q&&x.a[2][2]==q)
 return y+1;

 if(x.a[0][2]==q&&x.a[1][1]==q&&x.a[2][0]==q)
 return y+1;

 return 0;
}
bool draw(we x)
{fr(0,2)
 for(int j=0;j<3;j++)
 if(x.a[i][j]<='9'&&x.a[i][j]>='1')
 return false;
 return true;
}
bool com(we x,we y)
{fr(0,2)
 for(int j=0;j<3;j++)
 if(x.a[i][j]!=y.a[i][j])
 return false;
 return true;
}
vector <int> v[60000]; 
vector<we> r;
int dfs(int a)
{int y;
 if((int)v[a].size()==0)
 {if(draw(r[a]))
  return 0;
  y=check_winner(r[a],'X');
  if(y)
  return -1*y;
  y=check_winner(r[a],'O');
  if(y)
  return y; 
 }
 if(r[a].u=='X')
 {int z=20,w;
  for(auto i:v[a])
  {w=dfs(i);
   
   if(w<z)
   {z=w;y=i;}
  }
  r[a].next=y;
  return z;
 }

 int z=-20,w;
 for(auto i:v[a])
 {w=dfs(i);
  
  if(w>z)
  {z=w;y=i;}
 }
 r[a].next=y;
 return z;
}
void minimax(){
   we x;
   x.u='X';
   r.push_back(x);
   int i=0,j=0;
   while(i<=j)
   {for(int p=0;p<3;p++)
    for(int q=0;q<3;q++)
    x.a[p][q]=r[i].a[p][q];
    
    if(r[i].u=='X') x.u='O';
    else x.u='X';
    
    if(draw(x)||check_winner(x,x.u))
    {i++;continue;}

    for(int p=0;p<3;p++)
    for(int q=0;q<3;q++)
    if(x.a[p][q]!='O'&&x.a[p][q]!='X')
    {x.a[p][q]=r[i].u;
     
     j++;
     r.push_back(x);
     v[i].push_back(j);
     
     x.a[p][q]=(3*p+q+1+'0');
    }
    i++;
   }
   dfs(0);
}
int main()
{   yah_faster_baby
    minimax();
    int n,c,k;
    cout<<"Welcome to this tic tac toe game, I am unbeatable, wanna try?             \n"; 
    
    while(1)
    {
     cout<<"Enter the number of the spot you wanna place your mark\n";
     cout<<"I will go first\n";
     we y;
     c=1;k=0;
     while(!(draw(y)||check_winner(y,'X')||check_winner(y,'O')))
     {if(c)
      {
       show(y);
       cin>>n;
       --n;
       if(n<0||n>8||!(y.a[n/3][n%3]<='9'&&y.a[n/3][n%3]>='1'))
       {cout<<"Invalid move, enter the number corresponding to an empty            spot\n";
        break;
       }
       y.a[n/3][n%3]='X';
      }
      else
      {for(auto i:v[k])
       if(com(r[i],y))
       {k=i;break;}
       k=r[k].next;
       for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
       y.a[i][j]=r[k].a[i][j];
      }
      c=(c+1)%2;
     }
     show(y);
     if(check_winner(y,'X'))
     cout<<"You won, you have done the impossible\n";
     else if(check_winner(y,'O'))
     cout<<"I won, I am unbeatable\n";
     else
     cout<<"match drawn, I am still unbeatable\n";
     cout<<"\n";
     cout<<"Wanna play again? y/n? \n";
     cin>>s;
     if(s!='y')
     break;
    }     
    
    return 0;
}

