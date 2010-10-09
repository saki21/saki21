#pragma once

namespace ok {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
    /// MainForm の概要
	/// </summary>
#define OFF listView1->off()
#define ON listView1->on()
	public ref class MainForm : public System::Windows::Forms::Form
	{
		private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  point;

	private: System::Windows::Forms::CheckBox^  food;
	private: System::Windows::Forms::CheckBox^  interior;
	private: System::Windows::Forms::CheckBox^  seikatuzac;
	private: System::Windows::Forms::CheckBox^  hobby;
	private: System::Windows::Forms::CheckBox^  kadencamera;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  histStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  waitStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteStripMenuItem;
	private: System::Windows::Forms::CheckBox^  game;

	private: System::Windows::Forms::ToolStripMenuItem^  updateStripMenuItem;
	private: System::Windows::Forms::CheckBox^  pcoption;
	private: System::Windows::Forms::CheckBox^  other;
	private: System::Windows::Forms::ColumnHeader^  columnHeader11;
	private: AuctionPage^ap;

private: void setLimit(System::Object^  sender) {
			 String ^s = dynamic_cast<ComboBox^>(sender)->Text;
			 Single  v = Convert::ToSingle(s) * ok::SEP;
			 AuctionItem::limitGo = Convert::ToInt32(v);
			 Trace::WriteLine(String::Format("{0}", v));
		 }


private: void preThread(Object^ sender, EventArgs^ e)
        {
 			IEnumerator ^i = listView1->SelectedItems->GetEnumerator ();
			while (i->MoveNext()){
				 safe_cast<AuctionItem^>(i->Current)->preThread();
			}
        }
private: void doRireki(Object^ sender, EventArgs^ e)
        {
 			IEnumerator ^i = listView1->SelectedItems->GetEnumerator ();
			while (i->MoveNext()){
				 safe_cast<AuctionItem^>(i->Current)->doRireki();
			}
        }
private: void doDelete(Object^ sender, EventArgs^ e)
        {
 			IEnumerator ^i = listView1->SelectedItems->GetEnumerator ();
			while (i->MoveNext()){
				listView1->Items->Remove(safe_cast<AuctionItem^>(i->Current));
///				 safe_cast<AuctionItem^>(i->Current)->doDelete();
			}
        }
	public:
		MainForm(AuctionPage ^ap) : ap(ap)
		{
			InitializeComponent();
			//TODO: ここにコンストラクター コードを追加します
			listView1->View = View::Details;
//			listView1->LabelEdit = true;
		    listView1->AllowColumnReorder = true;
		    listView1->CheckBoxes = true;
			listView1->FullRowSelect = true;
		    listView1->GridLines = true;
			listView1->Sorting = SortOrder::Ascending;
			ap->listview = listView1;
			ap->UpdateItems();
#if 0
			ListView::ListViewItemCollection^items = listView1->Items;
			for (int k = 0; k < AuctionPage::Length; k++) {
				items->Add(AuctionPage::all[k]);
			}
#endif
			ok::mogi = this->checkBox2->Checked;
	        waitStripMenuItem->Click += gcnew EventHandler(this, &MainForm::preThread);
	        histStripMenuItem->Click += gcnew EventHandler(this, &MainForm::doRireki);
	        deleteStripMenuItem->Click += gcnew EventHandler(this, &MainForm::doDelete);
			timer1->Interval = 1000 / ok::SEP; //125;
			timer1->Enabled = true;
#define A_(a)	#a##".75", #a##".5", #a##".25"
#define B_(a)	"-"## #a##".25", "-"## #a##".5", "-"## #a##".75"
#define a_(a)	#a##".875",#a##".75", #a##".625", #a##".5", #a##".375", #a##".25", #a##".125"
#define b_(a)	"-"## #a##".125", "-"## #a##".25", "-"## #a##".375", "-"## #a##".5",\
				"-"## #a##".625", "-"## #a##".75", "-"## #a##".875"
		//	(56)
#define A(a)	A_(a), #a
#define C(a)	A_(a), #a, B_(a)
#define B(a)	"-"## #a, B_(a)
#define a(a)	a_(a), #a
#define c(a)	a_(a), #a, b_(a)
#define b(a)	"-"## #a, b_(a)
			comboBox1->Items->AddRange(
				ok::SEP == 4 ?
				gcnew cli::array< System::Object^  > {L"2", A(1),C(0),B(1),B(2),B(3),B(4),B(5)}:
				gcnew cli::array< System::Object^  > {L"2", a(1),c(0),b(1),b(2),b(3),b(4),b(5)}
			);
#undef a
#undef b
#undef c

	}

	protected:
		/// <summary>					
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	protected: 

	protected: 

	protected: 

	protected: 
	private: LV^  listView1;
//	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
//			this->listView1 = (gcnew LV()); //System::Windows::Forms::ListView());
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->point = (gcnew System::Windows::Forms::CheckBox());
			this->food = (gcnew System::Windows::Forms::CheckBox());
			this->interior = (gcnew System::Windows::Forms::CheckBox());
			this->seikatuzac = (gcnew System::Windows::Forms::CheckBox());
			this->hobby = (gcnew System::Windows::Forms::CheckBox());
			this->kadencamera = (gcnew System::Windows::Forms::CheckBox());
			this->game = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->contextMenuStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->updateStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->waitStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listView1 = (gcnew LV());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->pcoption = (gcnew System::Windows::Forms::CheckBox());
			this->other = (gcnew System::Windows::Forms::CheckBox());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(934, 7);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(68, 20);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Text = L"-1";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->Layout += gcnew System::Windows::Forms::LayoutEventHandler(this, &MainForm::comboBox1_Layout);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 11);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(48, 16);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"選択";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// point
			// 
			this->point->AutoSize = true;
			this->point->Location = System::Drawing::Point(692, 11);
			this->point->Name = L"point";
			this->point->Size = System::Drawing::Size(60, 16);
			this->point->TabIndex = 5;
			this->point->Text = L"ポイント";
			this->point->UseVisualStyleBackColor = true;
			this->point->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// food
			// 
			this->food->AutoSize = true;
			this->food->Location = System::Drawing::Point(632, 11);
			this->food->Name = L"food";
			this->food->Size = System::Drawing::Size(48, 16);
			this->food->TabIndex = 6;
			this->food->Text = L"食品";
			this->food->UseVisualStyleBackColor = true;
			this->food->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// interior
			// 
			this->interior->AutoSize = true;
			this->interior->Location = System::Drawing::Point(556, 9);
			this->interior->Name = L"interior";
			this->interior->Size = System::Drawing::Size(67, 16);
			this->interior->TabIndex = 7;
			this->interior->Text = L"インテリア";
			this->interior->UseVisualStyleBackColor = true;
			this->interior->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// seikatuzac
			// 
			this->seikatuzac->AutoSize = true;
			this->seikatuzac->Location = System::Drawing::Point(478, 9);
			this->seikatuzac->Name = L"seikatuzac";
			this->seikatuzac->Size = System::Drawing::Size(72, 16);
			this->seikatuzac->TabIndex = 8;
			this->seikatuzac->Text = L"生活雑貨";
			this->seikatuzac->UseVisualStyleBackColor = true;
			this->seikatuzac->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// hobby
			// 
			this->hobby->AutoSize = true;
			this->hobby->Location = System::Drawing::Point(419, 9);
			this->hobby->Name = L"hobby";
			this->hobby->Size = System::Drawing::Size(48, 16);
			this->hobby->TabIndex = 9;
			this->hobby->Text = L"趣味";
			this->hobby->UseVisualStyleBackColor = true;
			this->hobby->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// kadencamera
			// 
			this->kadencamera->AutoSize = true;
			this->kadencamera->Location = System::Drawing::Point(303, 8);
			this->kadencamera->Name = L"kadencamera";
			this->kadencamera->Size = System::Drawing::Size(48, 16);
			this->kadencamera->TabIndex = 10;
			this->kadencamera->Text = L"家電";
			this->kadencamera->UseVisualStyleBackColor = true;
			this->kadencamera->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// game
			// 
			this->game->AutoSize = true;
			this->game->Location = System::Drawing::Point(357, 8);
			this->game->Name = L"game";
			this->game->Size = System::Drawing::Size(54, 16);
			this->game->TabIndex = 11;
			this->game->Text = L"ゲーム";
			this->game->UseVisualStyleBackColor = true;
			this->game->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(67, 10);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(48, 16);
			this->checkBox2->TabIndex = 12;
			this->checkBox2->Text = L"模擬";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// contextMenuStrip
			// 
			this->contextMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->updateStripMenuItem, 
				this->histStripMenuItem, this->waitStripMenuItem, this->deleteStripMenuItem});
			this->contextMenuStrip->Name = L"contextMenuStrip1";
			this->contextMenuStrip->Size = System::Drawing::Size(153, 114);
			this->contextMenuStrip->Text = L"更新";
			this->contextMenuStrip->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MainForm::contextMenuStrip1_ItemClicked);
			// 
			// updateStripMenuItem
			// 
			this->updateStripMenuItem->Name = L"updateStripMenuItem";
			this->updateStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->updateStripMenuItem->Text = L"更新";
			this->updateStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::updateStripMenuItem_Click);
			// 
			// histStripMenuItem
			// 
			this->histStripMenuItem->Name = L"histStripMenuItem";
			this->histStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->histStripMenuItem->Text = L"履歴";
			this->histStripMenuItem->ToolTipText = L"履歴\r\n";
			// 
			// waitStripMenuItem
			// 
			this->waitStripMenuItem->CheckOnClick = true;
			this->waitStripMenuItem->Name = L"waitStripMenuItem";
			this->waitStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->waitStripMenuItem->Text = L"入札準備";
			this->waitStripMenuItem->ToolTipText = L"スレッドの起動";
			// 
			// deleteStripMenuItem
			// 
			this->deleteStripMenuItem->Name = L"deleteStripMenuItem";
			this->deleteStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->deleteStripMenuItem->Text = L"削除";
			this->deleteStripMenuItem->ToolTipText = L"オークション削除";
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(11) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8, 
				this->columnHeader9, this->columnHeader10, this->columnHeader11});
			this->listView1->ContextMenuStrip = this->contextMenuStrip;
			this->listView1->Location = System::Drawing::Point(12, 38);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(990, 484);
			this->listView1->TabIndex = 2;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &MainForm::listView1_ItemCheck);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"ID";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"商品名";
			this->columnHeader2->Width = 200;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"価格";
			this->columnHeader3->Width = 100;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"時間";
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"入札者";
			this->columnHeader5->Width = 200;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"単位";
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"該当";
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"手動";
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"モード";
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"備考";
			// 
			// pcoption
			// 
			this->pcoption->AutoSize = true;
			this->pcoption->Location = System::Drawing::Point(237, 9);
			this->pcoption->Name = L"pcoption";
			this->pcoption->Size = System::Drawing::Size(60, 16);
			this->pcoption->TabIndex = 13;
			this->pcoption->Text = L"パソコン";
			this->pcoption->UseVisualStyleBackColor = true;
			this->pcoption->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// other
			// 
			this->other->AutoSize = true;
			this->other->Location = System::Drawing::Point(759, 9);
			this->other->Name = L"other";
			this->other->Size = System::Drawing::Size(55, 16);
			this->other->TabIndex = 14;
			this->other->Text = L"その他";
			this->other->UseVisualStyleBackColor = true;
			this->other->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton_CheckedChanged);
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"カテゴリ";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1014, 549);
			this->Controls->Add(this->other);
			this->Controls->Add(this->pcoption);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->game);
			this->Controls->Add(this->hobby);
			this->Controls->Add(this->kadencamera);
			this->Controls->Add(this->seikatuzac);
			this->Controls->Add(this->food);
			this->Controls->Add(this->interior);
			this->Controls->Add(this->point);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->listView1);
			this->Name = L"MainForm";
			this->Text = L"DMM ペニーオークション";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResizeBegin += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeBegin);
			this->ResizeEnd += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeEnd);
			this->contextMenuStrip->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void MainForm_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
			 listView1->Width = Width - 20;	
			 listView1->Height = Height - 30;
		 }
private: System::Void MainForm_ResizeBegin(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			AuctionArg b;
			OFF;
 			IEnumerator ^i = listView1->Items->GetEnumerator ();
			while (i->MoveNext()){
				AuctionItem ^a = safe_cast<AuctionItem^>(i->Current);
				switch (a->mode) {
				default: if (a->down > AuctionItem::limitGo || (!a->Checked && a->down > ok::limitFinal)) {a->skip();} else { b.set(a);} break;
				case 2: case 3: case 6: if (a->down != a->look) { a->skip();} else {b.set(a);} break;
				case 4:;
				}
			}
			if (b.test()) AuctionItem::UpdateStatus(b.arg);
	//		AuctionItem::UpdateStatus();
			ON;
		 }

private: System::Void listView1_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
	//		ag_flag = true;
		 }

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 setLimit(sender);

		 }
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			bool v = dynamic_cast<CheckBox^>(sender)->Checked;
			OFF;
			array<AuctionItem^>^ a = AuctionPage::all;
			for (int  i = 0; i < AuctionPage::Length; i++) {
				a[i]->Checked = v;
			}
 			ON;
		 }

private: System::Void radioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 ap->setsub(dynamic_cast<CheckBox^>(sender)->Name, dynamic_cast<CheckBox^>(sender)->Checked);
		 }
private: System::Void comboBox1_Layout(System::Object^  sender, System::Windows::Forms::LayoutEventArgs^  e) {
			 setLimit(sender);		 }
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 ok::mogi = dynamic_cast<CheckBox^>(sender)->Checked;
		 }

private: System::Void contextMenuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
			W_("FFF");
		 }
	private: System::Void updateStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 ap->UpdateItems();
			 }
};
}

