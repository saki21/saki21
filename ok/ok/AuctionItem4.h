#undef SEP
ref class AuctionItem4 : public AuctionItem {
	static const int MEASUR_VAL = -SEP;  /* �v���\�r�b�g */
	static const int limitFinal = -5 * SEP;
public:
	static const int SEP = 8;
	AuctionItem4(Int32 id): AuctionItem(id) { down = limitGo - 1; }
	virtual void setDown(String ^st)override; 
};