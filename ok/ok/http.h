using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::Net;
public ref struct ur {
	Uri ^uri;
	Int32 url_id;
	String ^url;
	static int url_max = 1;
	static array<String^>^hosts = {".dmm.com"};
	static array<CookieCollection^>^cc = {gcnew CookieCollection};
	static CookieContainer ^ckc = gcnew CookieContainer;
	ur();
	ur(String ^url);
	void set_url_id();
};
public ref struct pos {
	Int32 p;		// TagTop Point
	Int32 i;		// TagEnd Point
	String ^name; // lookup tag name
};
public ref class http : public ur  {
protected:
	static const bool tag_debug = false;
	static const bool header_debug = false;
	static const int debug_print = 1000;
	String ^tx;
	Int32 p;		// TagTop Point
	Int32 i;		// TagEnd Point
	String ^name; // lookup tag name
	virtual void reflash(){};
	pos ^resume();
	void ride(pos^);
private:
	HttpWebRequest ^request;
	void saveCookie(HttpWebResponse^ res);
public:
	http(String ^url, int count);
	http(String ^url);
	http();
	void post();
	void wait();
	void go();
};
public ref class html : public http  {
public:
	html(String ^url, int count): http(url, count){}
	html(String ^url): http(url){}
	html(){};
protected:
	void tagsplit();
	void tagsplit(int len);
	void oversplit(int len);
	int nover(int len) ; // nestable over
	bool c_name_claer();
	bool c_name(String ^nm);
	void up();
	bool n_name(String ^nm);
	int over(int len);
	bool step(int len);
	void dtag(); 
	bool find(String ^s, String^nm);
	bool find(String ^s);
	bool tag_i(String^ nm);
	bool tag(String^s, String^nm);
	bool tag(String^s);
	bool key(String^s);
	void tagend(int len);
	int dnest(Int32 len, Int32 c);
	void bodysplit();
	bool repeat(Int32 c);
	bool repeat(Int32 c, bool split);
	int split(Int32 len, Int32 c);
	bool n(String ^s, Int32 c); /* ネスト */
	bool r(String ^s, Int32 c); /* 読み込み */
	bool o(String ^s);/*  ステップオーバー for simple */
	bool O(String ^s);/*  ステップオーバー for NestTag */
	bool s(String ^s);/*ステップイン*/
	int any();
	void parse();
	String ^tcut(String^a, String^b);
	String ^ToString() new;
	String ^ToString(String ^key);
	int ToInt();
	int ToInt(String ^key);
	int ToInt(String ^key, String ^fix);
	int ToInt(String ^key, String ^fix0, String ^fix1);
	bool hastag();
	int skip_com();
	virtual void reflash() override;
//	void ThredGo();
};