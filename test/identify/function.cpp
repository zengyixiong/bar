/********************
author:WeiKe Yao
date:  2019.8.1
********************/
#include "function.h"

bool HObjectToQImage(const HalconCpp::HObject *pHimg, QImage *pQimg)
{
	if (pHimg == nullptr || pQimg == nullptr)
		return false;

	if (!pHimg->IsInitialized())
		return false;

	try
	{
		HTuple hChannels = 0;
		HTuple hWidth = 0;
		HTuple hHeight = 0;
		HTuple hPtr;
		HObject hImage;

		ConvertImageType(*pHimg, &hImage, "byte");
		CountChannels(hImage, &hChannels);

		if (1 == hChannels)
		{
			GetImagePointer1(hImage, &hPtr, nullptr, &hWidth, &hHeight);

			if (pQimg->isNull()
				|| (pQimg->format() != QImage::Format_Indexed8 && pQimg->format() != QImage::Format_Grayscale8)
				|| pQimg->width() != hWidth || pQimg->height() != hHeight)
			{
				*pQimg = QImage(hWidth, hHeight, QImage::Format_Grayscale8);
			}

			uchar *ptr = (uchar *)hPtr[0].L();
			for (int i = 0; i < hHeight; ++i)
			{
				memcpy(pQimg->scanLine(i), ptr, hWidth[0].L());
				ptr += hWidth[0].L();
			}

		}
		else if (hChannels == 3)
		{
			HTuple hPtrG;
			HTuple hPtrB;

			GetImagePointer3(hImage, &hPtr, &hPtrG, &hPtrB, nullptr, &hWidth, &hHeight);

			if (pQimg->format() != QImage::Format_RGBA8888 || pQimg->width() != hWidth || pQimg->height() != hHeight)
			{
				*pQimg = QImage(hWidth, hHeight, QImage::Format_RGBA8888);
			}

			uchar *pR = (uchar *)hPtr[0].L();
			uchar *pG = (uchar *)hPtrG[0].L();
			uchar *pB = (uchar *)hPtrB[0].L();

			uchar *pLine = pQimg->bits();
			int height = hHeight;
			int width = hWidth;

			for (int row = 0; row < height; ++row)
			{
				for (int col = 0; col < width; ++col)
				{
					*pLine++ = *pR++;
					*pLine++ = *pG++;
					*pLine++ = *pB++;
					*pLine++ = 0xFF;
				}
			}
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}

bool QImageToHObject(const QImage *pQimg, HalconCpp::HObject *pHimg)
{
	if (pHimg == nullptr || pQimg == nullptr)
		return false;

	Hlong width = pQimg->width();
	Hlong height = pQimg->height();
	const uchar *pLine = pQimg->bits();

	switch (pQimg->format())
	{
	case QImage::Format_Indexed8:
	case QImage::Format_Grayscale8:
		try
		{
			GenImage1(pHimg, "byte", width, height, (Hlong)pLine);

			if (pQimg->bytesPerLine() != width)
			{
				HTuple hPtr;
				GetImagePointer1(*pHimg, &hPtr, nullptr, nullptr, nullptr);

				uchar *ptr = (uchar *)hPtr[0].L();
				for (int i = 0; i < height; ++i)
				{
					memcpy(ptr, pQimg->scanLine(i), width);
					ptr += width;
				}
			}
		}
		catch (...) { return false; }
		break;
	case QImage::Format_RGB888:
		try
		{
			GenImage3(pHimg, "byte", width, height, (Hlong)pLine, (Hlong)pLine, (Hlong)pLine);

			HTuple hPtrR;
			HTuple hPtrG;
			HTuple hPtrB;
			GetImagePointer3(*pHimg, &hPtrR, &hPtrG, &hPtrB, nullptr, nullptr, nullptr);
			uchar *pR = (uchar *)hPtrR[0].L();
			uchar *pG = (uchar *)hPtrG[0].L();
			uchar *pB = (uchar *)hPtrB[0].L();

			int spaceNum = pQimg->bytesPerLine() - (width * 3);
			for (int row = 0; row < height; ++row)
			{
				for (int col = 0; col < width; ++col)
				{
					*pR++ = pLine[0];
					*pG++ = pLine[1];
					*pB++ = pLine[2];
					pLine += 3;
				}
				pLine += spaceNum;
			}
		}
		catch (...) { return false; }
		break;
	case QImage::Format_RGB32:
	case QImage::Format_RGBX8888:
	case QImage::Format_RGBA8888:
	case QImage::Format_RGBA8888_Premultiplied:
		try
		{
			GenImage3(pHimg, "byte", width, height, (Hlong)pLine, (Hlong)pLine, (Hlong)pLine);

			HTuple hPtrR;
			HTuple hPtrG;
			HTuple hPtrB;
			GetImagePointer3(*pHimg, &hPtrR, &hPtrG, &hPtrB, nullptr, nullptr, nullptr);
			uchar *pR = (uchar *)hPtrR[0].L();
			uchar *pG = (uchar *)hPtrG[0].L();
			uchar *pB = (uchar *)hPtrB[0].L();

			for (int row = 0; row < height; ++row)
			{
				for (int col = 0; col < width; ++col)
				{
					*pB++ = pLine[0];
					*pG++ = pLine[1];
					*pR++ = pLine[2];
					pLine += 4;
				}
			}
		}
		catch (...) { return false; }
		break;
	default:
		return false;
	}

	return false;
}