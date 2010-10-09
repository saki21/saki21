#pragma once

namespace ok {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// HistForm の概要
	/// </summary>
	public ref class HistForm : public System::Windows::Forms::Form
	{
		AuctionItem ^a;
		int down;
	private: System::Windows::Forms::Timer^  timer1;
	public:
		HistListView ^listView1; 
		HistForm(AuctionItem ^a) : a(a), down(0)
		{
			InitializeComponent();
			SuspendLayout();
			listView1 = gcnew HistListView;
			listView1->Name = L"listView0";
			listView1->Size = System::Drawing::Size(121, 97);
			listView1->FullRowSelect = true;
		    listView1->GridLines = true;
			listView1->TabIndex = 0;
			listView1->UseCompatibleStateImageBehavior = false;
			listView1->View = System::Windows::Forms::View::Details;
			timer1->Enabled = true;
			Controls->Add(listView1);
			Closing += gcnew CancelEventHandler(this, &HistForm::OnHistFClosing);
			ResumeLayout(false);
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~HistForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: 
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &HistForm::timer1_Tick);
			// 
			// HistForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 328);
			this->Name = L"HistForm";
			this->Text = L"HistForm";
			this->Activated += gcnew System::EventHandler(this, &HistForm::HistForm_Activated);
			this->Load += gcnew System::EventHandler(this, &HistForm::HistForm_Load);
			this->Resize += gcnew System::EventHandler(this, &HistForm::HistForm_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void HistForm_Resize(System::Object^  sender, System::EventArgs^  e) {
				 listView1->Size = ClientSize;
			 }
	private: System::Void HistForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 listView1->Size = ClientSize;
			 }
	private: System::Void HistForm_Activated(System::Object^  sender, System::EventArgs^  e) {
				 AuctionHist::cur = a->h;
			 }
	private: void OnHistFClosing(Object^, CancelEventArgs^e){
		e->Cancel = true; Hide(); }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 down--;
				 switch (down) {
				 case -1:
					 if (a->mode != 4)
						 down = a->h->getTimeout() / timer1->Interval;
					 else
						Text += " 終了";
					 break;
				 case 0:
					 if (a->mode != 4)
						a->h->go();
					 break;
				 }
			 }
	};
}
