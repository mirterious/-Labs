//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
int n=0;
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
randomize();
Edit1->Clear();
Edit2->Clear();
Memo1->Clear();
Edit1->Text=IntToStr(n);
StringGrid1->ColCount=n;
Memo1->Lines->Add("Lab N.5 Vasilevich Ilya");
for(int i=0; i<n;i++)
        StringGrid1->Cells[i][0] = IntToStr(random(20)-10);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
n=StrToInt(Edit1->Text);
if(n>7){
        ShowMessage("max is 7!");
        n=7;
        Edit1->Text = "7";
}
StringGrid1->ColCount=n;
for(int i=0; i<n;i++)
StringGrid1->Cells[i][0]=IntToStr(random(20)-10);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int arr[10], min, max, IndexMax=0, IndexMin=0, pr=1;
for (int i=0; i<n; i++)
        arr[i]=StrToInt(StringGrid1->Cells[i][0]);
max=arr[0];
min=arr[0];
for (int i = 0; i < n; i++) {
        if (arr[i] >= max){
                max=arr[i];
                IndexMax = i;
        }
        if (arr[i] <= min){
                min=arr[i];
                IndexMin = i;
        }
}
if (IndexMin > IndexMax) {
    	for (++IndexMax; IndexMax < IndexMin; IndexMax++)
    		pr *= arr[IndexMax];
    }
if (IndexMin < IndexMax) {
    	for (++IndexMin; IndexMin < IndexMax; IndexMin++)
    		pr *= arr[IndexMin];
}
Edit2->Text=IntToStr(pr);
}
//---------------------------------------------------------------------------
