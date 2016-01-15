#include"shield.h"
#include<stdio.h>
#include<time.h>
using namespace shield;
using namespace std;

void agent::login()
{
  time_t xt;
  struct tm *it;
  time(&xt);
  it=localtime(&xt);
  int option;
  CLR;
  cout<<"********* Logged in Successfully *********\n******* Welcome Agent "<<name<<" *******\n";
 a:
  agent::displayo();
  cin>>option;
  switch(option){
   case 1:
    {
      CLR;
      passwd pwd;
      cout<<"Enter your Password: ";
      pwd.get();
      if(passwordc(pwd))
	{
         pmdetails();
	 goto a;
	}
      else
	{CLR;
	  cout<<"Wrong Password ...!\n";
	  goto a;
	}
      break;
    }
  case 2:
    {
      CLR;
      passwd pwd;
      cout<<"Enter your Password: ";
      pwd.get();
      agent x;
      if(passwordc(pwd))
	{
         edetails();
	 goto a;
	}
      else
	{CLR;
	  cout<<"Wrong Password ...!\n";
	  goto a;
	}
     break;
      }
  case 3:
    {
      CLR;
      FILE *p,*q;
      char c[100];
    b:
      p=fopen("/.shield/applications/ap.dat","r+");
      fscanf(p,"%s",c);
      while(!feof(p))
	{
	  if(strcmp(c,"000")!=0)
	    {
	  printf("%s\t",c);
	  fscanf(p,"%s",c);
	    }
	  else
	    fscanf(p,"%s",c);
	}
      cout<<"\nEnter the Application No. you want to read\nEnter 0 to go back..\n";
      int _id,k;
      cin>>_id;
      k=_id;
      if(k==0)
	{
	  fclose(p);
	  CLR;
          goto a;
	}
  char f[45];
  int ap=_id;
  sprintf(f,"/.shield/applications/%d.dat",_id);
  q=fopen(f,"r");
  fscanf(q,"%[^\n]",c);
  while(!feof(q))
	{
	  cout<<c<<endl;
	  fscanf(q,"%*c%[^\n]",c);
	}
  cout<<"\n\nDo you want to add him/her?\nPress y if yes....\n";
  cin>>c[0];
  if(c[0]=='y')
    {int x,j=0;
      fseek(p,0,0);
      fscanf(p,"%d%*c",&x);
      while(x!=k)
	{
	  j=ftell(p);
	  fscanf(p,"%d%*c",&x);
	}
      fseek(p,j,0);
      fprintf(p,"000");
      CLR;
      fseek(q,0,0);
      fscanf(q,"%[^\n]",c);
	fclose(p);
        _id=10001;
  p=fopen("/.shield/agents/ag.dat","r");
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
  fclose(p);
      p=fopen("/.shield/agents/ag.dat","a");
      fprintf(p,"%d\n",_id);
      fclose(p);
      char f1[42];
      sprintf(f1,"/.shield/agents/%d.adat",_id);
  p=fopen(f1,"w");
  char *s;
  s=(char*)malloc(10);
  strcpy(s,"shield");
  s=encrypt(s);
  fprintf(p,"%s\n1\n%s\n",s,c);
  free(s);
  fscanf(q,"%*c%[^\n]",c);
  fprintf(p,"%s\n",c);
  fprintf(p,"%d %d %d\n",it->tm_mday,it->tm_mon+1,it->tm_year+1900);
  fclose(p);
  fclose(q);
  sprintf(c,"rm /.shield/applications/%d.dat",ap);
  system(c);
  sprintf(c,"mkdir /.shield/messages/%d",_id);
  system(c);
  strcpy(f1,"/.shield/agents/fa.dat");
  p=fopen(f1,"a");
  fprintf(p,"%d\n",x);
  fclose(p);
  CLR;
  cout<<"Agent added, his ID is "<<x<<".\n";
  goto a;
    }
  else
    {
      CLR;
      fclose(q);
      fclose(p);
      goto b;
    }
  break;
    }
  case 4:
    {
      CLR;
      passwd pwd;
      cout<<"Enter your Password: ";
      pwd.get();
      agent x;
      if(passwordc(pwd))
	{
         x.pdetails();
	 goto a;
	}
      else
	{CLR;
	  cout<<"Wrong Password ...!\n";
	  goto a;
	}
      break;
    }
  case 5:
    {
      CLR;
      chatbox();
      break;
    }
  case 6:
    {
      _case x;
      CLR;
      x.add(level);
      break;
    }
  case 7:
    {
      CLR;
      _case x;
      x.pdetails(id,level);
      break;
    }
  case 8:
    {
      CLR;
      if(level==10)
        {
          cout<<"You won't be alloted special work..\nYou have to supervise all the cases\n";
	  break;
        }
      work();
      break;
      }
  case 9:
    {
      CLR;
      promote();
      break;
    }
  case 10:
    {
      CLR;
      demote();
      break;
      }
  case 11:
    {
      CLR;
      passwd pwd;
      cout<<"Enter your Password: ";
      pwd.get();
      agent x;
      if(passwordc(pwd))
	{
	  CLR;
          epassword();
	 goto a;
	}
      else
	{CLR;
	  cout<<"Wrong Password ...!";
	  goto a;
	}
      break;
    }
  case 12:
    {
    return;
    }
  default:
    {
    CLR;
    cout<<"Not a Valid Option ...!\nEnter Again...\n";
    goto a;
    }
  }
  goto a;
}

bool agent::passwordc(passwd x)
{
  char *s;
  x.tochar(&s);
  if(strcmp(s,password)==0)
    {
      free(s);
      return 1;
    }
  else
    {
      free(s);
      return 0;
    }
}

int agent::searchd(int _id)
{time_t xt;
  struct tm *it;
  time(&xt);
  it=localtime(&xt);
  id=_id;
  FILE *p;
  char f[50];
  strcpy(f,"/.shield/agents/director.ddat");
  p=fopen(f,"r");
      char *c,d[30];
      fscanf(p,"%[^\n]%*c",d);
      level=10;
      fclose(p);
  if(id==10000)
    {
      if(strcmp(d,"shield")==0)
	{
	  edetails();
	  p=fopen(f,"r+");
	  fscanf(p,"%*[^\n]%*c%*d%*c%*[^\n]%*c%*[^\n]%*c");
	  fprintf(p,"%d %d %d\n",it->tm_mday,it->tm_mon+1,it->tm_year+1900);
	  fclose(p);
	  epassword();
	}
      p=fopen(f,"r");
      fscanf(p,"%[^\n]%*c",d);
      c=(char*)malloc(strlen(d)+1);
      strcpy(c,d);
      c=agent::decrypt(c);
      c=agent::decrypt(c);
      password=(char*)realloc(password,strlen(c)+1);
      strcpy(password,c);
      free(c);
      fscanf(p,"%d",&level);
      fscanf(p,"%*c%[^\n]",d);
      name=(char*)realloc(name,strlen(d)+1);
      strcpy(name,d);
      fclose(p);
      return 1;
    }
  else
    {
      return 0;
    }
}

int agent::search(int _id)
{
  id=_id;
  FILE *p;
  char f[42];
  sprintf(f,"/.shield/agents/%d.adat",_id);
  p=fopen(f,"r");
  if(p)
    {
      char *c,d[30];
      fscanf(p,"%[^\n]%*c",d);
      c=(char*)malloc(strlen(d)+1);
      strcpy(c,d);
      c=agent::decrypt(c);
      password=(char*)realloc(password,strlen(c)+1);
      strcpy(password,c);
      free(c);
      fscanf(p,"%d",&level);
      fscanf(p,"%*c%[^\n]",d);
      name=(char*)realloc(name,strlen(d)+1);
      strcpy(name,d);
      if(strcmp(password,"shield")==0)
	{
	  fclose(p);
	  return 2;
	}
      fclose(p);
      return 1;
    }
  else
    {
      return 0;
    }
}

agent::agent(int _id,int _level,char* _name)
{
  id=_id;
  level=_level;
  name=(char*)malloc(strlen(_name)+1);
  strcpy(name,_name);
}

agent::agent()
{
  id=0;
  level=0;
  name=(char*)malloc(8);
  strcpy(name,"default");
  password=(char*)malloc(9);
  strcpy(password,"password");
}

char* agent::decrypt(char *pwd)
{
  char c[40];
  strcpy(c,pwd);
  free(pwd);
  char t;
  t=c[0];
  int n,i,s[180]={0},j=0;
  while(t!='\0')
    {n=t;
       if(n<91&&n>64)
	{n=n-65;
	}
      else if(n<48&&n>21)
	{n=n+4;
	}
      else if(n<58&&n>47)
	{n=n+4;
	}
      else if(n==43)
	{n=62;
	}
      else if(n==58)
	{n=63;
	}
      i=j*6+5;
      while(n!=0)
	{
	  if(n%2!=0)
	    {s[i--]=1;

	    }
	  else
	    {s[i--]=0;
	    }
	  n=n/2;
	  }
      j++;
      t=c[j];
    } 
  i=0;
  while(j*6-i*8>0)
    {c[i]=s[i*8]*128+s[i*8+1]*64+s[i*8+2]*32+s[i*8+3]*16+s[i*8+4]*8+s[i*8+5]*4+s[i*8+6]*2+s[i*8+7];
      i++;
    }
  c[i]='\0';
  char *st;
  st=(char*)malloc(strlen(c)+1);
  strcpy(st,c);
  return st;
}

void agent::epassword()
{
  char *k,*l,c[100];
  passwd pwd,z;
 a:
  cout<<"Enter New Password: \e[s\nConfirm Password: \e[u";
 b:
  pwd.get();
  if(!pwd.check_validity())
    {
      CLR;
      cout<<"Enter New Password: \e[s\n";
      cout<<"Password must contain 6-20 characters with\natleast one of each 0-9,a-z,A-Z and one symbol.\nConfirm Password: \e[u";
      goto b;
    }
  fflush(stdout);
  cout<<"                                               \n                                                     \n                                              \n";
  cout<<"\e[u\nConfirm Password: ";
  z.get();
  if(!z.check_validity())
    {
      CLR;
      cout<<"Enter New Password: \e[s";
      cout<<"\nConfirm Password: \nPassword must contain 6-20 characters with\natleast one of each 0-9,a-z,A-Z and one symbol\n\e[u";
      goto b;
    }
  fflush(stdout);
  z.tochar(&k);
  pwd.tochar(&l);
  if(strcmp(l,k)==0)
    {
      FILE *p,*q;
      char f[50],f1[40];
  int _id=id;
  strcpy(f1,"/.shield/agents/tmp.adat");
  if(level==10)
    {
        strcpy(f,"/.shield/agents/director.ddat");
    }
  else
    {
      sprintf(f,"/.shield/agents/%d.adat",_id);
    }
  p=fopen(f,"r");
  q=fopen(f1,"w+");
  fscanf(p,"%*[^\n]%*c%s",c);
  while(!feof(p))
    {
      fprintf(q,"%s\n",c);
      fscanf(p,"%*c%[^\n]",c);
    }
  fclose(q);
  fclose(p);
  p=fopen(f,"w");
  q=fopen(f1,"r");
  CLR;
  char *h;
  h=(char*)malloc(strlen(l)+1);
  strcpy(h,l);
  if(level==10)
    {
      h=encrypt(encrypt(h));
      fprintf(p,"%s\n",h);
    }
  else
    {
      h=encrypt(h);
      fprintf(p,"%s\n",h);
    }
  fscanf(q,"%s",c);
  while(!feof(q))
    {
      fprintf(p,"%s\n",c);
      fscanf(q,"%*c%[^\n]",c);
    }
  password=(char*)realloc(password,strlen(k)+1);
  strcpy(password,k);
  free(h);
  free(k);
  free(l);
  fclose(q);
  fclose(p);
  cout<<"Password changed successfully..\n";
    }
  else
    {
      CLR;
      cout<<"Passwords doesn't match..!\nTry Again....\n";
      goto a;
    }
}

char * agent::encrypt(char *x)
{
  char c[30];
  strcpy(c,x);
  char t;
  free(x);
  t=c[0];
  int n,i,s[200]={0},j=0;
  while(t!='\0')
    {n=t;
      i=j*8+7;
      while(n!=0)
	{
	  if(n%2!=0)
	    {s[i--]=1;

	    }
	  else
	    {s[i--]=0;
	    }
	  n=n/2;
	}
      j++;
      t=c[j];
    }
  i=0;
  while(j*8-i*6>0)
    {
      n=s[i*6]*32+s[i*6+1]*16+s[i*6+2]*8+s[i*6+3]*4+s[i*6+4]*2+s[i*6+5];
      if(n<26)
	{n=n+65;
	  c[i]=n;
	}
      else if(n<52)
	{n=n-4;
	  c[i]=n;
	}
      else if(n<62)
	{n=n-4;
	  c[i]=n;
	}
      else if(n==62)
	{c[i]=43;
	}
      else if(n==63)
	{c[i]=58;
	}
      i++;
    }
  c[i]=0;
  char *si;
  si=(char*)malloc(strlen(c)+1);
  strcpy(si,c);
  return si;
}

shield::agent::~agent()
{
  free(name);
  free(password);
}

shield::_case::~_case()
{
  free(name);
}
