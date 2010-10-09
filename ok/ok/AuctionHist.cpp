#include "StdAfx.h"
Cm::Cm() { 
	ToolStripMenuItem ^i = gcnew ToolStripMenuItem;
	Items->Add(i);
	i->Text = "XV"; 
	i->Click += gcnew EventHandler(this, &Cm::show);
}
void Cm::show(System::Object ^,System::EventArgs ^) {
	AuctionHist::s_show();
}
HistListView::HistListView() { ContextMenuStrip = AuctionHist::cm; } 
bool Hist::SetSub(Hist ^last) { bool ret = false;
	ListViewSubItemCollection ^s = SubItems;
	if (price->Length > last->price->Length || String::Compare(price, last->price) > 0) {
		s->Add(price);
		s->Add(user);
		s->Add(opt);
		ret = true;
	}
	return ret;
}
void AuctionHist::show() {
	Hist ^t; 
	if (lv->Parent->Text != par) {
		lv->Parent->Text = par;
		t = top;
		lv->Clear(); 
		lv->head();
	} else {
		t = current->next;
	}
	for (Hist ^i = t; i != Hist::end; i = i->next) 
		lv->Items->Insert(0, i); //Add(i);
	lv->Parent->Show();
}

void AuctionHist::parse() {
	int step = 0;
	Hist ^a;
	enum { TOP, HISTORIES, FIRST, HISTORIES2, HISTORY2};
	for (p = 0; p < tx->Length && hastag(); p++){
		switch(step) {
		case TOP:
		case HISTORIES:
			step++;
			break;
		case HISTORY2:
		case FIRST:
			for (int k = 0; k < 4; k++) {
				String ^tk;
				if (k == 3)
					i = tx->IndexOf("' }", p);
				else
					i = tx->IndexOf("',", p);
				p = tx->LastIndexOf('\'', i - 1);
				tk = tx->Substring(p + 1, i - 1 - p);
				p = i + 2;
   				W_(tk);
				switch(k) {
				case 0:a = gcnew Hist; a->price = tk; break;
				case 1:a->user = tk; break;
				case 2:a->Text = a->time = tk; /* Žž */
					break;
				case 3:a->opt = tk;
					if (step == FIRST)  
						current = last;
					if (!a->SetSub(current)) 
						return;
					if (step == FIRST)  
						last = a;
					if (current == Hist::end) {
						a->next = top;
						top = a;
					} else {
						a->next = current->next;
						current->next = a;
					}
					break;
				default: W_("data broken"); break;
				}
			}
			step = HISTORIES2;
			break;
		case HISTORIES2:
			step = HISTORY2;
			break;
		}
	}
	DEBUG(Trace::WriteLine("#" + AuctionGroup::ag->chk.ToString()));
}
int AuctionHist::getTimeout() { return down > 2000 ? down * ok::UNIT: LT; }
AuctionHist::AuctionHist(AuctionItem ^a) : par(a->id.ToString()), top(Hist::end), last(Hist::end), down(a->down) {
	ToolStripMenuItem ^i = gcnew ToolStripMenuItem;
	cm->Items->Add(i);
	i->Text = par;
	i->Click += gcnew EventHandler(this, &AuctionHist::m_show);
	lv = App::create_hist_form(a);
	tbl[Length] = this;
	Length++;
	url = ok::hist::url(par);
	go();
}
void AuctionHist::go(){
	json::go();
//	Trace::WriteLine(tx);
	parse();
	show();
}
