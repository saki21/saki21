#pragma once
using namespace System::Windows::Forms;
using namespace System::Threading;

/* AuctionItem.c */
public ref struct Img {
};
public ref struct _1yen: public Img {
};
public ref struct _5yen: public Img {
};
public ref struct hand_: public Img {
};
public ref struct zero: public Img {
};
public ref struct onlybid: public Img {
};
public ref struct no: public Img {
};
//interface struct tik {
//   virtual void setDown(String ^st);
// };
public ref class AuctionItem : System::Windows::Forms::ListViewItem /*,public phtml*/ { // For Point
protected:
	static _1yen ^__1yen = gcnew _1yen;
	static _5yen ^__5yen = gcnew _5yen;
	static hand_ ^_hand = gcnew hand_;
	static zero ^_zero = gcnew zero;
	static onlybid ^_onlybid = gcnew onlybid;
	static no ^_no = gcnew no;
	int t_flag;
	Thread ^thread;
	html b;
	int down0; // ひとつ前の計測値
	int down_type;
	array<Img^> ^icon;
	int icon_num;
	bool owner() { return user == USERNAME; }
public:
	AuctionHist ^h;
	String ^user;
	String ^price;
	String ^name;
	static int limitGo;
	Int32 id;
	int look; // 計測地点
	int mode;
	int down;
	ref class AuctionItem ^next;
	AuctionItem(int id, int down) : down(down), t_flag(0), h(nullptr){}
	AuctionItem(): t_flag(0), h(nullptr){}
	AuctionItem(Int32 id): id(id), icon_num(0), t_flag(0), h(nullptr){
		b.url = ok::p::url(id.ToString());
		icon = gcnew array<Img^>(3);
		Text = Int32(id).ToString();
	}
	void set(String ^st) {
		if (st[0] != 't') {// true //Live Auction
			setMode(4);
			if (Checked && !owner()) {
				WF_(("Auto decrement {2}: {0} -> {1}", AuctionItem::limitGo, AuctionItem::limitGo + 1, id));
				AuctionItem::limitGo += 1;
			}
		}
	}
	void go ();
	void wait ();
	void doRireki(); 
	void doDelete(); 
	void rereki() {
		Thread(gcnew ThreadStart(this, &AuctionItem::doRireki)).Start();
	}
	void preThread() {
		if (t_flag == 0) {
			t_flag = 1;
			SubItems[9]->Text += "w";
			thread = gcnew Thread(gcnew ThreadStart(this, &AuctionItem::wait));
			thread->Start();
		} else {
			down = 20 * ok::SEP; /* 20 秒の猶予 */
			thread->Interrupt();
			SubItems[9]->Text += "x";
		}
	}
private:	
	static array<String ^>^n0 = {"1円オークション", "落札限定", "5円オークション", "手動オークション"};
	static array<Img ^>^t0 = {__1yen, _onlybid, __5yen, _hand};
	static Img ^getIcon(String ^s) { Int32 e = Array::IndexOf(n0, s); return e > -1 ? t0[e] : _no ; }
public:
	void SetSub(String ^kat) {
		ListViewSubItemCollection ^s = SubItems;
		s->Add(name);
		s->Add(price);
		s->Add("--:--:--");
		s->Add("---");
		s->Add(unit());
		s->Add(opt());
		s->Add(hand());
		s->Add("");
		s->Add("");
		s->Add(kat);
//		s->Add("");
	}
	void set_icon(String ^s) {icon->SetValue(getIcon(s), icon_num);icon_num++;}
	bool ck(Img ^i){ return icon[0] == i || icon[1] == i || icon[2] == i; }
	String ^unit() { return icon[0] == __1yen ? "1" :icon[0] == __5yen ? "5" : "15";}
	String ^hand() { return (icon[0] == _hand || icon[1] == _hand) ? "hand" : "-"; } 
	String ^opt() { return  ck(_onlybid) ? "落札限定":  ck(_zero) ? "zero" : "-"; }
	void skip() {
		--down;
		if (!(down & ok::MASK))
			SubItems[3]->Text = Int32(down>>ok::BIT).ToString();
	}
protected:
	void setType();
	void threadGo() {
		down = 20 * ok::SEP; /* 20 秒の猶予 */
		if (t_flag == 0) {
			t_flag = 1;
			thread = gcnew Thread(gcnew ThreadStart(this, &AuctionItem::go));
			thread->Start();
		} else {
			thread->Interrupt();
		}
		SubItems[9]->Text += "x";
	}
public:
	virtual void setDown(String ^st){W_("GGG");};
	void setMode(int nextMode);
	static void UpdateStatus();
	static void UpdateStatus(String ^a);

};
/* ok.c */
AuctionItem ^getAuction(int id);
