
#pragma once
ref struct FormInputValue : public html {
	array<String^>^name;
	array<String^>^value;
	Int32 Length;
	void array_size() {
		Array::Resize(name,FORM_INPUT_VALUE_NUM);
		Array::Resize(value,FORM_INPUT_VALUE_NUM);
	}
	FormInputValue(String^url): html(url), Length(0) { array_size(); parse(); }
	void parse() {
		int step = 0;
	    enum { START, BODY, FORM, INPUT};
		for (p = 0; p < tx->Length && hastag(); p++){
			if (skip_com()) 
				continue;
			switch(step) {
			case START: if (o("head")) { step = BODY; continue; }
				break;
			case BODY: if (tag("form") && tx->IndexOf("action=\"/my/\"", p, i - p) > 0) { up(); step = INPUT; continue; }
				break;
			case INPUT: 
				if (tag("input")) {
					name->SetValue(tcut("name=\"","\""), Length);
					value->SetValue(tcut("value=\"","\""), Length); 
					Length++; up(); continue; 
				}
 				if (tag("/form")) return;
				break;
			}
			any();
		}
	}
};


ref struct EnterPage : public AuctionPage { // For Point
	String ^path;
	bool need_read;
	String ^postdata() {
		return 
		"login_id=oeq7ff66&save_log_id=1&password=" USERPASSWD "&save_password=1&x=70&y=18&path=" + path + "&path =" + path + "&act=commit";
	}
	EnterPage(): need_read(false), path("DRVESVwZTlNNBkVRXFhIUwwIGFVfVEs_"), 
		AuctionPage("https://www.dmm.com/my/", 0){ 
		tx=postdata(); 
		post(); 
		if(!isLogin()){
			Trace::WriteLine("----------------------------->Login ERROR");
			AltPage ^alt = gcnew AltPage(BASE);
			tx = alt->get();
		} else {
			Trace::WriteLine("----------------------------->Login OK");
		}
	}
	virtual void UpdateItems() override;
	virtual void setsub(String^, bool v) override;
};
/*
+open-action 
 + mod action-box
   + icon
   + box-1yen
    + inner
 + mod action-box             
*/
ref class Janru : public AuctionPage {
	Janru(): AuctionPage(POINT), id("point") { parse(); }
	Janru(String ^k): AuctionPage(ok::junru::url(k)), id(k) { set_action_in_div_open_action(); }
public:
	String ^id;
	static Janru ^Cre(String ^k) { return k == "point" ? gcnew Janru : gcnew Janru(k); }
	virtual String^ getid() override { return id; };
};
