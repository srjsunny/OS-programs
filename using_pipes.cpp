/*
Brief Description:
write a program to reverse the case of string entered using pipes 
*/

/*
Test cases:
 Case 1:
hero
Ouput:
the modified input is HERO

Case 2:
hiThere
Output:
the modified input is HItHERE
/

#include <iostream>

#include <unistd.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

using namespace std;

int main()

{

int ret_val;

int fd[2];

char buffer[100]="";

char tempString[100]="";

//cout<<"\nEnter the msg= ";

cin>>tempString;

ret_val = pipe(fd);              
  
if (ret_val != 0)            
 
{
  
cout<<"pipe not created";
  
exit(1);
 
}

if (fork() == 0)

{
   
close(fd[0]);
   
for(int i=0;i<strlen(tempString);i++)
   {
  
 if (isupper(tempString[i]))
   
{
   
tempString[i]=tolower(tempString[i]);
   	
   
}
   
else if(islower(tempString[i]))
   
{
   
tempString[i]=toupper(tempString[i]);	
  
 }
   
}
   
ret_val = write(fd[1],tempString,strlen(tempString));
   
if (ret_val != strlen(tempString))

 {
      
cout<<"Expected value is not returned\n";
      
exit(2);
   
}


}

else

{
   
close(fd[1]);
  
   
ret_val = read(fd[0],buffer,strlen(tempString));
  
 if (ret_val != strlen(tempString))
  
 {
   
cout<<"Expected value is not returned by read\n";
 
  exit(3);
  
 }
   
   
  
 cout<<"the modified input is"<<" "<<buffer;

}

exit(0);

}
