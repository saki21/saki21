#include "StdAfx.h"
#define StreamReader streamEuc
#define DEBUG(a) /* */
#define DEBUG_(a) a
void ur::set_url_id() { 
#if 0
	String ^s = uri->ToString();
	int n = s->IndexOf(".");
	if (Array::IndexOf(hosts, s->Substring(n)) >= 0) return; 
	url_max++;
	Array::Resize(hosts,url_max);
	Array::Resize(cc,url_max);
	cc[url_max - 1] = gcnew CookieCollection;
	hosts[url_max - 1] = uri->ToString();
	url_id = url_max - 1;
#endif
} 
ur::ur():url_id(0) {}
ur::ur(String ^url): url(url) {  uri = gcnew Uri(url); set_url_id() ;}
void html::reflash() { int p0; String ^n;
	if (header_debug) Trace::WriteLine("reflash():" + tx->Length.ToString()); 
	if (tx->Length < 700 && ((p0 = tx->IndexOf("<meta http-equi")) > 0) && (p0 = tx->IndexOf("Refresh", p0)) > 0) {
		p = p0; i = tx->IndexOf(">", p0);
		n = tcut("0;URL=", "\"");
		url = n;
		go();
	}
}
http::http(){}
http::http(String ^url, int count): ur(url){} 
http::http(String ^url): ur(url) {
	HttpWebRequest ^req = dynamic_cast<HttpWebRequest^>(HttpWebRequest::Create(url));
	//参考　http://msdn.microsoft.com/ja-jp/library/system.net.httpwebrequest.begingetrequeststream(v=VS.80).aspx
	req->UserAgent = "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/533.4 (KHTML, like Gecko) Chrome/5.0.375.127 Safari/533.4";
	req->Credentials = CredentialCache::DefaultCredentials; //アプリケーションのシステム資格情報を取得します。
	req->CookieContainer = ckc;
	req->Referer = "http://auction.dmm.com";
//	req->CookieContainer->Add(cc[url_id]);
	HttpWebResponse^ res = dynamic_cast<HttpWebResponse^>(req->GetResponse());
	if (header_debug) {
		Trace::TraceWarning("\nThe Request HttpHeaders are \n {0}", req->Headers);
		Trace::WriteLine(res->StatusDescription);
		Trace::TraceWarning("\nThe res HttpHeaders are \n {0}", res->Headers);
	}
	Stream^ s = res->GetResponseStream();
	StreamReader^ r = gcnew StreamReader(s);
	saveCookie(res);
	tx = r->ReadToEnd();
	r->Close();
	s->Close();
	res->Close();
	reflash();
}
//virtual void http::test(HttpWebResponse^ res) {
//}
void http::saveCookie(HttpWebResponse^ res) {
	Collections::IEnumerator ^myEnum = res->Cookies->GetEnumerator();
	while (myEnum->MoveNext()) {
		Cookie^ cook = safe_cast<Cookie^>(myEnum->Current);
		DEBUG(Trace::WiteLine(String::Format("Cookie: {0} = {1}", cook->Name, cook->Value)));
//		cc[url_id]->Add(safe_cast<Cookie^>(myEnum->Current));
		ckc->Add(safe_cast<Cookie^>(myEnum->Current));
#if 0
		Trace::TraceWarning( "Domain: {0}", cook->Domain );
		Trace::TraceWarning( "Path: {0}", cook->Path );
		Trace::TraceWarning( "Port: {0}", cook->Port );
		Trace::TraceWarning( "Secure: {0}", cook->Secure );
		Trace::TraceWarning( "When issued: {0}", cook->TimeStamp );
		Trace::TraceWarning( "Expires: {0} (expired? {1})", cook->Expires, cook->Expired );
		Trace::TraceWarning( "Don't save: {0}", cook->Discard );
		Trace::TraceWarning( "Comment: {0}", cook->Comment );
		Trace::TraceWarning( "Uri for comments: {0}", cook->CommentUri );
		Trace::TraceWarning( "Version: RFC {0}", cook->Version == 1 ? (String^)"2109" : "2965" );
		Trace::TraceWarning( "String: {0}", cook );
#endif
	}
}
void http::post() {
	request = dynamic_cast<HttpWebRequest^>(HttpWebRequest::Create(url));
	request->UserAgent = "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/533.4 (KHTML, like Gecko) Chrome/5.0.375.127 Safari/533.4";
	request->Credentials = CredentialCache::DefaultCredentials;
	request->CookieContainer = ckc; gcnew CookieContainer;
	request->ContentType = "application/x-www-form-urlencoded";
	request->Method = "POST";
//	request->CookieContainer->Add(uri, cc[url_id]);
	array<Byte>^b = ((gcnew System::Text::ASCIIEncoding)->GetBytes(tx));
	request->ContentLength = b->Length;
	Stream ^st = request->GetRequestStream();
	st->Write(b, 0, b->Length);
	st->Close();
	HttpWebResponse^ res = dynamic_cast<HttpWebResponse^>(request->GetResponse());
	if (header_debug) Trace::TraceWarning("\n!!!!!The POST HttpHeaders are \n {0}", request->Headers);
	Stream^ s = res->GetResponseStream();
	StreamReader^ r = gcnew StreamReader(s);
	saveCookie(res);
	tx = r->ReadToEnd();
	if (header_debug) {
		Trace::WriteLine(res->StatusDescription);
		Trace::TraceWarning("\nThe res HttpHeaders are \n {0}", res->Headers);
		if (tx->Length != 0)
			Trace::WriteLine(tx->Substring(0, (tx->Length > debug_print) ? debug_print : tx->Length));
		else 
			Trace::WriteLine("No responce");
	}
	r->Close();
	s->Close();
	res->Close();
	reflash();
}
void http::wait() {
	request = dynamic_cast<HttpWebRequest^>(HttpWebRequest::Create(url));
	request->UserAgent = "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/533.4 (KHTML, like Gecko) Chrome/5.0.375.127 Safari/533.4";
	request->Credentials = CredentialCache::DefaultCredentials;
	request->CookieContainer = ckc; //gcnew CookieContainer;
//	request->CookieContainer->Add(cc[url_id]);
	try {Thread::Sleep(Timeout::Infinite);} catch (ThreadInterruptedException ^) {}
	HttpWebResponse^ res = dynamic_cast<HttpWebResponse^>(request->GetResponse());
//	if (header_debug) {
		WF(("\nThe GET HttpHeaders are \n {0}", request->Headers));
		W(res->StatusDescription);
		WF(("\nThe res HttpHeaders are \n {0}", res->Headers));
//	}
#if 0
	Stream^ s = res->GetResponseStream();
	StreamReader^ r = gcnew StreamReader(s);
	saveCookie(res);
	tx = r->ReadToEnd();
	if (header_debug) {
		if (tx->Length != 0)
			Trace::WriteLine(tx->Substring(0, (tx->Length > debug_print) ? debug_print : tx->Length));
		else 
			Trace::WriteLine("No responce");
	}
	r->Close();
	s->Close();
#endif
	res->Close();
#if 0
	reflash();
#endif
}
void http::go() {
	request = dynamic_cast<HttpWebRequest^>(HttpWebRequest::Create(url));
	request->UserAgent = "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/533.4 (KHTML, like Gecko) Chrome/5.0.375.127 Safari/533.4";
	request->Credentials = CredentialCache::DefaultCredentials;
	request->CookieContainer = ckc; //gcnew CookieContainer;
//	request->CookieContainer->Add(cc[url_id]);
	HttpWebResponse^ res = dynamic_cast<HttpWebResponse^>(request->GetResponse());
	if (header_debug) {
		Trace::TraceWarning("\nThe GET HttpHeaders are \n {0}", request->Headers);
		Trace::WriteLine(res->StatusDescription);
		Trace::TraceWarning("\nThe res HttpHeaders are \n {0}", res->Headers);
	}
	Stream^ s = res->GetResponseStream();
	StreamReader^ r = gcnew StreamReader(s);
	saveCookie(res);
	tx = r->ReadToEnd();
	if (header_debug) {
		if (tx->Length != 0)
			Trace::WriteLine(tx->Substring(0, (tx->Length > debug_print) ? debug_print : tx->Length));
		else 
			Trace::WriteLine("No responce");
	}
	r->Close();
	s->Close();
	res->Close();
	reflash();
}
int html::skip_com() { int q;
	switch(tx[p + 1]) {
	case '!':
		switch(tx[p + 2]) {
		case '-':
			q = tx->IndexOf("->", p + 2);
			if (q >= 0)
				p = q + 2;
    		return true;
		default:
			q = tx->IndexOf(">", p + 2);
			if (q >= 0)
				p = q + 1;
			return true;
		}
	}
	return false;
}
void html::tagsplit() { tagsplit(0); }
void html::tagsplit(int len) { Int32 n;
	n = i - p - len -1;
	array<String^> ^a = {"\""};
	array<String^>^ ar = tx->Substring(p + len + 1, n)->Split(a, StringSplitOptions::RemoveEmptyEntries);
	Trace::WriteLine(ar[5]); // title 
}
void html::oversplit(int len) { Int32 n, e;
	for(i = p + len + 1; i < tx->Length; i++)
		if (tx[i] == '>')
			break;
	n = i - p - len -1;
	if (0) {
		e = tx->IndexOf("</" + tx->Substring(p + 1, len) + ">", i); 
		if (e >= 0) Trace::WriteLine(tx->Substring(p , e - p + len + 2));
	} else {
		Trace::WriteLine(tx->Substring(p , n + len + 2));
	}
	array<String^> ^a = {" "};
	array<String^>^ ar = tx->Substring(p + len + 1, n)->Split(a, StringSplitOptions::RemoveEmptyEntries);
}
int html::nover(int len) { // nestable over
	switch(tx[p + len + 1]) {
	case ' ': case '>': // マッチ
		Int32 n, m, nest, ii;
		String ^key;
		tagend(len);
		switch(tx[i - 1]) {
		default:
			key = tx->Substring(p + 1, len);
			ii = i; 
			do {
				nest = 0;
				n = tx->IndexOf("</" + key + ">", i);
				m = tx->IndexOf("<" + key , ii);
				switch(tx[m + len + 1]) {
					case ' ': case '>': // マッチ
						if (m >= 0 && m < n) {
							nest=1; ii = m + len; i = n + len;
						}
				}
			} while(nest);
			Trace::WriteLine(tx->Substring(p + 1, len));
			if (n >= 0) {
				p = n + len + 2;
			}
			Trace::WriteLine("n = " + n.ToString());
			break;
		case '/':; 
			Trace::WriteLine(tx->Substring(p + 1, len));
			Trace::WriteLine("i = " + i.ToString());
			p = i + 1;
		}
		return true;
	}
	return false;
}
bool html::tag_i(String ^nm) {
	Int32 n = tx->LastIndexOf('<', i, i - p + 1);
	String ^s = tx->Substring(n + 1, nm->Length + 1); 
	bool r = (s == (nm + " "));
	if (r) {
		name = nm;
		p = n;
	} else {
		Trace::WriteLine("tag_i() " + s + "!= " + nm + " p = " + p.ToString() + " i = " + i.ToString() + " " + tx->Length.ToString());
	}
	return r;
}
bool html::find(String ^nm, String ^c) {
	String ^s = "class=\"", ^t = c;
	Int32 n;
	bool ret = false;
	do {
		n = tx->IndexOf(t, i);
		if (n < 0) break;
		i = tx->IndexOf('>', n + t->Length);
	//	Trace::WriteLine(tx->Substring(i));
	//	Trace::WriteLine("p = " + p.ToString() + " i = " + i.ToString() + " " + tx->Length.ToString());
	} while(tx[n + t->Length] != '"' || tx->Substring(n - s->Length, s->Length) != s || !tag_i(nm));  
 	if (n > 0) {
		//Trace::WriteLine("find!");
	//	Trace::WriteLine("p = " + p.ToString() + " i = " + i.ToString() + " " + tx->Length.ToString());
		 ret = true;
	}
	return ret;
}

bool html::find(String ^nm) {
	for(; p < tx->Length  && hastag() && !tag(nm); any()); 
	return p < tx->Length;
}
bool html::c_name_claer() { // check end
	return !(tx->IndexOf("class=\"claer\"", p, i - p + 1) < 0);
}
bool html::c_name(String ^nm) { // nestable over
	String ^nm0 = "class=\"" + nm + "\"";
	return !(tx->IndexOf(nm0, p, i - p + 1) < 0);
}
void html::up() { p = i;  /* Trace::WriteLine("up() ->" + tx->Substring(p, 5)); */}
bool html::n_name(String ^nm) { // find name  
	bool ret = true;
	String ^st = "<" + name, ^en = "</" + name + ">", ^nm0 = "class=\"" + nm + "\"";
	switch(tx[i - 1]) {
	default:
		while(tx->IndexOf(nm0, p, i - p + 1) < 0) { 
			Int32 p0 = tx->IndexOf(st, i);
			if (p0 >= 0) p = p0; else { p = i; Trace::WriteLine("No Starter"); }
			if (!find(name)) {ret = false; break;}
		} 
		Trace::WriteLine(tx->Substring(p, i - p + 1));
		break;
	case '/': 
		Trace::WriteLine("i = " + i.ToString());
		ret = false;
	}
	return ret;
}
int html::over(int len) { // not nest tag
	String ^key;
	switch(tx[p + len + 1]) {
	case ' ': case '>': // マッチ
		Int32 n;
		tagend(len);
		switch(tx[i - 1]) {
		default:
			key = tx->Substring(p + 1, len);
			n = tx->IndexOf("</" + key + ">", i);
 			Trace::WriteLine(tx->Substring(p + 1, len));
			if (n >= 0) {
				p = n + len + 2;
			}
			break;
		case '/':; 
			Trace::WriteLine(tx->Substring(p + 1, len));
			Trace::WriteLine("i = "+i.ToString());
			p = i + 1;
		}
		return true;
	}
	return false;
}
bool html::step(int len) {
	switch(tx[p + len + 1]) {
	case ' ': case '>': // マッチ
		tagend(len);
		Trace::WriteLine(tx->Substring(p + 1, len));
		p = i;
		return true;
	}
	return false;
}
void html::dtag() {if (tag_debug) Trace::WriteLine(tx->Substring(p, i - p + 1));} 

String ^html::ToString(String ^key) {
	return tcut(key + "=\"", "\"");
}
int html::ToInt(String ^key) {
	return Convert::ToInt32(tcut(key + "=\"", "\""));
}
int html::ToInt(String ^key, String ^fix0, String ^fix1) {
	return Convert::ToInt32(tcut(key + "=\"" + fix0, fix1 + "\""));
}
int html::ToInt(String ^key, String ^fix) {
	return Convert::ToInt32(tcut(key + "=\"" + fix, "\""));
}

String ^html::ToString() {
	Int32 r = i, n;
	do {
		n = tx->IndexOf(name, r);
		r = n + name->Length;
	} while( tx[n - 1] != '/' || tx[n - 2] != '<' || tx[n + name->Length] != '>');  
	return tx->Substring(i + 1, n - 3 - i);
}
int html::ToInt() {
//	do {
		Int32 n = tx->IndexOf(name, i);
//	} while( tx[n - 1] != '/' || tx[n - 2] != '<' || tx[n + name->Length] != '>'); 
	String ^v = tx->Substring(i + 1, n - 2 - i - 1);
	return Convert::ToInt32(v);
}
bool html::tag(String^s, String^nm) { // class 付きタグ
	bool ret = false;
	if (key(s)) 
		switch(tx[p + s->Length + 1]) {
		case ' ': case '>': // マッチ
			name = s; //tx->Substring(p + 1, s->Length);
			tagend(s->Length);
			ret = c_name(nm);
			dtag();
		} 
	return ret;
}
bool html::tag(String^s) {
	bool ret = false;
	if (key(s)) 
		switch(tx[p + s->Length + 1]) {
		case ' ': case '>': // マッチ
			name = s; //tx->Substring(p + 1, s->Length);
			tagend(s->Length);
			ret = true;
			dtag();
		} 
	return ret;
}
bool html::key(String^s) { return String::Compare(tx, p + 1, s, 0, s->Length) == 0;}
bool html::hastag() {
	int pos = tx->IndexOf('<', p);
	if (pos < 0)
		return false;
	/* Trace::WriteLine(tx->Substring(pos, 5)); */
	p = pos;
	return true;
}
void html::tagend(int len) {
	for(i = p + len + 1;i < tx->Length; i++)
		if (tx[i] == '>')
			break;
}
int html::dnest(Int32 len, Int32 c) { // doubly nest table with dev for id // c = 2 only
	switch(tx[p + len + 1]) {
	case ' ': case '>': // マッチ
		Int32 n, m, ii;
		String ^key;
		tagend(len);
		switch(tx[i - 1]) {
		default:
			key = tx->Substring(p + 1, len);
			ii = i; 
 			n = tx->IndexOf("</" + key + ">", i);
			m = tx->IndexOf("<" + key , ii);
			if (n > 0 && m >= 0 && m < n) {
				switch(tx[m + len + 1]) { case ' ': case '>': /* マッチ */ii = m + len; i = n + len; }
 				p = m + len + 2;
			} else {
				Trace::WriteLine("Err");
				p += len + 2;
				Trace::WriteLine("n = " + n.ToString());
			}
			break;
		case '/':; 
			Trace::WriteLine(tx->Substring(p + 1, len));
			Trace::WriteLine("i = "+i.ToString());
			p = i + 1;
		}
		return true;
	}
	return false;
}
void html::bodysplit() {
	Int32 e;
	e = tx->IndexOf("</div>", i);
	if (e >= 0) {
		i = tx->IndexOf("<a ", i);
		p = e + 6;
		e = tx->IndexOf("</a>", i);
		Trace::WriteLine(tx->Substring(i, e + 4 - i));
	}
}
bool html::repeat(Int32 c) { return repeat(c, false); }
bool html::repeat(Int32 c, bool split) { // for div of auction box 
	Int32 len = name->Length;
	String ^key;
	if (split) tagsplit(len);
	switch(tx[i - 1]) {
	default:
		key = tx->Substring(p, len + 1);
		for (c--; c > 0; c--) {
			i = tx->IndexOf(key, i);
			if (i < 0) 
				break;
			i += len + 1;
			switch(tx[i]) {
				case ' ': case '>': continue;// マッチ
			}
			Trace::WriteLine("ErrFormat"); break;
		} 
		if (split) bodysplit();
		break;
	case '/':; 
		Trace::WriteLine(tx->Substring(p + 1, len));
		Trace::WriteLine("i = "+i.ToString());
		p = i + 1;
	}
	return c == 0;
}
int html::split(Int32 len, Int32 c) { // for div of auction box 
	String ^key;
	switch(tx[p + len + 1]) {
	case ' ': case '>': // マッチ
		tagend(len); tagsplit(len);
		switch(tx[i - 1]) {
		default:
			key = tx->Substring(p, len + 1);
			for (c--; c > 0; c--) {
				i = tx->IndexOf(key, i);
				if (i < 0) 
					break;
				i += len + 1;
				switch(tx[i]) {
					case ' ': case '>': continue;// マッチ
				}
				Trace::WriteLine("ErrFormat"); break;
			} 
			bodysplit();
			break;
		case '/':; 
			Trace::WriteLine(tx->Substring(p + 1, len));
			Trace::WriteLine("i = "+i.ToString());
			p = i + 1;
		}
		return true;
	}
	return false;
}
bool html::n(String ^s, Int32 c) {	return key(s) && dnest(s->Length, c); /* ネスト */}
bool html::r(String ^s, Int32 c) {	return key(s) && split(s->Length, c); /* 読み込み */}
bool html::o(String ^s) {	return key(s) && over(s->Length); /*  ステップオーバー for simple */}
bool html::O(String ^s) {	return key(s) && nover(s->Length); /*  ステップオーバー for NestTag */}
bool html::s(String ^s) {	return key(s) && step(s->Length); /*ステップイン*/}
int html::any() { 
	for (int len = 0; len < 100; len ++) {
		switch(tx[p + len + 1]) {
		case ' ': case '>': // マッチ
			name = tx->Substring(p + 1, len);
			tagend(len);
			p = i;
			return true;
		default:
			continue;
		}
	}
	Trace::WriteLine("Any Error");
	return false;
}
void html::parse() {};
String ^html::tcut(String^a, String^b) { 
	String ^s = tok(tx).cut(a, b, p, i);
	if(tag_debug) Trace::WriteLine(s);
	return s;
}
void http::ride(pos ^res) {
	p = res->p;
	i = res->i;
	name = res->name;
}
pos ^http::resume() {
	pos ^res = gcnew pos;
	res->p = p;
	res->i = i;
	res->name = name;
	return res;
}