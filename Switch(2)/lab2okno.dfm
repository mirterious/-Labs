object Form1: TForm1
  Left = 202
  Top = 110
  Width = 833
  Height = 482
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 288
    Top = 104
    Width = 16
    Height = 13
    Caption = 'A ='
  end
  object Label3: TLabel
    Left = 288
    Top = 136
    Width = 16
    Height = 13
    Caption = 'Z ='
  end
  object Label2: TLabel
    Left = 200
    Top = 120
    Width = 82
    Height = 13
    Caption = 'Input any number'
  end
  object RadioGroup1: TRadioGroup
    Left = 456
    Top = 104
    Width = 105
    Height = 145
    Caption = 'Choose Function'
    Items.Strings = (
      'f(x)=2*x'
      'f(x)=x^2'
      'f(x)=x/3')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 376
    Top = 264
    Width = 75
    Height = 25
    Caption = 'GO'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 264
    Top = 160
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object Edit1: TEdit
    Left = 320
    Top = 104
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'Edit1'
  end
  object Edit3: TEdit
    Left = 320
    Top = 136
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit3'
  end
end
