
// TeleTypeTxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TeleTypeTxt.h"
#include "TeleTypeTxtDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeleTypeTxtDlg dialog



CTeleTypeTxtDlg::CTeleTypeTxtDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TELETYPETXT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTeleTypeTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	SetWindowTextW(L"Програма друкування тектсів в режимі Телетайп");
}

BEGIN_MESSAGE_MAP(CTeleTypeTxtDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTeleTypeTxtDlg message handlers

BOOL CTeleTypeTxtDlg::OnInitDialog()
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

void CTeleTypeTxtDlg::OnPaint()
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

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);
		cx = RH / 2;
		cy = RW / 2;

		// TODO
		int bx, ex, by, ey;

		int maxX = rc.right;
		int minX = rc.left;
		int maxY = rc.bottom;
		int minY = rc.top;

		cf = RGB(0, 0, 0);
		dc.FillSolidRect(&rc, cf);

		x1 = minX + 70; y1 = minY + 35;
		x2 = maxX - 50; y2 = maxY - 30;

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


		ms = "Я вивчаю мову програмування C++";

		CString Stroka[4];
		Stroka[0] = "Найбiльше i найдорожче добро кожного народу – це його мова, та жива схованка людського духу, його багата скарбниця, в яку народ складає і своє давнє життя i свої сподiванки, розум, досвiд, почування.";
		Stroka[1] = "Запашна, співуча, гнучка, милозвучна, сповнена музики і квіткових пахощів – скількома епітетами супроводяться визнання української мови.";
		Stroka[2] = "Мова – втілення думки. Що багатша думка, то багатша мова. Любімо її, вивчаймо її, розвиваймо її! Борімося за красу мови, за правильність мови, за приступність мови, за багатство мови.";
		Stroka[3] = "Народ, що не усвідомлює значення рідної мови для свого вищого духовного життя і сам її покидає й відрікається, виконує над собою самовбивство.";

		for (i = 0; i < 4; i++)
		{
			ms = Stroka[i];
			x1 = cx - 265;
			y1 = cy - 250;
			dx = 15; k = 0;
			p = ms.GetLength();
			while (y1 < ey && k<p)
			{

				j = 0;
				for (k = 0; k < ms.GetLength(); k++)
				{
					t = ""; t += ms[k]; j++;
					if (j > 36)
					{
						y1 += dy;
						x1 = cx - 265;
						j = 0;
					}
					hNew = CreateFont(24, 0, 0, 0, FW_NORMAL, 0, 0, 0,
						ANSI_CHARSET, OUT_DEFAULT_PRECIS,
						CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						DEFAULT_PITCH | FF_DONTCARE,
						L"Tahoma");
					hold = (HFONT)SelectObject(dc, hNew);
					dc.SetTextColor(RGB(0, 0, 0));
					dc.SetBkColor(RGB(255, 255, 255));
					dc.TextOutW(x1, y1, t, t.GetLength());
					DeleteObject(hNew);
					hold = (HFONT)SelectObject(dc, hbk);
					Sleep(mtime);

					hNew = CreateFont(24, 0, 0, 0, FW_NORMAL, 0, 0, 0,
						ANSI_CHARSET, OUT_DEFAULT_PRECIS,
						CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
						DEFAULT_PITCH | FF_DONTCARE,
						L"Tahoma");
					hold = (HFONT)SelectObject(dc, hNew);
					dc.SetTextColor(RGB(255, 255, 255));
					dc.SetBkColor(RGB(0, 0, 0));
					dc.TextOutW(x1, y1, t, t.GetLength());
					DeleteObject(hNew);
					hold = (HFONT)SelectObject(dc, hbk);

					x1 += dx;


				}

				y1 += dy;
				x1 = cx - 265;

			}

			Sleep(mtime + 2000);

			if (i < 3)
			{
				cf = RGB(0, 0, 0);
				dc.FillSolidRect(&rc, cf);

				x1 = minX + 70; y1 = minY + 35;
				x2 = maxX - 50; y2 = maxY - 30;

				pen = CreatePen(PS_SOLID, 3, RGB(255, 211, 0));
				brush = CreateSolidBrush(cf);
				SelectObject(dc, pen);
				SelectObject(dc, brush);
				dc.Rectangle(x1, y1, x2, y2);
				DeleteObject(pen);
				DeleteObject(brush);
			}


		}

		DeleteObject(pen);
		DeleteObject(brush);

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);
		DeleteObject(hNew);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTeleTypeTxtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

