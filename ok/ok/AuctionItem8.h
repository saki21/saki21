ref class AuctionItem8 : public AuctionItem {
	static const int MEASUR_VAL = -SEP;  /* 計測可能ビット */
	static const int limitFinal = -5 * SEP;
public:
	static const int SEP = 8;
	AuctionItem8(Int32 id): AuctionItem(id){ down = limitGo - 1; }
	virtual void setDown(String ^st)override; 
};