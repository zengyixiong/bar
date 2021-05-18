#ifndef TYPEDEFINE_H
#define TYPEDEFINE_H
#include <QVector>
#include "halconCpp.h"

using namespace HalconCpp;


//注册保存的图像格式
struct logImgStruct
{
	HObject img;
	QString name;
	logImgStruct()
	{
		name = "";
	}
	void reset()
	{
		name = "";
	}
};

//注册保存的日志格式
struct logTextStruct
{
	QString infor;

	logTextStruct()
	{
		infor = "";
	}
};

struct Point3D
{
	float x;
	float y;
	float z;
	uchar r;
	uchar g;
	uchar b;

	Point3D()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
		r = 0;
		g = 0;
		b = 0;
	}

	float getDist()
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	bool Point3D::operator==(const Point3D& a)
	{
		if ((this->x == a.x) && (this->y == a.y) && (this->z == a.z))
			return true;
		else
			return false;
	}
};

struct dataHistory
{
	QString table;
	int		specs;
	QString batchNum;
	QString time;
	int		countNum;
	int		ratedNum;
	QString srcImgName;
	QString retImgName1;
	QString retImgName2;

	dataHistory()
	{
		table = "";
		specs = 0;
		batchNum = "";
		time = "";
		countNum = 0;
		ratedNum = 0;
		srcImgName = "";
		retImgName1 = "";
		retImgName2 = "";
	}
};

enum
{
	LOG_INFO = 0,
	LOG_WARN = 1,
	LOG_ERROR = 2,
	LOG_SEND = 3,
	LOG_RECV = 4
};

enum
{
	DETECT_BARS = 0,
	DETECT_WELDS = 1,
};

#endif