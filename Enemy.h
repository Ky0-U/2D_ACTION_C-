#pragma once
const int BOSS_X_DEF = 1000;			//ボス初期X座標
const int BOSS_Y_DEF = 400;				//ボス初期Y座標
const int COOL_TIME = 300;				//立ちんぼ状態
const int BOSS_TOTAL_GRAPH = 110;		//画像の総分割数(スプレットシート)
const int BOSS_GRAPH_WIDTH = 22;		//画像の横分割数
const int BOSS_GRAPH_HIGHT = 5;			//画像の縦分割数
const int BOSS_GRAPH_WIDTH_SIZE = 288;	//分割した画像の横のサイズ
const int BOSS_GRAPH_HIGHT_SIZE = 160;	//分割した画像の縦のサイズ
const int BOSS_XSIZE = 700;				//ボスの横拡大サイズ
const int BOSS_YSIZE = 400;				//ボスの縦拡大サイズ




class Player;

class Boss
{
public:
	
	float bossX;//ボスのX座標
	float bossY;//ボスのY座標

	//通常
	int bossGraph[BOSS_TOTAL_GRAPH];//通常のボスグラフ　横分割数0-21
	int NLAnim;//ノーマル、立ちアニメーション
	int MVAnim;//ムーブ、移動アニメーション
	int BTAnim;//バトル、バトルアニメーション「
	
	


	//反転用
	int bossReGraph[BOSS_TOTAL_GRAPH];//反転させたボスグラフ　横分割数21-0
	int ReNLAnim;//ノーマル、反転立ちアニメーション
	int ReMVAnim;//ムーブ、反転移動アニメーション
	int ReBTAnim;//バトル、反転バトルアニメーション

	//カウント取得用変数
	int MVCoolTime;//移動のクールタイム
	int count;//フレーム取得変数
	int Anim;//アニメーションフレーム取得変数
	int select;//モーションの種類を決定する変数
	bool dir;//画像の向き


	void Init();
	void Update(Player&player);
	void Draw();

	
};
