#include <iostream>
#include <io.h>
#include <stdlib.h>

using namespace std;

struct Student
{
	int num;
	char fio[20];
	int group;
	double math;
	double phys;
	double chem;
	double info;
	double avsc;
} Zap;
int size1 = sizeof(Student);
FILE *FileZap, *FileText;
char File_Zap[] = "zapisi.dat";
char File_Rez[] = "result.txt";
void Out(Student);
void TextOut(Student);

int main()
{
	setlocale(LC_ALL, "Russian");
	int option, DescriptorFILE, i = 0, kol, j=0, n=0, ID=1, find=0;
	long len;
	Student *mas_Z;
	FileText = fopen(File_Rez, "w");
		while (true) 
		{
		cout << "\nCreate - 1\nView - 2\nAdd - 3\nTask - 4\nCorrect - 5\nExit - 0\n";
		cin >> option;
		switch (option)
		{
		case 1:
			if ((FileZap = fopen(File_Zap, "wb")) == NULL)
			{
				cout << "\nCREATION ERROR";
				return 0;
			}
			fclose(FileZap);
			cout << "\nCreate New File " << File_Zap;
			break;
		case 2:
			if ((FileZap = fopen(File_Zap, "rb")) == NULL)
			{
				cout << "\nOPENING ERROR!";
				return 0;
			}
			while (1)
			{
				if (!fread(&Zap, size1, 1, FileZap)) break;
				Out(Zap);
			}
			fclose(FileZap);
			break;
		case 3:
			FileZap = fopen(File_Zap, "ab");
			DescriptorFILE = fileno(FileZap);
			len = filelength(DescriptorFILE);
			kol = len / size1;
			ID=kol+1;
			cout << "\nF.I.O" << endl;
			cin >> Zap.fio;
			cout << "\nGroup" << endl;
			cin >> Zap.group;
			cout << "\nEnter math mark" << endl;
			cin >> Zap.math;
			cout << "\nEnter physics mark" << endl;
			cin >> Zap.phys;
			cout << "\nEnter chemistry mark" << endl;
			cin >> Zap.chem;
			cout << "\nEnter informatics mark" << endl;
			cin >> Zap.info;
			Zap.num=ID;
			ID++;
			Zap.avsc = (Zap.math + Zap.phys + Zap.chem + Zap.info) / 4;
			fwrite(&Zap, size1, 1, FileZap);
			fclose(FileZap);
			break;
		case 4:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			len = filelength(DescriptorFILE);
			kol = len / size1;
			mas_Z = new Student[kol];
			for (i = 0; i < kol; i++)
				fread((mas_Z + i), size1, 1, FileZap);
			fclose(FileZap);
			FileText = fopen(File_Rez, "wt");
			for (i = 0; i < kol; i++)
			{
				if (mas_Z[i].avsc >= 8)
					TextOut(mas_Z[i]);
			}
			delete[]mas_Z;
			fclose(FileText);
			break;
		case 5:
			FileZap = fopen(File_Zap, "rb");
			DescriptorFILE = fileno(FileZap);
			len = filelength(DescriptorFILE);
			kol = len / size1;
			mas_Z = new Student[kol];
			for (i = 0; i < kol; i++)
				fread((mas_Z + i), size1, 1, FileZap);
			fclose(FileZap);
			FileZap = fopen(File_Zap, "wb");
			cout << "Enter number" << endl;
			cin >> find;
			for (i=0; i<kol; i++)
			{
				if (find==mas_Z[i].num)
				{	

					cout << "\nF.I.O" << endl;
					cin >> mas_Z[i].fio;
					cout << "\nGroup" << endl;
					cin >> mas_Z[i].group;
					cout << "\nEnter math mark" << endl;
					cin >> mas_Z[i].math;
					cout << "\nEnter physics mark" << endl;
					cin >> mas_Z[i].phys;
					cout << "\nEnter chemistry mark" << endl;
					cin >> mas_Z[i].chem;
					cout << "\nEnter informatics mark" << endl;
					cin >> mas_Z[i].info;
					mas_Z[i].avsc = (mas_Z[i].math + mas_Z[i].phys + mas_Z[i].chem + mas_Z[i].info) / 4;
				}
				for (j=0; j<19; j++)
				{
					Zap.fio[j]=mas_Z[i].fio[j];
				}
				Zap.group=mas_Z[i].group;
				Zap.math=mas_Z[i].math;
				Zap.phys=mas_Z[i].phys;
				Zap.chem=mas_Z[i].chem;
				Zap.info=mas_Z[i].info;
				Zap.avsc=mas_Z[i].avsc;
				Zap.num=mas_Z[i].num;
				fwrite(&Zap, size1, 1, FileZap);
			}
			fclose(FileZap);
			delete[]mas_Z;
			break;
		case 0:
			return 0;
		default: cout << "Wrong Input";
			break;
		}
	}
}
void Out(Student z)
{
	cout << z.num << " " << z.fio << " " << z.group << " " << z.math << " " << z.phys << " " << z.chem << " " << z.info << " " << z.avsc << endl;
}
void TextOut(Student z)
{
	cout << z.fio << " " << z.group << " " << z.chem << " " << z.phys << " " << z.info << " " << z.math << " " << z.avsc << endl;
	fprintf(FileText, "%s  %4.1lf \n", z.fio, z.avsc);
}