#ifndef MODULEMGR_H
#define MODULEMGR_H

#include <QMap>
#include "../include/Module.h"
#include "Common_global.h"
#include <QLibrary>

class COMMON_EXPORT ModuleMgr : public QObject
{
	Q_OBJECT

protected:
	ModuleMgr();

public:
	~ModuleMgr();

	static ModuleMgr * instance();
	static ModuleInterface * loadPlugin(const QString &dllfile, int id, const QString &name);
	static void removePlugin(int id);

	QList<int> getModelIdList();
	ModuleInterface * getModule(int id);
	void addModlue(ModuleInterface * pMoudle);
	void removeModlue(ModuleInterface * pMoudle);

private:
	ModuleInterface * loadModule(const QString &dllfile, int id, const QString &name);
	void freeModule(int id);

protected:
	static void destory();

private:
	QMap<int, ModuleInterface *> m_moduleList;
	QMap<int, QLibrary*> m_moduleLib;

	static ModuleMgr * _instance;
	static bool _bDestory;
};

template<typename T>
T * getModule(int moduleId) {
	ModuleMgr * _pMgr = ModuleMgr::instance();
	if (_pMgr)
	{
		return dynamic_cast<T*>(_pMgr->getModule(moduleId));
	}
	return NULL;
}

#endif
