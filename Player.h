#pragma once

const int PLAY_X_DEF = 500;
const int PLAY_Y_DEF = 400;
const int PLAY_HP = 500;


const int PLAY_SPEED = 2.5;

const int PLAY_TOTAL_GRAPH = 390;		//画像の総分割数(スプレットシート)
const int PLAY_GRAPH_WIDTH = 30;		//画像の横分割数
const int PLAY_GRAPH_HIGHT = 13;			//画像の縦分割数
const int PLAY_GRAPH_WIDTH_SIZE = 288;	//分割した画像の横のサイズ
const int PLAY_GRAPH_HIGHT_SIZE = 128;	//分割した画像の縦のサイズ
const int PLAY_XSIZE = 600;				//プレイヤーの横拡大サイズ
const int PLAY_YSIZE = 300;				//プレイヤーの縦拡大サイズ



class Boss;

class Player
{
public:

	int plyGraph[390];
	float playX;
	float playY;
	float plyHP;
	int HPcolor;
	float ColorR;
	float ColorG;
	float ColorB;

	bool dir;//向き

	int MVAnim;//ムーブ、移動アニメーション
	int NLAnim;
	int Anim;

	int mode;//モーションの状態

	void Init();
	void Update(Boss& boss);
	void Draw();


};
