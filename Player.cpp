#include"Player.h"
#include"DxLib.h"
#include"Enemy.h"

void Player::Init()
{
	LoadDivGraph("data/texture/player.png", PLAY_TOTAL_GRAPH, PLAY_GRAPH_WIDTH, PLAY_GRAPH_HIGHT, PLAY_GRAPH_WIDTH_SIZE, PLAY_GRAPH_HIGHT_SIZE, plyGraph);
	playX = PLAY_X_DEF;
	playY = PLAY_Y_DEF;
	plyHP = PLAY_HP;
	ColorR = 0;
	ColorG = 255;
	ColorB = 0;
	HPcolor = GetColor(ColorR, ColorG, ColorB);

	mode = 0;
	dir =1;

	Anim = 0;
	MVAnim = 30;
	NLAnim = 0;
}

void Player::Update(Boss&boss)
{
	if (CheckHitKey(KEY_INPUT_A))
	{
		dir = 0;
		mode = 1;
		playX -= PLAY_SPEED;
		Anim++;
	}
	else if (CheckHitKey(KEY_INPUT_D))
	{
		dir = 1;
		mode = 1;
		playX += PLAY_SPEED;
		Anim++;
		
	}
	else
	{
		mode = 0;
		Anim++;
	}

	if (CheckHitKey(KEY_INPUT_LSHIFT))
	{
		mode = 1;

		if (dir == 0)
		{
			Anim += 3;//アニメーション速度
			playX-= PLAY_SPEED*5;
		}
		else if (dir == 1)
		{
			Anim += 3;
			playX += PLAY_SPEED * 5;
		}
		


	}
	

	if (mode == 0)
	{
		if (Anim > 10)//アニメーションの速度（画像の切り替え速度）
		{
			NLAnim++;
			Anim = 0;
		}

		if (NLAnim > 7)
		{

			NLAnim = 0;
		}
	}
	else if (mode == 1)
	{
		if (Anim > 10)//アニメーションの速度（画像の切り替え速度）
		{
			MVAnim++;
			Anim = 0;
		}

		if (MVAnim > 37)
		{

			MVAnim = 30;
		}
	}
	

	if(boss.bossX)

	
	//HPゲージ仮
	plyHP-=0.5;
	if (plyHP < 10)
	{
		plyHP = 500;
		ColorR = 0;
		ColorG = 255;
		ColorB = 0;
	}

	if (plyHP < 100)
	{
		ColorR = 255;
		ColorG = 0;
		ColorB = 0;
	}
	else if(plyHP < 200)
	{
		ColorR = 255;
		ColorG = 182;
		ColorB = 0;
	}
	else if (plyHP < 300)
	{
		ColorR = 255;
		ColorG = 255;
		ColorB = 0;
	}
	
	
	
	HPcolor = GetColor(ColorR, ColorG, ColorB);
}

void Player::Draw()
{
	//DrawGraph(playX, playY, plyGraph[0],TRUE);
	if (mode == 0)
	{
		DrawExtendGraph(playX, playY, playX+ PLAY_XSIZE, playY+ PLAY_YSIZE,plyGraph[NLAnim],TRUE);
	}
	else if (mode == 1)
	{
		DrawExtendGraph(playX, playY, playX + PLAY_XSIZE, playY + PLAY_YSIZE, plyGraph[MVAnim], TRUE);
	}
	
	DrawBox(100, 50, 610, 100,GetColor(60,60,60),TRUE);
	DrawBox(110, 55, 600, 95, GetColor(150, 30, 30), TRUE);
	DrawBox(110, 55, 100+plyHP, 95, HPcolor, TRUE);
	

}