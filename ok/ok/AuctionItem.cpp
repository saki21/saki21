#include "StdAfx.h"
void AuctionItem::doRireki() {
	if (h == nullptr) { 
		SubItems[9]->Text += "H"; h = gcnew AuctionHist(this);
	} else h->go(); 
};
void AuctionItem::doDelete() {
//	Parent->Items->Delete(this);
};
void AuctionItem::setMode(int nextMode) {
	WF(("mode {0} -> {1}", mode, nextMode));
	mode = nextMode;
	SubItems[8]->Text = Int32(mode).ToString();
}
void AuctionItem::setType() {
	SubItems[9]->Text += Int32(down_type).ToString();
}
using namespace System::Threading;
void AuctionItem::wait(){ 
	do {
		if (!ok::mogi)
			b.wait();
		else {
			try {Thread::Sleep(Timeout::Infinite);} catch (ThreadInterruptedException ^) {}
			user = USERNAME;
		}
		WF_(("“üŽD’†:{0}", id));
	} while(1);
}

void AuctionItem::go(){ 
	do {
		if (!ok::mogi)
			b.go();
		else 
			user = USERNAME;
		WF_(("“üŽD’†:{0}", id));
		try {Thread::Sleep(Timeout::Infinite);} catch (ThreadInterruptedException ^) {}
	} while(1);
}

void AuctionItem::UpdateStatus(String ^a) {
	W("UpdateStatus --->" + a);
	AuctionStatus s(a);
}
void AuctionItem::UpdateStatus() {
	AuctionArg b;
	for (int  i = 0; i < AuctionPage::Length; i++) {
		AuctionItem ^a = AuctionPage::all[i];
		switch (a->mode) {
		default:
			if (a->down > AuctionItem::limitGo ||
				(!a->Checked && a->down > ok::limitFinal)) { 
				a->skip();
			} else {
				b.set(a);
			}
			break;
		case 2:
		case 3:
		case 6:
			if (a->down != a->look) { 
				a->skip();
			} else {	
				b.set(a); 
			}
			break;
		case 4:
			;
		}
	}
	if (b.test()) UpdateStatus(b.arg);
}