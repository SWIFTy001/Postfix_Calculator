//---------------------------------------------------------------------------
#include "Postfix_Calculator.h"
#include <iostream>
//#include <cstring>
#include <string>
#include <stack>
#include <vcl.h>
#include <math.h>

char input[20];

int size=0, result = NULL;


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

//---------------------------------------------------------------------------
Node* TForm1::insert(Node *root, int val) {
	if (root == nullptr) {
		root = new Node;
		root->val = val;
		root->left = root->right = nullptr;
	} else if (val < root->val) {
		root->left = insert(root->left, val);
	} else {
		root->right = insert(root->right, val);
	}
	return root;
}

//---------------------------------------------------------------------------
int TForm1::evaluate(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->val;
	}
	int left = evaluate(root->left);
    int right = evaluate(root->right);
    if (root->val == '+') {
		return left + right;
    } else if (root->val == '-') {
        return left - right;
    } else if (root->val == '*') {
		return left * right;
	} else if (root->val == '/') {
		return left / right;
	} else if (root->val == '^') {
		return pow(left,right);
	}
    return 0;
}

//---------------------------------------------------------------------------
Node* TForm1::postfix_to_bst(const char* expression) {
	std::stack<Node*> stack;
    for (int i = 0; i < strlen(expression); i++) {
        if (isdigit(expression[i])) {
			stack.push(insert(nullptr, expression[i] - '0'));
        } else {
			Node *right = stack.top();
			stack.pop();
			Node *left = stack.top();
            stack.pop();
            Node *root = new Node;
            root->val = expression[i];
			root->left = left;
            root->right = right;
            stack.push(root);
        }
	}
    return stack.top();
}
//---------------------------------------------------------------------------
int TForm1::evaluate_postfix(const char* expression) {
	Node *tree = postfix_to_bst(expression);
	return evaluate(tree);

}

//---------------------------------------------------------------------------
void __fastcall TForm1::one(TObject *Sender)
{
strcat(input, "1");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::two(TObject *Sender)
{
strcat (input, "2");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::three(TObject *Sender)
{
strcat (input, "3");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::four(TObject *Sender)
{
strcat(input, "4");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::five(TObject *Sender)
{
strcat (input, "5");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::six(TObject *Sender)
{
 strcat (input, "6");
size++;
 Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::seven(TObject *Sender)
{
strcat (input, "7");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::eight(TObject *Sender)
{
strcat (input, "8");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nine(TObject *Sender)
{
strcat (input, "9");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::zero(TObject *Sender)
{
strcat (input, "0");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::plus(TObject *Sender)
{
strcat (input, "+");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::minus(TObject *Sender)
{
strcat (input, "-");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::multiply(TObject *Sender)
{
strcat (input, "*");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::division(TObject *Sender)
{
 strcat (input, "/");
size++;
 Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::power(TObject *Sender)
{
strcat (input, "^");
size++;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::clearAll(TObject *Sender)
{
strcpy(input,"");
size=0;
Edit1->Text = input;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


void __fastcall TForm1::Result(TObject *Sender)
{
//input = (char)Edit1->Text;



result = evaluate_postfix (input);

Edit1->Text = result;
size=0;
result = NULL;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RemoveOne(TObject *Sender)
{
input[size-1]=NULL;
size--;
Edit1->Text = input;
}
//---------------------------------------------------------------------------


