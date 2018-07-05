object Form1: TForm1
  Left = 1002
  Top = 201
  Width = 329
  Height = 203
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
    Left = 16
    Top = 24
    Width = 20
    Height = 13
    Caption = 'Size'
  end
  object Label4: TLabel
    Left = 16
    Top = 48
    Width = 61
    Height = 13
    Caption = 'Proizvedenie'
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 72
    Width = 281
    Height = 33
    ColCount = 2
    DefaultColWidth = 40
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    ScrollBars = ssNone
    TabOrder = 0
  end
  object Button1: TButton
    Left = 216
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 16
    Top = 112
    Width = 185
    Height = 41
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Edit1: TEdit
    Left = 80
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Edit1'
  end
  object Edit2: TEdit
    Left = 80
    Top = 48
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'Edit2'
  end
end
