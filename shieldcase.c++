#include"shield.h"
#include<stdio.h>
#include<time.h>
using namespace std;
using namespace shield;

void _case::add(int x)
{
  if(x==10)
    {
     CLR;
      FILE *p,*q;
      char c[100];
    b:
      p=fopen("/.shield/reports/rp.dat","r+");
      fscanf(p,"%s",c);
      while(!feof(p))
	{
	  if(strcmp(c,"00000")!=0)
	    {
	  printf("%s\t",c);
	  fscanf(p,"%s",c);
	    }
	  else
	    fscanf(p,"%s",c);
	}
      cout<<"\nEnter the Report No. you want to read\nEnter 0 to go back..\n";
      int _id,k;
      cin>>_id;
      k=_id;
      if(k==0)
	{
	  CLR;
	  fclose(p);
          return;
	}
  char f[43];
  sprintf(f,"/.shield/reports/%d.dat",_id);
  q=fopen(f,"r");
  fscanf(q,"%c",&c[0]);
  while(!feof(q))
	{
	  cout<<c[0];
	  fscanf(q,"%c",&c[0]);
	}
  cout<<"Do you want to add this Case?\nPress y if yes....\n";
  cin>>c[0];
  if(c[0]=='y')
    {
      int x,j=0;
      fseek(p,0,0);
      fscanf(p,"%d%*c",&x);
      while(x!=k)
	{
	  j=ftell(p);
	  fscanf(p,"%d%*c",&x);
	}
      fseek(p,j,0);
      fprintf(p,"00000");
      CLR;
      	fclose(p);
	int cs=_id;
        _id=90000;
  p=fopen("/.shield/cases/cs.dat","r");
  fscanf(p,"%d",&x);
  while(!feof(p))
    {
      if(x==_id)
	{
	  _id++;
	  fseek(p,0,0);
	}
      fscanf(p,"%d",&x);
    }
  x=_id;
  id=_id;
  fclose(p);
      p=fopen("/.shield/cases/cs.dat","a");
      fprintf(p,"%d\n",_id);
      fclose(p);
      char f1[42];
      sprintf(f1,"/.shield/cases/%d.cdat",_id);
  p=fopen(f1,"w");
    d:
  CLR;
  agent a;
  a.freea();
  cout<<"Enter the ID of Agent you want to add\n";
  cin>>_id;
  j=adda(_id);
  if(j==1)
    fprintf(p,"%d\t",_id);
  CLR;
  cout<<"Do you want to add one more agent?\nPress 1 if yes..\n";
  cin>>c[0];
  if(c[0]==49)
    {
      goto d;
    }
  fseek(q,0,0);
  fprintf(p,"\n0\n");
  fscanf(q,"%c",&c[0]);
  while(!feof(q))
    {
      fprintf(p,"%c",c[0]);
      fscanf(q,"%c",&c[0]);
    }
  time_t tx;
  struct tm *ti;
  time(&tx);
  ti=localtime(&tx);
  fprintf(p,"%d %d %d\n",ti->tm_mday,ti->tm_mon+1,ti->tm_year+1900);
  fclose(p);
  fclose(q);
  sprintf(c,"rm /.shield/reports/%d.dat",cs);
  system(c);
  CLR;
    }
  else
    {
      CLR;
      fclose(p);
      fclose(q);
      goto b;
    }
    }
  else
    {
      CLR;
      cout<<"You don't have permission to add cases\n";
    }
}

void agent::freea()
{
  FILE *p;
  int i;
  p=fopen("/.shield/agents/fa.dat","r");
  fscanf(p,"%d",&i);
  agent x;
  while(!feof(p))
    {
     if(i!=0)
       {
	 x.search(i);
	 printf("%d - %s - Level- %d(%d)\n",i,x.name,x.level,x.cases());
       }
     fscanf(p,"%d",&i);
    }
  printf("\n");
  fclose(p);
}

int _case::adda(int i)
{
  FILE *p;
  int j=0,k;
  p=fopen("/.shield/agents/fa.dat","r+");
  fscanf(p,"%d%*c",&k);
  while(i!=k)
    {
      if(feof(p))
	{
	  CLR;
	  cout<<"Agent may have been alloted another case. He is not in Free list\n";
	  return 0;
	}
      j=ftell(p);
     fscanf(p,"%d%*c",&k);
    }
  fseek(p,j,0);
  fprintf(p,"00000");
  fclose(p);
  char f[45];
  sprintf(f,"/.shield/agents/%d.adat",k);
  p=fopen(f,"a");
  fprintf(p,"%d - 0\n",id);
  fclose(p);
  return 1;
}

_case::_case(int x,char *na,int level)
{
  id=x;
  name=na;
  level_access=level;
}

_case::_case()
{
  id=0;
  name=(char*)malloc(5);
  strcpy(name,"case");
  level_access=0;
}

int _case::searchc(int x)
{
  int _id=x;
  FILE *p;
  char f1[41];
  sprintf(f1,"/.shield/cases/%d.cdat",_id);
  p=fopen(f1,"r");
  if(p)
    {
      fscanf(p,"%*[^\n]%*c%d",&_id);
      fscanf(p,"%[^\n]%*c",f1);
      name=(char *)realloc(name,strlen(f1)+1);
      strcpy(name,f1);
      id=x;
      level_access=_id;
      fclose(p);
      return 1;
    }
  else
    {
      return 0;
    }
}

void _case::pdetails(int id,int x)
{
  FILE *q;
  int _id;
  char r[]="/.shield/cases/cs.dat";
 a:
  q=fopen(r,"r");
  fscanf(q,"%d",&_id);
  while(!feof(q))
    {
      if(_id!=0)
      printf("%d\t",_id);
      fscanf(q,"%d",&_id);
    }
  fclose(q);
  cout<<"\nEnter the ID of the Case you Want to read.\nPress 0 to go back..\n";
  cin>>_id;
  if(_id==0)
    {
      CLR;
      return;
    }
  if(searchc(_id))
    {
      if(level_access==0)
	{
	  CLR;
	  cout<<"The case is not solved yet.\n";
	  return;
	}
      FILE *p;
      char f1[41];
      sprintf(f1,"/.shield/cases/%d.cdat",_id);
  p=fopen(f1,"r");
  int ch,own=0;
  fscanf(p,"%d%c",&ch,&f1[0]);
  while(f1[0]!='\n')
    {
      if(ch==id)
	{
	  own=1;
	}
      fscanf(p,"%d%c",&ch,&f1[0]);
    }
  fclose(p);
      if(x>=level_access||own)
	{
      sprintf(f1,"/.shield/cases/%d.cdat",_id);
  p=fopen(f1,"r");
  fscanf(p,"%*[^\n]%*c%*d%*c%c",&f1[0]);
  while(!feof(p))
    {
      printf("%c",f1[0]);
      fscanf(p,"%c",&f1[0]);
    }
  fclose(p);
  cout<<"\n\nPress Enter to go back..\n";
  scanf("%*c%*c");
  CLR;
  goto a;
	}
      else
	{
	  CLR;
	  cout<<"You don't have access to this case.\n";
	  return;
	}
    }
  else
    {
      CLR;
      cout<<"Input ID doesn't exist.\nTry Again....\n";
      goto a;
    }
}

void agent::work()
{
  CLR;
  FILE *p;
  int k=id;
  char f[45];
  sprintf(f,"/.shield/agents/%d.adat",k);
  p=fopen(f,"r");
  fscanf(p,"%*[^\n]%*c%*d%*c%*[^\n]%*c%*[^\n]%*c%*[^\n]");
  int _d=0,j,ca;
  k=0;j=1;
  while(!feof(p))
    {
      if(_d>=90000)
	{
	  k=ftell(p);
	  ca=_d;
	}
      fscanf(p,"%*c%d%*c%*c%*c%*d",&_d);
    }
  if(k!=0)
    {
      fseek(p,k-1,0);
      fscanf(p,"%d",&j);
    }
  fclose(p);
  if(j==1)
    {
      CLR;
      cout<<"You don't have any Case at present..\n";
      return;
    }
  if(j==0)
    {
      FILE *q;
      char f1[41];
      sprintf(f1,"/.shield/cases/%d.cdat",ca);
  q=fopen(f1,"r");
  fscanf(q,"%d",&j);
  while(j!=0)
    {
      printf("%d\t",j);
      fscanf(q,"%d",&j);
    }
  fscanf(q,"%c",&f1[0]);
  while(!feof(q))
    {
      printf("%c",f1[0]);
      fscanf(q,"%c",&f1[0]);
    }
  fclose(q);
  cout<<"Press 0 to go back ...\n\nPress 1 if case is solved.\n";
  cin>>f1[0];
  if(f1[0]==48)
    {
      CLR;
      return;
    }
  if(f1[0]==49)
    {
      f1[0]='/';
      q=fopen(f1,"r+");
      int g;
      fscanf(q,"%d",&g);
      while(g!=0)
	{
	  p=fopen("/.shield/agents/fa.dat","r+");
	  fscanf(p,"%d%*c",&k);
	  _d=0;
	  while(k!=0)
	    {
	      _d=ftell(p);
	      fscanf(p,"%d%*c",&k);
	    }
	  fseek(p,_d,0);
	  fprintf(p,"%d",g);
	  fclose(p);
	  sprintf(f,"/.shield/agents/%d.adat",g);
	  p=fopen(f,"r+");
	  fscanf(p,"%*[^\n]%*c%*d%*c%*[^\n]%*c%*[^\n]%*c%*[^\n]%*c");
	  while(!feof(p))
	    {
	      if(j!=0&&j!=1)
		{
		  k=ftell(p);
		}
	      fscanf(p,"%d %*c %*d",&j);
	    }
	  fseek(p,k-1,0);
	  fprintf(p,"1");
	  fclose(p);
	  fscanf(q,"%d",&g);
	}
      CLR;
      cout<<"What is the level of the case.\n";
      cin>>j;
      fseek(q,-1,1);
      fprintf(q,"%d",j);
      fclose(q);
      q=fopen(f1,"a");
      time_t tx;
      struct tm *ti;
      time(&tx);
      ti=localtime(&tx);
      fprintf(q,"%d %d %d\n",ti->tm_mday,ti->tm_mon+1,ti->tm_year+1900);
      cout<<"Enter your Report as a Para and Press Enter at the end.\n            ";
      scanf("%*c%c",&f[0]);
      while(f[0]!='\n')
	{
	  fprintf(q,"%c",f[0]);
	  scanf("%c",&f[0]);
	}
      CLR;
      fclose(q);
      cout<<"Case work completed..Congrats.\n";
    }
    }
}

char agent::iswork()
{
  if(level==10)
    {return '~';
    }
  FILE *p;
  int k=id;
  char f[45];
  sprintf(f,"/.shield/agents/%d.adat",k);
  p=fopen(f,"r");
  fscanf(p,"%*[^\n]%*c%*[^\n]%*c%*[^\n]%*c%*[^\n]%*c%*[^\n]");
  int _d=0,j,ca;
  k=0;j=1;
  while(!feof(p))
    {
      if(_d>=90000)
	{
	  k=ftell(p);
	  ca=_d;
	}
      fscanf(p,"%*c%d%*c%*c%*c%*d",&_d);
    }
  if(k!=0)
    {
      fseek(p,k-1,0);
      fscanf(p,"%d",&j);
    }
  fclose(p);
  if(j==1)
    {
      return 'N';
    }
  if(j==0)
    {
      return 'Y';
    }
}

void agent::chatbox()
{
  FILE *p,*q;
  int i;
 a:
  agent x;
  p=fopen("/.shield/agents/ag.dat","r");
  fscanf(p,"%d",&i);
  if(id!=10000)
    printf("Director-10000(%d)\n",amsg(10000));
  while(!feof(p))
    {  x.search(i);
      if(i!=id)
	printf("%s-%d(%d)\n",x.name,i,amsg(i));
      fscanf(p,"%d",&i);
    }
  fclose(p);
  cout<<"\nEnter the ID of the Agent you want to message.\nPress 0 to go back..\n";
  cin>>i;
  if(i==0)
    {
      CLR;
      return;
    }
  if(i==id)
    {
      CLR;
      cout<<"How can you have messages from yourself\n";
      goto a;
    }
  int j=i,k,l=id,g=i;
  char f[50],f1[50];
  k=x.search(i);
  if(k==0)
    {
      k=x.searchd(g);
      if(k==0)
	{
	  CLR;
	  cout<<"Invalid Input..\n";
	  goto a;
	}
    }
  sprintf(f,"/.shield/messages/%d/%d.mdat",j,l);
  sprintf(f1,"/.shield/messages/%d/%d.mdat",l,j);
  p=fopen(f,"r");
  q=fopen(f1,"r");
  char s,m,c;
  if(p)
    {
      fclose(p);
      fclose(q);
      q=fopen(f1,"r+");
      p=fopen(f,"r+");
      fseek(q,-3,2);
      fscanf(q,"%c%c",&m,&s);
      if(s=='1'&&m=='\n')
	{
	  fseek(q,-2,2);
	  fprintf(q," \b");
	  fseek(p,0,2);
	  fprintf(p,"(seen)\n");
	}
      CLR;
      fseek(q,0,0);
      fscanf(q,"%c",&s);
      while(!feof(q))
	{
	  printf("%c",s);
	  fscanf(q,"%c",&s);
	}
      fclose(q);
      q=fopen(f1,"a");
      cout<<"You:\n\e[s";
      cout<<"\n\n\n\n\n\nPress Enter to return to previous page\e[u";
      scanf("%*c");
      scanf("%c",&c);
      if(c=='\n')
	{
	  fclose(p);
	  CLR;
	  goto a;
	}
      fseek(p,-3,2);
      fscanf(p,"%c%c",&m,&s);
      if(s=='1'&&m=='\n')
	{
	  fseek(p,-2,2);
	  fprintf(p," \b");
	}
      fclose(p);
      p=fopen(f,"a+");
    }
  else
    {
      p=fopen(f,"w");
      q=fopen(f1,"w");
      CLR;
      cout<<"You:\n\e[s";
      cout<<"\n\n\n\n\n\nPress Enter to return to previous page\e[u";
      scanf("%*c");
      scanf("%c",&c);
      if(c=='\n')
	{
	  CLR;
	  goto a;
	}
    }
      fprintf(p,"%d(%s):\n",id,name);
      fprintf(q,"You:\n");
      while(c!='\n')
	{
	  fprintf(p,"%c",c);
	  fprintf(q,"%c",c);
	  scanf("%c",&c);
	}
      fprintf(p,"%c",c);
      fprintf(q,"%c",c);
      fprintf(p,"1\n");
      fclose(p);
      fclose(q);
      CLR;
      goto a;
}

int agent::messages()
{
  FILE *p,*q;
  int i=10000,l,m,c=0;
  char f[50];
  p=fopen("/.shield/agents/ag.dat","r");
  if(level==10)
    {
      fscanf(p,"%d",&i);
    }
  while(!feof(p))
    {
      l=id;
      sprintf(f,"/.shield/messages/%d/%d.mdat",l,i);
      q=fopen(f,"r");
      if(q)
	{
	  fseek(q,-2,2);
	  fscanf(q,"%d",&i);
	  if(i==1)
	    {
	      c++;
	    }
	  fclose(q);
	}
      fscanf(p,"%d",&i);
    }
  fclose(p);
  return c;
}

int agent::amsg(int x)
{
  FILE *q;
  int i=x,l,m,c=0;
  char f[50];
      l=id;
      sprintf(f,"/.shield/messages/%d/%d.mdat",l,i);
      q=fopen(f,"r");
      if(q)
	{
	  fseek(q,-2,2);
	  fscanf(q,"%d",&i);
	  if(i==1)
	    {
	      return 1;
	    }
	  fclose(q);
	}

      return 0;
}

int agent::cases()
{
  FILE *p;
  char f[45];
  int k=id;
  sprintf(f,"/.shield/agents/%d.adat",k);
  p=fopen(f,"r");
  fscanf(p,"%*[^\n]%*c%*d%*c%*[^\n]%*c%*[^\n]%*c%*[^\n]%*c");
  int _d=0,j=0,ca;
  k=0;j=0;
  while(!feof(p))
    { 
      if(_d>=90000)
      j++;
      fscanf(p,"%d %*c %*d",&_d);
    }
  return j;
}
