// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
#pragma once
#include "i_ok.h"
// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
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
