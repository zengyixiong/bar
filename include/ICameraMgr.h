#ifndef ICAMERAMGR_H
#define ICAMERAMGR_H
#include "ICamera.h"

class ICameraMgr
{
public:
	virtual void reloadCam() = 0;
	virtual int getCameraNum() = 0;
	virtual QStringList getCamList() = 0;
	virtual ICamera* getCamera(const QString &strId) = 0;
	virtual void releaseCameraAll() = 0;
	virtual void showDlg() = 0;
};

#endif