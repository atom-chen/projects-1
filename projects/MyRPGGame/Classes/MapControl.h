#pragma once
#include "RPGHead.h"
#include "Role.h"

#define MAX_MOVE_X			 50

// �ƶ�һ����������ʱ��
#define MAX_MOVE_TIME		 1


typedef enum CameraType
{
	// ��ͷ�����������
	camera_none,

	// ��ͷ��Ӣ�ۿ���
	camera_hero,
};

class MapControl : public Role
{
public:
	MapControl(void);
	~MapControl(void);

	bool init();

	void load();

	void update(float dt);

	Point getRoleCenterPoint() const;

	bool cameraTo(const Point point, float delayTime=0.5f, bool force=false);

	void cameraToRole();
	
	void cameraOver();

	bool cameraMoving();

	void setCameraType(CameraType type);

	static MapControl* getInstance();

	Size getMapSize();

private:

	Size _size;
	
	Point _off;

	CameraType _cameraType;

	bool _cameraMoving;
};

