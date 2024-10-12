#pragma once
const int BOSS_X_DEF = 1000;			//�{�X����X���W
const int BOSS_Y_DEF = 400;				//�{�X����Y���W
const int COOL_TIME = 300;				//������ڏ��
const int BOSS_TOTAL_GRAPH = 110;		//�摜�̑�������(�X�v���b�g�V�[�g)
const int BOSS_GRAPH_WIDTH = 22;		//�摜�̉�������
const int BOSS_GRAPH_HIGHT = 5;			//�摜�̏c������
const int BOSS_GRAPH_WIDTH_SIZE = 288;	//���������摜�̉��̃T�C�Y
const int BOSS_GRAPH_HIGHT_SIZE = 160;	//���������摜�̏c�̃T�C�Y
const int BOSS_XSIZE = 700;				//�{�X�̉��g��T�C�Y
const int BOSS_YSIZE = 400;				//�{�X�̏c�g��T�C�Y




class Player;

class Boss
{
public:
	
	float bossX;//�{�X��X���W
	float bossY;//�{�X��Y���W

	//�ʏ�
	int bossGraph[BOSS_TOTAL_GRAPH];//�ʏ�̃{�X�O���t�@��������0-21
	int NLAnim;//�m�[�}���A�����A�j���[�V����
	int MVAnim;//���[�u�A�ړ��A�j���[�V����
	int BTAnim;//�o�g���A�o�g���A�j���[�V�����u
	
	


	//���]�p
	int bossReGraph[BOSS_TOTAL_GRAPH];//���]�������{�X�O���t�@��������21-0
	int ReNLAnim;//�m�[�}���A���]�����A�j���[�V����
	int ReMVAnim;//���[�u�A���]�ړ��A�j���[�V����
	int ReBTAnim;//�o�g���A���]�o�g���A�j���[�V����

	//�J�E���g�擾�p�ϐ�
	int MVCoolTime;//�ړ��̃N�[���^�C��
	int count;//�t���[���擾�ϐ�
	int Anim;//�A�j���[�V�����t���[���擾�ϐ�
	int select;//���[�V�����̎�ނ����肷��ϐ�
	bool dir;//�摜�̌���


	void Init();
	void Update(Player&player);
	void Draw();

	
};
