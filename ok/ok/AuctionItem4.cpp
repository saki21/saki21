#include "StdAfx.h"
void AuctionItem4::setDown(String ^st) {
int d = Convert::ToInt32(st) * SEP;
int maru = down & 3;
#define MEASUR_VAL -4  /* �v���\�r�b�g */
RETRY:
	switch (mode) {
	case 0:
		if (d <= limitGo) goto FINAL;
		look = d - 6;
		down = d;
		if (look > limitGo) {
			down0 = d;
			setMode(2); /* �v���\ */
		} else {
			setMode(1); /* �v���s�\ */
		}
		break;
	case 1:
		if (d <= limitGo) goto FINAL;
		break;
	case 5:
		down--;
		if ((down & MEASUR_VAL) != d) { 
			if ((maru || (down & MEASUR_VAL) != (d + SEP))) { /* �������s */
				if (d - down < 20) /* 20 �ȏ�̌덷�͓r�����D�ōĒ������K�v�������@*/
					WF_(("����NG {0} {1} {2} {3} {4} {5}", down & MEASUR_VAL, d, id, down, down_type, user));
				setMode(0); goto RETRY;
			} else {WF_(("����OK1 {0} {1} {2} {3}", id, down, down_type, user));} // �܂����v��
		} else {WF_(("����OK0 {0} {1} {2} {3}", id, down, down_type, user));}
		if (down <= limitGo) {goto FINAL;}
		break;
	case 2:
		down--;
		switch (down0 - d) {
		case 1 * SEP:
			down_type = 0;
			down0 = d;  goto LOOK_CHK; 
		case 2 * SEP:
			down_type = 2;
			down0 = d; down += 2; goto LOOK_CHK; 
		default:
			WF_(("Error2!! {0} look = {1}", down0 - d, look));
			setMode(0); // �Čv��
			goto RETRY;
LOOK_CHK:
			look -= 5; /* 1-> 5 2-> 7 �̊��o�̑���ɑ��� */
			if (look > limitGo) {
				setMode(3); /* �v���\ */
			} else {
				setMode(1); /* �v���s�\ */
			}
			break;
		}
		break;
	case 3:
		switch (down0 - d) {
		case 1 * SEP:
			down = d;
			break;
		case 2 * SEP:
			down_type |= 1;
			down = d + 3; // ����
			break;  
		default:
			WF_(("Error3!! {0}", down0 - d));
			setMode(0); // �Čv��
			goto RETRY;
		}
		setMode(5); // ��������
		setType();
		break;
FINAL:
		if (this->Checked && !owner()) {
			threadGo();
		}
	}
}