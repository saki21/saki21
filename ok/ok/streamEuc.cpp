#include "StdAfx.h"
//http://msdn.microsoft.com/ja-jp/library/b0084kay.aspx
#define d if(0)Trace::WriteLine(__FUNCDNAME__ " "__FUNCTION__)
using namespace System::Text;
//http://www.weblio.jp/content/EncodingInfo.GetEncoding+%E3%83%A1%E3%82%BD%E3%83%83%E3%83%89
streamEuc::streamEuc(Stream ^s): StreamReader(s, Encoding::GetEncoding(51932)) {}
#if 0
String ^streamEuc::ReadToEnd() {
	static const int N = 1000;
	d; int pos = 0, r;
	array<Char> ^a;
#if 0
	for (Array::Resize(a, N); N != (r = StreamReader::Read(a, pos, N)); pos += N)
		Array::Resize(a, pos + N);
#else
	int v;
	for (Array::Resize(a, N);; pos += N) {
		for (r = 0; r < N && ((v = StreamReader::Read()) != -1); r++) {
			a->SetValue(Char(v), pos + r);
			if (v == 0xFFFD) 
				Trace::WriteLine("FFFD<-[" + Int32(v).ToString("X"));
		}
		if (r != N) break;
		Array::Resize(a, pos + N + N);
	}
#endif
	StringBuilder b(a->Length - N + r);
	b.Append(a);
//	b.CopyTo(0, a, 0, b.Length); 
//	return StreamReader::ReadToEnd();
	return b.ToString();
}
#endif
int streamEuc::Read() { d; return StreamReader::Read(); }
String ^streamEuc::ReadToEnd() { d; return StreamReader::ReadToEnd(); }