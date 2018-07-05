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
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Form1->DoubleBuffered=true;  // ��������� ������ "������� �����������" ��� ���������� ��������
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 double x=StrToFloat(Edit1->Text);   // ����� � ��������
 Edit1->Text=x+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 int speed = 5;
 Image2->Left+=speed;                     // �������� ��������
 if (Image2->Left>700)
   Image2->Left=Image1->Left;   // ������� �������� � ������ ����
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
 Image3->Top-=8;          // �������� ������
 
 int sx1,sx2,sy1,sy2,rx1,rx2,ry1,ry2;
 sx1=Image2->Left;                   // ����� ���� ��������
 sx2=Image2->Left+Image2->Width;     // ������ ���� ��������
 sy1=Image2->Top;                    // ������� ���� ��������
 sy2=Image2->Top+Image2->Height;     // ������ ���� ��������
 rx1=Image3->Left;
 rx2=Image3->Left+Image3->Width;     // �� �� ��� ������
 ry1=Image3->Top;
 ry2=Image3->Top+Image3->Height;
 if (!(rx1>sx2 || rx2<sx1 || ry1>sy2 || ry2<sy1)) {
                                           // ����������� �������� � �������
   Label3->Caption=Label3->Caption.ToInt()+1;  // ����
   if (Label3->Caption.ToInt()>=10)
        speed+=2;

   Image5->Height=50;                           // ������ �������� ������
   Image5->Width=50;
   Image5->Left=(rx1+rx2)/2-Image5->Width/2;    // ��������� ������ ���, ��� ���� ������
   Image5->Top=ry1-Image5->Height;

   Image5->Show();                 // �������� �����
   Image2->Hide();                 // ������ ������� � ������
   Image3->Hide();

   Timer3->Enabled=false;          // ���������� ������ ������
   Timer4->Enabled=true;          // �������� ������ ���������� �������� ������
 }

 if (ry2<0) {                     // ������ ���� �����
   Timer3->Enabled=false;         // ���������� ������ ������
   Image3->Top=Image4->Top;       // ������� ������ � ��������� �������
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 Timer3->Enabled=true;            // ��������� �������� ������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer4Timer(TObject *Sender)
{                               // ���������� �������� ������
  double dh=3,dw=3;
  Image5->Height+=2*dh;
  Image5->Top-=dh*0.8;
  Image5->Width+=2*dw;
  Image5->Left-=dw/2;

  if (Image5->Height>180) {   // ��������� ������ ������
    Timer4->Enabled=false;
    Image2->Left=-Image2->Width;   // �������������� �������� � ������
    Image3->Top=Image4->Top;
    Image2->Show();
    Image3->Show();
    Image5->Hide();
  }  
}
//---------------------------------------------------------------------------

