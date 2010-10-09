#pragma once
ref class AuctionItem;
ref class Arg {
	int no;
public:
	Arg(): no(0) {}
	void set() { no++; }
	void clear() { no = 0; }
	bool test() { return no > 0; }
    virtual String^ ToString() override 
    {
        return String::Format("{0}", no);
    }
};
ref struct AuctionArg : Arg {
	String ^arg;
	AuctionArg() {}
	void set(AuctionItem ^i);
	void clear() { Arg::clear(); arg = ""; }
	void UpdateStatus();
};
ref struct AuctionArgList : public AuctionArg {
	static AuctionItem ^end = gcnew AuctionItem;
	AuctionItem ^top;
	void set(AuctionItem ^i);
	void clear() { top = end; AuctionArg::clear(); }
};

ref struct AuctionGroup {
};