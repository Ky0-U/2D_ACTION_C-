//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include"DxLib.h"
#include"Enemy.h"
#include"Player.h"


//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(1920, 1080, 16);		// �𑜓x��640*480�Acolor��16bit�ɐݒ�.
	ChangeWindowMode(FALSE);			// �E�C���h�E���[�h��ύX(FALSE���t���N���[��)

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	//�C���X�^���X��
	Boss *boss = new Boss();
	Player* play = new Player();

	//������
	play->Init();
	boss->Init();


	// �Q�[�����[�v.
	while (1)
	{

		// ��ʂ�������(�^�����ɂ���)
		ClearDrawScreen();

		play->Update(*boss);
		boss->Update(*play);

		play->Draw();
		boss->Draw();



		// ����ʂ̓��e��\��ʂɃR�s�[����i�`��̊m��j.
		ScreenFlip();

		// Windows ���L�̖ʓ|�ȏ������c�w���C�u�����ɂ�点��
		// �}�C�i�X�̒l�i�G���[�l�j���Ԃ��Ă����烋�[�v�𔲂���
		if (ProcessMessage() < 0)
		{
			return 0;					// �\�t�g�̏I��
		}
		// �����d�r�b�L�[��������Ă����烋�[�v���甲����
		else if (CheckHitKey(KEY_INPUT_ESCAPE))
		{

			return 0;					// �\�t�g�̏I��
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;					// �\�t�g�̏I��
}
