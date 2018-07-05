//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop
#include "lab2okno.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
double  x, z, a, f, y;
int b;
Edit1->Clear();
Edit3->Clear();
Memo1->Clear();
Memo1->Lines->Add("Lab.3 Vasilevich");
RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Clear();
Memo1->Lines->Add("Lab.3 Vasilevich");
double  x, z, a, f, y;
a=StrToFloat(Edit1->Text);
z=StrToFloat(Edit3->Text);
if (z<1)
        pow(x,2);
else x = z + 1;
switch (RadioGroup1->ItemIndex){
        case 0: f=2*x;
                Memo1->Lines->Add("F = "+FloatToStrF(f,ffFixed,5,2));
           break;
        case 1: f=pow(x,2);
                Memo1->Lines->Add("F = "+FloatToStrF(f,ffFixed,5,2));
           break;
        case 2: f=x/3;
                Memo1->Lines->Add("F = "+FloatToStrF(f,ffFixed,5,2));
           break; }
        y = a * log(1 + pow(x, 1./5)) + pow(cos(f + 1), 2);
Memo1->Lines->Add("Y = "+FloatToStrF(y,ffFixed,5,2));
}
//---------------------------------------------------------------------------
