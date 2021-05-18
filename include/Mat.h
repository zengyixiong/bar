#ifndef _MAT_H_
#define _MAT_H_
#include "stddef.h"
#include <iostream>
#include <string>
#include <math.h>

// def
typedef unsigned char  uchar;
typedef unsigned short ushort;

// dllexport
#ifdef _WIN32
#ifdef MATDLL_EXPORTS
#define MATDLL_API  __declspec(dllexport)
#else
#define MATDLL_API   __declspec(dllimport)
#endif
#else
#ifdef MATDLL_EXPORTS
#define MATDLL_API   __attribute__((visibility("default")))
#else
#define MATDLL_API   __attribute__((visibility("default")))
#endif
#endif

//
#define ALSON_8U   0
#define ALSON_8S   1
#define ALSON_16U  2
#define ALSON_16S  3
#define ALSON_32U  4
#define ALSON_32S  5
#define ALSON_32F  6
#define ALSON_64F  7

namespace ALSON
{
	// Mat Type
	template <typename TypeName>
	class   MatNew
	{
	public:
		// construct
		MatNew();

		// construct
		MatNew(size_t nr, size_t nc, int nChannel = 1);

		// destructor
		~MatNew();

		// copy constructor   shallow copy
		MatNew(const MatNew& m);

		// shallow copy
		MatNew& operator=(const MatNew& m);

		// deep copy
		MatNew clone();

		// Mat (+ - * /) numerical
		MatNew operator*(TypeName val);
		MatNew operator/(TypeName val);
		MatNew operator+(TypeName val);
		MatNew operator-(TypeName val);

		// Mat + - Mat
		MatNew operator+(const MatNew& m);
		MatNew operator-(const MatNew& m);

		//		// Rotation matrix multiplication
		//		MatNew operator*(const MatNew& m);

		// is empty锛?
		bool empty();

		// Assign by pointer
		void setData(TypeName* _pData, int nWidth, int nHeight, int nChannel = 1);

		// Round
		MatNew getRound();

		// Allocate space and assign values
		void zeros(size_t nr, size_t nc, int nChannel = 1);

		// Allocate space and assign values
		void ones(size_t nr, size_t nc, int nChannel = 1);

		// Allocation space And not assigned
		void creat(size_t nr, size_t nc, int nChannel = 1);

		// only release data
		void release();

		// Support Mat_uc(channel = 1,channel = 3)
		bool imwrite(std::string strPath);
		bool imread(std::string strPath);

		void writeToTxt(std::string strPath);

		//   Only single channel is supported
		void Roate90();
		void Roate270();

		// transposition
		MatNew t();

	public:
		TypeName* pData;  // can鈥檛 change it
		int rows;
		int cols;
		int m_nChannel;

	private:
		void initialType();
		int* m_refCount;
		uchar type;
	};

	// export Mat
	template class MATDLL_API MatNew<char>;
	template class MATDLL_API MatNew< unsigned char>;

	template class MATDLL_API MatNew<unsigned short int>;
	template class MATDLL_API MatNew<short int>;

	template class MATDLL_API MatNew<int>;
	template class MATDLL_API MatNew<unsigned int>;

	template class MATDLL_API MatNew<float>;
	template class MATDLL_API MatNew<double>;

	// alias
	typedef  MatNew<char> Mat_c;
	typedef  MatNew< unsigned char> Mat_uc;

	typedef  MatNew<short int> Mat_si;
	typedef  MatNew<unsigned short int> Mat_usi;

	typedef  MatNew<int> Mat_i;
	typedef  MatNew<unsigned int> Mat_ui;

	typedef  MatNew<float> Mat_f;
	typedef  MatNew<double> Mat_d;

	// Mat type convert
	template <typename TypeName1, typename TypeName2>
	bool MatConvert(MatNew<TypeName1>& src, MatNew<TypeName2>& dst);
}

namespace ALSON
{
	//=============================================
	// point
	typedef struct POINT
	{
		float x;
		float y;

		POINT()
		{
			x = 0.0;
			y = 0.0;
		}
		POINT(float _x, float _y)
		{
			x = _x;
			y = _y;
		}

		POINT& operator=(POINT& value)
		{
			x = value.x;
			y = value.y;
			return *this;
		}
	}POINT, *PPOINT;

	typedef struct RECT
	{
		int nOffset_x;
		int nOffset_y;
		int nWidth;
		int nHeight;
		RECT()
		{
			nOffset_x = -1;
			nOffset_y = -1;
			nWidth = -1;
			nHeight = -1;
		}
		RECT(int _nOffset_x, int _nOffset_y, int _nWidth, int _nHeight)
		{
			nOffset_x = _nOffset_x;
			nOffset_y = _nOffset_y;
			nWidth = _nWidth;
			nHeight = _nHeight;
		}

		RECT& operator=(RECT& value)
		{
			nOffset_x = value.nOffset_x;
			nOffset_y = value.nOffset_y;
			nWidth = value.nWidth;
			nHeight = value.nHeight;
			return *this;
		}
	}Rect, *prect;

	// Match Pts
	typedef struct tagPOINTMATCH
	{
		POINT  L;
		POINT  R;
	}POINTMATCH, *PPOINTMATCH;

	// 3d Pts
	typedef struct POINT3F
	{
		float x;
		float y;
		float z;

		POINT3F() {};
		POINT3F(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

		POINT3F operator+(POINT3F &_pt)
		{
			POINT3F tmp;
			tmp.x = x + _pt.x, tmp.y = y + _pt.y, tmp.z = z + _pt.z;
			return tmp;
		}
		POINT3F operator-(POINT3F &_pt)
		{
			POINT3F tmp;
			tmp.x = x - _pt.x, tmp.y = y - _pt.y, tmp.z = z - _pt.z;
			return tmp;
		}
		POINT3F operator/(float &length)
		{
			POINT3F tmp;
			tmp.x = x / length, tmp.y = y / length, tmp.z = z / length;
			return tmp;
		}

		// 鍙変箻
		POINT3F operator*(POINT3F &per)
		{
			return POINT3F{ y *  per.z - z* per.y,
				z *  per.x - x  * per.z,
				x  * per.y - y *  per.x };
		}

		float GetModuleLength()
		{
			return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		}
	}point3f, *ppoint3f;

	// compute Pts Normal
	extern MATDLL_API  void computePtsNormal(Mat_f& pts, Mat_f& ptsNormal);

	// save Pts in Tiff format
	extern MATDLL_API  bool saveTiffFormat_x_y_z(Mat_f& pts, std::string strPath);

	// save PtsNormal in Tiff format
	extern MATDLL_API  bool saveTiffFormat_xyz(Mat_f& pts, std::string strPath);
}

// SavePtsFormat savePtsType
enum savePtsType
{
	PLY__ASCII = 1,      /* ascii PLY file */
	PLY__BINARY_BE = 2,     /* binary PLY file, big endian */
	PLY__BINARY_LE = 3,      /* binary PLY file, little endian */
	PLY__BINARY_NATIVE = 4      /* binary PLY file, same endianness as current architecture */
};

namespace  ALSON
{
	// SavePt in ply format
	extern  MATDLL_API bool write(ALSON::Mat_f & pts, ALSON::Mat_f& normal, ALSON::Mat_uc & rgb, std::string strPath = "", int file_type = PLY__BINARY_BE, bool isPtsOrder = false);
}

#endif
