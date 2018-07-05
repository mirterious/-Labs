#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <vcl.h>
#include <cstring.h>
#pragma hdrstop
using namespace std;

#pragma argsused
int main(int argc, char* argv[])
{
        AnsiString s;
        int i, len, m=0, k=0;
	cout <<"Input string using 1 and 0" << endl;
	cin >> s;
	len=s.Length();
	for(i=1;i<=len;i++){
		if (s[i]!=' ') k++;
		else {
			if(k==5){
				m++;
				k=0;
			}
			k=0;
		}
                if (i==len && k==5) m++;
	}
        cout << m;
	puts("\nPress any key ...");
	getch();
	return 0;
}
//---------------------------------------------------------------------------
 