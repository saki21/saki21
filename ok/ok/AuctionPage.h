#pragma once
ref class AuctionItem;
public ref class LV : public ListView {
	public:
		void on() {DoubleBuffered = true; }
		void off() {DoubleBuffered = false;}
};
public ref class AuctionPage : public html {
	void set() { 
		if (Length < 0) { 
			Length = 0; 
			all = gcnew array<AuctionItem ^>(all_max);  
			sub = gcnew array<AuctionPage ^>(10);
		}
	}
	static Int32 all_max = 100;
public:
	static Int32 Length = -1;
	static array<AuctionItem ^>^all;
	static Int32 SubLength = 0;
	static array<AuctionPage ^>^sub;
	String ^loginoutpath;
	String ^login;
	static LV ^listview = nullptr;
	AuctionPage(String ^s):html(s) {set();}
	AuctionPage(String ^s, Int32 n):html(s,n){set();}
	static AuctionItem^getAuction(Int32 id);
	static bool hasTbl(Int32 id);
	bool setAuction();
	void setAuction(AuctionItem ^a);
	bool isLogin();
	void set_action_in_div_open_action();
	virtual void UpdateItems();
	virtual void setsub(String ^key, bool v);
	virtual String ^getid() {return "";}
};
public ref struct AltPage : public AuctionPage {
	AltPage(String ^s):AuctionPage(s) {}
	String ^get() { return tx; }
};
