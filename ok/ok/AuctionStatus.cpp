#include "StdAfx.h"
//"jsonp1286620229758({"status":
// [{"auction_id":"65590","is_active":true,"last_price":"5,258","last_bidder":"\u30d6\u30e9\u30c3\u30af\u30c8\u30ec\uff0d\u30c0\uff0d","countdown":"00:00:08","timelimit":8,"mem":true},{"auction_id":"65913","is_active":true,"last_price":"37,590","last_bidder":"DOROMITI","countdown":"00:00:09","timelimit":9,"mem":true},
//  {"auction_id":"65922","is_active":true,"last_price":"2,100","last_bidder":"eyesonly","countdown":"00:00:16","timelimit":16,"mem":true},
//  {"auction_id":"66025","is_active":true,"last_price":"9,495","last_bidder":"karmie","countdown":"00:00:09","timelimit":9,"mem":true},
// {"auction_id":"66065","is_active":true,"last_price":"17,175","last_bidder":"\u30d6\u30e9\u30c3\u30af \u30b8\u30e3\u30c3\u30af","countdown":"00:00:19","timelimit":19,"mem":true},
// {"auction_id":"66068","is_active":true,"last_price":"15,240","last_bidder":"\u3089\u3044\u3068\u3075\u3043\u308a\u3063\u3077\u3059","countdown":"00:00:11","timelimit":11,"mem":true},
// {"auction_id":"66071","is_active":true,"last_price":"922","last_bidder":"\u4eba\u751f\u3001\u65c5\u306e\u9053","countdown":"00:00:16","timelimit":16,"mem":true},
// {"auction_id":"66077","is_active":true,"last_price":"5,560","last_bidder":"danzig1962","countdown":"00:00:19","timelimit":19,"mem":true},{"auction_id":"66104","is_active":true,"last_price":"747","last_bidder":"rich","countdown":"00:00:08","timelimit":8,"mem":true},{"auction_id":"66115","is_active":true,"last_price":"8,475","last_bidder":"\u30ec\u30c3\u30c9\u30aa\u30fc\u30b7\u30e3\u30f3","countdown":"00:00:06","timelimit":6,"mem":true},{"auction_id":"66152","is_active":true,"last_price":"402","last_bidder":"\u771f\u3061\u3083\u3093\uff12","countdown":"00:00:08","timelimit":8,"mem":true},{"auction_id":"66163","is_active":true,"last_price":"353","last_bidder":"syouri8","countdown":"00:00:06","timelimit":6,"mem":true},{"auction_id":"66167","is_active":true,"last_price":"2,210","last_bidder":"\u9ed2\u9dfa","countdown":"00:00:19","timelimit":19,"mem":true},{"auction_id":"66170","is_active":true,"last_price":"6,435","last_bidder":"\u640d\u3057\u3066\u5f97\u3068\u308c","countdown":"00:00:06","timelimit":6,"mem":true},{"auction_id":"66178","is_active":true,"last_price":"226","last_bidder":"\uff57\uff49\uff4e\uff45\uff42\uff4f\uff59\uff59\uff55\uff4d\uff49","countdown":"00:00:19","timelimit":19,"mem":true},{"auction_id":"66182","is_active":true,"last_price":"3,300","last_bidder":"Japon","countdown":"00:00:17","timelimit":17,"mem":true},{"auction_id":"66205","is_active":true,"last_price":"98","last_bidder":"\u9b3c\u8718\u86db\uff8c\uff67\uff9d\uff84\uff9e2","countdown":"00:00:10","timelimit":10,"mem":true},{"auction_id":"66213","is_active":true,"last_price":"1,110","last_bidder":"-want you!-","countdown":"00:00:18","timelimit":18,"mem":true},{"auction_id":"66214","is_active":true,"last_price":"66","last_bidder":"\u7d42\u308f\u308b\u307e\u3067\u7d99\u7d9a","countdown":"00:00:19","timelimit":19,"mem":true},{"auction_id":"66219","is_active":true,"last_price":"215","last_bidder":"\u30a8\u30a2\u30b8","countdown":"00:00:08","timelimit":8,"mem":true},{"auction_id":"66221","is_active":true,"last_price":"330","last_bidder":"maruhatu","countdown":"00:00:07","timelimit":7,"mem":true},{"auction_id":"66222","is_active":true,"last_price":"125","last_bidder":"\u30b1\u30f3zi","countdown":"00:00:16","timelimit":16,"mem":true},{"auction_id":"66223","is_active":true,"last_price":"34","last_bidder":"\u2160\u2161\u2162\u2163\u2164\u2165\u2166\u2167\u2168","countdown":"00:00:18","timelimit":18,"mem":true},{"auction_id":"66224","is_active":true,"last_price":"22","last_bidder":"\u7a93\u30aa\u30fc\u30d7\u30f3","countdown":"00:00:11","timelimit":11,"mem":true},{"auction_id":"66225","is_active":true,"last_price":"60","last_bidder":"\u30ae\u30e3 \u30f3\u30d6\u30eb\u30de\u30b7\u30fc \u30f3","countdown":"00:00:11","timelimit":11,"mem":true}]});"	System::String^

void AuctionStatus::parse() {
	int step = 0;
	System::Windows::Forms::ListViewItem::ListViewSubItemCollection^ s;
	AuctionItem ^a;
	enum { AUCTION, ITEMS};
	for (p = 0; p < tx->Length && hastag(); p++){
		switch(step) {
		case AUCTION:
			step = ITEMS;
			break;
		case ITEMS: 
			for (Int32 k = 0; k < 6; k++) { // 最後の１つは解析しない
				String ^tk;
				if (k == 5 || k== 1) {
					i = tx->IndexOf(',', p);
					p = tx->LastIndexOf(':', i - 1);
				} else {
					i = tx->IndexOf("\",", p);
					p = tx->LastIndexOf('\"', i - 1);
				}
				tk = tx->Substring(p + 1, i - 1 - p);
				p = i + 2;
//				Trace::WriteLine(tk);
				switch(k) {
// {"auction_id":"66068","is_active":true,"last_price":"15,240","last_bidder":"\u3089\u3044\u3068\u3075\u3043\u308a\u3063\u3077\u3059","countdown":"00:00:11","timelimit":11,"mem":true},
				case 0: 
					a = AuctionPage::getAuction(Convert::ToInt32(tk)); 
					s = a->SubItems; break;
				case 1: a->set(tk);/* is_active */ break;
				case 2: s[2]->Text = tk;/* last_price */ break;
				case 3: /* last_bidder */ 
					if (a->mode != 4 && a->user != tk) {
						a->setMode(0); /* 計測キャンセルして新たに開始 */
						a->user	= tok::u(tk);
						s[4]->Text = a->user;/* user_name */ 
					}break;
				case 4: /* countdown */ break;
				case 5:  a->setDown(tk); s[3]->Text = tk; /* timelimit*/ break;
				}
			}
			step = AUCTION;
			break;
		}
	}
	DEBUG(Trace::WriteLine("#" + AuctionGroup::ag->chk.ToString()));
//		AuctionGroup::ag->_1.finish();
}
