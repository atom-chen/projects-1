#include "RobotScript.h"

RobotScript::RobotScript(void)
{
}


RobotScript::~RobotScript(void)
{
}


void RobotScript::init(Role *role)
{
	this->_role = role;
	if (_role) _role->retain();
}

Node* RobotScript::createRoleNode()
{
	Armature *armature = Armature::create("robot");
	armature->getAnimation()->playWithIndex(0);
	armature->setPosition(Point(D_display.cx, D_display.cy));
	armature->setScale(0.6f);
	armature->getAnimation()->setSpeedScale(0.5f);
		
	ParticleSystem *p1 = CCParticleSystemQuad::create("Particles/SmallSun.plist");
	ParticleSystem *p2 = CCParticleSystemQuad::create("Particles/SmallSun.plist");

	Bone *bone  = Bone::create("p1");
	bone->addDisplay(p1, 0);
	bone->changeDisplayWithIndex(0, true);
	bone->setIgnoreMovementBoneData(true);
	bone->setLocalZOrder(100);
	bone->setScale(1.2f);
	armature->addBone(bone, "bady-a3");

	bone  = Bone::create("p2");
	bone->addDisplay(p2, 0);
	bone->changeDisplayWithIndex(0, true);
	bone->setIgnoreMovementBoneData(true);
	bone->setLocalZOrder(100);
	bone->setScale(1.2f);
	armature->addBone(bone, "bady-a30");

	return armature;
}

void RobotScript::doScript(float dt)
{
}

void RobotScript::doTouchActions(std::vector<DirectionFlag> directionFlags)
{

}
