#pragma once
/* 情報を保持するクラス */
ref struct AuctionStatus : public json {
//	AuctionStatus(String^par): json(ok::st::url(), 0) { tx = "aid=" + par + "&type=status"; post(); parse(); }
	AuctionStatus(String^par): json(ok::st::url(par)) { parse(); }
	void parse();
};
