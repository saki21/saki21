// ok.cpp : メイン プロジェクト ファイルです。
 
#include "stdafx.h"
#include "ok.h"
#include "MainForm.h"
#include "HistForm.h"
using namespace ok;
App::App() : form(dynamic_cast<Form^>(gcnew ok::MainForm(gcnew EnterPage()))){  
	form->Show(); 
	form->Closed += gcnew EventHandler(this, &App::OnFormClosed);
}
App ^App::Cre() { app = gcnew App(); return app; }
HistListView ^App::create_hist_form(AuctionItem ^a) {
	return (gcnew HistForm(a))->listView1; 
}
void EnterPage::UpdateItems() {
	if (need_read) go();
	set_action_in_div_open_action();
	need_read = true;
}
void EnterPage::setsub(String ^id, bool v) {
	for (int i = 0; i < SubLength; i++) {
		Janru ^j = dynamic_cast<Janru^>(sub[i]);
		if (j->id == id) {
			listview->off();
			if (!v) {
				Collections::IEnumerator ^ie = listview->Items->GetEnumerator();
				while (ie->MoveNext()) {
					AuctionItem^ a = safe_cast<AuctionItem^>(ie->Current);
					if (a->SubItems[10]->Text == id)
						listview->Items->Remove(a);
				}
			} else {
				for (int i = 0; i < Length; i++) {
					if (all[i]->SubItems[10]->Text == id)
						listview->Items->Add(all[i]);
				}
			}
			listview->on();
			return;
		}
	}
	if (SubLength < 10)  {
		sub[SubLength] = Janru::Cre(id);
		SubLength++;
	}
}
[STAThreadAttribute] 
int main(array<System::String ^> ^args)
{
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(App::Cre());
	return 0;
}