//---------------------------------------------------------------------------

#ifndef Postfix_CalculatorH
#define Postfix_CalculatorH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <iostream>
//#include <cstring>
#include <string>
#include <stack>
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
struct Node {
	int val;
	Node *left;
	Node *right;
};

//--------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TEdit *Edit1;
	void __fastcall one(TObject *Sender);
	void __fastcall two(TObject *Sender);
	void __fastcall three(TObject *Sender);
	void __fastcall four(TObject *Sender);
	void __fastcall five(TObject *Sender);
	void __fastcall six(TObject *Sender);
	void __fastcall seven(TObject *Sender);
	void __fastcall eight(TObject *Sender);
	void __fastcall nine(TObject *Sender);
	void __fastcall zero(TObject *Sender);
	void __fastcall plus(TObject *Sender);
	void __fastcall minus(TObject *Sender);
	void __fastcall multiply(TObject *Sender);
	void __fastcall division(TObject *Sender);
	void __fastcall power(TObject *Sender);
	void __fastcall clearAll(TObject *Sender);
	void __fastcall Result(TObject *Sender);
	void __fastcall RemoveOne(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	Node* insert(Node *root, int val);
	int evaluate(Node *root);
	Node* postfix_to_bst(const char* expression);
	int evaluate_postfix(const char* expression);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
