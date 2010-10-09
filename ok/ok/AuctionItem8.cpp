#include "StdAfx.h"
void AuctionItem8::setDown(String ^st) {
int d = Convert::ToInt32(st) * SEP;
int maru = down & (SEP - 1);
RETRY:
	switch (mode) {
	case 0:
		if (d <= limitGo) goto FINAL;
		look = d - 12;
		down = d;
		if (look > limitGo) {
			down0 = d;
			setMode(2); /* 計測可能 */
		} else {
			setMode(1); /* 計測不可能 */
		}
		break;
	case 1:
		if (d <= limitGo) goto FINAL;
		break;
	case 5:
		down--;
		if ((down & MEASUR_VAL) != d) { 
			if ((maru || (down & MEASUR_VAL) != (d + SEP))) { /* 調整失敗 */
				if (d - down < 20) /* 20 以上の誤差は途中入札で再調整が必要だった　*/
					WF_(("調整NG {0} {1} {2} {3} {4} {5}", down & MEASUR_VAL, d, id, down, down_type, user));
				setMode(0); goto RETRY;
			} else {WF_(("調整OK1 {0} {1} {2} {3}", id, down, down_type, user));} // またぎ計測
		} else {WF_(("調整OK0 {0} {1} {2} {3}", id, down, down_type, user));}
		if (down <= limitGo) {goto FINAL;}
		break;
	case 2:
		down--;
		switch (down0 - d) {
		case 1 * SEP:
			down_type = 0;
			down0 = d;  goto LOOK_CHK; 
		case 2 * SEP:
			down_type = 4;
			down0 = d; down += 4; goto LOOK_CHK; 
		default:
			WF_(("Error2!! {0} look = {1}", down0 - d, look));
			setMode(0); // 再計測
			goto RETRY;
LOOK_CHK:
			look -= 10;
			if (look > limitGo) {
				setMode(3); /* 計測可能 */
			} else {
				setMode(1); /* 計測不可能 */
			}
			break;
		}
		break;
	case 3:
		down--;
		switch (down0 - d) {
		case 1 * SEP:
			down0 = d;goto LOOK_CHK2;
		case 2 * SEP:
			down_type |= 2;
			down0 = d; down += 2; goto LOOK_CHK2;
		default:
			WF_(("Error3!! {0}", down0 - d));
			setMode(0); // 再計測
			goto RETRY;
LOOK_CHK2:
			look -= 9;
			if (look > limitGo) {
				setMode(6); /* 計測可能 */
			} else {
				setMode(1); /* 計測不可能 */
			}
			break;
		}
		break;
	case 6:
		switch (down0 - d) {
		case 1 * SEP:
			down = d;
			break;
		case 2 * SEP:
			down_type |= 1;
			down = d + SEP - 1; // 調整
			break;  
		default:
			WF_(("Error6!! {0}", down0 - d));
			setMode(0); // 再計測
			goto RETRY;

		}
		setMode(5); // 調整完了
		setType();
		break;FINAL:
		if (this->Checked && !owner()) {
			threadGo();
		}
	}
}