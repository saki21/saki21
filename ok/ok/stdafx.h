// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
#pragma once
#include "i_ok.h"
// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B
#include "http.h"
#include "json.h"
#include "tok.h"
#include "streamEuc.h"
#include "AuctionStatus.h"
#include "AuctionPage.h"
#include "AuctionHist.h"
#include "AuctionItem.h"
#include "AuctionGroup.h"
#include "AuctionItem4.h"
#include "AuctionItem8.h"
#include "AuctionItem20.h"
#include "App.h"
HistListView ^create_hist_form(AuctionItem ^a); /* ok.cpp */
