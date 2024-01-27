#include<stdio.h>
#include<string.h>

void longestRepeatedSubstring(char str[]) {
  unsigned long n=strlen(str);
  int LCSRe[n][n];
  char res[50]="";
  int res_length=0;
  int i,j, index=0;
  for(i=0;i<=n;i++){
    for(j=i+1;j<=n;j++){
      if((str[i-1]==str[j-1]) && (LCSRe[i-1][j-1]<(j-i))){
      LCSRe[i][j]=LCSRe[i-1][j-1]+1;
      if (LCSRe[i][j]>res_length){
      res_length=LCSRe[i][j];
      index=(i>index)?i:index;}}
      else {
        LCSRe[i][j] = 0;}}}
  j=0;
  if(res_length>0){
      for(i=index-res_length+1; i<=index; i++){
          res[j]= str[i-1];
          j++;}}
  printf("%s",res);}
  

int main() {
char str[50];
printf("input: ");
scanf("%s",str);
printf("output: ");
longestRepeatedSubstring(str);
printf("\n");
}
