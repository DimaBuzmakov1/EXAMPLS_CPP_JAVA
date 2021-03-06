
// AnimaciaMovingObjectPoligonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AnimaciaMovingObjectPoligon.h"
#include "AnimaciaMovingObjectPoligonDlg.h"
#include "afxdialogex.h"

#include <time.h>

using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAnimaciaMovingObjectPoligonDlg dialog



CAnimaciaMovingObjectPoligonDlg::CAnimaciaMovingObjectPoligonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ANIMACIAMOVINGOBJECTPOLIGON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	srand((unsigned)time(NULL));
}

void CAnimaciaMovingObjectPoligonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAnimaciaMovingObjectPoligonDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CAnimaciaMovingObjectPoligonDlg message handlers

BOOL CAnimaciaMovingObjectPoligonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAnimaciaMovingObjectPoligonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CClientDC dc(this);
		GetClientRect(&rc);

		hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0,
			ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			L"Times New Roman Cyr");
		hold = (HFONT)SelectObject(dc, hNew);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);


		// TODO

		int XA[360], YA[360];
		double xf, yf, f;

		int D = 550;
		int n = 60;


		f = 0;
		k = 0;

		dc.MoveTo(cx, cy + D / 2);

		while (k < n)
		{
			xf = D / 2 * cos(f);
			yf = D / 2 * sin(f);
			XA[k] = xf + cx;
			YA[k] = yf + cy;
			k++;
			f += (2 * PI / n);
		}

		//-------------------------------------------------------------

		dc.FillSolidRect(&rc, RGB(0, 0, 0));


		dx = dy = 45;
		for (k = 0; k < n; k++)
		{
			cf = RGB(255, 221, 41);
			hPenOxy = CreatePen(PS_SOLID, 2, cf);
			brush = CreateSolidBrush(cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			SelectObject(dc, brush);

			dc.Ellipse(XA[k], YA[k], XA[k] + dx, YA[k] + dy);
			dc.MoveTo(XA[k] + dx / 2, YA[k] + dy / 2);
			dc.LineTo(cx, cy);

			Sleep(mtime - 50);

			cf = RGB(0, 0, 0);
			hPenOxy = CreatePen(PS_SOLID, 2, cf);
			brush = CreateSolidBrush(cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			SelectObject(dc, brush);

			dc.Ellipse(XA[k], YA[k], XA[k] + dx, YA[k] + dy);
			dc.MoveTo(XA[k] + dx / 2, YA[k] + dy / 2);
			dc.LineTo(cx, cy);

			SelectObject(dc, hOldPen);
			DeleteObject(hPenOxy);
			DeleteObject(brush);

		}

		Sleep(mtime + 150);

		//-------------------------------------------------------------

		dc.FillSolidRect(&rc, RGB(0, 0, 0));

		dx = dy = 45;
		for (k = 0; k < n; k++)
		{
			cf = RGB(120, 100, 255);
			hPenOxy = CreatePen(PS_SOLID, 2, cf);
			brush = CreateSolidBrush(cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			SelectObject(dc, brush);

			dc.Rectangle(XA[k], YA[k], XA[k] + dx, YA[k] + dy);
			dc.MoveTo(XA[k] + dx / 2, YA[k] + dy / 2);
			dc.LineTo(cx, cy);

			Sleep(mtime - 50);

			cf = RGB(0, 0, 0);
			hPenOxy = CreatePen(PS_SOLID, 2, cf);
			brush = CreateSolidBrush(cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
			SelectObject(dc, brush);

			dc.Rectangle(XA[k], YA[k], XA[k] + dx, YA[k] + dy);
			dc.MoveTo(XA[k] + dx / 2, YA[k] + dy / 2);
			dc.LineTo(cx, cy);

			SelectObject(dc, hOldPen);
			DeleteObject(hPenOxy);
			DeleteObject(brush);

		}

		Sleep(mtime + 150);

		//-------------------------------------------------------------

		dc.FillSolidRect(&rc, RGB(0, 0, 0));

		for (k = 0; k < 1024; k++)
		{
			hNew = CreateFont(10 + rand() % 146, 0, 0, 0, FW_BOLD, 0, 0, 0,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE,
				L"Trebuchet Ms");
			hold = (HFONT)SelectObject(dc, hNew);

			int dig = 10 + rand() % 89;
			ms.Format(L"%i", dig);

			SetBkMode(dc, TRANSPARENT);
			SetTextColor(dc, RGB(rand() % 255, rand() % 255, rand() % 255));
			SetBkColor(dc, RGB(rand() % 255, rand() % 255, rand() % 255));
			
			x1 = rc.left + rand() % rc.right - 10;
			y1 = rc.top + rand() % rc.bottom - 10;
			dc.TextOutW(x1, y1, ms, ms.GetLength());

			Sleep(mtime - 110);

			hold = (HFONT)SelectObject(dc, hbk);

		}

		Sleep(mtime + 150);

		//-------------------------------------------------------------

		int bx, ex, by, ey;

		int maxX = rc.right;
		int minX = rc.left;
		int maxY = rc.bottom;
		int minY = rc.top;

		cf = RGB(0, 0, 0);
		dc.FillSolidRect(&rc, cf);

		x1 = minX + 100; y1 = minY + 35;
		x2 = maxX - 80; y2 = maxY - 30;

		pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
		brush = CreateSolidBrush(cf);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		dc.Rectangle(x1, y1, x2, y2);
		DeleteObject(pen);
		DeleteObject(brush);

		bx = minX + 110; by = minY + 60;
		ex = maxX - 120; ey = maxY - 65;

		dx = dy = 30;

		x1 = (bx + ex) / 2; y1 = by;

		while (x1 <= ex)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 += dx;
			y1 += dy;

		}

		x1 = ex; y1 = (by + ey) / 2;

		while (x1 > (bx + ex) / 2)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 -= dx;
			y1 += dy;

		}


		x1 = (bx + ex) / 2; y1 = ey - dy * 0.5;

		while (x1 > bx)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 -= dx;
			y1 -= dy;

		}


		x1 = bx; y1 = (by + ey) / 2 - dy / 2;

		while (x1 < (bx + ex) / 2)
		{
			pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			Sleep(mtime);
			pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			brush = CreateSolidBrush(cf);
			SelectObject(dc, pen);
			SelectObject(dc, brush);
			dc.Rectangle(x1, y1, x1 + dx, y1 + dy);
			DeleteObject(pen);
			DeleteObject(brush);
			x1 += dx;
			y1 -= dy;

		}

		x1 = minX + 100; y1 = minY + 35;
		x2 = maxX - 80; y2 = maxY - 30;

		pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		brush = CreateSolidBrush(cf);
		SelectObject(dc, pen);
		SelectObject(dc, brush);
		dc.Rectangle(x1, y1, x2, y2);
		DeleteObject(pen);
		DeleteObject(brush);

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);
		hold = (HFONT)SelectObject(dc, hbk);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnimaciaMovingObjectPoligonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}