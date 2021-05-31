#ifndef FUNCTION_H
#define FUNCTION_H

#include "Halcon.h"
#include "cpp\HalconCpp.h"
#include "halconcpp\HalconCpp.h"
#include <QString>
#include <QImage>
#include "visionmodule_global.h"

using namespace HalconCpp;

bool HObjectToQImage(const HalconCpp::HObject *pHimg, QImage *pQimg);
bool QImageToHObject(const QImage *pQimg, HalconCpp::HObject *pHimg);

#endif