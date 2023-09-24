#pragma once

class bodyStr{
public:
	dBodyID	b;		//ボディのID
	int		e;		//ボディ有効
	dGeomID	g;		//ジオメトリのID
	int		ge;		//ジオメトリ設定 有/無
	char		k;		//ボディの種類
	char		c;		//色の種類
	double	l;		//長さ
	double	w;		//幅
	double	h;		//高さ
	double	r;		//半径
};

class jointStr{
public:
	dJointID j;		//ジョイントID
	char		k;		//ジョイントの種類
	int		e;		//ジョイント有効
	double	x;		//X座標
	double	y;		//Y座標
	double	z;		//Z座標
	double	dn;		//下限角度
	double	up;		//上限角度
	double	t;		//関節角度
	double	t2;		//関節2角度(ユニバーサル時)
	double	tm;		//最大角速度
	double	tm2;		//最大角速度
	double	tk;		//関節トルク
	double	tk2;		//関節トルク
	int		s;		//特別制御フラグ(1の場合、歩行制御特別ジョイント)
	int		c;		//汎用カウンタ
	int		mode;	//駆動モード
	int		pn;		//足圧力カウンタ
	int		sv;		//サーボ識別
};

extern double fbRad;	//頭前後角度		前が-
extern double lrRad;	//頭左右角度		右が-
extern double fbAV;	//頭前後角速度	前が+
extern double lrAV;	//頭左右角速度	右が+


