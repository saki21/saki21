#include "StdAfx.h"

ref struct FormImgAlt : public html {
	array<String^>^alt;
	array<String^>^ancer;
	Int32 Length;
	void array_size() {
		Array::Resize(ancer,FORM_IMG_ALT_NUM);
		Array::Resize(alt,FORM_IMG_ALT_NUM);
	}
	FormImgAlt(String^url): html(url), Length(0) { array_size(); parse(); }
	void parse() {
		int step = 0;
	    enum { START, BODY, FORM, IMG};
		for (p = 0; p < tx->Length && hastag(); p++){
			if (skip_com()) 
				continue;
			switch(step) {
			case START: if (o("head")) { step = BODY; continue; }
				break;
			case BODY: if (tag("form")) { up(); step = IMG; continue; }
				break;
			case IMG: 
				if (tag("a")){ ancer->SetValue(tcut("href=\"","\""), Length); up(); continue; }
				if (tag("img")){ alt->SetValue(tcut("alt=\"","\""), Length); Length++; up(); continue; }
				if (tag("/form")) return;
				break;
			}
			any();
		}
	}
};

bool AuctionPage::setAuction() { bool ret = false;
	if (find("div", "mod")) { 
		pos ^res = resume();
//	if (find("div", "mod auction-box")) {
		if (find("a")) {
			int id = ToInt("href", "/auction/-/detail/=/aid=", "/");
			ride(res);
			if (!hasTbl(id))
				setAuction(
					ok::SEP == AuctionItem20::SEP ? (AuctionItem^)gcnew AuctionItem20(id):
					ok::SEP == AuctionItem8::SEP ? (AuctionItem^)gcnew AuctionItem8(id):
					(AuctionItem^)gcnew AuctionItem4(id) 
					); 
			ret = true;
		} else ride(res);
	}
	return ret;
}
AuctionItem ^AuctionPage::getAuction(int id) { 
	for (int k = 0; k < AuctionPage::Length; k++) 
		if (all[k]->id == id) 
			return all[k]; 
	throw -1; 
}
bool AuctionPage::hasTbl(Int32 id)
{
	for (int k = 0; k < Length; k++) 
		if (all[k]->id == id) 
			return true;
	return false;
}
void AuctionPage::setAuction(AuctionItem ^a) { 
	enum { ICON, NAME}; 
	int step = ICON;
	if (Length == all_max) {
		all_max += 100;
		Array::Resize(all, all_max);
	}
	all->SetValue(a, Length);
	Length++;
	for (; p < tx->Length && hastag(); p++){
		if (skip_com()) 
			continue;
		switch(step) {
		case ICON: if (tag("img")) {  a->set_icon(ToString("alt")); up();continue; }
					if (tag("/div")) { step = NAME; continue;}
			break;
		case NAME: if (tag("span", "name")) { 
				a->name = ToString()->Trim();  
				a->SetSub(getid());
				if (listview != nullptr) listview->Items->Add(a);
				return;
			}
		}
		any();
	}
}
bool AuctionPage::isLogin() {
	int step = 0;
	enum {START, BODY, PASSWD};
	for (p = 0; p < tx->Length && hastag(); p++){
		if (skip_com()) 
			continue;
		switch(step) {
		case START: if (o("head")) { step = BODY; continue; }
			break;
#ifdef IFRAME
		case BODY: if (tag("iframe")) { 
				loginoutpath = tcut("src=\"","\""); 
				if (loginoutpath != "") { 
					FormImgAlt a(loginoutpath);
					if (a.Length >= 1 && String::Compare(a.alt[0], LOGOUT) == 0)
						return true;
					login = a.ancer[1]; // 会員登録の次のアンカーがログイン
					return false;
				} else return false;
			}
			break;
#else
//<img src="http://p.dmm.com/p/navi/global/bt_logout.gif" width="75" height="23" alt="ログアウト"></a></li>
		case BODY: if (find("img")) {
				String ^s = tcut("alt=\"","\""), ^s2;
				W_(s); up();
				if (find("img")) { s2 = tcut("alt=\"","\"");
				  W_(s2);
				}
				return String::Compare(s2, LOGOUT) == 0;
			}
			break;
#endif
		}
		any();
	}
	return false;
}
void AuctionPage::set_action_in_div_open_action() {
	int step = 0;
	enum { START, BODY, BOX, ICON};
	for (p = 0; p < tx->Length && hastag(); p++){
		if (skip_com()) 
			continue;
		switch(step) {
		case START: if (o("head")) { step = BODY; continue; }
			break;
		case BODY: if (find(L"div", L"open-auction")) { up(); step = BOX; continue; }
			break;
		case BOX: if (setAuction()) continue;
			break;
		}
		any();
	}
}
void AuctionPage::UpdateItems() {
	go();
	set_action_in_div_open_action();
}
void AuctionPage::setsub(String ^s, bool v) {
}