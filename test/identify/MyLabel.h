#pragma once

#include <QLabel>
extern 	double m_roiRect_topLeft_x, m_roiRect_topLeft_y,m_roiRect_bottomLeft_x,m_roiRect_bottomLeft_y;
/* ���ŷ��� */
enum EmDirection
{
	DIR_TOP = 0,
	DIR_BOTTOM,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_LEFTTOP,
	DIR_LEFTBOTTOM,
	DIR_RIGHTTOP,
	DIR_RIGHTBOTTOM,
	DIR_MIDDLE,
	DIR_NONE
};

#define EDGPADDING       5        //���ܱ�Ե��������
#define CORPADDING       6        //�Ľǿ�������

#define MIN_WIDTH        5        //���������С���
#define MIN_HEIGHT       5        //���������С�߶�

#define POINT_WIDTH      6        //��Ե9��Ŀ��
#define POINT_HEIGHT     6        //��Ե9��ĸ߶�

#define EDGE_WIDTH       3        //�߿�Ŀ��
#define MIDDLELINE_WIDTH 2        //�����ߵĿ��

#define DRAW_TEN_POINT            //����ʮ����
#define DRAW_SUB_LINE             //���Ƹ�����

class QMenu;
class QAction;

class MyLabel : public QLabel
{
	Q_OBJECT

public:
	MyLabel(QWidget *parent = nullptr);
	~MyLabel();
	QRect getRoiRect() const;               //��ȡ�Ѿ�Ȧѡ�Ŀ� �ⲿ����
	void setBackImage(const QImage &img);   //���ñ���ͼƬ  �ⲿ����
	QRect m_roiRect;
	void saveROIImage();
protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev);
	void keyPressEvent(QKeyEvent *ev);
	void contextMenuEvent(QContextMenuEvent *ev);

private:
	void initViewer();                         //��ʼ��
                //��ROI�����ͼƬ�洢����
	EmDirection region(const QPoint &point);   //�������λ�����������״
	void scaleRect(const QPoint &mousePoint);  //���ž���
	void paintRect(const QPoint &mousePoint);  //���ƾ���
	void moveRect(const QPoint &mousePoint);   //�ƶ�����

private:
	bool m_bPainterPressed;        //�Ƿ����ڻ���
	bool m_bMovedPressed;          //�Ƿ������϶�
	bool m_bScalePressed;          //�Ƿ��������Ŵ�С
	QPoint m_paintStartPoint;      //���Ƶĳ�ʼλ��
	QPoint m_moveStartPoint;       //�϶��ĳ�ʼλ��
              //���Ƶ�ROI
	EmDirection m_emCurDir;        //�϶��ķ���

	QImage m_backImage;            //����ͼ

	QMenu *m_pOptMenu;
	QAction *m_pDelAction;
	QAction *m_pSaveAction;
};
//QRect m_roiRect_save = MyLabel.m_roiRect;