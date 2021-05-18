/**************************************************************************
Copyright owner:ALSON

Author:ALSON

Description:Structured light scanning interface
**************************************************************************/

#ifndef SCAN_PTS_FILE_HEADER_
#define SCAN_PTS_FILE_HEADER_

#include <iostream>
#include <vector>
#include "MacroDefine.h"
#include "Mat.h"
using namespace std;

//
#ifdef _WIN32
#ifdef SCANDLL_EXPORTS
#define SCANDLL_API  __declspec(dllexport)                                 //__declspec(dllexport)
#else
#define SCANDLL_API   __declspec(dllimport)
#endif
#else
#ifdef SCANDLL_EXPORTS
#define SCANDLL_API   __attribute__((visibility("default")))
#else
#define SCANDLL_API   __attribute__((visibility("default")))
#endif
#endif

namespace ALSON
{
	// 导入扫描类
	// Import scan class
	class CScan_Private;

	/*---------------------------------------------------------------------------------
	函数名：				string GetLog(int nState);
	功能：				将返回的int型信息转换成字符信息
	参数1：		<in>	nState  输入状态码值
	返回值：				将int型的状态转换成字符

	Function name:          string GetLog(int nState);
	Function:               Convert the returned int type information to character information
	Parameter1:     <in>	nState  Enter  states code value
	Return value:           int_type state to character
	-----------------------------------------------------------------------------------*/
	extern  SCANDLL_API string GetLog(int nState);

	// 向本地输出日志信息
	// Output log information to Local folder
	extern  SCANDLL_API bool LogInitial(std::string confPath = "");

	/*---------------------------------------------------------------------------------
	点云扫描类
	Point cloud scan class
	-----------------------------------------------------------------------------------*/
	class SCANDLL_API CScan
	{
	public:
		CScan();
		~CScan();

	public:
		/*---------------------------------------------------------------------------------
		函数名：				void SetCameraHeartbeat(int nHeartbeatTime = 10000);
		功能：				设置相机的心跳包，设备相机收不到信号自动断开的时间。调试状态根据实际需求设置时间。正常运行状态设置成3000us。
		参数1：		<in>	nHeartbeatTime  相机的心跳包时间，单位：us。 默认心跳包时间是10000us。
		返回值：				无
		前置函数：			无

		Function name:				void SetCameraHeartbeat(int nHeartbeatTime = 10000);
		Function:					Set the heartbeat package of the camera, when the device camera can't receive the signal to disconnect automatically.
									The debugging status sets the time according to the actual demand. The normal operation state is set to 3000us.
		Parameter1:     <in>		nHeartbeatTime the heartbeat packet time of the camera, unit: US. The default heartbeat packet time is 3000us.
		Return value:				None
		Pre dependent function:		None
		-----------------------------------------------------------------------------------*/
		void SetCameraHeartbeat(int nHeartbeatTime = 10000);

		/*---------------------------------------------------------------------------------
		函数名：				void SetCamUserId(std::vector<int> cam_user_id_vec);
		功能：				设置相机的user_ID
		参数1：		<in>	cam_user_id_vec  输入相机的user_ID。 设备默认相机ID是1和2
		返回值：				无
		前置函数：			无

		Function name:				void SetCamUserId(std::vector<int> cam_user_id_vec);
		Function:					Set user_ID of camera
		Parameter1:     <in>		Enter the user_ID of camera. The default camera ID of the device is 1 and 2.
		Return value:				None
		Pre dependent function:		None
		-----------------------------------------------------------------------------------*/
		void SetCamUserId(std::vector<int> cam_user_id_vec);

		/*---------------------------------------------------------------------------------
		函数名：				void SetSerialCom(int nSerialCom = 1);
		功能：				设置串口通信的端口号
		参数1：		<in>    nSerialCom  端口的序列号  默认端口号1
		返回值：				无
		前置函数：			无

		Function name:				 SetSerialCom(int nSerialCom = 1);
		Function:					 Set serial port number for serial communication
		Parameter1:     <in>		 nSerialCom  serial port number, default port number is 1
		Return value:				 None
		Pre dependent function:      None
		-----------------------------------------------------------------------------------*/
		void SetSerialCom(int nSerialCom);
		void SetSerialCom(string strSerialCom);

		/*---------------------------------------------------------------------------------
		函数名：				void SetDeviceType(string strDeviceType);
		功能：  				设置设备的型号。新款设备自动获取设备型号，老款设备需人工指定设备型号
		参数1：		<in>    strDeviceType  设备型号 {"01C", "02C", "03C"...}。 如果不设置，程序将会自动获取
		返回值：				无
		前置函数：			无

		Function name:				void SetDeviceType(string strDeviceType);
		Function:					Set device model. New device obtains device model autotically, old device needs to manually specify the device model
		Parameter1:     <in>		strDeviceType  device model {"01C", "02C", "03C"...}.  If not set, the program will get automatically
		Return value:				None
		Pre dependent function:     None
		-----------------------------------------------------------------------------------*/
		void SetDeviceType(string strDeviceType);

		/*---------------------------------------------------------------------------------
		函数名				int SetCamParaPath(std::vector<string> cam_Path);
		功能：				设置相机参数文件路径
		参数1：		<in>	cam_Path  相机参数的文件路径。要求按照参数文件的左右顺序以此输入!
		返回值：				返回SUCESS代表成功，否则代表失败，需要检查相机文件是否存在。
		前置函数：			无

		Function name:				int SetCamParaPath(std::vector<string> cam_Path);
		Function:					Set camera parameter file path
		Parameter1:     <in>		cam_Path  camera parameter file path. It is required to input according to the left and right order of parameter file!
		Return value:				Returning success means success, otherwise means failed, you need to check whether the camera file exists.
		Pre dependent function:		None
		-----------------------------------------------------------------------------------*/
		int SetCamParaPath(vector<string> cam_Path);

		/*---------------------------------------------------------------------------------
		函数名：				int ConnectDevice();
		功能：  				连接设备
		返回值：				SUCESS代表成功，其他失败
		前置函数：			1 	int SetCamParaPath(std::vector<string> cam_Path);			必设
							2	void SetCamUserId(std::vector<int> cam_user_id_vec);		设置或默认
							3	void SetSerialCom(int nSerialCom = 1);						设置或默认
							4	void SetDeviceType(string strDeviceType);					设置或默认
							5   void SetCameraHeartbeat(int nHeartbeatTime = 3000);			设置或默认

		Function name:          int ConnectDevice();
		Function:               Connect device
		Return value:           SUCCESS means success, others failure
		Pre dependent function:     1 	int SetCamParaPath(std::vector<string> cam_Path);			Must set
									2	void SetCamUserId(std::vector<int> cam_user_id_vec);		Set or default
									3	void SetSerialCom(int nSerialCom = 1);						Set or default
									4	void SetDeviceType(string strDeviceType);					Set or default
									5   void SetCameraHeartbeat(int nHeartbeatTime = 3000);			Set or default
		-----------------------------------------------------------------------------------*/
		int ConnectDevice();

		/*---------------------------------------------------------------------------------
		函数名：				bool IsDeviceConnect();
		功能：  				返回设备连接状态
		返回值：				true代表连接，false代表未连接
		前置函数：			无

		Function name:				  bool IsDeviceConnect();
		Function:					  Return device connect state
		Return value:				  ture means connected, false means not connected.
		Pre dependent function:       None
		-----------------------------------------------------------------------------------*/
		bool IsDeviceConnect();
		/*---------------------------------------------------------------------------------
		函数名：				int SetImgRect(int nOffset_x = -1, int nOffset_y = -1, int nWidth = -1, int nHeight = -1);
		功能：  				设置左相机的感兴趣区域。
		参数1：		<in>    nOffset_x  ROI的x起点
		参数2：		<in>    nOffset_y  ROI的y起点
		参数3：		<in>    nWidth	   ROI的宽
		参数4：		<in>    nHeight    ROI的高
		返回值：				返回SUCESS代表成功，否则请检查ROI区域是否超出范围。
		前置函数：			ConnectDevice();

		Function name:				int SetImgRect(int nOffset_x = -1, int nOffset_y = -1, int nWidth = -1, int nHeight = -1);
		Function:					Set the region of interest for the left camera.
		Parameter1:     <in>		nOffset_x  ROI's x starting point
		Parameter2:     <in>		nOffset_y  ROI's y starting point
		Parameter3:     <in>		nWidth	   ROI's width
		Parameter4:     <in>		nHeight    ROI's height
		Return value:				success means success, otherwise please check whether the ROI area is out of range
		Pre dependent function:	    ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int SetImgRect(int nOffset_x = -1, int nOffset_y = -1, int nWidth = -1, int nHeight = -1);

		/*---------------------------------------------------------------------------------
		函数名				void SetDecodeThreold(int nDecodeThreold = 4);
		功能：				Set decode threshold
		参数1：		<in>	nDecodeThreold  decode threshold。通过调整解码阈值，可以改变生成点云的区域。该值越小对黑色物体重建点云的能力越强，反之则反。
							"range[0 255]",其含义是光栅图像波峰波谷的差值。
		返回值：				无
		前置函数：			无

		Function name:				void SetDecodeThreold(int nDecodeThreold = 4);
		Function:					Set camera parameter file path
		Parameter1:     <in>		nDecodeThreold  decode threshold.By adjusting the decoding threshold, the region in which the point cloud
									is generated can be changed. The smaller the value is, the stronger the ability of reconstructing point clouds
									for black objects is. Otherwise, it is inverse.
									"range[0 255]", Its meaning is the difference between the peaks and troughs of structured light image.

		Return value:				None
		Pre dependent function:		None
		-----------------------------------------------------------------------------------*/
		void SetDecodeThreold(int nDecodeThreold = 4);

		/*---------------------------------------------------------------------------------
		函数名：				void SetPtsDistRange(int nMinDist , int nMaxDist);
		功能：  				设置点云的最远最近距离，(仅Z方向)
		参数1：		<in>    nMinDist  点云的最近距离  默认为	0mm
		参数2：		<in>    nMaxDist  点云的最远距离  默认为   -6000mm
		返回值：				无
		前置函数：			无

		Function name:				 void SetPtsDistRange(int nMinDist , int nMaxDist);
		Function:					 Set the furthest and closest distance of point cloud.Only in Z axis
		Parameter1:     <in>		 nMinDist  the closest distance of point cloud  the default is 	0mm
		Parameter2:     <in>		 nMaxDist  the furthest distance of point cloud   the default is   -6000mm
		Return value:				 None
		Pre dependent function:      None
		-----------------------------------------------------------------------------------*/
		void SetPtsDistRange(int nMinDist, int nMaxDist);

		/*---------------------------------------------------------------------------------
		函数名：				void CloseDevice();
		功能：  				关闭设备，正常情况下不需要调用这个函数，建议函数异常时在 try catch中调用该函数。
		返回值：				无
		前置函数：			int ConnectDevice();

		Function name:				  CloseDevice();
		Function:					  Close device,This function does not need to be called under nomal circumstances, it is recommended to call the function in try catch when the function is abnormal
		Return value:				  None
		Pre dependent function:       int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		void CloseDevice();

		/*---------------------------------------------------------------------------------
		函数名：				void SetScanExposureTime(double* m_pdExposureTime, int nNum);
		功能：  				设置采集点云曝光时间，可设置多个值。其中获取打光图像时将采取最后一次的曝光时间。
		参数1：		<in>    pdExposureTime  曝光时间，范围 200us - 30000 us。
		参数2：		<in>    nNum  曝光时间的个数,nNum 最大值为6
		返回值：				无
		前置函数：			int ConnectDevice();

		Function name:				void SetScanExposureTime(double* m_pdExposureTime, int nNum);
		Function:					Set acquisition point cloud exposure time, multiple values can be set
		Parameter1:     <in>		pdExposureTime  exoosure time, range is 200us - 30000 us.
		Parameter2:     <in>		nNum  num of exposure time, nNum the maximum value is 6
		Return value:				None
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		void SetScanExposureTime(double* pdExposureTime, int nNum);
		void SetScanExposureTime(int* pnExposureTime, int nNum);
		/*---------------------------------------------------------------------------------
		函数名：				int SetExposureTimeRealtime(double m_pdExposureTime);
		功能：  				设置相机实时曝光时间。
		参数1：		<in>    pdExposureTime  曝光时间 范围 200us - 3000000us
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();

		Function name:				int SetExposureTimeRealtime(double m_pdExposureTime);
		Function:					Set the real-time exposure time of camera
		Parameter1:     <in>		pdExposureTime   exposure time   range is 200us - 3000000us
		Return value:				return SUCCESS means success, others means failure
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int SetExposureTimeRealtime(int nExposureTime);

		/*---------------------------------------------------------------------------------
		函数名：				int GetExposureTime(int& nExposureTime);
		功能：  				获得相机的曝光时间
		参数1：		<out>   nExposureTime  返回曝光时间
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();

		Function name:				 int GetExposureTime(int& nExposureTime);
		Function:					 Get the exposure time of camera
		Parameter1:     <out>		 nExposureTime    return exposure time
		Return value:				 return SUCCESS means success, others means failure
		Pre dependent function:      int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int GetExposureTime(int& nExposureTime);

		/*---------------------------------------------------------------------------------
		函数名：				int GetMaximumAllowableExposureTime(int& nExposureTime);
		功能：  				获取设备扫描状态允许的最大曝光时间
		参数1：		<out>   nExposureTime  返回允许的最大曝光时间
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();

		Function name:				 int GetMaximumAllowableExposureTime(int& nExposureTime);
		Function:					 Gets the maximum exposure time allowed for the scan status of the device
		Parameter1:     <out>		 nExposureTime   returns the maximum exposure time allowed
		Return value:				 return SUCCESS means success, others means failure
		Pre dependent function:      int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int GetScanMaximumAllowableExposureTime(int& nExposureTime);

		/*---------------------------------------------------------------------------------
		函数名：					void SetPacketSize(int nPacketSize = 5000);相机丢帧可以调整该数值。调整原则，若是cpu较好则调小该数值到1500.若
		网卡较好则调整该数值到8000.

		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			无;
		-----------------------------------------------------------------------------------*/
		void SetPacketSize(int nPacketSize = 5000);

		/*---------------------------------------------------------------------------------
		函数名：				int SetGain(int nGain );
		功能：  				设置相机增益
		参数1：		<in>    nGain。 连续模式下增益范围0-360.扫描点云模式建议增益范围0-20.
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();

		Function name:				int SetGain(int nGain );
		Function:					Set camera gain
		Parameter1:     <in>		nGain.The gain range is 0-360 under continuous mode. The recommended gain range is 0-20 under scanning point cloud mode.
		Return value:				Returning success meas success, others mean failure
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int SetGain(int nGain);

		/*---------------------------------------------------------------------------------
		函数名：				int GetGain(int& nGain);
		功能：  				获得相机增益
		参数1：		<out>   nGain  增益
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();

		Function name:				int GetGain(int& nGain);
		Function:					Get camera gain
		Parameter1:     <in>		nGain   Gain
		Return value:				return SUCCESS means success, others means failure
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int GetGain(int& nGain);

		/*---------------------------------------------------------------------------------
		函数名：				int SetFrameRate(float nFrameRate);
		功能：  				设置相机的实时采集速率
		参数1：		<in>    nFrameRate  帧率 范围 1 - 1000000 fps
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：				int ConnectDevice();

		Function name:				int SetFrameRate(float nFrameRate);
		Function:					Set the real-time acquisition rate of camera
		Parameter1:     <in>		nFrameRate   Frame rate   range is 1 - 1000000 fps
		Return value:				return SUCCESS means success, others means failure
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int SetFrameRate(int nFrameRate);

		/*---------------------------------------------------------------------------------
		函数名：				void GetWidthHeight(int& nWidth, int& nHeight);
		功能：  				获取图像宽、高、通道
		参数1：		<in>    nWidth  图像宽
		参数2：		<in>    nHeight 图像高
		返回值：				无
		前置函数：			int ConnectDevice();

		Function name:				void GetWidthHeight(int& nWidth, int& nHeight);
		Function:					Get image width and height
		Parameter1:     <in>		nWidth  image width
		Parameter2:     <in>		nHeight image height
		Return value:				None
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		void GetWidthHeight(int& nWidth, int& nHeight);

		/*---------------------------------------------------------------------------------
		函数名：				int GetSingleShotImg(std::vector<ALSON::Mat_uc>& imgVec);
		功能：  				获取单张原始图像。该函数可放在你的线程中实时调用。该图像是灰度图像。
		参数1：		<out>   imgVec  几个相机就几张图像。
		参数2：		<out>   imgType  默认获取灰度图像，若当前设备支持彩色可以获取彩色图像。
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();

		Function name:				int GetSingleShotImg(std::vector<ALSON::Mat_uc>& imgVec);
		Function:					Get a single original image. This function can be called in real time in your thread。The image is grayscale。
		Parameter1:     <out>		imgVec   several cameras have several images
		Parameter2：		<out>		imgType  Gray image is obtained by default. Color image can be obtained if current device supports color.
		Return value:				return SUCCESS means success, others means failure
		Pre dependent function:     int ConnectDevice();
		-----------------------------------------------------------------------------------*/
		int GetSingleShotImg(std::vector<ALSON::Mat_uc>& imgVec, int imgType = GREY);

		/*---------------------------------------------------------------------------------
		函数名：				int GetImageH(std::vector<ALSON::Mat_uc>& imgVec);
		功能：
		参数1：		<out>   img_L   只返回左相机图像
		参数2：		<in>    imgType  默认获取灰度图像，若当前设备支持彩色可以获取彩色图像。
		参数3：		<in>    fill_in_light  是否开启补光灯。若开启补光灯曝光时间范围在0 - 30 000us，若未开启，曝光范围在 0 - 1000 000 us
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数：			int ConnectDevice();
							void SetScanExposureTime(double* pdExposureTime, int nNum);

		Function name:				int GetImageH(std::vector<ALSON::Mat_uc>& imgVec);
		Function:					1. Get stereo rectification lighting images, you can call this function to take out lighting iamges after calling "int ScanPts(ALSON::Mat_f& pts, int nProjectorSelector = ALL_PROJECTOR)";
									The exposure used for lighting image at this time is based on the last exposure time of the exposure time you specified.
									You can also call this function separately to get and take out lighting image
		Parameter1:     <in>		img_L  Return left camera image only
		Parameter2：		<in>		imgType  Gray image is obtained by default. Color image can be obtained if current device supports color.
		Parameter3：		<in>		fill_in_light  Whether to turn on the fill light. If the fill lamp is turned on, the exposure time range is 0-30 000us, if not, the exposure range is 0-1000 000 us。
		Pre dependent function:		int ConnectDevice();
									void SetScanExposureTime(double* pdExposureTime, int nNum);
		-----------------------------------------------------------------------------------*/
		int GetImageH(Mat_uc& img_L, int imgType = GREY, int fill_in_light = fill_in_light_ON);

		/*---------------------------------------------------------------------------------
		函数名：				void SetStep(int step);
		功能：  				设置点云的步长
		参数1：		<in>    step  点云的步长，xy方向步长一致
		返回值：				无
		前置函数：			无

		Function name:				void SetStep(int step);
		Function；					Set the step size of point cloud
		Parameter1:     <in>		step  the step size of point cloud, and it is same in xy direction
		Return value:				None
		Pre dependent function:     None
		-----------------------------------------------------------------------------------*/
		void SetStep(int nStep);

		/*---------------------------------------------------------------------------------
		函数名：				void SetEnhancedMode(bool bFlag = false);
		功能：  				设置增强模式
		参数1：		<in>    bFlag  增强模式开关，增强模式对黑色物体有较好的帮助
		返回值：				无
		前置函数：			无

		Function name:				void SetEnhancedMode(bool bFlag = false);
		Function；					Set enhanced mode
		Parameter1:     <in>		bFlag  	Enhanced mode switch。The enhancement mode is helpful for black objects。
		Return value:				None
		Pre dependent function:     None
		-----------------------------------------------------------------------------------*/
		void SetEnhancedMode(bool bFlag = false);

		/*---------------------------------------------------------------------------------
		函数名：				void SetFilterFlag(bool bFlag = false);
		功能：  				滤波模式开关
		参数1：		<in>    bFlag  滤波开关
		返回值：				无
		前置函数：			无

		Function name:				void SetFilterFlag(bool bFlag = false);
		Function；					Set Filter mode
		Parameter1:     <in>		bFlag  	Filter Flag
		Return value:				None
		Pre dependent function:     None
		-----------------------------------------------------------------------------------*/
		void SetFilterFlag(bool bFlag = false);

		/*---------------------------------------------------------------------------------
		函数名：				int ScanPts(ALSON_Mat::Mat_f& pts,  int nProjectorSelector = ALL_PROJECTOR);
		功能：				采集点云。
		声明：				该函数与“int GetSingleShotImg(std::vector<ALSON::Mat_uc>& imgVec);”可并行调用，内部做了互斥处理。
							二则如果间歇调用，会有100ms的切换时间。若为了提升节拍，建议不要间歇调用这两个函数。
		参数1：		<out>   pts 3通道Mat类型的点云。
		参数2：		<out>   img_L 获取左相机立体校正图像。其曝光时间是多次曝光参数中的最后一个。
		参数3：		<in>    nProjectorSelector    双光机需要用户指定该参数，单光机默认即可。
		返回值：				返回SUCESS代表成功，返回其他代表失败
		前置函数				int ConnectDevice();
							void SetScanExposureTime(double* pdExposureTime, int nNum);

		Function name:				int ScanPts(ALSON_Mat::Mat_f& pts,  int nProjectorSelector = ALL_PROJECTOR);
		Function:					Scan for get point cloud
		Statement:					This function can be called in parallel with "int GetSingleShotImg(std::vector<ALSON::Mat_uc>& imgVec);", they have done mutex processing internally.
									If the two are called intermittently, there will be a switching time of 100ms. In order to improve the beat, it is recommended not to call these two functions intermittently.
		Parameter1:     <out>		pts Three channel Mat type point cloud
		Parameter2:     <out>		img_L Get stereo correction image of left camera,The exposure used for lighting image at this time is based on the
									last exposure time of the exposure time you specified.
		Parameter3:    <in>			nProjectorSelector    Dual optical mechine requires user to specify this parameter, single optical mechine can be default.
		Return value:				Returning SUCCESS means success, others mean failure.
		Pre dependent function:     int ConnectDevice();
									void SetScanExposureTime(double* pdExposureTime, int nNum);
		-----------------------------------------------------------------------------------*/
		int ScanPts(ALSON::Mat_f& pts, Mat_uc& img_L, int nProjectorSelector = ALL_PROJECTOR);

		/*---------------------------------------------------------------------------------
		函数名：				int GetptsNum();
		功能：				获取当前扫描点云的个数，注意该函数只能调用一次，调用后自动置零。
		返回值：				点云的个数
		前置函数				1 int ConnectDevice();
							2 int ScanPts(ALSON::Mat_f& pts, int nProjectorSelector = ALL_PROJECTOR);

		Function name:				int GetptsNum();
		Function:					Get the num of current scanned point cloud, pay attention to this function can only be called once, it will be set to zero automatically after calling.
		Return value:				Number of point cloud
		Pre dependent function:     1 int ConnectDevice();
									2 int ScanPts(ALSON::Mat_f& pts, int nProjectorSelector = ALL_PROJECTOR);
		-----------------------------------------------------------------------------------*/
		int GetptsNum();

		/*---------------------------------------------------------------------------------
		函数名：				void IsSaveOriginalData(bool bFlag = false);
		功能：				是否保存原始数据的开关
		返回值：				无
		前置函数				无

		Function name:				void IsSaveOriginalData(bool bFlag = false);
		Function:					Whether to save the original data?
		Return value:				 None
		Pre dependent function:		 None
		-----------------------------------------------------------------------------------*/
		void IsSaveOriginalData(bool bFlag = false);

		/*---------------------------------------------------------------------------------
		函数名：				bool SaveOriginalData(string strPath);
		功能：				保存原始数据
		返回值：				true or false
		前置函数				无

		Function name:				bool SaveOriginalData(string strPath);
		Function:					Save the original data.
		Return value:				 true or false
		Pre dependent function:		 None
		-----------------------------------------------------------------------------------*/
		bool SaveOriginalData(string strPath);

	private:
		CScan_Private* pScan;
	};
}

#endif
