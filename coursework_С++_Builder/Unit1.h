//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------

#define DefFileName L"Безымянный" //значение по умолчанию
#define gr 9.81
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TSaveDialog *SaveFileDialog;
	TOpenDialog *OpenDialog1;
	TMenuItem *N4;
	TMenuItem *MOpenFile;
	TMenuItem *MSaveFile;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N7;
	TGroupBox *GroupBox1;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *Slope;
	TLabel *Label16;
	TEdit *Edit2;
	TLabel *Label17;
	TEdit *Edit3;
	TLabel *Label18;
	TEdit *Edit4;
	TLabel *Label19;
	TEdit *TimeFirstBrakPhase;
	TLabel *Label20;
	TEdit *TimeSecBrakPhase;
	TLinkLabel *LinkLabel1;
	TEdit *InertCoefRotatMas;
	TLabel *Label21;
	TEdit *BrakDistFrom;
	TLabel *Label22;
	TEdit *BrakDistTo;
	TLinkLabel *LinkLabel2;
	TEdit *VSlope;
	TCheckBox *CheckTypeCar;
	TButton *ProcesData;
	TEdit *Edit11;
	TStatusBar *StatBarInfo;
	TGroupBox *GroupBox2;
	TStringGrid *BrakDistGrid;
	TLabel *Label1;
	TLabel *Label2;
	TStringGrid *VSlopeGrid;
	TMenuItem *N5;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MCreateFileClick(TObject *Sender);
	void __fastcall MOpenFileClick(TObject *Sender);
	void __fastcall ProcesDataClick(TObject *Sender);
	void __fastcall Exit(TObject *Sender);
	void __fastcall informationClick(TObject *Sender);
	void __fastcall MSaveFileClick(TObject *Sender);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall CheckTypeCarClick(TObject *Sender);
	void __fastcall SaveASClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
   //	void __fastcall MAddColDataGridClick(TObject *Sender);
   //	void __fastcall MDelColDataGridClick(TObject *Sender);
	//void __fastcall TimeFirstBrakPhaseChange(TObject *Sender);
private:	// User declarations
	bool __fastcall CheckData (bool ToSave = false);
	bool __fastcall SaveData ();
    void __fastcall ClearOldResults();
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);


};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
