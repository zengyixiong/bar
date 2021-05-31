#ifndef SYSDATA_H
#define SYSDATA_H
#include <QObject>
#include <QMutex>
#include "common_global.h"
#include <QMap>
#include <QVariant>
#include <QFile>
#include <QDate>
#include <QTextCodec>
#include <QVector>
#include "../include/commonDefine.h"

enum LogType
{
	LOGTEXT = 0,
	LOGIMG = 1,
	LOGCSV = 2,
};

class COMMON_EXPORT WKSysData : public QObject
{
	Q_OBJECT
public:
	WKSysData();
	~WKSysData();

	static WKSysData * instance();
	void loadQss(const QString &fileName);
	QVariant getData(const QString &key, QVariant defaultValue = 0);
	void setData(const QString &key, const QVariant &data);

	void sleepTime(int msec);

	void logText(void* data);
	void logData(void* data);
	void logImage(void* data);
	void deleteHistory();

	//logImg×¢²á
	void registerLogImg(void* pLog) { m_fLogImg = (pLogImg)pLog; }
	//logText×¢²á
	void registerLogText(void* pLog) { m_fLogText = (pLogText)pLog; }
	//logData×¢²á
	void registerLogData(void* pLog) { m_fLogData = (pLogData)pLog; }

	void addLog(int state, QString log);
	QString getLog(int state);

private:
	static WKSysData* _pinstance;
	static bool _destory;
	QMutex m_mutex;
	QMap<QString, QVariant> m_data;
	QMap<int, QString> m_logList;
	QDate* m_pcurDate;
	QFile* m_pLogFile;
	QString m_dataDir;
	QString m_logImageDir;
	QFile* m_pCsvFile;

	pLogImg m_fLogImg;
	pLogText m_fLogText;
	pLogData m_fLogData;

private:
	static void destory();
	void checkDirDate(int type);
	void deleteDir(const QString &strDir);

	bool logText1(void* data);
	bool logData1(void* data);
	bool logImage1(void* data);

};

#define ySystem WKSysData::instance()

#endif // SYSDATA_H