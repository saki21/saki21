ref class App: public ApplicationContext
{
private:
   Form^		form;
   void OnFormClosed(Object^, EventArgs^){ ExitThread();}
   static App^ app;
   App();
public:
	static App ^Cre();
	static HistListView ^create_hist_form(AuctionItem ^a);
};
