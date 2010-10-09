ref struct streamEuc : public StreamReader{
	streamEuc(Stream ^s);
//	String ^ReadToEnd();
	virtual int Read() override;
	virtual String ^ReadToEnd() override;
};