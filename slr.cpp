#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#define epsilon '^'
char prod[20][20],T[20],NT[20],c[10][10],foll[10][10],fir[10][10];
int tt,tnt,tp,a;
int follow[20][20],first[20][20];
void first_of(char);
int count(int j);
void rhs(int j);
void read_tnt();

void read_tnt()
{       cout<<"For SLR parser: ";
        cout<<"\nEnter number of terminals: ";
        cin>>tt;
        cout<<"\nEnter terminals: ";
        for(int i=0;i<tt;i++)
        T[i]=getche();
        getch();
        cout<<"\nEnter number of Non-terminals: ";
        cin>>tnt;
        cout<<"\nEnter Non-terminals: ";
        for(i=0;i<tnt;i++)
               NT[i]=getche();
        getch();      }

void read_prod()
{       int j;
        char x=0;
        cout<<"\n\nEnter number of productions: ";
        cin>>tp;
        cout<<"\n Enter productions: ";
        for(int i=0;i<tp;i++)
        {       j=x=0;
               while(x!='\r')
               {       prod[i][j]=x=getche();
                       j++;    }
               cout<<"\n";             }
        getch();                                      }
  return(i);
if(t=='$')
  return(tt);
return(-1);            }
int terminal(char x)
{       for(int i=0;i<tt;i++)
        if(T[i]==x)
               return(1);
        return(0);             }
int nonterminal(char x)
{       for(int i=0;i<tnt;i++)
        if(NT[i]==x)
               return(1);
        return(0);             }
int in_rhs(char *s,char x)
{       for(int i=0;i<=strlen(s);i++)
               if(*(s+i)==x)
                       return(i);
               return(-1);                    }
void find_first()
{       for(int i=0;i<tnt;i++)
        first_of(NT[i]);               }
void first_of(char n)
{       int t1,t2,p1,cnt=0,i,j;
        char x;
        static int over[20];
        p1=t_no(epsilon);
        if(terminal(n))
                return;
        t1=nt_no(n);
        if(over[t1])
               return;
        over[t1]=1;
        for(i=0;i<tp;i++)
        {       t1=nt_no(prod[i][0]);
               if(prod[i][0]==n)
               {       int k=0;
                       cnt=count(1);
                       rhs(i);
                       while(k<cnt)
                       {       x=c[i][k];
                               if(terminal(x))
                               {       t2=t_no(x);
                                       first[t1][t2]=1;
                                       break;                 }
                               else
                               {       t2=nt_no(x);
                                       first_of(x);
                                       for(int j=0;j<tt;j++)
         first[t1][p1]=1;      }   }   }
void follow_of(char n)
{       int f,t1,t2,p1,t,cnt=0;
        char x,beta;
        static int over[20];
        p1=t_no(epsilon);
        t1=nt_no(n);
        if(over[t1])
               return;
        over[t1]=1;
        if(NT[0]==n)
        follow[nt_no(NT[0])][tt]=1;
        for(int i=0;i<tp;i++)
        {       rhs(i);
               cnt=count(i);
               t=in_rhs(c[i],n);
                       int bno;
                       for(int j=0;j<tt;j++)
                       {
                               bno=nt_no(beta);
                               if((first[bno][j]) && (j!=p1))
                                       follow[t1][j]=1;       }
                               if((p1!=-1) && (first[bno][p1]==1))
                                       continue;
                               else if((t==(cnt-1)||(k>=cnt)))
                               {       follow_of(prod[i][0]);
                                      t1=nt_no(prod[i][0]);
                                      for(int l=0;l<=tt+1;l++)
                                      if(follow[t][l])
                                       follow[t1][l]=1;       }       }       }       }
                                      int count(int j)
                                      {  int c1=0;
                                         for(int q=3;prod[j][q]!='\r';q++)
                                         c1++;
                                         return(c1);         }
void show_follow()
{       int b=0;
        a=0;
        cout<<"\n\n Follow Table For Grammar: \n";
        for(int i=0;i<tnt;i++)
        {
               b=0;
               cout<<"\n FOLLOW ("<<NT[i]<<" )= { ";
               for(int j=0;j<tt+1;j++)
               if(follow[i][j] && j!=tt)
               {       foll[a][b]=T[j];
                       b++;
                       cout<<T[j]<<" ";       }
               else
                       if(j==tt)
                       {       foll[a][b]='$';
                               b++;
                               cout<<'$';     }
                       a++;
                       cout<<" } ";           }
                       getch();               }
                       void show_first()
                       {       int b=0;
                               a=0;
                               cout<<"\n\n First Table For Grammar: \n";
                               for(int i=0;i<tnt;i++)
                               {       b=0;
                                      cout<<"\n FIRST ("<<NT[i]<<" )= { ";
                                      for(int j=0;j<tt+1;j++)
                                      if(first[i][j] && j!=tt)
                                      {       fir[a][b]=T[j];
                                              b++;
                                              cout<<T[j]<<" ";       }
                                      a++;
                                      cout<<" } ";           }
                                      getch()}}}}