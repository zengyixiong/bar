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
	//���ڳ���μ�ʱͳ��
	void startCaliTimer();
	double stopCaliTimer();
	//ϵͳ��־���
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
