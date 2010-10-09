#include "StdAfx.h"
tok::tok(String ^s):s(s) {}
String ^tok::cut(String ^st_, String ^en_, Int32 st, Int32 en) {
	Int32 pos = s->IndexOf(st_, st, en - st);
	if (pos == -1) {
		WF_(("No {0} in {1}", st_, s->Substring(st, en - st)));
		return "";
	}
	Int32 pos2 = s->IndexOf(en_, pos + st_->Length, en - pos - st_->Length); 
	if (pos2 == -1) {
		WF_(("No {0} in {1}", en_, s->Substring(st, en - st)));
		return "";
	}
	return s->Substring(pos + st_->Length, pos2 - pos - st_->Length);
}
