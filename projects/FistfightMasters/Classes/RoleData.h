#pragma once
#include "RPGHead.h"
#include "BattleConfig.h"

// ��������
const int HERO_ANIMI_ACTION_ATTACK = 1;

// վ������
const int HERO_ANIMI_ACTION_STAND = 2;

// ����������
const int HERO_ANIMI_ACTION_HITTED = 3;

// �ƶ�����
const int HERO_ANIMI_ACTION_MOVE = 4;

enum SkillType
{
	// ������
	SkillClose,

	// Զ�̹���
	SkillRemote,
};

enum SkillAttackType
{
	// ������ǰ��1������
	attackFront1,
	// ������ǰ��2������
	attackFront2,
	// ������ǰ��3������
	attackFront3,
	// ������ǰ��4������
	attackFront4,
	// ������ǰ��5������
	attackFront5,
};

struct AnimiAction
{
	int _actionType;
	int _actionIndexs[2];
};

class SkillData : public Object
{
public:
	SkillData(void);

	~SkillData(void);

	bool init(void);

	CREATE_FUNC(SkillData);

public:
	char *_animiName;
	int _animiIndex[2];
};

class RoleData : public Object
{
public:
	RoleData(void);

	~RoleData(void);

	bool init(void);

	void initDatas(Vector<SkillData*> skillDatas, char *_roleAnimiName);

	CREATE_FUNC(RoleData);

public:
	char *_roleAnimiName;

	Vector<SkillData*> _skillDatas;

	/** ��ɫ�����ж��� */
	AnimiAction *_roleAnimiActions;

	int _animiCount;
};

