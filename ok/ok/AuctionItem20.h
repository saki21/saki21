
ref class AuctionItem20 : public AuctionItem {
	/* static const int MEASUR_VAL = -SEP;  �v���\�r�b�g */
	static const int limitFinal = -5 * SEP;
	int sep0; /* �S�� */
	int sep1; /* �܂ޕ���(2���@) */
public:
	static const int SEP = 50;
	AuctionItem20(Int32 id): AuctionItem(id){ down = limitGo - 1; }
	virtual void setDown(String ^st)override; 
	bool One(); 
	bool Two();
};