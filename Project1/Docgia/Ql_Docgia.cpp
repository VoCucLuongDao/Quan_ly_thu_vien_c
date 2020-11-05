#include "Ql_Docgia.h"

/************ Them doc gia ***************/
Khunghienthi kht_dg[50][50];
Khunghienthi lcht1_dg, lcht2_dg;
int sh_dg = 0, sc_dg = 0;
/*********** Hien thi ds **************
Khunghienthi kht2[50][50];
int sh2 = 0, sc2 = 0;
int so_luong_doc_gia = 0, value_count = 0;
int vt_trang = 1, sl_trang = 1;
/*************************************/

void Khung_Ql_sach_Them_docgia()
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
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 22 / 2);
	std::cout << "GIAO DIEN THEM DOC GIA" << endl;
	/**********************************************************/

	std::string danhmuc_hang[10] = { "Ma so: ",
									 "Ho ten: ",
									 "Ngay sinh: ",
									 "Gioi tinh: ",
									 "So dien thoai: ",
									 "Trang thai: " };
	std::string danhmuc_cot[10] = { "", " " };
	int vt_cot[10] = { 20,45 };
	int vt_hang[10] = { 5, 5, 5, 5, 5, 5};

	Table tb(8, 12, vt_hang, vt_cot, 0);
	tb.Set_danhmuc(danhmuc_hang, danhmuc_cot);
	tb.CreatTable(kht_dg, sh_dg, sc_dg);
	
	gotoxy(23, 90);
	std::cout << "Ban muon luu va thoat ?" << endl;

	lcht1_dg.SetToaDo(25, 80);
	lcht1_dg.SetKichThuoc(3, 20);
	lcht1_dg.SetBackground(0);
	lcht1_dg.SetNoiDung("Save");
	lcht1_dg.DrawKhunghienthi();

	lcht2_dg.SetToaDo(25, 105);
	lcht2_dg.SetKichThuoc(3, 20);
	lcht2_dg.SetBackground(0);
	lcht2_dg.SetNoiDung("Cancel");
	lcht2_dg.DrawKhunghienthi();

	gotoxy(30, 90);
	std::cout << "Su dung phim Ctrl+S de luu" << endl;
	gotoxy(31, 90);
	std::cout << "Su dung phim Esc de thoat" << endl;
}

int Xuly_Ql_sach_Them_docgia()
{
	int dien_x[50];
	int dien_y[50];
	int tt_cnt = 0;
	std::string str[50];
	int flag_exit = 0;
	v_date t_date;

	for (int i = 0; i < sh_dg; i++)
	{
		dien_x[i] = kht_dg[i][1].Get0x() + 2;
		dien_y[i] = kht_dg[i][1].Get0y() + 5 / 2;
		str[i] = " ";
	}
	str[2] = "  /  /    ";
	gotoxy(dien_y[2], dien_x[2]);
	std::cout << str[2];
	Show_point(true);
	gotoxy(dien_y[0], dien_x[0]);

	while (!flag_exit)
	{
		//Sleep(5);
		Show_point(true);
		char kk = _getch();
		//xoa thong bao
		lcht1_dg.Doinen(0);
		lcht2_dg.Doinen(0);
		gotoxy(33, 90);
		std::cout << "                           " << endl;

		if (kk == -32)
		{
			char cc = _getch();
			if (cc == 80)
			{
				tt_cnt++;
				if (tt_cnt > 5) tt_cnt = 0;
			}
			if (cc == 72)
			{
				tt_cnt--;
				if (tt_cnt < 0) tt_cnt = 5;
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
		}
		if (30 < kk && kk < 122)
		{
			if (tt_cnt != 2) {
				str[tt_cnt].push_back(kk);
				Show_point(false);
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				std::cout << str[tt_cnt];
				Show_point(true);
			}
			else
			{
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
				str[2] = Suadate2(kk, str[2]);
				tt_cnt++;
				gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			}
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
				std::cout << " ";
			}
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);
			std::cout << str[tt_cnt];
			Show_point(true);
		}

		if (kk == 13)
		{
			tt_cnt++;
			if (tt_cnt > 5) tt_cnt = 0;
			gotoxy(dien_y[tt_cnt], dien_x[tt_cnt]);

		}
		if (kk == 19)
		{
			int vt_lcht = 0;
			lcht1_dg.Doinen(2);

			while (1)
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
							lcht1_dg.Doinen(0);
							lcht2_dg.Doinen(2);
						}
						else
						{
							vt_lcht = 0;
							lcht1_dg.Doinen(2);
							lcht2_dg.Doinen(0);
						}
					}
				}
				if (t_kk == 13)
				{
					if (vt_lcht == 0)
					{
						for (int i = 0; i < sh_dg; i++)
						{
							kht_dg[i][1].SetNoiDung(str[i]);
						}
						textcolor(WHITE);
						std::string tt_docgia = kht_dg[0][1].GetNoiDung() + " ; "
												+ kht_dg[1][1].GetNoiDung() + " ; "
												+ kht_dg[2][1].GetNoiDung() + " ; "
												+ kht_dg[3][1].GetNoiDung() + " ; "
												+ kht_dg[4][1].GetNoiDung() + " ; "
												+ kht_dg[5][1].GetNoiDung() + " ; \n";
			
						//them bien static so luong sach
						Ghifile("Ql_tt_docgia.txt", tt_docgia);
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
void Hienthi_Ql_docgia_ds()
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
	gotoxy(0 + 5 / 2 + 1, 10 + 120 / 2 - 27 / 2);
	std::cout << "GIAO DIEN DANH SACH DOC GIA" << endl;
	/**********************************************************

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
	/******************************** Xu ly data *****************************************************

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
	std::cout << "Huong dan:" << cnt_hang << endl;
	while (1);
	*/
}