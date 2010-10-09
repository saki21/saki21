ref struct tok {
	String ^s;
	tok(String ^s);
	String ^cut(String ^st_, String ^en_, Int32 st, Int32 en);
	static String ^u(String^v) {
		enum { START, COPY };
		Text::StringBuilder ^b;
		int e = 0, step = START, len = v->Length;
		for (e = 0; e < len; e++)
			switch (step) {
			case START:
				if (v[e] == '\\' && e + 5 < len && v[e + 1] == 'u')
					b = gcnew Text::StringBuilder(v, 0, e, 256), 
					b->Append(get_u(v, e)), 
					e += 5, 
					step = COPY;
				break;
			case COPY:
				if (v[e] == '\\' && e + 5 < len && v[e + 1] == 'u')
					b->Append(get_u(v, e)), e += 5;
				else
					b->Append(v[e]);
				break;
			}
		return step == START ? v : b->ToString();
	}
private :static Char get_u(String^v, Int32 e) {
		String ^s = v->Substring(e + 2, 4);
		return Int32::Parse(s, System::Globalization::NumberStyles::AllowHexSpecifier);
	}
};