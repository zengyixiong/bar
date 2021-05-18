#ifndef _MACRO_DEFINE_H_
#define _MACRO_DEFINE_H_

//---------------------------------------------------------------
// Function work states
//---------------------------------------------------------------
enum STATE
{
	SUCESS = 0,													// SUCESS
	FIND_CAM_FAILED = 200,										// No camera found
	OPEN_CAM_FAILED = 201,										// Failed to open camera
	CAM_IS_CONNECTED = 102,										// Camera connected
	CAM_IS_NOT_CONNECTED = 202,									// Camera not connected
	Get_EXPOSURE_TIME_FAILED = 203,								// Failed to get exposure time
	Set_EXPOSURE_TIME_FAILED = 204,								// Failed to set exposure time
	GET_GAIN_FAILED = 205,										// Failed to get gain
	SET_GAIN_FAILED = 206,										// Failed to set gain
	Set_FRAMERATE_FAILED = 207,									// Set the frame rate
	GRAB_TRIGGER_IMAGES_FAILED = 208,						    // Scanned image drops frames
	GRAB_SINGLE_SHOT_IMAGE_FAILED = 209,					    // Failed to get real-time image
	NOT_SET_EXPOSURE_TIME = 210,								// Not set exposure time
	DEVICE_IS_NOT_CONNECTED = 211,								// Device not open
	NOT_SET_CAM_ID = 212,										// Not set camera or serial port ID
	NOT_INSTALL_CAM_DRIVER = 213,								// Not install camera driver
	OPEN_SERIAL_PORT_FAILED = 401,								// Error opening serial port
	NO_SERIAL_PORT_RESPONSE_SCAN = 402,							// Serial port signal timeout
	INCONSISTENT_IMAGE_SIZE = 501,								// Inconsistent image size between dual cameras
	RECT_BEYOUND_IMAGE = 502,									// ROI region setting error
	NO_CAM_PARAMETER_PATH = 503,								// No camera parameter path was entered, or the path entered incorrectly
	GET_WHITE_IMAGE_FAILED = 504,						     	// Failed to get lighting image
	DEVICE_IS_SCANNINT_STATE = 505,							    // The device is scanning, and cannot be scanned again
	CAN_NOT_GET_DEVICE_TYPE = 506,							    // Failed to get device model
	PROJECTOR_PARAMETER_ERROR = 507,							// Opitical mechine input error, please confirm the device type and select appropriate optical mechine parameters
	CAN_NOT_GET_POLAR_DIRCETION = 508,							// Unable to get the epipolar line direction
	TEMPERATURE_ALARM = 509									    // The temperature of the equipment is too high
};

// Optical selection
enum ProjectSelector
{
	ALL_PROJECTOR,   // Single optical mechine is one optical mechine working, dual optical mehcine both optical mechines working
	LEFT_PROJECTOR,	 // Dual-optical mechine surpports this mode, the information will be ignored in single-optical mechine
	RIGHT_PROJECTOR  // Dual-optical mechine surpports this mode, the information will be ignored in single-optical mechine
};

// image type
enum IMAGETYPE
{
	GREY,
	COLOR
};

// fill-in light
enum fill_in_light
{
	fill_in_light_ON,
	fill_in_light_OFF
};

#define DeleteArrayPointer(pointer) if( NULL != pointer) {delete  []pointer; pointer = NULL;}
#define DeletePointer(pointer) if( NULL != pointer) {delete  pointer; pointer = NULL;}

#endif
