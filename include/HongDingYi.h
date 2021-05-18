//宏定义文件

#define  ID_JiChuHanShu_VIEW			1  //基础函数视图
#define  ID_XiangJiKongZhi_VIEW			2  //相机控制视图
#define  ID_SheBeiBiaoDing_VIEW			3  //标定视图
#define  ID_DingXiang_VIEW				4  //定向视图
#define  ID_TuXiangChuLi_VIEW			5  //图形处理视图
#define  ID_DanXiangJi_VIEW				6  //单相机视图
#define  ID_DuoXiangJi_VIEW				7  //多相机视图



//绘制的按钮，总项
#define  ID_BUTTON_JiChuHanShu			101  //基础函数视图
#define  ID_BUTTON_XiangJiKongZhi		102  //相机控制视图
#define  ID_BUTTON_SheBeiBiaoDing		103  //标定视图
#define  ID_BUTTON_DingXiang			104  //定向视图
#define  ID_BUTTON_TuXiangChuLi			105  //图形处理视图
#define  ID_BUTTON_DanXiangJi			106  //单相机视图
#define  ID_BUTTON_DuoXiangJi			107  //多相机视图 

//绘制，各分项所对应的宏
#define  ID_JiChuHanShu_QianFangJiaoHui			    201  //基础函数视图
#define  ID_JiChuHanShu_HouFangJiaoHui			    202  //基础函数视图
#define  ID_JiChuHanShu_XiangDuiDingXiang			203  //基础函数视图
#define  ID_JiChuHanShu_JueDuiDingXiang			    204  //基础函数视图
#define  ID_JiChuHanShu_HeXianPiPei			        205  //基础函数视图
#define  ID_JiChuHanShu_XiangGuanXiShu			    206  //基础函数视图
#define  ID_JiChuHanShu_ZuoBiaoBianHuan			    207  //基础函数视图

//相机控制宏
#define  ID_XiangJiKongZhi_XiangJiLianJie			221  //相机控制视图
#define  ID_XiangJiKongZhi_CanShuSheZhi				222  //相机控制视图
#define  ID_XiangJiKongZhi_ShiPin					223  //相机控制视图
#define  ID_XiangJiKongZhi_BaoCun					224  //相机控制视图

//设备标定宏
#define  ID_SheBeiBiaoDing_XiangJiBiaoDing			241  //相机控制视图
#define  ID_SheBeiBiaoDing_ProbBiaoDing				242  //相机控制视图
#define  ID_SheBeiBiaoDing_SaoMiaoBiaoDing			243  //相机控制视图

//定向宏
#define  ID_DingXiang_DanXiangJiDingXiang			261  //单相机定向
#define  ID_DingXiang_SuangXiangJiDingXiang			262  //双相机定向
#define  ID_DingXiang_DuoXiangJiDingXiang			263  //多相机定向

//多相机
#define  ID_DuoXiangJi_DongTaiCeLiang			281  //动态测量
#define  ID_DuoXiangJi_GenZongDaoHang			282  //跟踪导航
#define  ID_DuoXiangJi_JieGouGuangSaoMiao		283  //结构光扫描
#define  ID_DuoXiangJi_DuoXiangJiZhenLie		284  //多相机阵列
#define  ID_DuoXiangJi_ProbCeLiang				285  //Prob测量
#define  ID_DuoXiangJi_3D						286  //3D视图

//总项选项卡
#define  ID_ZongXiangXuanXiangKa_Photogrammetry				300  //总项选项卡-摄影测量 
#define  ID_ZongXiangXuanXiangKa_Radar				        301  //总项选项卡 -雷达

//绘制的按钮，总项

#define  ID_BUTTON_XJKZ					27  //坐标转换
#define  ID_BUTTON_SPXS					28  //坐标转换
#define  ID_BUTTON_TPBC					29  //坐标转换
#define  ID_BUTTON_XJBD					30  //坐标转换
#define  ID_BUTTON_PBBD					31  //坐标转换
#define  ID_BUTTON_SMBD					32  //坐标转换
#define  ID_BUTTON_SXJDX				33  //坐标转换
#define  ID_BUTTON_DXJDX				34  //坐标转换
#define  ID_BUTTON_HDZFT				35  //坐标转换
#define  ID_BUTTON_YZ					36  //坐标转换
#define  ID_BUTTON_BJTQ					37  //坐标转换
#define  ID_BUTTON_YDTQ					38  //坐标转换
#define  ID_BUTTON_GJH					39  //坐标转换
#define  ID_BUTTON_DANSWDY				40  //坐标转换
#define  ID_BUTTON_DANPBCL				41  //坐标转换
#define  ID_BUTTON_DANPMCL				42  //坐标转换
#define  ID_BUTTON_DANJGGSM				43  //坐标转换
#define  ID_BUTTON_DUOSWDY				44  //坐标转换

#define  ID_BUTTON_DUOPBCL				45  //坐标转换
#define  ID_BUTTON_DUODTCL				46  //坐标转换
#define  ID_BUTTON_DUOGZDH				47  //坐标转换

#define  ID_BUTTON_DUOJGGSM				48  //坐标转换
#define  ID_BUTTON_DUODXJZL				49  //坐标转换


 
//CONtrolFRom中的视图资源
#define  ID_CAM_VIEW			201  //相机文件
#define  ID_IMAGE_LIST_VIEW		202  //图片缩略图
#define  ID_VIEW_BLANK			203  //默认视图
#define  ID_3d_VIEW				204  //三维视图
#define  ID_fullpic_VIEW		205  //全尺寸图片显示视图（改为定向了，哈哈）
#define  ID_ContralData_VIEW	206  //控制场数据
#define  ID_LiveImage_VIEW		207  //采图的实时视频
#define  ID_he_xian_VIEW		208  //核线视图
#define  ID_ItemFram_VIEW		209  //总选项视图
#define  ID_FenXiangFram_VIEW	210  //分选项视图
 

//自定义消息
#define WM_ITEMSELECET_MESSAGE			(WM_USER+100)   //总选项卡上选择的信息
#define WM_FENXIANGSELECET_MESSAGE		(WM_USER+101)   //分项选项卡上选择的信息
#define WM_VideoLiveKommand_MESSAGE		(WM_USER+102)   //图像采集部分
#define WM_SetFoucsToVideoLive_MESSAGE	(WM_USER+103)   //设置焦点
 
 

//相机内参数模型  
#define nMoXINGSHU_BD                   9          //航摄相机内参数模型，所包含的变量因子
#define nMoXINGSHU                     10          //相机内参数模型，所包含的变量因子   
#define MAX_CAMERA_NUMBER_SCANER         2         //激光扫描仪连接的最大相机个数
#define MAX_LASERPLANE_NUMBER_SCANER     1         //激光扫描仪光斑条数


//文档里面的数据清空控制宏
#define  nClearAllData				 0			//图像数据清零
#define  nClearImageData             1			//图像数据清零
#define  nClearCtrlData              2          //控制数据清零
#define  nClearCameraData            3			//相机，及相机类数据清零


//图像处理--处理的是哪一类要素，有CODE、激光线条、环形编码
#define  IMAGE_PRO_CODE				        0			//处理CODE图像数据
#define  IMAGE_PRO_LASER_LINE               1			//处理激光线条图像数据
#define  IMAGE_PRO_CIRCLE_CODE              2           //处理环形编码图像数据


//扫描模式
#define scan_postprocessing				0	//后处理模式
#define scan_realtime 		            1   //实时模式


//自定义的控件ID编号
#define   CTextPicShowView_IDC_ImageListCtrl           20131			//图像链表控件



//相机视频的相关宏定义
#define   VideoLiveKommand_ShiPin           3			//视频
#define   VideoLiveKommand_CunTu            4			//存图 
#define   VideoLiveKommand_CameraConnect    1			//连接相机
#define   VideoLiveKommand_SingleTrager     2			//单帧采集  
#define   VideoLiveKommand_FreeRun			3			//自由采集
#define   VideoLiveKommand_TurnPage		    4			//翻页
#define   VideoLiveKommand_Set				5			//设置
#define   VideoLiveKommand_Exit				6			//退出


//Timer 时间的相依宏
#define   VideoLiveKommand_TuPianCaiJi           1			//图片连续采集

//字符最长宏定义
#define			CHARLONG_WARDS_MAX					260			//字符类的数组长度
#define			CHARLONG_WARDS_MIN					100			//字符类的数组长度
#define			DINGXIANG_PICTURE_MAX				150			//字符类的数组长度 



//定义字符串，用在数据内存申请上
#define			Appli_INT_Memorys					        1
#define			Appli_SHORT_Memorys					        2
#define			Appli_CHAR_Memorys					        3
#define			Appli_BYTE_Memorys					        4
#define			Appli_UNSIGNED_CHAR_Memorys					5
#define			Appli_FLOAT_Memorys					        6
#define			Appli_DOUBLE_Memorys					        7
#define			Appli_BOOL_Memorys					        8
#define			Appli_LONG_Memorys					        9



//相机的最多个数
#define			MAX_CAMERA_NUMBER                           10 

//字符串的最大长度
#define			CHAR_LONG_MAX                               260
#define         MAX_CHAR_LONG                               260        //用于定义字符数组的最大长度
#define			CHAR_LONG_MIN					            100			//字符类的数组长度
#define			DINGXIANG_PICTURE_MAX				        150			//字符类的数组长度 

//极小值数，当一个数小于一下这个数时，认为它等于零
#define			NUMBER_CLOSE_TO_ZERO                        0.0000001//趋近于零的数，小数点后面10位

//单相机输出的文件类型
#define			BUNDLE_OUT_FILE_IMAG                        1  
#define			BUNDLE_OUT_FILE_3D                          2   


//被踢除的像点标记
#define			BUNDLE_REMOVE_IMAGE_PT_X                    100000 
#define			BUNDLE_REMOVE_IMAGE_PT_X_SET                100010

//单相机中，图片最大输入数量
#define			BUNDLE_Image_MAX_NUMBER                     5000  





//读写特定格式文件标识
#define			MOD_ROBAT_TXT                               1        //.dom文件（机器人抓取中，测量设备扫描到的三维点云数据）
#define         MOD_ROBAT_BIN                               2        //
#define			RAJ_ROBAT_TXT					            4		 //.raj机器人防碰撞过程中需要的料框、夹具信息文件
#define			RAJ_ROBAT_BIN					            5		 // 



#define			CLI_3D_TXT					                50		//从剪切板中读取三维点坐标数据 