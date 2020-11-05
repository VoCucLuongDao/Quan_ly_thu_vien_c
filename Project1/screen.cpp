#include "screen.h"

void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT WindowSize;
	WindowSize.Top = (40 - height) / 2;
	WindowSize.Left = (160 - width) / 2;
	WindowSize.Right = (160 + width) / 2;
	WindowSize.Bottom = (40 + height) / 2;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void Creat_main_guide(int &lua_chon) 
{
	textcolor(WHITE);
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));
	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 15 / 2);
	std::cout << "GIAO DIEN CHINH" << endl;
	ThanhNgang(38, 11, 120, BLACK, WHITE, char(205));
	gotoxy(39,11+20);
	std::cout << " cac phim dieu khien ^ v < > enter " << endl;
	string danhmuc[24] = { " 1.  Quan ly muon-tra             ",        // 0  ----
		                   " 2.  Quan ly sach                 ",        // 1
		                   " 3.  Quan ly doc gia              ",	    // 2
						   " 4.  Thong ke                     ",        // 3
		                   " 5.  Thoat                        ",        // 4  ****
		                       " 1.1  Muon sach               ",        // 5  ----
							   " 1.2  Tra sach                ",        // 6
	                           " 1.3  Tro lai                 ",        // 7  ****
		                       " 2.1  Tim kiem sach           ",        // 8  ----
                               " 2.2  Them sach               ",        // 9
					           " 2.3  Sua thong tin sach      ",        // 10
	 				           " 2.4  Xoa sach                ",        // 11
							   " 2.5  Ds sach                 ",        // 12
		                       " 2.6  Tro lai                 ",        // 13 ****
		                       " 3.1  Tim kiem doc gia        ",        // 14 -----
							   " 3.2  Them doc gia            ",        // 15
							   " 3.3  Sua thong tin doc gia   ",        // 16
							   " 3.4  Xoa doc gia             ",        // 17
							   " 3.5  Ds doc gia              ",        // 18
							   " 3.6  Tro lai                 ",        // 19 *****
		                       " 4.1  Ds sach muon qua han    ",        // 20 -----
							   " 4.2  Ds doc gia muon qua han ",        // 21
							   " 4.3  Ds top sach yeu thich   ",        // 22
							   " 4.4  Tro lai                 ",        // 23 ****

	};

	Docfile(5, 80, "gui_main.txt");
	
    Show_point(FALSE);
	Khunghienthi ht_main[24];
	for (int i = 0; i < 5; i++)
	{
		ht_main[i].SetToaDo(6 + i * 6, 13);
		ht_main[i].SetKichThuoc(6, 60);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
		ht_main[i].DrawKhunghienthi();
	}
	for (int i = 5; i < 8; i++)
	{
		ht_main[i].SetToaDo(6 + (i-5) * 4 , 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}
	for (int i = 8; i < 14; i++)
	{
		ht_main[i].SetToaDo(6 + (i - 8) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}
	for (int i = 14; i < 20; i++)
	{
		ht_main[i].SetToaDo(6 + (i - 14) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}
	for (int i = 20; i < 24; i++)
	{
		ht_main[i].SetToaDo(6 + (i - 20) * 4, 80);
		ht_main[i].SetKichThuoc(4, 45);
		ht_main[i].SetBackground(0);
		ht_main[i].SetNoiDung(danhmuc[i]);
	}

	int vt_func0 = 4, vt_func1 = 0;
	int lop = 0;
	while (1) {
		gotoxy(7, 11);
		Sleep(50);
		char kk = _getch();
        if (kk == -32) {
		    char cc = _getch();
			if (lop == 0)
			     XoaMang(6, 75, 32, 52, 0);
			if (cc == 72)
			{
				if (lop == 0) 
				{
				    ht_main[vt_func0].Doinen(0);
					vt_func0--;
					if (vt_func0 < 0) vt_func0 = 4;
					ht_main[vt_func0].Doinen(1);
				}
				else
				{
					if(vt_func0 == 0)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 5) vt_func1 = 7;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 1)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 8) vt_func1 = 13;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 2)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 14) vt_func1 = 19;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 3)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1--;
						if (vt_func1 < 20) vt_func1 = 23;
						ht_main[vt_func1].Doinen(1);
					}  
				}
			}

			if (cc == 80)
			{
				if (lop == 0)
				{
					ht_main[vt_func0].Doinen(0);
					vt_func0 ++;
					if(vt_func0 == 5) vt_func0 = 0;
					ht_main[vt_func0].Doinen(1);
				}
				else
				{
					if (vt_func0 == 0)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 >7) vt_func1 = 5;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 1)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 13) vt_func1 = 8;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 2)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 19) vt_func1 = 14;
						ht_main[vt_func1].Doinen(1);
					}
					if (vt_func0 == 3)
					{
						ht_main[vt_func1].Doinen(0);
						vt_func1++;
						if (vt_func1 > 23) vt_func1 = 20;
						ht_main[vt_func1].Doinen(1);
					}
				}
			}

			if (lop == 0)
			{
				if (vt_func0 == 0)
				{
					vt_func1 = 5;
					for (int i = 5; i < 8; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 1)
				{
					vt_func1 = 8;
					for (int i = 8; i < 14; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 2)
				{
					vt_func1 = 14;
					for (int i = 14; i < 20; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 3)
				{
					vt_func1 = 20;
					for (int i = 20; i < 24; i++)
					{
						ht_main[i].DrawKhunghienthi();
					}
				}
				if (vt_func0 == 4)
				{
					SetBGColor(0);
					Docfile(5, 80, "gui_main.txt");
				}
			}
		}
		


		if (kk == 13)
		{
			if (lop == 0)
			{
				lop = 1;
				if (vt_func0 == 4)
				{
					lua_chon = 100;
					break;
				}
				else
					ht_main[vt_func1].Doinen(1);
			}
			else
			{
				lop = 0;
				if (vt_func1 == 7 || vt_func1 == 13 || vt_func1 == 19 || vt_func1 == 23)
				{
					ht_main[vt_func1].Doinen(0);
				}
				else
				{	
					gotoxy( 0, 0);
			        lua_chon = vt_func1;
					break;
				}
			}
		}
	}
}

void Creat_timkiemsach_guide()
{
	textcolor(WHITE);

	textcolor(WHITE);
	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 26 / 2);
	std::cout << "GIAO DIEN QUAN LY TIM KIEM" << endl;
	/**********************************************************/



	/**********************************************************/
}

void Creat_qlmuontra_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 28 / 2);
	std::cout << "GIAO DIEN QUAN LY MUON - TRA" << endl;
	/**************************************************************/



	/**************************************************************/
}

void Creat_qlsach_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 22 / 2);
	std::cout << "GIAO DIEN QUAN LY SACH" << endl;

	/****************************************************/



	/****************************************************/
}

void Creat_qldocgia_guide()
{
	textcolor(WHITE);
	extern int cnt;
	cnt = 0;

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 22 / 2);
	std::cout << "GIAO DIEN QUAN DOC GIA" << endl;

	
}

void Creat_topyeuthich_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 23 / 2);
	std::cout << "GIAO DIEN TOP YEU THICH" << endl;
	/*******************************************************/


	/*******************************************************/
}

void Creat_danhsachdocgiaquahan_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 35 / 2);
	std::cout << "GIAO DIEN DANH SACH DOC GIA QUA HAN" << endl;
	/**********************************************************/



	/**********************************************************/
}

void Creat_danhsachsachchuatra_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 33 / 2);
	std::cout << "GIAO DIEN DANH SACH SACH CHUA TRA" << endl;
	/***********************************************************/

	/**********************************************************/
}

void Creat_thongkedulieu_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 26 / 2);
	std::cout << "GIAO DIEN THONG KE DU LIEU" << endl;
	/******************************************************/



	/******************************************************/
}

void Creat_caidattrogiup_guide()
{
	textcolor(WHITE);

	Khunghienthi background(0, 10, 36, 120, 0, 0);
	background.DrawKhunghienthi();

	Khunghienthi title(0, 10, 5, 120, 0, 0);
	title.DrawKhunghienthi();

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 28 / 2);
	std::cout << "GIAO DIEN CAI DAT - TRO GIUP" << endl;
	/*****************************************************/

	/*****************************************************/
}