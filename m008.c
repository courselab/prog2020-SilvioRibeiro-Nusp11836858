/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)
{
  int lastPos;
for(int i=0;i<MAX;i++){
if(s[i]==*" ")
    lastPos=i;
if(s[i]==*"\n"){
    s[i]=*"\0";
    break;}
}
char resposta[MAX];
lastPos+=1;
strcpy(resposta,s+lastPos);
int lastnamelen=strlen(s+lastPos);
char* bufptr;
bufptr=resposta+lastnamelen;
*(bufptr++)= *",";
*(bufptr++)= *" ";
s[--lastPos]=0;
strcpy(bufptr,s);
for(int i=1;i<lastnamelen;i++){
resposta[i]-=32;
}
strcpy(s,resposta);
}



/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
