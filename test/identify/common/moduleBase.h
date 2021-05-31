#ifndef MODULEBASE_H
#define MODULEBASE_H

#include "../include/Module.h"
#include "Common_global.h"

class COMMON_EXPORT ModuleBase : public ModuleInterface
{
public:
	ModuleBase(int id, const QString &name);
	virtual ~ModuleBase();

	virtual QString getDisplayName();
	virtual int getId();

private:
	int m_id;
	QString m_name;
};

#endif // MODULEBASE_H
