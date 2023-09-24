/*
June 1,2021
Delete variable K2Ｗ[2]
*/

#pragma once

extern double K0W[2];			//股関節前後方向書込用
extern double K1W[2];			//股関節横方向書込用
//extern double K2W[2];		//股関節ヨー軸方向書込用
extern double HW [2];			//膝関節書込用
extern double A0W[2];			//足首上下方向書込用
extern double A1W[2];			//足首横方向書込用
extern unsigned char walkF;	//歩行フラグ	（b0:歩行  b1:未  b2:未）
extern double asiPress_r;		//右足裏圧力
extern double asiPress_l;		//左足裏圧力
extern int uvcOff;			//UVC歩行フラグ

class core{
	public:
	float dx[2];				//前後方向脚位置
	unsigned char jikuasi;
	float adjFR;				//前後調整値
	float autoH;				//高さ自動調整
	float autoHs;			//高さ自動調整
	float fw;				//中心からの振り出し股幅
	short mode;
	unsigned char sw;		//横振り距離
	unsigned char swf;		//横振り最大距離
	float fwr0;				//中心からの戻り股幅(軸足)
	float fwr1;				//中心からの戻り股幅(遊脚)
	float landRate;			//0.1一歩の内、両足接地期間の割合
	short fwctEnd;			//一周期最大カウント数
	short fwct;				//一周期カウンタ
	float fh;				//足上げ高さ指示
	short fhMax;				//足上げ最大高さ
	float dy;				//横振り距離
	float dxi;				//縦距離積分値
	float dyi;				//横距離積分値
	float pitch;
	float roll;

	void footCont(float x,float y,float h,int s);
	void walk(void);
	core(void);
	~core(void);
};


