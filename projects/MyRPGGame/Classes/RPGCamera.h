#pragma once
#include "RPGHead.h"

class RPGCamera : public Object
{
public:
	RPGCamera(void);
	~RPGCamera(void);

	virtual bool init(Size size, Size sceneSize);

	//virtual void update(float dt);

	/**
	* ��⾵ͷ��û�г���
	* return true ���磻return false û�г���
	*/
	virtual bool checkBound(const Point off);

	/**
	* ���þ�ͷ�۲��
	*/
	virtual void setCamera(const Point viewPosition);
	
	/**
	* ���þ�ͷ�۲��
	*/
	virtual void setCamera(float x, float y);

	/**
	* ������ͷ�۲��,���ܳ���
	*/
	virtual Point correctCamera(const Point viewPosition);

protected:

	/**
	* ��ͷ�����ƶ�
	*/
	virtual void updateCamera(const float x, const float y);

protected:
	// ��ͷ��С
	Size _size;

	// ��ͷ������С
	Size _sceneSize;

	// ��ͷƫ����
	Point _off;
	
};

