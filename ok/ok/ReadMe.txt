========================================================================
    アプリケーション: ok プロジェクトの概要
========================================================================
この ok アプリケーションは、AppWizard により作成されました。
<iframe id="top" marginwidth="0" height="175" src="http://www.dmm.com/remotepage/-/navi/=/loginoutpath=aHR0cDovL2F1Y3Rpb24uZG1tLmNvbS8=/channel=auction/link=_parent/_jloff=1/page=/" scrolling="no" width="100%" border="no" frameborder="0"></iframe>
9/18 slice opt pre make タイムスライスして状態取得パラメータをあらかじめ作成する手法の廃止。

●テスト依頼
ノンパスワードチェックPATHの詳細ポートは？
https://www.dmm.com/my/=/path=DRVESVwZTlNNBkVRXFhIUwwIGFVfVEs_/

●以下でwww.dmm.comのクッキーファイル ck が生成される
$ ./gc.txt 

手法：キャプチャーして strings 実行
http.request.method == "POST"
#https
tcp.port == 443
http and ip[16:2]==3b.6a
SYN ACK
tcp.flags & 0x02
# ＴＣＰ　ＩＰ接続開始 SYN
tcp[13:1]==02


[0,["\u304a\u3046\u3058","15",10693,99.98,"20","5","1024"],["\u30e6\u30ad\u30ea\u30f3\u300d","810",1793,64,"20","5","1251"],["assh","315",12893,91.6,"20","5","1254"],["\u96ea\u574a\u4e3b","540",7793,92.8,"20","5","1256"]]
[0,["\u304a\u3046\u3058","15",10690,99.98,"20","5","1024"],["\u30e6\u30ad\u30ea\u30f3\u300d","810",1790,64,"20","5","1251"],["assh","315",12890,91.6,"20","5","1254"],["\u96ea\u574a\u4e3b","540",7790,92.8,"20","5","1256"]]
[0,["\u304a\u3046\u3058","15",10688,99.98,"20","5","1024"],["\u30e6\u30ad\u30ea\u30f3\u300d","810",1788,64,"20","5","1251"],["assh","315",12888,91.6,"20","5","1254"],["\u96ea\u574a\u4e3b","540",7788,92.8,"20","5","1256"]]
[0,["\u304a\u3046\u3058","15",10686,99.98,"20","5","1024"],["\u30e6\u30ad\u30ea\u30f3\u300d","810",1786,64,"20","5","1251"],["assh","315",12886,91.6,"20","5","1254"],["\u96ea\u574a\u4e3b","540",7786,92.8,"20","5","1256"]]
[0,["\u304a\u3046\u3058","15",10684,99.98,"20","5","1024"],["\u30e6\u30ad\u30ea\u30f3\u300d","810",1784,64,"20","5","1251"],["assh","315",12884,91.6,"20","5","1254"],["\u96ea\u574a\u4e3b","540",7784,92.8,"20","5","1256"]]
[0,["\u304a\u3046\u3058","15",10681,99.98,"20","5","1024"],["\u30e6\u30ad\u30ea\u30f3\u300d","810",1781,64,"20","5","1251"],["assh","315",12881,91.6,"20","5","1254"],["\u96ea\u574a\u4e3b","540",7781,92.8,"20","5","1256"]]

User-Agent
Host	auction.dmm.com
Connection
Referer
X-Requested-With
Accept
Accept-Encoding
Cookie
 back_url
 __utmz
 PHPSESSID	g64edimgslovcuiqm8lgfdjo1
 BASKET_Cookie
 __utma
 __utmc
 __utmv
 __utmb
 license
 UID
 check_done_login=1
 ystjd

okLogin6,pcap
358	5.798684	192.168.0.3	203.209.146.217	HTTP	GET / HTTP/1.1
548	6.881670	192.168.0.3	203.209.146.217	HTTP	GET /getUserStats.php?userId=D100dr2mv5bv HTTP/1.1 
0000   00 3a 9d 19 67 58 02 ff 65 6a 26 cc 08 00 45 00  .:..gX..ej&...E.
0010   05 dc 7c 37 40 00 80 06 59 8e c0 a8 00 03 cb d1  ..|7@...Y.......
0020   92 d9 09 87 00 50 08 02 3c 75 86 8c fa 8e 50 10  .....P..<u....P.
0030   80 00 de 0b 00 00 47 45 54 20 2f 67 65 74 55 73  ......GET /getUs
0040   65 72 53 74 61 74 73 2e 70 68 70 3f 75 73 65 72  erStats.php?user
0050   49 64 3d 44 31 30 30 64 72 32 6d 76 35 62 76 20  Id=D100dr2mv5bv 
0060   48 54 54 50 2f 31 2e 31 0d 0a 48 6f 73 74 3a 20  HTTP/1.1..Host: 
0070   61 75 63 74 69 6f 6e 2e 64 6d 6d 2e 63 6f 6d 0d  auction.dmm.com.
0080   0a 43 6f 6e 6e 65 63 74 69 6f 6e 3a 20 6b 65 65  .Connection: kee
0090   70 2d 61 6c 69 76 65 0d 0a 55 73 65 72 2d 41 67  p-alive..User-Ag
00a0   65 6e 74 3a 20 4d 6f 7a 69 6c 6c 61 2f 35 2e 30  ent: Mozilla/5.0
00b0   20 28 57 69 6e 64 6f 77 73 3b 20 55 3b 20 57 69   (Windows; U; Wi
00c0   6e 64 6f 77 73 20 4e 54 20 35 2e 31 3b 20 65 6e  ndows NT 5.1; en
00d0   2d 55 53 29 20 41 70 70 6c 65 57 65 62 4b 69 74  -US) AppleWebKit
00e0   2f 35 33 33 2e 34 20 28 4b 48 54 4d 4c 2c 20 6c  /533.4 (KHTML, l
00f0   69 6b 65 20 47 65 63 6b 6f 29 20 43 68 72 6f 6d  ike Gecko) Chrom
0100   65 2f 35 2e 30 2e 33 37 35 2e 31 32 37 20 53 61  e/5.0.375.127 Sa
0110   66 61 72 69 2f 35 33 33 2e 34 0d 0a 52 65 66 65  fari/533.4..Refe
0120   72 65 72 3a 20 68 74 74 70 3a 2f 2f 61 75 63 74  rer: http://auct
0130   69 6f 6e 2e 64 6d 6d 2e 63 6f 6d 2f 0d 0a 58 2d  ion.dmm.com/..X-
0140   52 65 71 75 65 73 74 65 64 2d 57 69 74 68 3a 20  Requested-With: 
0150   58 4d 4c 48 74 74 70 52 65 71 75 65 73 74 0d 0a  XMLHttpRequest..
0160   41 63 63 65 70 74 3a 20 61 70 70 6c 69 63 61 74  Accept: applicat
0170   69 6f 6e 2f 6a 73 6f 6e 2c 20 74 65 78 74 2f 6a  ion/json, text/j
0180   61 76 61 73 63 72 69 70 74 2c 20 2a 2f 2a 0d 0a  avascript, */*..
0190   41 63 63 65 70 74 2d 45 6e 63 6f 64 69 6e 67 3a  Accept-Encoding:
01a0   20 67 7a 69 70 2c 64 65 66 6c 61 74 65 2c 73 64   gzip,deflate,sd
01b0   63 68 0d 0a 41 63 63 65 70 74 2d 4c 61 6e 67 75  ch..Accept-Langu
01c0   61 67 65 3a 20 6a 61 2c 65 6e 2d 55 53 3b 71 3d  age: ja,en-US;q=
01d0   30 2e 38 2c 65 6e 3b 71 3d 30 2e 36 0d 0a 41 63  0.8,en;q=0.6..Ac
01e0   63 65 70 74 2d 43 68 61 72 73 65 74 3a 20 53 68  cept-Charset: Sh
01f0   69 66 74 5f 4a 49 53 2c 75 74 66 2d 38 3b 71 3d  ift_JIS,utf-8;q=
0200   30 2e 37 2c 2a 3b 71 3d 30 2e 33 0d 0a 43 6f 6f  0.7,*;q=0.3..Coo
0210   6b 69 65 3a 20 62 61 63 6b 5f 75 72 6c 3d 25 33  kie: back_url=%3
0220   44 25 32 46 70 61 74 68 25 33 44 3b 20 50 48 50  D%2Fpath%3D; PHP

0230   53 45 53 53 49 44 3d 67 36 34 65 64 69 6d 67 73  SESSID=g64edimgs
0240   6c 6f 76 63 75 69 71 6d 38 6c 67 66 64 6a 6f 31  lovcuiqm8lgfdjo1
0250   36 3b 20 5f 5f 75 74 6d 7a 3d 32 32 35 32 33 31  6; __utmz=225231
0260   38 37 37 2e 31 32 38 33 38 36 35 39 34 39 2e 32  877.1283865949.2
0270   34 2e 36 2e 75 74 6d 63 73 72 3d 64 6d 6d 2e 63  4.6.utmcsr=dmm.c
0280   6f 6d 7c 75 74 6d 63 63 6e 3d 28 72 65 66 65 72  om|utmccn=(refer
0290   72 61 6c 29 7c 75 74 6d 63 6d 64 3d 72 65 66 65  ral)|utmcmd=refe
02a0   72 72 61 6c 7c 75 74 6d 63 63 74 3d 2f 72 65 6d  rral|utmcct=/rem
02b0   6f 74 65 70 61 67 65 2f 2d 2f 6e 61 76 69 2f 3d  otepage/-/navi/=
02c0   2f 6c 6f 67 69 6e 6f 75 74 70 61 74 68 3d 61 48  /loginoutpath=aH
02d0   52 30 63 44 6f 76 4c 32 46 31 59 33 52 70 62 32  R0cDovL2F1Y3Rpb2
02e0   34 75 5a 47 31 74 4c 6d 4e 76 62 53 38 3d 2f 63  4uZG1tLmNvbS8=/c
02f0   68 61 6e 6e 65 6c 3d 61 75 63 74 69 6f 6e 2f 6c  hannel=auction/l
0300   69 6e 6b 3d 5f 70 61 72 65 6e 74 2f 5f 6a 6c 6f  ink=_parent/_jlo
0310   66 66 3d 31 2f 70 61 67 65 3d 2f 3b 20 42 41 53  ff=1/page=/; BAS
0320   4b 45 54 5f 43 6f 6f 6b 69 65 3d 70 61 79 6d 65  KET_Cookie=payme
0330   6e 74 25 33 44 25 32 36 70 61 79 6d 65 6e 74 5f  nt%3D%26payment_
0340   69 64 25 33 44 25 32 36 6d 6f 6e 65 79 25 33 44  id%3D%26money%3D
0350   25 32 36 72 65 66 5f 75 72 6c 25 33 44 25 32 36  %26ref_url%3D%26
0360   72 65 66 5f 69 64 25 33 44 25 32 36 72 65 67 69  ref_id%3D%26regi
0370   73 74 25 33 44 3b 20 5f 5f 75 74 6d 61 3d 32 32  st%3D; __utma=22
0380   35 32 33 31 38 37 37 2e 31 39 30 39 30 37 38 31  5231877.19090781
0390   33 38 2e 31 32 38 33 32 37 34 35 37 32 2e 31 32  38.1283274572.12
03a0   38 33 39 31 32 32 31 34 2e 31 32 38 33 39 34 32  83912214.1283942
03b0   33 35 38 2e 32 39 3b 20 5f 5f 75 74 6d 63 3d 32  358.29; __utmc=2
03c0   32 35 32 33 31 38 37 37 3b 20 5f 5f 75 74 6d 76  25231877; __utmv
03d0   3d 32 32 35 32 33 31 38 37 37 2e 4d 65 6d 62 65  =225231877.Membe
03e0   72 3b 20 5f 5f 75 74 6d 62 3d 32 32 35 32 33 31  r; __utmb=225231
03f0   38 37 37 2e 33 2e 31 30 2e 31 32 38 33 39 34 32  877.3.10.1283942
0400   33 35 38 3b 20 63 68 65 63 6b 5f 6f 70 65 6e 5f  358; check_open_
0410   6c 6f 67 69 6e 3d 31 3b 20 49 4e 54 5f 53 45 53  login=1; INT_SES
0420   49 44 3d 41 67 34 45 58 42 6b 56 44 77 52 65 52  ID=Ag4EXBkVDwReR
0430   6a 5a 37 49 68 6f 49 46 56 39 57 56 67 4d 54 4f  jZ7IhoIFV9WVgMTO
0440   67 41 69 62 6b 51 44 52 44 4a 33 65 45 45 69 64  gAibkQDRDJ3eEEid
0450   58 55 4b 44 51 46 57 66 69 55 6c 49 6e 4d 65 47  XUKDQFWfiUlInMeG
0460   67 67 56 58 31 46 59 47 32 49 33 64 54 5a 6a 45  ggVX1FYG2I3dTZjE
0470   41 35 61 57 51 63 46 43 6c 41 4e 42 46 56 57 58  A5aWQcFClANBFVWX
0480   67 49 4d 46 31 35 54 43 45 51 61 43 43 68 65 46  gIMF15TCEQaCCheF
0490   31 67 41 43 30 46 39 4b 6d 4e 74 5a 6e 59 77 66  1gAC0F9KmNtZnYwf
04a0   33 4d 51 57 46 55 4b 58 6c 67 64 52 67 31 56 56  3MQWFUKXlgdRg1VV
04b0   56 6b 51 41 6b 31 44 43 67 77 48 41 30 31 59 44  VkQAk1DCgwHA01YD
04c0   46 70 47 44 45 45 50 41 31 6b 55 46 51 6b 51 44  FpGDEEPA1kUFQkQD
04d0   67 4e 63 51 44 4e 38 63 30 5a 66 45 41 68 58 41  gNcQDN8c0ZfEAhXA
04e0   51 6c 45 55 78 4d 7a 65 48 34 51 64 53 56 79 58  QlEUxMzeH4QdSVyX
04f0   6c 70 55 41 48 39 32 63 79 4a 31 53 45 52 5a 46  lpUAH92cyJ1SERZF
0500   51 38 4f 58 6b 59 4f 56 77 74 61 56 68 51 36 44  Q8OXkYOVwtaVhQ6D
0510   51 59 62 43 68 41 4f 56 51 55 49 46 33 64 53 42  QYbChAOVQUIF3dSB
0520   67 64 57 45 51 5a 64 45 46 63 45 51 78 56 66 46  gdWEQZdEFcEQxVfF
0530   31 6b 48 58 42 70 58 42 44 6f 4e 42 68 73 4b 45  1kHXBpXBDoNBhsKE
0540   41 35 56 44 52 41 47 45 56 68 46 44 51 70 5a 46  A5VDRAGEVhFDQpZF
0550   6c 77 48 45 52 4a 62 56 67 6b 42 51 51 6b 56 41  lwHERJbVgkBQQkVA
0560   67 64 63 52 39 57 55 67 39 74 42 44 78 63 4e 43  gdcR9WUg9tBDxcNC
0570   77 38 52 42 56 39 46 51 52 64 61 55 51 73 48 52  w8RBV9FQRdaUQsHR
0580   41 35 45 58 6c 42 5a 45 4b 48 57 25 32 42 72 46  A5EXlBZEKHW%2BrF
0590   48 58 78 45 44 41 46 73 4f 52 6b 52 54 57 45 4d  HXxEDAFsORkRTWEM
05a0   50 55 32 68 58 44 56 56 53 43 67 63 35 55 31 73  PU2hXDVVSCgc5U1s
05b0   46 41 30 45 4a 42 41 49 43 58 52 5a 65 55 77 77  FA0EJBAICXRZeUww
05c0   4c 51 56 55 44 55 6d 31 55 52 78 64 54 52 45 59  LQVUDUm1URxdTREY
05d0   43 51 46 6b 4a 44 45 51 4f 56 56 35 55 57 45 38  CQFkJDEQOVV5UWE8
05e0   62 3b 20 6c 69 63 65 6e 73 65                    b; license

0000   00 3a 9d 19 67 58 02 ff 65 6a 26 cc 08 00 45 00  .:..gX..ej&...E.
0010   00 6f 7c 38 40 00 80 06 5e fa c0 a8 00 03 cb d1  .o|8@...^.......
0020   92 d9 09 87 00 50 08 02 42 29 86 8c fa 8e 50 18  .....P..B)....P.
0030   80 00 d6 df 00 00 55 49 44 3d 36 77 51 41 4f 73  ......UID=6wQAOs
0040   41 41 45 6c 6f 67 63 49 41 41 41 41 78 3b 20 63  AAElogcIAAAAx; c
0050   68 65 63 6b 5f 64 6f 6e 65 5f 6c 6f 67 69 6e 3d  heck_done_login=
0060   31 3b 20 79 73 74 6a 64 3d 25 32 46 69 6e 64 65  1; ystjd=%2Finde
0070   78 2e 70 68 70 25 32 43 31 0d 0a 0d 0a           x.php%2C1....

552	6.900158	192.168.0.3	203.209.147.252	HTTP	GET /remotepage/-/navi/=/loginoutpath=aHR0cDovL2F1Y3Rpb24uZG1tLmNvbS8=/channel=auction/link=_parent/_jloff=1/page=/ HTTP/1.1  

Cooki
0260   65 3a 20 62 61 63 6b 5f 75 72 6c 3d 25 33 44 25  e: back_url=%3D%
0270   32 46 70 61 74 68 25 33 44 3b 　　　　　　　　　  2Fpath%3D; 

(詳細)
0000   00 3a 9d 19 67 58 02 ff 65 6a 26 cc 08 00 45 00  .:..gX..ej&...E.
0010   05 dc 7c 43 40 00 80 06 58 5f c0 a8 00 03 cb d1  ..|C@...X_......
0020   93 fc 09 89 00 50 f0 56 e3 9f 14 b3 85 d4 50 10  .....P.V......P.
0030   80 00 46 62 00 00 47 45 54 20 2f 72 65 6d 6f 74  ..Fb..GET /remot
0040   65 70 61 67 65 2f 2d 2f 6e 61 76 69 2f 3d 2f 6c  epage/-/navi/=/l
0050   6f 67 69 6e 6f 75 74 70 61 74 68 3d 61 48 52 30  oginoutpath=aHR0
0060   63 44 6f 76 4c 32 46 31 59 33 52 70 62 32 34 75  cDovL2F1Y3Rpb24u
0070   5a 47 31 74 4c 6d 4e 76 62 53 38 3d 2f 6c 69 6e  ZG1tLmNvbS8=/lin
0080   6b 3d 5f 70 61 72 65 6e 74 2f 5f 6a 6c 6f 66 66  k=_parent/_jloff
0090   3d 31 2f 70 61 67 65 3d 66 6f 6f 74 65 72 2f 20  =1/page=footer/ 
00a0   48 54 54 50 2f 31 2e 31 0d 0a 48 6f 73 74 3a 20  HTTP/1.1..Host: 
00b0   77 77 77 2e 64 6d 6d 2e 63 6f 6d 0d 0a 43 6f 6e  www.dmm.com..Con
00c0   6e 65 63 74 69 6f 6e 3a 20 6b 65 65 70 2d 61 6c  nection: keep-al
00d0   69 76 65 0d 0a 55 73 65 72 2d 41 67 65 6e 74 3a  ive..User-Agent:
00e0   20 4d 6f 7a 69 6c 6c 61 2f 35 2e 30 20 28 57 69   Mozilla/5.0 (Wi
00f0   6e 64 6f 77 73 3b 20 55 3b 20 57 69 6e 64 6f 77  ndows; U; Window
0100   73 20 4e 54 20 35 2e 31 3b 20 65 6e 2d 55 53 29  s NT 5.1; en-US)
0110   20 41 70 70 6c 65 57 65 62 4b 69 74 2f 35 33 33   AppleWebKit/533
0120   2e 34 20 28 4b 48 54 4d 4c 2c 20 6c 69 6b 65 20  .4 (KHTML, like 
0130   47 65 63 6b 6f 29 20 43 68 72 6f 6d 65 2f 35 2e  Gecko) Chrome/5.
0140   30 2e 33 37 35 2e 31 32 37 20 53 61 66 61 72 69  0.375.127 Safari
0150   2f 35 33 33 2e 34 0d 0a 52 65 66 65 72 65 72 3a  /533.4..Referer:
0160   20 68 74 74 70 3a 2f 2f 61 75 63 74 69 6f 6e 2e   http://auction.
0170   64 6d 6d 2e 63 6f 6d 2f 0d 0a 41 63 63 65 70 74  dmm.com/..Accept
0180   3a 20 61 70 70 6c 69 63 61 74 69 6f 6e 2f 78 6d  : application/xm
0190   6c 2c 61 70 70 6c 69 63 61 74 69 6f 6e 2f 78 68  l,application/xh
01a0   74 6d 6c 2b 78 6d 6c 2c 74 65 78 74 2f 68 74 6d  tml+xml,text/htm
01b0   6c 3b 71 3d 30 2e 39 2c 74 65 78 74 2f 70 6c 61  l;q=0.9,text/pla
01c0   69 6e 3b 71 3d 30 2e 38 2c 69 6d 61 67 65 2f 70  in;q=0.8,image/p
01d0   6e 67 2c 2a 2f 2a 3b 71 3d 30 2e 35 0d 0a 41 63  ng,*/*;q=0.5..Ac
01e0   63 65 70 74 2d 45 6e 63 6f 64 69 6e 67 3a 20 67  cept-Encoding: g
01f0   7a 69 70 2c 64 65 66 6c 61 74 65 2c 73 64 63 68  zip,deflate,sdch
0200   0d 0a 41 63 63 65 70 74 2d 4c 61 6e 67 75 61 67  ..Accept-Languag
0210   65 3a 20 6a 61 2c 65 6e 2d 55 53 3b 71 3d 30 2e  e: ja,en-US;q=0.
0220   38 2c 65 6e 3b 71 3d 30 2e 36 0d 0a 41 63 63 65  8,en;q=0.6..Acce
0230   70 74 2d 43 68 61 72 73 65 74 3a 20 53 68 69 66  pt-Charset: Shif
0240   74 5f 4a 49 53 2c 75 74 66 2d 38 3b 71 3d 30 2e  t_JIS,utf-8;q=0.
0250   37 2c 2a 3b 71 3d 30 2e 33 0d 0a 43 6f 6f 6b 69  7,*;q=0.3..Cooki
0260   65 3a 20 62 61 63 6b 5f 75 72 6c 3d 25 33 44 25  e: back_url=%3D%
0270   32 46 70 61 74 68 25 33 44 3b 20 5f 5f 75 74 6d  2Fpath%3D; __utm
0280   7a 3d 32 32 35 32 33 31 38 37 37 2e 31 32 38 33  z=225231877.1283
0290   38 36 35 39 34 39 2e 32 34 2e 36 2e 75 74 6d 63  865949.24.6.utmc
02a0   73 72 3d 64 6d 6d 2e 63 6f 6d 7c 75 74 6d 63 63  sr=dmm.com|utmcc
02b0   6e 3d 28 72 65 66 65 72 72 61 6c 29 7c 75 74 6d  n=(referral)|utm
02c0   63 6d 64 3d 72 65 66 65 72 72 61 6c 7c 75 74 6d  cmd=referral|utm
02d0   63 63 74 3d 2f 72 65 6d 6f 74 65 70 61 67 65 2f  cct=/remotepage/
02e0   2d 2f 6e 61 76 69 2f 3d 2f 6c 6f 67 69 6e 6f 75  -/navi/=/loginou
02f0   74 70 61 74 68 3d 61 48 52 30 63 44 6f 76 4c 32  tpath=aHR0cDovL2
0300   46 31 59 33 52 70 62 32 34 75 5a 47 31 74 4c 6d  F1Y3Rpb24uZG1tLm
0310   4e 76 62 53 38 3d 2f 63 68 61 6e 6e 65 6c 3d 61  NvbS8=/channel=a
0320   75 63 74 69 6f 6e 2f 6c 69 6e 6b 3d 5f 70 61 72  uction/link=_par
0330   65 6e 74 2f 5f 6a 6c 6f 66 66 3d 31 2f 70 61 67  ent/_jloff=1/pag
0340   65 3d 2f 3b 20 42 41 53 4b 45 54 5f 43 6f 6f 6b  e=/; BASKET_Cook
0350   69 65 3d 70 61 79 6d 65 6e 74 25 33 44 25 32 36  ie=payment%3D%26
0360   70 61 79 6d 65 6e 74 5f 69 64 25 33 44 25 32 36  payment_id%3D%26
0370   6d 6f 6e 65 79 25 33 44 25 32 36 72 65 66 5f 75  money%3D%26ref_u
0380   72 6c 25 33 44 25 32 36 72 65 66 5f 69 64 25 33  rl%3D%26ref_id%3
0390   44 25 32 36 72 65 67 69 73 74 25 33 44 3b 20 5f  D%26regist%3D; _
03a0   5f 75 74 6d 61 3d 32 32 35 32 33 31 38 37 37 2e  _utma=225231877.
03b0   31 39 30 39 30 37 38 31 33 38 2e 31 32 38 33 32  1909078138.12832
03c0   37 34 35 37 32 2e 31 32 38 33 39 31 32 32 31 34  74572.1283912214
03d0   2e 31 32 38 33 39 34 32 33 35 38 2e 32 39 3b 20  .1283942358.29; 
03e0   5f 5f 75 74 6d 63 3d 32 32 35 32 33 31 38 37 37  __utmc=225231877
03f0   3b 20 5f 5f 75 74 6d 76 3d 32 32 35 32 33 31 38  ; __utmv=2252318
0400   37 37 2e 4d 65 6d 62 65 72 3b 20 5f 5f 75 74 6d  77.Member; __utm
0410   62 3d 32 32 35 32 33 31 38 37 37 2e 33 2e 31 30  b=225231877.3.10
0420   2e 31 32 38 33 39 34 32 33 35 38 3b 20 49 4e 54  .1283942358; INT
0430   5f 53 45 53 49 44 3d 41 67 34 45 58 42 6b 56 44  _SESID=Ag4EXBkVD
0440   77 52 65 52 6a 5a 37 49 68 6f 49 46 56 39 57 56  wReRjZ7IhoIFV9WV
0450   67 4d 54 4f 67 41 69 62 6b 51 44 52 44 4a 33 65  gMTOgAibkQDRDJ3e
0460   45 45 69 64 58 55 4b 44 51 46 57 66 69 55 6c 49  EEidXUKDQFWfiUlI
0470   6e 4d 65 47 67 67 56 58 31 46 59 47 32 49 33 64  nMeGggVX1FYG2I3d
0480   54 5a 6a 45 41 35 61 57 51 63 46 43 6c 41 4e 42  TZjEA5aWQcFClANB
0490   46 56 57 58 67 49 4d 46 31 35 54 43 45 51 61 43  FVWXgIMF15TCEQaC
04a0   43 68 65 46 31 67 41 43 30 46 39 4b 6d 4e 74 5a  CheF1gAC0F9KmNtZ
04b0   6e 59 77 66 33 4d 51 57 46 55 4b 58 6c 67 64 52  nYwf3MQWFUKXlgdR
04c0   67 31 56 56 56 6b 51 41 6b 31 44 43 67 77 48 41  g1VVVkQAk1DCgwHA
04d0   30 31 59 44 46 70 47 44 45 45 50 41 31 6b 55 46  01YDFpGDEEPA1kUF
04e0   51 6b 51 44 67 4e 63 51 44 4e 38 63 30 5a 66 45  QkQDgNcQDN8c0ZfE
04f0   41 68 58 41 51 6c 45 55 78 4d 7a 65 48 34 51 64  AhXAQlEUxMzeH4Qd
0500   53 56 79 58 6c 70 55 41 48 39 32 63 79 4a 31 53  SVyXlpUAH92cyJ1S
0510   45 52 5a 46 51 38 4f 58 6b 59 4f 56 77 74 61 56  ERZFQ8OXkYOVwtaV
0520   68 51 36 44 51 59 62 43 68 41 4f 56 51 55 49 46  hQ6DQYbChAOVQUIF
0530   33 64 53 42 67 64 57 45 51 5a 64 45 46 63 45 51  3dSBgdWEQZdEFcEQ
0540   78 56 66 46 31 6b 48 58 42 70 58 42 44 6f 4e 42  xVfF1kHXBpXBDoNB
0550   68 73 4b 45 41 35 56 44 52 41 47 45 56 68 46 44  hsKEA5VDRAGEVhFD
0560   51 70 5a 46 6c 77 48 45 52 4a 62 56 67 6b 42 51  QpZFlwHERJbVgkBQ
0570   51 6b 56 41 67 64 63 52 39 57 55 67 39 74 42 44  QkVAgdcR9WUg9tBD
0580   78 63 4e 43 77 38 52 42 56 39 46 51 52 64 61 55  xcNCw8RBV9FQRdaU
0590   51 73 48 52 41 35 45 58 6c 42 5a 45 4b 48 57 25  QsHRA5EXlBZEKHW%
05a0   32 42 72 46 48 58 78 45 44 41 46 73 4f 52 6b 52  2BrFHXxEDAFsORkR
05b0   54 57 45 4d 50 55 32 68 58 44 56 56 53 43 67 63  TWEMPU2hXDVVSCgc
05c0   35 55 31 73 46 41 30 45 4a 42 41 49 43 58 52 5a  5U1sFA0EJBAICXRZ
05d0   65 55 77 77 4c 51 56 55 44 55 6d 31 55 52 78 64  eUwwLQVUDUm1URxd
05e0   54 52 45 59 43 51 46 6b 4a 44                    TREYCQFkJD

0000   00 3a 9d 19 67 58 02 ff 65 6a 26 cc 08 00 45 00  .:..gX..ej&...E.
0010   00 7f 7c 44 40 00 80 06 5d bb c0 a8 00 03 cb d1  ..|D@...].......
0020   93 fc 09 89 00 50 f0 56 e9 53 14 b3 85 d4 50 18  .....P.V.S....P.
0030   80 00 3c 86 00 00 45 51 4f 56 56 35 55 57 45 38  ..<...EQOVV5UWE8
0040   62 3b 20 6c 69 63 65 6e 73 65 55 49 44 3d 36 77  b; licenseUID=6w
0050   51 41 4f 73 41 41 45 6c 6f 67 63 49 41 41 41 41  QAOsAAElogcIAAAA
0060   78 3b 20 63 68 65 63 6b 5f 64 6f 6e 65 5f 6c 6f  x; check_done_lo
0070   67 69 6e 3d 31 3b 20 63 68 65 63 6b 5f 6f 70 65  gin=1; check_ope
0080   6e 5f 6c 6f 67 69 6e 3d 31 0d 0a 0d 0a           n_login=1....

572	7.348157	192.168.0.3	203.209.147.252	HTTP	GET /remotepage/-/navi/=/loginoutpath=aHR0cDovL2F1Y3Rpb24uZG1tLmNvbS8=/link=_parent/_jloff=1/page=footer/ HTTP/1.1 
:gXej&E|D@]PVSP<EQOVV5UWE8b; licenseUID=6wQAOsAAElogcIAAAAx; check_done_login=1; check_open_login=1

572	7.348157	192.168.0.3	203.209.147.252	HTTP	GET /remotepage/-/navi/=/loginoutpath=aHR0cDovL2F1Y3Rpb24uZG1tLmNvbS8=/link=_parent/_jloff=1/page=footer/ HTTP/1.1 
hostname
自動入札
203.209.146.218	HTTP	POST /my-autobid-add.php?auctionid=21355&userID=D100dr2mv5bv&nickname=saki21 HTTP/1.1  (application/x-www-form-urlencoded)
minimum_price=2000&maximum_price=10000&number_of_bids=2&auction_id=21355&dateset=&MM_insert=form1
203.209.146.218	HTTP	GET /auction/-/detail/=/aid=21355/result=BBREVgRfBVNcAVRc HTTP/1.1 
203.209.146.218	HTTP	GET /css/dd.css HTTP/1.1 
203.209.146.218	HTTP	GET /css/base.css HTTP/1.1 
203.209.146.218	HTTP	GET /js/jquery.js HTTP/1.1 
203.209.146.218	HTTP	GET /js/jquery.jsonp.js HTTP/1.1 
203.209.146.218	HTTP	GET /js/effect.js HTTP/1.1 
203.209.146.218	HTTP	GET /js/auction.js HTTP/1.1 
203.209.146.218	HTTP	GET /ap.css HTTP/1.1 
203.209.146.218	HTTP	GET /getUserStats.php?userId=D100dr2mv5bv HTTP/1.1 
203.209.146.232	HTTP	POST /my-autobid-add.php?auctionid=21355&userID=D100dr2mv5bv&nickname=saki21 HTTP/1.1  (application/x-www-form-urlencoded)
minimum_price=4000&maximum_price=20000&number_of_bids=2&auction_id=21355&dateset=&MM_insert=form1

分析中
	http and ip.src == 192.168.0.3
sts,his
236,233
234,232
235,218
232,234
234,232
237,232

分析中
	http and ip.dst == 203.209.146.236
ログイン管理はどうやっているか！

IP アドレス変更のメカニズム

218,237
233,237
234,217
app,Text (IP 最下位　Byte)
237,233
235,217
234,217
237,233
234,232
237,217
237,232
236,218
234,218

auction.dmm.com　203.209.146.233　(text/html)
subauction.dmm.com 203.209.146.237
	ok4.pcap
	http and ip.dst == 192.168.0.3
	  source
	    203.209.246.346 HTTP/1.1 200 OK  (application/json)
		203.209.246.217 HTTP/1.1 200 OK  (text/html)
		203.209.246.236 HTTP/1.1 200 OK  (application/json)
		203.209.246.234 HTTP/1.1 200 OK  (application/json)
		203.209.146.234	[TCP Retransmission] HTTP/1.1 200 OK  (application/json)

Ver 1.2 ソース過剰
        nover 消去
	int nover(int len) { // nestable over
		switch(tx[p + len + 1]) {
		case ' ': case '>': // マッチ
			Int32 n, m, nest, ii;
			String ^key;
			tagend(len);
			switch(tx[i - 1]) {
			default:
				key = tx->Substring(p + 1, len);
				ii = i; 
				do {
					nest = 0;
					n = tx->IndexOf("</" + key + ">", i);
					m = tx->IndexOf("<" + key , ii);
					switch(tx[m + len + 1]) {
						case ' ': case '>': // マッチ
							if (m >= 0 && m < n) {
								nest=1; ii = m + len; i = n + len;
							}
					}
				} while(nest);
				Trace::WriteLine(tx->Substring(p + 1, len));
				if (n >= 0) {
				//	Trace::WriteLine(tx->Substring(p, n - p + len + 2));
					p = n + len + 2;
				}
				Trace::WriteLine("n = " + n.ToString());
				break;
			case '/':; 
				Trace::WriteLine(tx->Substring(p + 1, len));
				Trace::WriteLine("i = " + i.ToString());
				p = i + 1;
			}
			return true;
		}
		return false;
	}
ok3.pcap にトップぺージ参照コマンドを保存  
●デフォルト　(203.209.146.218,217)
GET / HTTP/1.1
Host: auction.dmm.com
connection: Keep-Alive
●Chrome (203.209.146.232)
Host: auction.dmm.com
connection: Keep-Alive
user-Agent: Mozilla/5.0 (Windows; U;Windows NT 5.1; en-US)
Applewebkit/533.4
Referre: http://www.dmm.com/digital/pcgame/
Front Page 解析



このファイルには、ok 
アプリケーションを構成する各ファイルの内容の概要が含まれています。

ok.vcxproj
    これは、アプリケーション ウィザードを使用して生成された VC++ 
    プロジェクトのメイン プロジェクト ファイルです。 
    ファイルを生成した Visual C++ のバージョンに関する情報と、アプリケーション 
    ウィザードで選択されたプラットフォーム、
    構成、およびプロジェクト機能に関する情報が含まれています。

ok.vcxproj.filters
    これは、アプリケーション ウィザードで生成された VC++ プロジェクトのフィルター 
    ファイルです。 
    このファイルには、プロジェクト内のファイルとフィルターとの間の関連付けに関する
    情報が含まれています。 
    この関連付けは、特定のノードで同様の拡張子を持つファイルのグループ化を
    示すために IDE で使用されます (たとえば、".cpp" ファイルは "ソース ファイル" 
    フィルターに関連付けられています)。

ok.cpp
    これは、メインのアプリケーション ソース ファイルです。
    フォームを表示するコードが含まれています。

MainForm.h
    フォーム クラスと InitializeComponent() 関数の実装が含まれています。

AssemblyInfo.cpp
    アセンブリ メタデータを変更するカスタム属性が含まれています。

/////////////////////////////////////////////////////////////////////////////
その他の標準ファイル :

StdAfx.h、StdAfx.cpp
    これらのファイルは、ok.pch 
    という名前のプリコンパイル済みヘッダー (PCH) ファイルと、StdAfx.obj 
    という名前のプリコンパイル済みの型ファイルを構築するために使用されます。

/////////////////////////////////////////////////////////////////////////////
