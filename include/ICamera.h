#ifndef ICAMERA_H
#define ICAMERA_H

enum TriggerMode
{
	ContinueTrigger,         // 连续触发
	SoftwareTrigger,         // 软触发
	ExternalTrigger          // 外触发
};

enum ExternalTriggerType
{
	RisingEdgeTrigger,       // 上升沿触发
	FallingEdgeTrigger,      // 下降沿触发
	HighLevelTrigger,        // 高电平触发，高电平期间一直曝光，直到变为低电平结束曝光
	LowLevelTrigger          // 低电平触发，低电平期间一直曝光，直到变为高电平结束曝光
};

enum LutMode
{
	DynamicLut,              // 通过调节伽马和对比度动态生成LUT表
	PresetLut,               // 使用相机预设的LUT表
	CustomLut                // 使用自定义的LUT表
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

	// 曝光
	virtual void exposureTimeRange(int &min, int &max) = 0;
	virtual void exposureTimeStep(int &step) = 0;
	virtual int exposureTime() = 0;
	virtual bool setExposureTime(int value) = 0;

	// 增益
	virtual void gainRange(int &min, int &max) = 0;
	virtual void gainStep(int &step) = 0;
	virtual int gain() = 0;
	virtual bool setGain(int value) = 0;

	// 触发模式
	virtual int triggerMode() const = 0;
	virtual bool setTriggerMode(int mode) = 0;

	// 外触发模式
	virtual int externalTriggerType() = 0;
	virtual bool setExternalTriggerType(int type) = 0;

	// 外触发延时 微秒
	virtual int externalTriggerDelayTime() = 0;
	virtual bool setExternalTriggerDelayTime(int usecs) = 0;

	// 色温模式
	virtual void colorTempRange(int &min, int &max) = 0;
	virtual int colorTempMode() const = 0;
	virtual bool setColorTempMode(int value) = 0;

	// 查表变换LUT模式
	virtual int lutMode() = 0;
	virtual bool setLutMode(int mode) = 0;

	// 查表变伽马参数
	virtual int lutGamma() = 0;
	virtual bool setLutGamma(int value) = 0;

	// 查表变对比度参数
	virtual int lutContrast() = 0;
	virtual bool setLutContrast(int value) = 0;

	virtual bool loadCfg() = 0;
};

#endif