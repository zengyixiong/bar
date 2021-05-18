#ifndef ICAMERA_H
#define ICAMERA_H

enum TriggerMode
{
	ContinueTrigger,         // ��������
	SoftwareTrigger,         // ����
	ExternalTrigger          // �ⴥ��
};

enum ExternalTriggerType
{
	RisingEdgeTrigger,       // �����ش���
	FallingEdgeTrigger,      // �½��ش���
	HighLevelTrigger,        // �ߵ�ƽ�������ߵ�ƽ�ڼ�һֱ�ع⣬ֱ����Ϊ�͵�ƽ�����ع�
	LowLevelTrigger          // �͵�ƽ�������͵�ƽ�ڼ�һֱ�ع⣬ֱ����Ϊ�ߵ�ƽ�����ع�
};

enum LutMode
{
	DynamicLut,              // ͨ������٤��ͶԱȶȶ�̬����LUT��
	PresetLut,               // ʹ�����Ԥ���LUT��
	CustomLut                // ʹ���Զ����LUT��
};

#include <QImage>
#include <QSize>

class ICamera
{
public:
	virtual bool open() = 0;
	virtual void close() = 0;
	virtual bool isOpen() const = 0;

	virtual QString id() const = 0;
	virtual int status() = 0;
	virtual QString errorMessage() = 0;

	virtual QSize imageSize() const  = 0;
	virtual int channels() const = 0;

	virtual bool grabImage(QImage &image) = 0;

	// �ع�
	virtual void exposureTimeRange(int &min, int &max) = 0;
	virtual void exposureTimeStep(int &step) = 0;
	virtual int exposureTime() = 0;
	virtual bool setExposureTime(int value) = 0;

	// ����
	virtual void gainRange(int &min, int &max) = 0;
	virtual void gainStep(int &step) = 0;
	virtual int gain() = 0;
	virtual bool setGain(int value) = 0;

	// ����ģʽ
	virtual int triggerMode() const = 0;
	virtual bool setTriggerMode(int mode) = 0;

	// �ⴥ��ģʽ
	virtual int externalTriggerType() = 0;
	virtual bool setExternalTriggerType(int type) = 0;

	// �ⴥ����ʱ ΢��
	virtual int externalTriggerDelayTime() = 0;
	virtual bool setExternalTriggerDelayTime(int usecs) = 0;

	// ɫ��ģʽ
	virtual void colorTempRange(int &min, int &max) = 0;
	virtual int colorTempMode() const = 0;
	virtual bool setColorTempMode(int value) = 0;

	// ���任LUTģʽ
	virtual int lutMode() = 0;
	virtual bool setLutMode(int mode) = 0;

	// ����٤�����
	virtual int lutGamma() = 0;
	virtual bool setLutGamma(int value) = 0;

	// ����ԱȶȲ���
	virtual int lutContrast() = 0;
	virtual bool setLutContrast(int value) = 0;

	virtual bool loadCfg() = 0;
};

#endif