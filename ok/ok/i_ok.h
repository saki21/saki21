#include "passwd.h"
namespace i_ok {
	using namespace System::Web;
	class iok {

	};
}
using namespace System;
using namespace System::Diagnostics;
// bet
using namespace System::IO;
using namespace System::Net;
using namespace System::Threading;
using namespace System::Windows::Forms;


#define BASE	"http://auction.dmm.com/"
#define SUB		"http://sub-auction.dmm.com/"
#define Auction AuctionItem
#define ENTER_PAGE "http://auction.dmm.com/"
#define JUNRU		BASE##"auction/-/list/=/article=keyword/id="
#define FOOD		JUNRU##"food/"
#define POINT		JUNRU##"47302/"

//#define PAUTO   SUB##"service_autobid.php?auction_id=" 
#define PAUTO   SUB##"auction/ajax/-/auction_info/=/" 
#define PHIST0  SUB##"getbidhistory.php?id="
#define PHIST1   "&userid=D100dr2mv5bv"
#define FRAME	"https://www.dmm.com/my/=/path=DRVESVwZTlNNBkVRXFhIUwwIGFVfVEs_/"
#define LOGIN	"https://www.dmm.com/my/=/path=DRVESVwZTlNNBkVRXFhIUwwIGFVfVEs_/"
#define PAUCTION	BASE##"placebid.php?AuctionID="
#define ASTATUS0		SUB##"auction/ajax/-/auction_info/=/?callback=jsonp1286620229758&aid="
#define ASTATUS1		"&type=status"
#define LOGINGO 
#define LOGOUT "ログアウト"
#define FORM_IMG_ALT_NUM 4
#define FORM_INPUT_VALUE_NUM 10
#define DEBUG(a) /* */
#define DEBUG_(a) a
#define DEBUGALT(a,b) a
#define DEBUGALT_(a,b) b
#ifdef _DEBUG
#define WF(a) /*Trace::WriteLine(String::Format(" */
#define WF_(a) Trace::WriteLine(String::Format a )
#define WL(a) /*Trace::WriteLine */
#define WL_(a) Trace::WriteLine(a)
#define W(a) /*Trace::Write */
#define W_(a) Trace::Write(a)
#else
#define WF(a) /*Trace::WriteLine(String::Format(" */
#define WF_(a) Console::WriteLine a 
#define WL(a) /*Trace::WriteLine */
#define WL_(a) Console::WriteLine(a)
#define W(a) /*Trace::Write */
#define W_(a) Console::Write(a)
#endif
namespace ok {
#if 1
 static const int BIT = 3;
 static const int SEP = 1<<BIT;  // 1000 = SEP * 125
 static const int MASK = SEP - 1;
#else
 static const int BIT = 5;
 static const int SEP = 20;   // 1000 = SEP * 50
 static const int MASK = (1<<BIT) - 1;
#endif
 static const int UNIT = 1000 / SEP;
 static const int limitFinal = -SEP * 20;
 extern bool mogi;
 struct st { static String^url(String^s) { return ASTATUS0 + s + ASTATUS1; }};
 struct p { static String^url(String^s) { return PAUCTION + s; }};
 struct junru { static String^url(String^s) { return JUNRU + s + "/"; }};
 struct hist { static String^url(String^s) { return PHIST0 + s + PHIST1; }};

};
#undef PHIST0
#undef PHIST1
#undef PAUCTION
#undef ASTATUS
