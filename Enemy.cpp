#include"Enemy.h"
#include"DxLib.h"
#include"Player.h"

void Boss::Init()
{
	LoadDivGraph("data/texture/Boss.png", BOSS_TOTAL_GRAPH, BOSS_GRAPH_WIDTH, BOSS_GRAPH_HIGHT, BOSS_GRAPH_WIDTH_SIZE, BOSS_GRAPH_HIGHT_SIZE,bossGraph);
	LoadDivGraph("data/texture/BossRe.png", BOSS_TOTAL_GRAPH, BOSS_GRAPH_WIDTH, BOSS_GRAPH_HIGHT, BOSS_GRAPH_WIDTH_SIZE, BOSS_GRAPH_HIGHT_SIZE, bossReGraph);
	bossX = BOSS_X_DEF;
	bossY = BOSS_Y_DEF;
	MVCoolTime = COOL_TIME;

	NLAnim = 0;
	MVAnim =22;
	BTAnim = 0;
	count = 0;
	select = 1;
	Anim = 0;
	dir = 0;

	ReNLAnim = 21;
	ReMVAnim = 43;
	ReBTAnim = 0;
}

void Boss::Update(Player& player)
{
	

	Anim++;
	count++;

	if (count > 500)
	{
		count = 0;
	}


	if (MVCoolTime > count)
	{
		select = 1;
		if (player.playX < bossX)
		{
			dir = 0;
			bossX -= 0.5;
		}
		else
		{
			dir = 1;
			bossX += 0.5;
	
		}

		if (Anim > 20)
		{
			Anim = 0;
			MVAnim++;
			ReMVAnim--;
		}
		if (MVAnim > 33)
		{
			MVAnim = 22;
		}
		if (ReMVAnim < 32)
		{
			ReMVAnim = 43;
		}
	}

	if (500 > count && 300 < count)
	{
		select = 0;
		if (Anim > 20)
		{
			Anim = 0;
			NLAnim++;
			ReNLAnim--;
		}


		if (NLAnim > 5)
		{
			NLAnim = 0;
		}
		if (ReNLAnim < 17)
		{
			ReNLAnim = 21;
		}



		if (player.playX < bossX)
		{
			dir = 0;
		}
		else
		{
			dir = 1;

		}

	}
	
	

	
}

void Boss::Draw()
{
	if (select == 0)
	{
		if(dir==0)
		{ 
			DrawExtendGraph(bossX, bossY, bossX + BOSS_XSIZE, bossY + BOSS_YSIZE, bossGraph[NLAnim], TRUE);
			//DrawGraph(bossX, bossY, bossGraph[SBAnim], TRUE);

		}
		else if(dir==1)
		{
			DrawExtendGraph(bossX, bossY, bossX + BOSS_XSIZE, bossY + BOSS_YSIZE, bossReGraph[ReNLAnim], TRUE);
		}
	
	}
	else if (select == 1)
	{
		if (dir == 0)
		{
			DrawExtendGraph(bossX, bossY, bossX + BOSS_XSIZE, bossY + BOSS_YSIZE, bossGraph[MVAnim], TRUE);
			//DrawGraph(bossX, bossY, bossGraph[MVAnim], TRUE);
		}
		else if (dir == 1)
		{
			DrawExtendGraph(bossX, bossY, bossX + BOSS_XSIZE, bossY + BOSS_YSIZE, bossReGraph[ReMVAnim], TRUE);
		}
	}

	
}