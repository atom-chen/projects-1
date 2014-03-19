#pragma once

//
// ��ɫ����
//
typedef enum RoleDirect
{
	roleLeft,
	roleRight
};

//
// ��ɫ��������
//
typedef enum RoleAction
{
	// ����
	actionAttack,
	// ������
	actionHurt,
	// ����
	actionWait,
	// �ƶ�
	actionMove,
	// ��
	actionRun,
	// ����
	actionDefense
};


typedef enum ScriptType
{
	scriptRobot
};

struct RoleData
{
	int roleId;
	float px;
	float py;
	ScriptType scriptType;
	RoleData()
	{
		this->roleId = 0;
		this->px = 0;
		this->py = 0;

	}

	RoleData(const int roleId, const float px, const float py, const ScriptType scriptType)
	{
		this->roleId = roleId;
		this->px = px;
		this->py = py;
		this->scriptType = scriptType;
	}
};


