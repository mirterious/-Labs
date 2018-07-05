#include <stdio.h>
#include <conio.h>
#include <string.h>

char s[101];
int i, len, m, k=0;
int main(){
	printf("Input string using 1 and 0\n");
	gets(s);
	len=strlen(s);
	for(i=0;i<len;i++){
		if (s[i]!=' ') k++;
		else {
			if(k==5){
				m++;
				k=0;
			}
			k=0;
		} 
		if (i==len-1 && k==5) m++; 
	}	
	printf("%d",m);
	puts("\nPress any key ...");
	getch();
	return 0;
}