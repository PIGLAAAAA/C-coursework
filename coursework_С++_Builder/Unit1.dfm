object MainForm: TMainForm
  Left = 110
  Top = 185
  Caption = #1056#1072#1089#1095#1077#1090' '#1090#1086#1088#1084#1086#1079#1085#1086#1075#1086' '#1087#1091#1090#1080
  ClientHeight = 678
  ClientWidth = 788
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 709
    Height = 249
    Caption = #1048#1089#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Label14: TLabel
      Left = 8
      Top = 19
      Width = 165
      Height = 16
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1089#1094#1077#1087#1083#1077#1085#1080#1103' '#966':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label15: TLabel
      Left = 8
      Top = 82
      Width = 252
      Height = 16
      Caption = 'C'#1082#1086#1088#1086#1089#1090#1100' '#1087#1077#1088#1077#1076' '#1090#1086#1088#1084#1086#1078#1077#1085#1080#1077#1084' V0 ('#1084'/'#1089'): '#1086#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label16: TLabel
      Left = 347
      Top = 82
      Width = 14
      Height = 16
      Caption = #1076#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label17: TLabel
      Left = 434
      Top = 82
      Width = 22
      Height = 16
      Caption = #1096#1072#1075
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label18: TLabel
      Left = 8
      Top = 104
      Width = 46
      Height = 16
      Caption = #1059#1082#1083#1086#1085' i:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label19: TLabel
      Left = 8
      Top = 131
      Width = 252
      Height = 16
      Caption = #1042#1088#1077#1084#1103' '#1087#1077#1088#1074#1086#1081' '#1092#1072#1079#1099' '#1090#1086#1088#1084#1086#1078#1077#1085#1080#1103'  t1 ('#1089#1077#1082'):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label20: TLabel
      Left = 344
      Top = 131
      Width = 251
      Height = 16
      Caption = #1042#1088#1077#1084#1103' '#1074#1090#1086#1088#1086#1081' '#1092#1072#1079#1099' '#1090#1086#1088#1084#1086#1078#1077#1085#1080#1103'  t2 ('#1089#1077#1082'):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label21: TLabel
      Left = 344
      Top = 161
      Width = 194
      Height = 16
      Caption = #1044#1083#1080#1085#1072' '#1090#1086#1088#1084#1086#1079#1085#1086#1075#1086' '#1087#1091#1090#1080' S ('#1084'): '#1086#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label22: TLabel
      Left = 610
      Top = 161
      Width = 14
      Height = 16
      Caption = #1076#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Slope: TEdit
      Left = 55
      Top = 104
      Width = 61
      Height = 24
      TabOrder = 0
      OnKeyPress = Edit2KeyPress
    end
    object Edit2: TEdit
      Left = 280
      Top = 79
      Width = 61
      Height = 24
      TabOrder = 1
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 367
      Top = 79
      Width = 61
      Height = 24
      TabOrder = 2
      OnKeyPress = Edit2KeyPress
    end
    object Edit4: TEdit
      Left = 462
      Top = 79
      Width = 61
      Height = 24
      TabOrder = 3
      OnKeyPress = Edit2KeyPress
    end
    object TimeFirstBrakPhase: TEdit
      Left = 280
      Top = 128
      Width = 61
      Height = 24
      TabOrder = 4
      OnKeyPress = Edit2KeyPress
    end
    object TimeSecBrakPhase: TEdit
      Left = 630
      Top = 128
      Width = 61
      Height = 24
      TabOrder = 5
      OnKeyPress = Edit2KeyPress
    end
    object LinkLabel1: TLinkLabel
      Left = 8
      Top = 162
      Width = 275
      Height = 20
      Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1080#1085#1077#1088#1094#1080#1080' '#1074#1088#1072#1097#1072#1102#1097#1080#1093#1089#1103' '#1084#1072#1089#1089' '#948':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object InertCoefRotatMas: TEdit
      Left = 280
      Top = 158
      Width = 61
      Height = 24
      TabOrder = 7
      OnKeyPress = Edit2KeyPress
    end
    object BrakDistFrom: TEdit
      Left = 544
      Top = 158
      Width = 61
      Height = 24
      TabOrder = 8
      OnKeyPress = Edit2KeyPress
    end
    object BrakDistTo: TEdit
      Left = 630
      Top = 158
      Width = 61
      Height = 24
      TabOrder = 9
      OnKeyPress = Edit2KeyPress
    end
    object LinkLabel2: TLinkLabel
      Left = 8
      Top = 188
      Width = 265
      Height = 20
      Caption = #1057#1082#1086#1088#1086#1089#1090#1100' '#1076#1083#1103' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1080#1103' '#1091#1082#1083#1086#1085#1072' V0 ('#1084'/'#1089'):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
    end
    object VSlope: TEdit
      Left = 280
      Top = 188
      Width = 61
      Height = 24
      TabOrder = 11
      OnKeyPress = Edit2KeyPress
    end
    object CheckTypeCar: TCheckBox
      Left = 3
      Top = 213
      Width = 233
      Height = 17
      Caption = #1043#1088#1091#1078#1077#1085#1099#1081'/'#1087#1086#1088#1086#1078#1085#1080#1081' '#1072#1074#1090#1086#1084#1086#1073#1080#1083#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 12
      OnClick = CheckTypeCarClick
    end
    object Edit11: TEdit
      Left = 3
      Top = 41
      Width = 688
      Height = 24
      TabOrder = 13
    end
  end
  object ProcesData: TButton
    Left = 524
    Top = 256
    Width = 193
    Height = 33
    Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100' '#1076#1072#1085#1085#1099#1077
    TabOrder = 1
    OnClick = ProcesDataClick
  end
  object StatBarInfo: TStatusBar
    Left = 0
    Top = 659
    Width = 788
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 295
    Width = 709
    Height = 358
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099' '#1086#1073#1088#1072#1073#1086#1090#1082#1080' '#1076#1072#1085#1085#1099#1093
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    DesignSize = (
      709
      358)
    object Label1: TLabel
      Left = 8
      Top = 18
      Width = 133
      Height = 16
      Caption = #1058#1086#1088#1084#1086#1079#1085#1086#1081' '#1087#1091#1090#1100' S ('#1084'):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 274
      Width = 46
      Height = 16
      Anchors = [akLeft, akBottom]
      Caption = #1059#1082#1083#1086#1085' i:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitTop = 166
    end
    object BrakDistGrid: TStringGrid
      Left = 0
      Top = 40
      Width = 709
      Height = 120
      ColCount = 1
      FixedCols = 0
      RowCount = 1
      FixedRows = 0
      TabOrder = 0
    end
    object VSlopeGrid: TStringGrid
      Left = 0
      Top = 301
      Width = 709
      Height = 57
      Anchors = [akLeft, akBottom]
      ColCount = 1
      FixedCols = 0
      RowCount = 1
      FixedRows = 0
      TabOrder = 1
    end
  end
  object MainMenu1: TMainMenu
    Left = 736
    Top = 56
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N4: TMenuItem
        Caption = #1057#1086#1079#1076#1072#1090#1100
        ShortCut = 16462
        OnClick = MCreateFileClick
      end
      object MOpenFile: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100'...'
        ShortCut = 16463
        OnClick = MOpenFileClick
      end
      object MSaveFile: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Enabled = False
        ShortCut = 16467
        OnClick = MSaveFileClick
      end
      object N8: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
        ShortCut = 49235
        OnClick = SaveASClick
      end
      object N9: TMenuItem
        Caption = '-'
      end
      object N10: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = Exit
      end
    end
    object N3: TMenuItem
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
      object N7: TMenuItem
        Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100' '#1076#1072#1085#1085#1099#1077
        OnClick = ProcesDataClick
      end
    end
    object N2: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N5: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = informationClick
      end
    end
  end
  object SaveFileDialog: TSaveDialog
    DefaultExt = 'cbd'
    Filter = #1060#1072#1081#1083#1099' '#1089' '#1080#1089#1093#1086#1076#1085#1099#1084#1080' '#1076#1072#1085#1085#1099#1084#1080'(*.cpic)|*.cbd|'#1042#1089#1077' '#1092#1072#1081#1083#1099'(*.*)|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofEnableSizing]
    Left = 736
    Top = 8
  end
  object OpenDialog1: TOpenDialog
    Left = 736
    Top = 104
  end
end
