#include "Ql_sach.h"
#include "fstream"

/************ Them sach ***************/
Khunghienthi kht[50][50];
Khunghienthi lcht1, lcht2;
int sh = 0, sc = 0;
/*********** Hien thi ds **************/
Khunghienthi kht2[50][50];
int sh2 = 0, sc2 = 0;
int so_luong_sach = 0, value_count = 0;
int vt_trang = 1, sl_trang = 1;
/*************************************/
void Khung_Ql_sach_Them_sach()
{
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 20 / 2);
	std::cout << "GIAO DIEN THEM SACH" << endl;
	/**********************************************************/

	std::string danhmuc_hang[10] = { "Ma sach: ",
								"Ten sach: ",
		                        "Tac gia",
								"Nha xuat ban",
		                        "Nam xuat ban",
								"Trang thai",
								"Vi tri" };
	std::string danhmuc_cot[10] = { "", " " };
		int vt_cot[10] = { 15,50};
		int vt_hang[10] = {5, 5, 5, 5, 5, 5, 5};
		
	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht, sh, sc);

	gotoxy(23, 90);
	std::cout << "Ban muon luu va thoat ?" << endl;

	lcht1.SetToaDo(25, 80);
	lcht1.SetKichThuoc(3,20);
	lcht1.SetBackground(0);
	lcht1.SetNoiDung("Save");
	lcht1.DrawKhunghienthi();

	lcht2.SetToaDo(25, 105);
	lcht2.SetKichThuoc(3, 20);
	lcht2.SetBackground(0);
	lcht2.SetNoiDung("Cancel");
	lcht2.DrawKhunghienthi();

	gotoxy(30, 90);
	std::cout << "Su dung phim Ctrl+S de luu" << endl;
	gotoxy(31, 90);
	std::cout << "Su dung phim Esc de thoat" << endl;
}

int Xuly_Ql_sach_Them_sach() 
{
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	std::string str[50];
    int flag_exit = 0;

	for (int i = 0; i < sh; i++)
	{
		dien_x[i] = kht[i][1].Get0x()+2;
		dien_y[i] = kht[i][1].Get0y() + 5/2;
		str[i] = " ";
	}
	Show_point(true);
    gotoxy(dien_y[0], dien_x[0]);
	
	while (!flag_exit)
	{
			//Sleep(5);
			Show_point(true);
			char kk = _getch();
			//xoa thong bao
			lcht1.Doinen(0);
			lcht2.Doinen(0);
			gotoxy(33, 90);
			std::cout << "                           " << endl;

			if (kk == -32)
			{
				char cc = _getch();
				if (cc == 80)
				{
					tt_cnt++;
					if (tt_cnt >6 ) tt_cnt = 0;
				}
				if (cc == 72)
				{
					tt_cnt--;
					if (tt_cnt < 0) tt_cnt = 6;
				}
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
			if (30 < kk && kk < 122)
			{
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				std::cout << str[tt_cnt];
				Show_point(true);
			}
		
			if (kk == 8)
			{
				if (!str[tt_cnt].empty())
				{
					str[tt_cnt].pop_back();
				}
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				for (int i = 0; i < str[tt_cnt].length() + 2; i++)
				{
					std:: cout << " ";
				}
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				std::cout << str[tt_cnt];
				Show_point(true);
			}	
			
			if (kk == 13)
			{
				tt_cnt++;
				if (tt_cnt > 6) tt_cnt = 0;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

			}
			if (kk == 19)
			{
				int vt_lcht = 0;
				lcht1.Doinen(2);
				
				while(1)
				{
					Show_point(false);
					char t_kk = _getch();
					if (t_kk == -32)
					{
						char t_cc = _getch();
						if (t_cc == 75 || t_cc == 77)
						{
							if (vt_lcht == 0)
							{
								vt_lcht = 1;
								lcht1.Doinen(0);
								lcht2.Doinen(2);
							}
							else
							{
								vt_lcht = 0;
								lcht1.Doinen(2);
								lcht2.Doinen(0);
							}
						}
					}
					if (t_kk == 13) 
					{
						if (vt_lcht == 0) 
						{
							for (int i = 0; i < sh; i++)
							{
								kht[i][1].SetNoiDung(str[i]);
							}
							textcolor(WHITE);
							std::string tt_sach =   kht[0][1].GetNoiDung()  + " ; "
								                  + kht[1][1].GetNoiDung()  + " ; "
				                                  + kht[2][1].GetNoiDung()  + " ; "
							                      + kht[3][1].GetNoiDung()  + " ; "
											      + kht[4][1].GetNoiDung()  + " ; "
												  + kht[5][1].GetNoiDung()  + " ; "
												  + kht[6][1].GetNoiDung()  + " ; \n ";
							//them bien static so luong sach
							Ghifile("Ql_tt_sach.txt", tt_sach);
							gotoxy(33, 90);
							std::cout << "Ban da luu" << endl;
							flag_exit = 1;
						}
						if (vt_lcht == 1) 
						{
							gotoxy(33, 90);
							std::cout << "Ban da huy" << endl;
							flag_exit = 0;
						}
					    break;
					}
					if (t_kk == 27)
					{
						return 1;
					}
				}
				SetBGColor(0);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
			if (kk == 27)
			{
				return 1;
			}
	}
	return 0;
}

void Hienthi_Ql_sach_ds()
{
	textcolor(WHITE);
	SetBGColor(0);

	Khunghienthi htmain(0, 10, 41, 120, 0, 0);
	htmain.DrawKhunghienthi();
	ThanhNgang(5, 11, 120, BLACK, WHITE, char(205));

	gotoxy(0 + 5 / 2 - 1, 10 + 120 / 2 - 29 / 2);
	std::cout << "CHUONG TRINH QUAN LY THU VIEN" << endl;
	gotoxy(0 + 5 / 2, 10 + 120 / 2 - 30 / 2);
	std::cout << "BTL NGON NGU LAP TRINH - 20201" << endl;
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 20 / 2);
	std::cout << "GIAO DIEN DANH SACH SACH" << endl;
	/**********************************************************/

	std::string danhmuc_hang[20] = { "Stt", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
	std::string danhmuc_cot[10] = { "Stt", "Ma sach","Ten sach", "Tac gia", "Nha xuat ban",
									"Nam xb", "Trang thai","vi tri" };
	int vt_cot[10] = { 7, 12, 30, 20, 20, 10, 14, 10 };
	int vt_hang[15] = { 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3 };

	int v_stt[100], v_nam_xb[100];
	std::string v_masach[100], v_ten_sach[1000], v_ten_tg[100], v_ten_nxb[100], v_trangthai[100], v_vitri[100];

	std::string data = Getfile("Ql_tt_sach.txt");

	Table tb2(7, 12, vt_hang, vt_cot, 0);
	tb2.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb2.CreatTable(kht2, sh2, sc2);

	gotoxy(38, 13 + 60 - 5);
	std::cout << "Trang " << vt_trang << "/" << sl_trang << endl;
	/******************************** Xu ly data *****************************************************/

	char c;
	int cnt_hang = 0, cnt_cot = 0;
	std::string str_tt_sach = "", t_data;
	for (int i = 0; i < data.length(); i++)
	{
		c = data.at(i);

		if (c == '\n')
		{
			so_luong_sach++;
			value_count++;
			cnt_hang++;

	        kht2[cnt_hang][0].SetNoiDung(std::to_string(value_count));
			kht2[cnt_hang][0].AddNoidung();

			cnt_cot = 1; 
			str_tt_sach = "";
			c = ' ';
		}

    	if (c == ';')
		{
			t_data = Xoa_khoang_trang_thua(str_tt_sach);
			kht2[cnt_hang][cnt_cot].SetNoiDung(t_data);
			kht2[cnt_hang][cnt_cot].AddNoidung();
			cnt_cot++;
			str_tt_sach = "";
		}
		else
			str_tt_sach += c;
	}

	kht2[cnt_hang][0].SetNoiDung(" ");
	kht2[cnt_hang][0].AddNoidung();

	gotoxy(39, 13);
	std::cout << "Huong dan:"<< cnt_hang <<endl;
	while (1) {
		char kk = _getch();
		if (kk == 27)
		{
			break;
		}
	}
}