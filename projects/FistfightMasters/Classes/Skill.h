#pragma once
#include "RPGHead.h"
#include "RoleData.h"
#include "BattleRole.h"

class Skill : public Object
{
public:
	Skill(void);
	~Skill(void);

	virtual bool init(SkillData *_skillData);

	virtual void start(BattleRole* srcRole);

	virtual void doDamage();

	virtual const int getDamage() const;

	virtual void getCanAttackRoles();

	virtual Vector<Point> getCanAttackGrids();

protected:
	/** �������� */
	SkillType _skillType;

	/** ������Χ������ */
	SkillAttackType _skillAttackType;

	/** ������Ŀ�� */
	Vector<BattleRole*> _targetRoles;

	/** ������ */
	BattleRole *_srcRole;

	/** �������� */
	SkillData *_skillData;
};

