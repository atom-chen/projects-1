#include "Skill.h"
#include "BattleRoles.h"


Skill::Skill(void)
	: _skillData(nullptr)
	, _srcRole(nullptr)
	, _skillAttackType(SkillAttackType::attackFront1)
	, _skillType(SkillType::SkillClose)
{
}


Skill::~Skill(void)
{
	CC_SAFE_RELEASE(_skillData);

	CC_SAFE_RELEASE(_srcRole);
}

bool Skill::init(SkillData *skillData)
{
	_skillData = skillData;
	CC_SAFE_RETAIN(_skillData);

	_targetRoles.reserve(5);

	return true;
}

void Skill::start(BattleRole* srcRole)
{
	_srcRole = srcRole;
	CC_SAFE_RETAIN(_srcRole);

	getCanAttackRoles();
}

void Skill::doDamage()
{


}

const int Skill::getDamage() const
{
	return 100;
}


Vector<Point> Skill::getCanAttackGrids()
{
	Vector<Point> grids;
	
	if (!_srcRole) return grids;

	grids.reserve(5);

	Point srcGrid = _srcRole->getGridIndex();
	Point point = Point::ZERO;
	bool isLeft = _srcRole->isLeft();

	int _doFlag = -1;
	int count = 0;

	switch (_skillAttackType)
	{
	case attackFront1:
		_doFlag = 1;
		count = 1;
		break;
	case attackFront2:
		_doFlag = 1;
		count = 2;
		break;
	case attackFront3:
		_doFlag = 1;
		count = 3;
		break;
	case attackFront4:
		_doFlag = 1;
		count = 4;
		break;
	case attackFront5:
		_doFlag = 1;
		count = 5;
		break;
	default:
		break;
	}

	if (_doFlag == 1)
	{
		for(int i=0; i<count; i++)
		{
			point.x = srcGrid.x - i;
			point.y = srcGrid.y;
			bool bounds = CHECK_GRID_BOUNDS(point.x, point.y);
			if (!bounds) grids.pushBack(Point(point));
		}
	}

	return grids;
}

void Skill::getCanAttackRoles()
{
	_targetRoles.clear();

	Vector<Point> grids = getCanAttackGrids();

	for (Point grid : grids)
    {
		BattleRole* role = BattleRoles::getInstance()->getRoleByGrid(grid);
		if (role) _targetRoles.pushBack(role);
    }
}