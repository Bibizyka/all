#pragma once
#include <Windows.h>
#include "Expression.h"
#include "PolandStr.h"
#include "Integral.h"

namespace ����������_���������������_��������� {//������ ������������ ����

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	
	
	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm: public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}
	private:Graphics^ g;
			bool b;//���� ������
			double inf;
			double sup;
	private: System::Windows::Forms::Label^  answer;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel1;











	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  UDymax;
	private: System::Windows::Forms::NumericUpDown^  UDymin;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;











	public: 

	private:
		Expression^ exp;
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;



	protected: 

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->answer = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->UDymax = (gcnew System::Windows::Forms::NumericUpDown());
			this->UDymin = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->UDymax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->UDymin))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox1->Location = System::Drawing::Point(93, 297);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(213, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->BackColor = System::Drawing::Color::AliceBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(388, 291);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 26);
			this->button1->TabIndex = 2;
			this->button1->Text = L"���������";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::AliceBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 391);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"�����:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// answer
			// 
			this->answer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->answer->AutoSize = true;
			this->answer->BackColor = System::Drawing::Color::LightSteelBlue;
			this->answer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->answer->Location = System::Drawing::Point(90, 395);
			this->answer->Name = L"answer";
			this->answer->Size = System::Drawing::Size(0, 18);
			this->answer->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::AliceBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(607, 391);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(115, 29);
			this->button3->TabIndex = 7;
			this->button3->Text = L"�����";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::AliceBlue;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(521, 291);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(250, 24);
			this->label3->TabIndex = 8;
			this->label3->Text = L"������� ��������������:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown1->Location = System::Drawing::Point(597, 332);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 9;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, System::Int32::MinValue});
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown2->Location = System::Drawing::Point(597, 363);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 10;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::AliceBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(5, 294);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"��������";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::AliceBlue;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(312, 297);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 24);
			this->label4->TabIndex = 11;
			this->label4->Text = L"dx";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->flowLayoutPanel1->Location = System::Drawing::Point(6, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(558, 282);
			this->flowLayoutPanel1->TabIndex = 12;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::flowLayoutPanel1_Paint);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::NavajoWhite;
			this->panel1->Controls->Add(this->UDymax);
			this->panel1->Controls->Add(this->UDymin);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Location = System::Drawing::Point(570, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(161, 282);
			this->panel1->TabIndex = 0;
			// 
			// UDymax
			// 
			this->UDymax->DecimalPlaces = 1;
			this->UDymax->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->UDymax->Location = System::Drawing::Point(80, 66);
			this->UDymax->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->UDymax->Name = L"UDymax";
			this->UDymax->Size = System::Drawing::Size(46, 20);
			this->UDymax->TabIndex = 20;
			this->UDymax->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->UDymax->Visible = false;
			this->UDymax->ValueChanged += gcnew System::EventHandler(this, &MyForm::UDymax_ValueChanged);
			// 
			// UDymin
			// 
			this->UDymin->DecimalPlaces = 1;
			this->UDymin->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 65536});
			this->UDymin->Location = System::Drawing::Point(80, 25);
			this->UDymin->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
			this->UDymin->Name = L"UDymin";
			this->UDymin->Size = System::Drawing::Size(46, 20);
			this->UDymin->TabIndex = 19;
			this->UDymin->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, System::Int32::MinValue});
			this->UDymin->Visible = false;
			this->UDymin->ValueChanged += gcnew System::EventHandler(this, &MyForm::UDymin_ValueChanged);
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::AliceBlue;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(19, 66);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(55, 24);
			this->label8->TabIndex = 17;
			this->label8->Text = L"ymax";
			this->label8->Visible = false;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::AliceBlue;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(19, 21);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 24);
			this->label7->TabIndex = 16;
			this->label7->Text = L"ymin";
			this->label7->Visible = false;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::AliceBlue;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(521, 363);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 24);
			this->label6->TabIndex = 15;
			this->label6->Text = L"xmax";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::AliceBlue;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(521, 330);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 24);
			this->label5->TabIndex = 14;
			this->label5->Text = L"xmin";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PeachPuff;
			this->ClientSize = System::Drawing::Size(734, 425);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->answer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->SizeChanged += gcnew System::EventHandler(this, &MyForm::MyForm_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->UDymax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->UDymin))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		

private: System::Void UDymin_ValueChanged(System::Object^  sender, System::EventArgs^  e) {//�� ����� �������� � y ��� � ����,������������ ���
			 Double x=(Double)UDymin->Value+0.1;
			 UDymax->Minimum=(Decimal)x;
			 MoveAxes();
		 }

private: System::Void UDymax_ValueChanged(System::Object^  sender, System::EventArgs^  e) {//�� �� ����� ��� � ���,��� ������ ��� �� �����
			Double x=(Double)UDymax->Value-0.1;
			 UDymin->Maximum=(Decimal)x;
			 MoveAxes();
		 }

		private: System:: Void MoveAxes(){//�����,������� ��� �������������� ������� � ���
			 g= flowLayoutPanel1->CreateGraphics();//����������� �� ,����������� � �� ��� ������
			  g->Clear(Color::White);//�������,���� �� ������������� ���� �� �����
			  double xmin = (double)numericUpDown1->Value;//� ������ ��������� ��������
			  double xmax = (double)numericUpDown2->Value;
			  /*double ymin = (double)UDymin->Value;
			  double ymax = (double)UDymax->Value;*/
			  int width = flowLayoutPanel1->Width;//������ ���� ��������
			  int height = flowLayoutPanel1->Height;//������ ��������
			  PanelParameters^ pp = gcnew PanelParameters(xmin-0.5,xmax+0.5,inf-0.5,inf-0.5,sup+0.5,height);//��������� �������,�������� ��� ��������� ������ � ��������� ��
			  DecartPainter^ dp= gcnew DecartPainter(pp);//�� ���� ��������� ������� ������ ������ DecartPainter
			  dp->PaintAxes(g);//������ ���
			  dp->PaintDiv(g);//�������
			  
			  if(b) DrawFunction();//b-����� �� �������� �������,����� -������ � ��������
		 }
				 
		void DrawFunction(){//������ ������
				
				g= flowLayoutPanel1->CreateGraphics();//�� �� �����,��� � ����������
				g->Clear(Color::White);
				double xmin = (double)numericUpDown1->Value;
				double xmax = (double)numericUpDown2->Value;
				int width = flowLayoutPanel1->Width;
				int height = flowLayoutPanel1->Height;
			  
				Function^ f=gcnew Function(exp);//������� ������ ������Function �� ���������
				
				f->FindInfSup(xmin,xmax);//������� ������� � ��������
				sup = f->GetSup();				
				inf = f->GetInf();
				
				
				if(xmin>xmax){		//������ �������,���� ���� ��������� ����������			
					double t = xmin;
					xmin=xmax;
					xmax=t;
				} 
				
			   PanelParameters^ pp = gcnew PanelParameters(xmin-0.5,xmax+0.5,inf-0.5,sup+0.5,width,height);// �� �� �����
				FunctionPainter^ fp = gcnew FunctionPainter(f,pp);// ������� FunctionPainter �� ������� � ���������
				fp->DrawFunc(g,xmin,xmax);	//������ �������			
				
				
		 }                                                                                                                                                                                                     





private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^s = textBox1->Text;//���������
			 s = s->Replace(" ","");//������� ��� ������� �� ������
			 textBox1->Text=s;//� ��������� ���������� ��� ������������
				 PolandStr^str = gcnew PolandStr(s);//������� ������ ������ PolandStr
				 String^result = str->GetPolandStr();//� ������ ^result ���������� �������� ������
				 result=result->Trim();//������� � ������ � � ����� ��� �������
				 if(result=="") answer->Text="������� ������������ ���������";
			 exp = gcnew Expression(result);// exp-���� ������,�� ������ ������ ������� ������ ������ ��������� � ���������� �� � ���� ������
			 answer->Text="";//�����,���� �� ���������� �����,���� ��� ���-�� ���� ,��� �������
			 GetResult();//�������,�� ������� ���������
		 }


		void GetResult(){	//�������		  			 
			 if(!exp->FindVars()){//���� � ��������� �� ���������� ����������,�� �� ������ ������� ��� ���������� b ����������� �������� ���,��������� �������� ���������
				try{
				  DrawFunction();
			      b = true;
				
				  Integrate();
				 }
				 catch(Exception^ ex){//���� �� ���������� ���-��,�� ������� ������������ ���������
					 answer->Text="������� ������������ ���������";
				 }

				
			 }
			 else{
				 answer->Text="����������, ������� ��������� ��� ����������";	//���� ���� ����������,�� �����					
			 }
			 

		 }
		PanelParameters^ forint;//���� ������
		String^otv;//�����
		Integral^ i;//������ ������ ��������
		void �������������������(){//����� ,��������� �����,�� ��� �� �������
		otv=i->CalcK(textBox1->Text);
		} 
		
		void Integrate(){//�������,������� ������� �������� ���������
			
			bool otr;//�����,���� ������� �������������� ������� ��������
			double xmin=(double)numericUpDown1->Value;//��������� ��������� ���
			double xmax=(double)numericUpDown2->Value;
			int width = flowLayoutPanel1->Width;
			int height = flowLayoutPanel1->Height;
			  
			
			if(xmin>xmax){//���� ��� ����� �� � ��� �������,������ �������
				otr = true;
				double t = xmin;
				xmin=xmax;
				xmax=t;
			}
			Function^ f1=gcnew Function(exp);	//������� ������� �� ���������		exp

			forint = gcnew PanelParameters(xmin-0.5,xmax+0.5,inf-0.5,sup+0.5,width,height);//��� ��������� ������ ���� ����������
			
			
			 i = gcnew Integral(xmin,xmax);//������� ������ ������ ��������
			 �������������������();//����� ���������� ���������
			 if (otr){
				 if(otv[0]=='-')otv ->Remove('-');//���� ��� ����� �� ��� �������
			 else otv="-"+otv;//���� ��� �� ����,�����������
			 }

			ThreadStart^ s=gcnew ThreadStart(this,&MyForm::�������������������);//ThreadStart ����� ��� ������,����� ����� ������������� ����� �������������������
			Thread^potok=gcnew Thread(s);//�� ThreadStart ������ �����
			potok->Start();//��������� �����
			Convertation::Converter^perevod=gcnew Convertation::Converter(forint);//�� ������� ������ ������ ��������� 
			NextStep(perevod->XtoPx(xmin),perevod->XtoPx(xmax));//��������� ������� �������
			if (otr){
				 if(otv[0]=='-')otv ->Remove('-');//���� ��� ����� �� ��� �������
			 else otv="-"+otv;//���� ��� �� ����,�����������
			 }
			answer->Text=otv;//���������� �����
		}




				
	void NextStep(int xn,int xk){//��������� �� ��������� �� ��������

			
			Convertation::Converter^ con = gcnew Convertation::Converter(forint);//������ ������ ��������� �������
			Function^f = gcnew Function(exp);//������� ������� �� ���������
			for(int i=xn;i<xk;i++){//���� ���� �� ������ �� ������
				Sleep(5);
				double y = f->Calc(con->PxtoX(i));//��������� ���������� �����,�������� ������� � �����
				DrawLine1(i,con->YtoPy(0),i,con->YtoPy(y));	//������ ����� �� �������� �� ���������			
			}
		}

	void DrawLine1(int x1,int y1,int x2,int y2){//����� ���� ������,��� ���������,����� ����� ����� � ������ ������ �����
		Color col = Color::FromArgb(50, 255, 0, 0);
		Pen^ pen =gcnew Pen(col);
			g->DrawLine(pen,x1,y1,x2,y2);
	}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();//������ ������
		 }
private: System::Void Symb_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }

private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void MyForm_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 MoveAxes();//���� �� ������ ������ ����,�� ��� �����������������
		 }
private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};
};