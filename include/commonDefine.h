#ifndef COMMONDEFINE_H
#define COMMONDEFINE_H
#include <QFile>

typedef bool (*pLogImg) (void* data);
typedef bool (*pLogText) (QFile* file, void* data);
typedef bool (*pLogData) (QFile* file, void* data);

#endif