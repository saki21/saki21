
using namespace System::Windows::Forms;
public ref struct Hist : public ListViewItem  {
	String ^user;
	String ^price;
	String ^time;
	String ^opt;
	Hist ^ next;
	static Hist ^end = gcnew Hist("00:00:00");
	static Hist ^cur = end;
	Hist(String ^s): time(s), price("") {}
	Hist(): next(end) {}
public:
	bool SetSub(Hist ^last); 
};
public ref struct HistListView: public LV {
	HistListView();
	void head() {
		for (int i = 0; i < 4; i++) { 
			ColumnHeader ^c = gcnew ColumnHeader;
			switch(i) {
			case 0: c->Text = L"ŽžŠÔ"; break;
			case 1: c->Text = L"‰¿Ši"; break;
			case 2: c->Text = L"“üŽDŽÒ"; break;
			case 3: c->Text = L"Œ`Ž®"; break;
			}
			Columns->Add(c);
		}
	}
};
public ref class Cm : public ContextMenuStrip {
public:
	Cm();
	void show(System::Object ^,System::EventArgs ^);
};

public ref class AuctionHist : public json {
	Hist ^top;
	Hist ^last;
	Hist ^current;
	String ^par;
	Threading::Timer ^t;
	static const int LT = 20 * 1000 /** 100*/;
	int down;
public:
	static AuctionHist ^cur;
	static Cm ^cm = gcnew Cm;
	static int Length = 0;
	static array<AuctionHist^> ^tbl = gcnew array<AuctionHist^>(100);
	HistListView ^lv;
	int getTimeout() ;
	AuctionHist(AuctionItem ^a);
private:
	void show();
	void m_show(System::Object ^,System::EventArgs ^) { go(); }
	void t_go(Object ^s) { 	Trace::WriteLine("hh");
WF_(("t_go = {0} {1}", s, this)); this->go();	Trace::WriteLine("bb");
}
	void parse();
public:	
	void go() new;
	static void s_show() { cur->go(); }
};

