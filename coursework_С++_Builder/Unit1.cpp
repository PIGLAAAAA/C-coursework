//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
#include <sstream>
#include <string.h>
#include <cstring>
#include <fstream>
using namespace std;
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
   MainForm->Caption=String(Application->Title)+L" - "+DefFileName;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MCreateFileClick(TObject *Sender)
{
	 if (MSaveFile->Enabled)
	 {
		 String FileName=SaveFileDialog->FileName;
		 if (FileName==L"")
		{
			FileName=DefFileName;
		}
		switch (Application->MessageBox((String(L"Присутствуют не сохраненые изменения. Сохранить изменения в файле \"")
		+FileName+"\"?").w_str(),Application->Title.w_str(), MB_YESNOCANCEL|MB_ICONQUESTION))
		{
			case mrCancel:
				return;
			case mrNo:
				break;
			case mrYes:
				if (!CheckData(true))
					return;
					if (SaveFileDialog->FileName==L"") {
					SaveFileDialog->FileName=DefFileName;
					if (!SaveFileDialog->Execute()) {
						if (SaveFileDialog->FileName==DefFileName) {
							SaveFileDialog->FileName=L"";
						}
						return;
					}
				}
				if (!SaveData())
					return;
				break;
		}
	 }
	//выполнить зачистку старых данных
	ClearOldResults();
	//for (int i=1; i < DataGrid->ColCount; i++)
	//DataGrid->Cells[i][1]=L"";
	//DataGrid->ColCount=2;
	Edit11->Text=L"";
	Edit2->Text=L"";
	Edit3->Text=L"";
	Edit4->Text=L"";
	Slope->Text=L"";
	TimeFirstBrakPhase->Text=L"";
	TimeSecBrakPhase->Text=L"";
	InertCoefRotatMas->Text=L"";
	BrakDistFrom->Text=L"";
	BrakDistTo->Text=L"";
	VSlope->Text=L"";
	//MDelColDataGrid->Enabled = false;
	Caption=String(Application->Title)+L" - "+ DefFileName;
	MSaveFile->Enabled = false;
	CheckTypeCar->Checked=false;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

bool __fastcall TMainForm::CheckData (bool ToSave) // проверка файла
{
    bool ErrorF = false;
	String ErrMess;
	double TempValue;
	bool ErrorFEdit = false;
	if (!(Edit2->Text==L""&&ToSave) && (!TryStrToFloat(Edit2->Text, TempValue)||TempValue<0))
	{
		if (ErrorF)
			ErrMess+=L". Некорректные или недопустимое значение: cкорость перед торможением от";
		else
		{
			ErrorF=true;
			ErrMess=L"Некорректные или недопустимое значение: cкорость перед торможением от";
	   }
		ErrorFEdit = true;
	}
	if (!(Edit3->Text==L""&&ToSave) && (!TryStrToFloat(Edit3->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; cкорость перед торможением до";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: cкорость перед торможением до";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: cкорость перед торможением до";
			}
			ErrorFEdit = true;
		}
	}
	if (!(Edit4->Text==L""&&ToSave) && (!TryStrToFloat(Edit4->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; cкорость перед торможением, шаг";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: cкорость перед торможением, шаг";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: cкорость перед торможением, шаг";
			}
			ErrorFEdit = true;
		}
	}
    if (!(Slope->Text==L""&&ToSave) && (!TryStrToFloat(Slope->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; уклона";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: уклона";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: уклона";
            }
			ErrorFEdit = true;
		}
	}
	if (!(TimeFirstBrakPhase->Text==L""&&ToSave) && (!TryStrToFloat(TimeFirstBrakPhase->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; время первой фазы торможения";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: время первой фазы торможения";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: время первой фазы торможения";
            }
			ErrorFEdit = true;
		}
	}
	if (!(TimeSecBrakPhase->Text==L""&&ToSave) && (!TryStrToFloat(TimeSecBrakPhase->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; время второй фазы торможения";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: время второй фазы торможения";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: время второй фазы торможения";
            }
			ErrorFEdit = true;
		}
	}
	if (!(InertCoefRotatMas->Text==L""&&ToSave) && (!TryStrToFloat(InertCoefRotatMas->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; коэффициент инерции вращающихся масс";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: коэффициент инерции вращающихся масс";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: коэффициент инерции вращающихся масс";
			}
			ErrorFEdit = true;
		}
	}
	if (!(BrakDistFrom->Text==L""&&ToSave) && (!TryStrToFloat(BrakDistFrom->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; длина тормозного пути от";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: длина тормозного пути от";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: длина тормозного пути от";
			}
			ErrorFEdit = true;
		}
	}
	if (!(BrakDistTo->Text==L""&&ToSave) && (!TryStrToFloat(BrakDistTo->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; длина тормозного пути до";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: длина тормозного пути до";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: длина тормозного пути до";
			}
			ErrorFEdit = true;
		}
	}
	if (!(VSlope->Text==L""&&ToSave) && (!TryStrToFloat(VSlope->Text, TempValue)||TempValue<0)) {
		if (ErrorFEdit)
			ErrMess+=L"; скорость для расчета уклона";
		else {
			if (ErrorF)
				ErrMess+=L". Некорректные или недопустимое значение: скорость для расчета уклона";
			else {
				ErrorF=true;
				ErrMess=L"Некорректные или недопустимое значение: скорость для расчета уклона";
			}
			ErrorFEdit = true;
		}
	}
	if (ErrorF) {
		ErrMess+=L".";
		StatBarInfo->SimpleText=ErrMess;
		Application->MessageBox(ErrMess.w_str(),Application->Title.w_str(), MB_OK|MB_ICONEXCLAMATION);
		return false;
	}
	return true;
}

void __fastcall TMainForm::Exit(TObject *Sender)
{
	 Close();
}

void __fastcall TMainForm::MOpenFileClick(TObject *Sender)
{
	if (MSaveFile->Enabled)
	{
      	String FileName=SaveFileDialog->FileName;
		if (FileName==L"")
		{
			FileName=DefFileName;
		}
			switch (Application->MessageBox((String(L"Присутствуют не сохраненые изменения. Сохранить изменения в файле \"")+
			FileName+"\"?").w_str(),Application->Title.w_str(), MB_YESNOCANCEL|MB_ICONQUESTION))
			{
			case mrCancel:
				return;
			case mrNo:
				break;
			case mrYes:
				if (!CheckData(true))
					return;
				if (SaveFileDialog->FileName==L"") {
					SaveFileDialog->FileName=DefFileName;
					if (!SaveFileDialog->Execute()) {
						if (SaveFileDialog->FileName==DefFileName) {
							SaveFileDialog->FileName=L"";
						}
						return;
					}
				}
				if (!SaveData())
					return;
				break;
		}
	}

	if (!OpenDialog1->Execute())
		return;
	unsigned int ByteCount;
	fstream file;
	file.open(AnsiString(OpenDialog1->FileName).c_str(), ios::in | ios::binary);
	if (!file) {
		Application->MessageBox((String(L"Не удалось открыть файл \"")+OpenDialog1->FileName+"\"!").w_str(),Application->Title.w_str(), MB_OK|MB_ICONERROR);
		return;
	}
	file.read((char*)&ByteCount, sizeof(ByteCount));
	file.seekg(0, ios::end);
	file.clear();
	if (ByteCount != file.tellg()){
		file.close();
		Application->MessageBox((String(L"Не удалось загрузить данные из файла \"")+OpenDialog1->FileName+"\". Файл поврежден.").w_str(), Application->Title.w_str(), MB_OK|MB_ICONERROR);
		return;
	}
	file.clear();
	file.seekg(sizeof(ByteCount));
	double DataEdit;
	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		Edit2->Text=L"";
	else
		Edit2->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		Edit3->Text=L"";
	else
		Edit3->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		Edit4->Text=L"";
	else
		Edit4->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		Slope->Text=L"";
	else
		Slope->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		TimeFirstBrakPhase->Text=L"";
	else
		TimeFirstBrakPhase->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		TimeSecBrakPhase->Text=L"";
	else
		TimeSecBrakPhase->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		InertCoefRotatMas->Text=L"";
	else
		InertCoefRotatMas->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		BrakDistFrom->Text=L"";
	else
		BrakDistFrom->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		BrakDistTo->Text=L"";
	else
		BrakDistTo->Text=DataEdit;

	file.read((char*)&DataEdit, sizeof(DataEdit));
	if (DataEdit==DBL_MIN)
		VSlope->Text=L"";
	else
		VSlope->Text=DataEdit;
	bool TypeCar;
	file.read((char*)&TypeCar, sizeof(TypeCar));
	CheckTypeCar->Checked=TypeCar;
	int ColCount;
	file.read((char*)&ColCount, sizeof(ColCount));
	DynamicArray<double> DGrid;
		try
	{
		DGrid.Length=ColCount;
	} catch (...)
	{
		DGrid.Length=0;
		file.close();
		Application->MessageBox(L"Не хватает оперативной памяти для загрузки данных.",Application->Title.w_str(), MB_OK|MB_ICONEXCLAMATION);
		return;
	}
    file.read((char*)&DGrid[0], sizeof(DGrid[0])*ColCount);
	file.close();
	stringstream stream;
	String str = "";
	for (int i=0; i < ColCount-1; i++)
	{
	  str=str + FloatToStr(DGrid[i])+" " ;
	}
	Edit11->Text = str ;
	ClearOldResults();
	SaveFileDialog->FileName=OpenDialog1->FileName;
	MainForm->Caption=String(Application->Title)+L" - "+ExtractFileName(SaveFileDialog->FileName);
}




//---------------------------------------------------------------------------
 double functionS (bool TypeCar, double &ir, double &t1, double &t2, double &b, double &f, double &v,double &Sp) {
	double Ky;
	if (TypeCar)
		Ky=1.07*b-1.26*(f-0.3)+(0.1-0.21*(f-0.3))*ir;
	else
		Ky=1.3*b-1.2*(f-0.3)+(0.08+0.19*(f-0.3))*ir;
	return (v*(t1+t2)-gr/(1+b)*(f*pow(t2,2)/2-ir*pow((t1+t2),2)/2)+((v-gr/(1+b))*((0.5*f-ir)*t2-t1)*(1+b)*Ky)/(2*gr*(f-ir)))-Sp;

}
//---------------------------------------------------------------------------

 double algВivSegmentHalf (bool TypeCar, double &t1, double &t2, double &b, double &f, double &v, double &From, double &To, double &e) {
	double il=-90, ir=90;
	double Sp=(To-From)/2.0;
	do {
		double f1=functionS(TypeCar, il, t1, t2, b, f, v,Sp);
		double HalfI=(il+ir)/2.0;
		double f2= functionS(TypeCar, HalfI, t1, t2, b, f, v,Sp);
		if (f1*f2<0)
			ir=HalfI;
		else
			il=HalfI;
	}while (fabs(ir-il)>e);
	double i=(ir+il)/2.0;
	Sp=0;
	double res=functionS(TypeCar, i, t1, t2, b, f, v,Sp);
	if (res>From&&res<To)
		return i;
	else
		return DBL_MIN;
 }


void __fastcall TMainForm::ProcesDataClick(TObject *Sender)
{
  if (!CheckData())
		return;
  //подсчет количества значений по коэффицентам fi из поля edit
  int FCount=0;
  float NUM;
  //int n;
  stringstream stream; // Edit11->Text;
  AnsiString str= Edit11->Text;
  char *str2 = new char[ str.Length() + 1 ] ;
  strcpy (str2,str.c_str());
  stream<<str2;
  DynamicArray<double> FI;
  while(!stream.eof())
  {
	stream>>NUM;
	FCount++;
  }
  //
  FI.Length = FCount;
  stream.clear();
  stream.seekg(0);
  for(int i = 0; i < FI.Length; i++)
  stream>>FI[i];
  BrakDistGrid-> ColCount= FCount+1;
  //-------------------------------------------------------------------------
  double StartMean=StrToFloat(Edit2->Text); //присвоение скоростей от, до, шаг
  double FinishMean=StrToFloat(Edit3->Text);
  double StMean=StrToFloat(Edit4->Text);
  int CountSpeed=(FinishMean-StartMean)/StMean+1;//высчитываем кол-во строк
  BrakDistGrid->RowCount=CountSpeed+1;
  double EdMean=StartMean;
  //-------------------------------------------------------------------------
  for (int i=1; i < CountSpeed+1; i++) //заполняем 1 столбец скорости
   {
		BrakDistGrid->Cells[0][i]=EdMean;
		EdMean+=StMean;
		if (EdMean>FinishMean)
			EdMean=FinishMean;
   }
   //------------------------------------------------------------------------
	BrakDistGrid->Cells[0][0]=L"V0\\f";//продолжаем заполнение таблицы
	VSlopeGrid->RowCount=2;
	VSlopeGrid->ColCount=FCount+1;
	VSlopeGrid->Cells[0][0]=L"f";
	VSlopeGrid->Cells[0][1]=L"Уклон";
	bool TypeCar=CheckTypeCar->Checked;
	double ir =StrToFloat(Slope->Text);
	double t1 = StrToFloat(TimeFirstBrakPhase->Text);
	double t2 = StrToFloat(TimeSecBrakPhase->Text);
	double b = StrToFloat(InertCoefRotatMas->Text);
	double v = StrToFloat(VSlope->Text);
	double vF=StrToFloat(BrakDistFrom->Text);
	double vT=StrToFloat(BrakDistTo->Text);
	for (int i=1; i <FCount; i++)
	{
	   BrakDistGrid->Cells[i][0] = FI[i-1];
	   EdMean=StartMean;
	   double f =  FI[i-1];
       double Ky;
			if (TypeCar)
				Ky=1.07*b-1.26*(f-0.3)+(0.1-0.21*(f-0.3))*ir;
			else
				Ky=1.3*b-1.2*(f-0.3)+(0.08+0.19*(f-0.3))*ir;
		for (int j=1; j <= CountSpeed; j++) {
			BrakDistGrid->Cells[i][j]=EdMean*(t1+t2)-gr/(1+b)*(f*pow(t2,2)/2-
									  ir*pow((t1+t2),2)/2)+((EdMean-gr/(1+b))*
									  ((0.5*f-ir)*t2-t1)*(1+b)*Ky)/(2*gr*(f-ir));
			EdMean+=StMean;
			if (EdMean>FinishMean)
				EdMean=FinishMean;
		}
		double e=0.01;
		VSlopeGrid->Cells[i][0]=f;
		double VS=algВivSegmentHalf (TypeCar, t1, t2, b, f, v, vF, vT, e);
		if (VS==DBL_MIN)
			VSlopeGrid->Cells[i][1]=L"-";
		else
			VSlopeGrid->Cells[i][1]=VS;
	}
   //SaveProcData->Enabled=true;
}

void __fastcall TMainForm::ClearOldResults ()
 {
	BrakDistGrid->ColCount=1;
	BrakDistGrid->RowCount=1;
	BrakDistGrid->Cells[0][0]=L"";
	VSlopeGrid->ColCount=1;
	VSlopeGrid->RowCount=1;
	VSlopeGrid->Cells[0][0]=L"";
   //	SaveProcData->Enabled=false;
}


void __fastcall TMainForm::informationClick(TObject *Sender)
{
	ShowMessage("Создание программного приложения для расчета тормозного пути грузового автомобиля при заданных условиях движения. Проект разработан студентом группы 2бАСУ1 Московского автомобильно-дорожного государственного технического университета Никитиным Н.С. под руководством Баринова К.А.");

	// доб. удаление результатов

}
//---------------------------------------------------------------------------
bool __fastcall TMainForm::SaveData ()
{
  DynamicArray<double> DGrid;
   // int ColCount = DataGrid->ColCount-1;
  int ColCount = 0;
  double NUM;
  stringstream stream; // Edit11->Text;
  AnsiString str= Edit11->Text;
  char *str2 = new char[ str.Length() + 1 ] ;
  strcpy (str2,str.c_str());
  stream<<str2;
  while(!stream.eof())
  {
	stream>>NUM;
	ColCount++;
  }
  try
  {
	DGrid.Length=ColCount;
  }
  catch (...)
  {
     DGrid.Length=0;
	 Application->MessageBox(L"Не хватает оперативной памяти, для сохранения данных!"
	 ,Application->Title.w_str(),MB_OK|MB_ICONEXCLAMATION);
	 return false;
  }
  stream.clear();
  stream.seekg(0);
  for (int i=0; i < ColCount; i++)
  {
	  stream>>DGrid[i];
  }
  double DataEdit;
  bool TypeCar = CheckTypeCar->Checked;
  unsigned int CountByte =  sizeof(ColCount)+ColCount*sizeof(DGrid[0])+sizeof(CountByte)+sizeof(DataEdit)*10+sizeof(TypeCar);
  fstream file;
  file.open(AnsiString(SaveFileDialog->FileName).c_str(), ios::out | ios::binary);
	if (!file)
   {
		Application->MessageBox((String(L"Не удалось создать файл \"")
		+SaveFileDialog->FileName+"\"!").w_str(),Application->Title.w_str(),MB_OK|MB_ICONERROR);
		return false;
   }
   	file.write((char*)&CountByte, sizeof(CountByte));
	if (Edit2->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(Edit2->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (Edit3->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(Edit3->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (Edit4->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(Edit4->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (Slope->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(Slope->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (TimeFirstBrakPhase->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(TimeFirstBrakPhase->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (TimeSecBrakPhase->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(TimeSecBrakPhase->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (InertCoefRotatMas->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(InertCoefRotatMas->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (BrakDistFrom->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(BrakDistFrom->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

	if (BrakDistTo->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(BrakDistTo->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));
	if (VSlope->Text==L"")
		DataEdit=DBL_MIN;
	else
		TryStrToFloat(VSlope->Text, DataEdit);
	file.write((char*)&DataEdit, sizeof(DataEdit));

    file.write((char*)&TypeCar, sizeof(TypeCar));
	file.write((char*)&ColCount, sizeof(ColCount));
	file.write((char*)&DGrid[0], sizeof(DGrid[0])*ColCount);
	DGrid.Length=0;
	file.close();
	MSaveFile->Enabled = false;
	return true;
}

void __fastcall TMainForm::MSaveFileClick(TObject *Sender)
{
	if (!CheckData(true))
		return;
			if (SaveFileDialog -> FileName==L"")
	{
		SaveFileDialog->FileName=DefFileName;
		if (!SaveFileDialog->Execute()) {
			if (SaveFileDialog->FileName==DefFileName) {
				SaveFileDialog->FileName=L"";
			}
			return;
		}
	}
	if (!SaveData())
		return;
	MainForm->Caption=String(Application->Title)+L" - "+ExtractFileName(SaveFileDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
	if (!MSaveFile->Enabled) {
		MSaveFile->Enabled= true;
		MainForm->Caption+=L"*";
	}
	if (!((Key >= '0' && Key <= '9') || (int)Key == 22 || (int)Key == 13  || (int)Key == 24 || (int)Key == 26||(int)Key == 8|| (int)Key == 3 || (int)Key == 44)) {//проверка коррекности введеного символа
		StatBarInfo -> SimpleText=String(L"Введен недопустимый символ \"") + Key + L"\"";
		Key = 0;
		return;
	}
	StatBarInfo -> SimpleText = L"";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CheckTypeCarClick(TObject *Sender)
{
	if (!MSaveFile->Enabled) {
		MSaveFile->Enabled= true;
		MainForm->Caption+=L"*";
	}
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SaveASClick(TObject *Sender)
{
	if (!CheckData(true))
		return;
	String OldFileName = SaveFileDialog->FileName;
	SaveFileDialog->FileName=DefFileName;
	if (!SaveFileDialog->Execute()) {
		SaveFileDialog->FileName = OldFileName;
		return;
	}
	if (!SaveData()) {
		SaveFileDialog->FileName=OldFileName;
		return;
	}
	MainForm->Caption=String(Application->Title)+L" - "+ExtractFileName(SaveFileDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
	BrakDistGrid -> Width = ClientWidth - 16;
	VSlopeGrid -> Width = ClientWidth - 16;
	BrakDistGrid -> Height = ClientHeight - 395;
	GroupBox1 ->Width = ClientWidth - 16;
    GroupBox2 -> Width = ClientWidth - 16;
}
//---------------------------------------------------------------------------

