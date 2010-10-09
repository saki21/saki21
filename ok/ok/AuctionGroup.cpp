#include "StdAfx.h"
void	AuctionArg::UpdateStatus(){
}
void AuctionArgList::set(AuctionItem ^i){
	AuctionItem ^p;
	if (!test()) { 
		top = i;
		top-> next = end;
	} else {
		for (p = top; p->next != end ; p = p->next); 
		p->next = i;
		i->next = end;
	}
	AuctionArg::set(i);
}
void AuctionArg::set(AuctionItem ^i){
	if (test()) 
		arg += "," + i->Text;
	else {
		arg = i->Text;
	}
	Arg::set();
}
