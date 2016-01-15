#include"shield.h"
#include<stdio.h>

using namespace std;
using namespace shield;

void shield::apply()
{
  FILE *p;
  int x,ap=400;
  p=fopen("/.shield/applications/ap.dat","r");
  fscanf(p,"%d",&x);
  while(!feof(p))
    {
      if(x==ap)
	{
	  ap++;
	  fseek(p,0,0);
	}
      fscanf(p,"%d",&x);
    }
    fclose(p);
    int i=ap;
  char f[45];
  sprintf(f,"/.shield/applications/%d.dat",ap);
  p=fopen(f,"w");
    CLR;
    cout<<"What is your Name?\n";
    scanf("%*c%[^\n]",f);
    fprintf(p,"%s\n",f);
    cout<<"Enter your Date of Birth in dd mm yyyy format\n";
    for(ap=0;ap<3;ap++)
      {
	cin>>x;
	fprintf(p,"%d ",x);
      }
    CLR;
    cout<<"Enter the reason Why you want to join S.H.I.E.L.D. without pressing Enter in middle, Press enter at the end\n\n";
    scanf("%*c%c",&f[0]);
    fprintf(p,"\n");
    while(f[0]!='\n')
      {
	fprintf(p,"%c",f[0]);
	scanf("%c",&f[0]);
      }
    fprintf(p,"\n");
    cout<<"Enter your phone no.: ";
    long a;
    cin>>a;
    fprintf(p,"%ld\n",a);
    fclose(p);
    p=fopen("/.shield/applications/ap.dat","a");
    fprintf(p,"%d\n",i);
    fclose(p);
    CLR;
    cout<<"Application Submitted..\n";
    return;
}

void shield::report()
{
  FILE *p;
  int x,ap=50000;
  p=fopen("/.shield/reports/rp.dat","r");
  fscanf(p,"%d",&x);
  while(!feof(p))
    {
      if(x==ap)
	{
	  ap++;
	  fseek(p,0,0);
	}
      fscanf(p,"%d",&x);
    }
    fclose(p);
    int i=ap;
  char f[42];
  sprintf(f,"/.shield/reports/%d.dat",ap);
  p=fopen(f,"w");
  cout<<"What type of Problem you want to report?\n";
  scanf("%*c%[^\n]",f);
  fprintf(p,"%s\n",f);
  cout<<"What do you know about this problem?\nWrite as a paragragh and press Enter at the end..\n";
  scanf("%*c%c",&f[0]);
    while(f[0]!='\n')
      {
	fprintf(p,"%c",f[0]);
	scanf("%c",&f[0]);
      }
    fprintf(p,"\n");
  fclose(p);
  p=fopen("/.shield/reports/rp.dat","a");
  fprintf(p,"%d\n",i);
  fclose(p);
  CLR;
  cout<<"Problem Reported..\n";
  return;
}

int shield::nreports()
{
  FILE *p;
  int x,rp=0;
  p=fopen("/.shield/reports/rp.dat","r");
  fscanf(p,"%d",&x);
  while(!feof(p))
    {
      if(x!=0)
	{
	  rp++;
	}
      fscanf(p,"%d",&x);
    }
  fclose(p);
  return rp;
}

int shield::nappli()
{
  FILE *p;
  int x,ap=0;
  p=fopen("/.shield/applications/ap.dat","r");
  fscanf(p,"%d",&x);
  while(!feof(p))
    {
      if(x!=0)
	{
	  ap++;
	}
      fscanf(p,"%d",&x);
    }
  fclose(p);
  return ap;
}

void agent::pmdetails()
{
  CLR;
  FILE *p;
  int _id=id;
  char f[50];
  if(level==10)
    {
      strcpy(f,"/.shield/agents/director.ddat");
    }
  else
    {
      sprintf(f,"/.shield/agents/%d.adat",_id);
    }
  p=fopen(f,"r");
  fscanf(p,"%[^\n]",f);
  fscanf(p,"%*c%c",&f[0]);
  printf("Level - ");
  while(!feof(p))
    {
      printf("%c",f[0]);
      fscanf(p,"%c",&f[0]);
    }
  fclose(p);
  cout<<"\n\nPress Enter to go back...";
  scanf("%*c%*c");
  CLR;
}

void agent::pdetails()
{
  CLR;
  FILE *p;
  cout<<"Enter the ID of the Agent: ";
  int _id;
  cin>>_id;
  CLR;
  if(search(_id))
    {
  char f[42];
  sprintf(f,"/.shield/agents/%d.adat",_id);
  p=fopen(f,"r");
  fscanf(p,"%[^\n]",f);
  fscanf(p,"%*c%c",&f[0]);
  if(f[0]<=level+48)
    {
  printf("Level - ");
  while(!feof(p))
    {
      printf("%c",f[0]);
      fscanf(p,"%c",&f[0]);
    }
  fclose(p);
  cout<<"\n\nPress Enter to go back...";
  scanf("%*c%*c");
  CLR;
    }
  else
    {
      CLR;
      cout<<"You don't have access to this Agent's details\n";
    }
    }
  else
    {
      CLR;
      cout<<"Input ID doesn't exist..!\n";
      return;
    }
}

void agent::edetails()
{
  CLR;
  FILE *p,*q;
  int _id=id;
  char f[50];
  if(level==10)
    {
      strcpy(f,"/.shield/agents/director.ddat");
    }
  else
    {
      sprintf(f,"/.shield/agents/%d.adat",_id);
    }
  p=fopen(f,"r+");
  q=fopen("/.shield/agents/tmp.adat","w");
  fscanf(p,"%*[^\n]%*c%*d%*c");
  int j=ftell(p);
  fscanf(p,"%*[^\n]%*c%*[^\n]%*c%c",&f[0]);
  while(!feof(p))
    {
      fprintf(q,"%c",f[0]);
      fscanf(p,"%c",&f[0]);
    }
  int k=ftell(p);
  fseek(p,j,0);
  for(int i=0;i<(k-j);i++)
    {
      fprintf(p," ");
    }
  fseek(p,j,0);
  cout<<"Enter your name\n";
  scanf("%*c%[^\n]%*c",f);
  name=(char*)realloc(name,strlen(f)+1);
  strcpy(name,f);
  fprintf(p,"%s\n",f);
  cout<<"Enter your date of birth in dd mm yyyy format\n";
  int d,m,y;
  cin>>d>>m>>y;
  fprintf(p,"%d %d %d\n",d,m,y);
  fclose(q);
  q=fopen("/.shield/agents/tmp.adat","r");
  fscanf(q,"%c",&f[0]);
  while(!feof(q))
    {
      fprintf(p,"%c",f[0]);
      fscanf(q,"%c",&f[0]);
    }
  fclose(p);
  fclose(q);
  CLR;
  cout<<"Details changed...\n";
}

void agent::promote()
{
  FILE *p;
  int _id;
  agent x;
 a:
  p=fopen("/.shield/agents/ag.dat","r");
  fscanf(p,"%d",&_id);
  while(!feof(p))
    {
      agent y;
      y.search(_id);
      if(id!=_id)
	{
	  printf("%d - %s - Level- %d\n",_id,y.name,y.level);
	}
      fscanf(p,"%d",&_id);
    }
  printf("\n\n");
  fclose(p);
  cout<<"Enter the ID of the Agent\nPress 0 to go back..\n";
  cin>>_id;
  if(id==_id)
    {CLR;
      cout<<"You can't promote yourself, right?..\n";
      goto a;
    }
  if(_id==0)
    {
      CLR;
      return;
    }
  if(x.search(_id))
    {
  char f[42];
  int m=_id;
  sprintf(f,"/.shield/agents/%d.adat",_id);
  p=fopen(f,"r+");
  fscanf(p,"%*[^\n]%*c");
  int j,k=ftell(p);
  fscanf(p,"%d",&j);
  if(level>j)
    {
      j++;
      fseek(p,k,0);
      fprintf(p,"%d",j);
      CLR;
      fclose(p);
      CLR;
      cout<<m<<" is Promoted.\n";
    }  
  else
    {
      fclose(p);
      CLR;
      cout<<"You cannot promote this Agent\n";
    }
    }
  else
    {
      fclose(p);
      CLR;
      cout<<"Invalid ID\nInput ID doesn't exist...!\n";
    }
}

void agent::demote()
{
  FILE *p;
  int _id;
 a:
  agent x;
  p=fopen("/.shield/agents/ag.dat","r");
  fscanf(p,"%d",&_id);
  while(!feof(p))
    { 
      agent y;
      y.search(_id);
      if(id!=_id)
	{
	  printf("%d - %s - Level- %d\n",_id,y.name,y.level);
	}
      fscanf(p,"%d",&_id);
    }
  printf("\n\n");
  fclose(p);
  cout<<"Enter the ID of the Agent\nPress 0 to go back..\n";
  cin>>_id;
  if(id==_id)
    {
      CLR;
      cout<<"You can't demote yourself. Sorry..\n";
      goto a;
    }
  if(_id==0)
    {CLR;
      return;
    }
  if(x.search(_id))
    {
  char f[42];
  int m=_id;
  sprintf(f,"/.shield/agents/%d.adat",_id);
  p=fopen(f,"r+");
  fscanf(p,"%*[^\n]%*c");
  int j,k=ftell(p);
  fscanf(p,"%d",&j);
  if(level>j)
    {
      j--;
      fseek(p,k,0);
      fprintf(p,"%d",j);
      fclose(p);
      CLR;
      cout<<m<<" is Demoted.\n";
    }  
  else
    {
      CLR;
      fclose(p);
      cout<<"You cannot demote this Agent\n";
    }
    }
  else
    {
      CLR;
      fclose(p);
      cout<<"Invalid ID\nInput ID doesn't exist...!\n";
    }
}

void agent::displayo()
{
  cout<<"1.Show your details.\n2.Change your details.\n3.Add an Agent(";
  cout<<nappli()<<").\n4.Details of another Agent\n5.ChatBox(";
  cout<<messages()<<").\n6.Add a case(";
  cout<<nreports()<<").\n7.Details of a case.\n8.Check work allotted to you(";
  cout<<iswork()<<").\n9.Promote an Agent.\n10.Demote an Agent.\n11.Change Password.\n12.Logout\n";
      cout<<"Enter your option Agent "<<agent::name<<endl;
    
}

char * agent::aname()
{
  return name;
}

void agent::fpwd()
{
  CLR;
  cout<<"Enter your ID: ";
  int k;
  cin>>k;
  search(k);
  if(level==0)
    {
      searchd(k);
    }
  cout<<"What is your level?\n";
  cin>>k;
  if(k!=level)
    {
      CLR;
      cout<<"Sorry! you are Wrong..\n";
      return;
    }
  cout<<"What is your name as in account?\n";
  char c[100];
  scanf("%*c%[^\n]%*c",c);
  if(strcmp(c,name)!=0)
    {
      CLR;
      cout<<"Sorry! you are Wrong..\n";
      return;
    }
  FILE *p;
  int _id=id;
  char f[43];
  if(level==10)
    {
        strcpy(f,"/.shield/agents/director.ddat");
    }
  else
    {
      sprintf(f,"/.shield/agents/%d.adat",_id);
    }
  p=fopen(f,"r");
  fscanf(p,"%*[^\n]%*c%*d%*c%*[^\n]%*c%*[^\n]%*c%*[^\n]");
  k=0;
  while(!feof(p))
    {
      if(_id!=0&&_id!=1)
	k=_id;
      fscanf(p,"%*c%d%*c%*c%*c%*d",&_id);
    }
  if(level!=10)
    cout<<"Enter the last Case you worked\nPress 0 if you didn't work any case yet...\n";
  else
    {
      int i;
      CLR;
      cout<<"Your password is ' "<<password[0];
      for(i=0;i<strlen(password)-2;i++)
	{
	  cout<<"*";
	}
      cout<<password[i+1]<<" '\n";
      fclose(p);
      return;
    }
  int j;
  cin>>j;
  if(j!=k)
    {
      CLR;
      fclose(p);
      cout<<"Sorry! you are Wrong..\n";
      return;
    }
  CLR; 
  fclose(p);
  cout<<"Your Password is ' "<<password<<" '\n";
}
