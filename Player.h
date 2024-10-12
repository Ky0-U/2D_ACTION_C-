#pragma once

const int PLAY_X_DEF = 500;
const int PLAY_Y_DEF = 400;
const int PLAY_HP = 500;


const int PLAY_SPEED = 2.5;

const int PLAY_TOTAL_GRAPH = 390;		//�摜�̑�������(�X�v���b�g�V�[�g)
const int PLAY_GRAPH_WIDTH = 30;		//�摜�̉�������
const int PLAY_GRAPH_HIGHT = 13;			//�摜�̏c������
const int PLAY_GRAPH_WIDTH_SIZE = 288;	//���������摜�̉��̃T�C�Y
const int PLAY_GRAPH_HIGHT_SIZE = 128;	//���������摜�̏c�̃T�C�Y
const int PLAY_XSIZE = 600;				//�v���C���[�̉��g��T�C�Y
const int PLAY_YSIZE = 300;				//�v���C���[�̏c�g��T�C�Y



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

	bool dir;//����

	int MVAnim;//���[�u�A�ړ��A�j���[�V����
	int NLAnim;
	int Anim;

	int mode;//���[�V�����̏��

	void Init();
	void Update(Boss& boss);
	void Draw();


};
