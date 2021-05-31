#ifndef DEBUGFUN_H
#define DEBUGFUN_H
#include <QObject>
#include "common_global.h"
#include <QElapsedTimer>

class COMMON_EXPORT DebugFun : public QObject
{
	Q_OBJECT

public:
	DebugFun();
	~DebugFun();

	static DebugFun *instance();
	//用于程序段计时统计
	void startCaliTimer();
	double stopCaliTimer();
	//系统日志输出
	static void sysMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:
	static DebugFun* _pInstance;
	static bool _destory;
	QElapsedTimer m_mstimer;
	double m_runTime;

private:
	static void destory();
};

#define yDebug DebugFun::instance()

#endif
