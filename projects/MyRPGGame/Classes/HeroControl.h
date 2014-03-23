#pragma once
#include "RPGHead.h"
#include "HeroRole.h"
#include "RoleHelper.h"

class HeroControl : public Object
{
public:
	HeroControl(void);
	~HeroControl(void);

	virtual void init(HeroRole *role);

	/**
	* ���ƽ�ɫ�ƶ�
	* speedx speedy ��ɫ�ƶ��ٶ�
	* direct �ƶ������Ƿ�������ֵ��������
	* fast �Ƿ��ǳ����ƶ�
	*/
	virtual void doMove(float speedx, float speedy, RoleDirect direct, bool fast=false);

	virtual void update(float dt);

	virtual void stop();

protected:
	HeroRole *_hero;

	/** �ƶ��ٶ� */
	Point _speed;

	/** �Ƿ����ƶ� */
	bool _fastMove;

	RoleDirect _roleDirect;

};

