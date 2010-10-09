public ref class json : public http {
public:
	json() {}
	json(String ^url): http(url) {}
	json(String ^url, int n): http(url, n) {}
protected:
	bool hastag() { bool ret = false;
		Int32 n = tx->IndexOf('{', p);
		if (n > 0) {
			p = n; ret = true;
		}
		return ret;
	}
};