#ifndef MODULE_H
#define MODULE_H

#include <QString>

class ModuleInterface 
{
public:
    virtual QString getDisplayName() = 0;
    virtual int getId() = 0;

};

#define MOUDLE_INIT(type) \
extern "C"{ \
   Q_DECL_EXPORT ModuleInterface * crateModule(int id,const QString &name){return new type(id,name);}\
   Q_DECL_EXPORT void destoryModule(ModuleInterface * p){if(p) {delete p; p = NULL;}}\
};

#endif
