#include "StdAfx.h"

bool AuctionItem20::One() { 
	sep0 = sep0 - sep1; 
	if (sep0 == 1) 
		return true; 
	sep1 = sep0 / 2; 
	return false; 
} 
bool AuctionItem20::Two() { 
	if (sep1 == 1) 
		return true; 
	down += (sep0 - sep1);
	sep0 = sep1; 
	sep1 /= 2; 
	return false;
}
void AuctionItem20::setDown(String ^st) {
int d0 = Convert::ToInt32(st);
int d = d0 * ok::SEP;

RETRY:
	switch (mode) {
	case 0:
		if (d <= limitGo) goto FINAL;
		look = d - 30;
		down = d;
		if (look > limitGo) {
			down0 = d;
			down_type = 0;
			sep0 = 20;
			sep1 = 10;
			setMode(2); /* vªÂ\ */
		} else {
			setMode(1); /* vªsÂ\ */
		}
		break;
	case 1:
		if (d <= limitGo) goto FINAL;
		break;
	case 5:
		down--;
		if (down / SEP != d0) { 
			if ((!(down % SEP)) || (down / SEP) != (d0 + 1)) { /* ²®¸s */
				if (d - down < 20) /* 20 ÈãÌë·ÍrüDÅÄ²®ªKv¾Á½@*/
					WF_(("²®NG {0} {1} {2} {3} {4} {5}", down / SEP, d0, id, down, down_type, user));
				setMode(0); goto RETRY;
			} else {WF_(("²®OK1 {0} {1} {2} {3}", id, down, down_type, user));} // Ü½¬vª
		} else {WF_(("²®OK0 {0} {1} {2} {3}", id, down, down_type, user));}
		if (down <= limitGo) {goto FINAL;}
		break;
	case 2:
		down--;
		switch (down0 - d) {
		case 1 * SEP:
			if (One()) goto FIND; goto LOOK_CHK; 
		case 2 * SEP:
			down_type += sep1; 
			if (Two()) goto FIND; goto LOOK_CHK; 
		default:
			WF_(("Error{3}!! {0} look = {1}", down0 - d, look, sep0));
			setMode(0); // Ävª
			goto RETRY;
LOOK_CHK:
			down0 = d; 
			look -= SEP + sep1;
			if (look > limitGo) {
				setMode(3); /* vªÂ\ */
			} else {
				setMode(1); /* vªsÂ\ */
			}
			break;
FIND:
			setMode(5); // ²®®¹
			setType();
			break;
		}
		break;
FINAL:
		if (this->Checked && !owner()) {
			threadGo();
		}
	}
}