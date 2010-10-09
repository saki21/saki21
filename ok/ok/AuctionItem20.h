
ref class AuctionItem20 : public AuctionItem {
	/* static const int MEASUR_VAL = -SEP;  計測可能ビット */
	static const int limitFinal = -5 * SEP;
	int sep0; /* 全体 */
	int sep1; /* 含む部分(2分法) */
public:
	static const int SEP = 50;
	AuctionItem20(Int32 id): AuctionItem(id){ down = limitGo - 1; }
	virtual void setDown(String ^st)override; 
	bool One(); 
	bool Two();
};