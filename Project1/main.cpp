#include "main.h"
#include "./Support/date_ht.h"
int main()
{	
	int lua_chon = 0;
	Show_point(false);
	Disable_maximize();

	while (1) {
		Creat_main_guide(lua_chon);
		SetBGColor(0);
		system("cls");
		switch (lua_chon)
		{
		case 5:                     //1.1 Muon sach
			//Menu_Tim_Kiem(sach);
			_getch();
			break;
		case 6:                     //1.2 Tra sach
			//Creat_qlmuontra_guide();
			_getch();
			break;
		case 8:                     //2.1 Tim kiem sach
			//Creat_qldocgia_guide();
			_getch();
			break;
		case 9:                    //2.2 Them sach
				while (1)
				{
					Khung_Ql_sach_Them_sach();
					if(Xuly_Ql_sach_Them_sach())
					   
                    break;
				}
			break;
		case 10:                  //2.3 Sua thong tin sach
			//Menu_Sua(sach);
			_getch();
			break;
		case 11:                  //2.4 Xoa sach
			//Menu_Xoa(sach);
			_getch();
			break;
		case 12:                  //2.5 Ds sach
			Hienthi_Ql_sach_ds();
			_getch();
			break;
		case 14:                  //3.1 Tim kiem doc gia
			Creat_thongkedulieu_guide();
			_getch();
			break;
		case 15:                 //3.2 Them doc gia
			while (1)
			{
				Khung_Ql_sach_Them_docgia();
				if (Xuly_Ql_sach_Them_docgia())

					break;
			}
			break;
		case 16:                 //3.3 Sua thong tin doc gia
			//Creat_timkiem_guide();
			_getch();
			break;
		case 17:                  //3.4 Xoa doc gia
			Creat_qlmuontra_guide();
			_getch();
			break;
		case 18:                 //3.5 Danh sach doc gia
			Creat_qldocgia_guide();
			_getch();
			break;
		case 20:                 //4.1 Danh sach sach qua han
			Creat_qlsach_guide();
			_getch();
			break;
		case 21:                //4.2 Danh sach doc gia muon qua han
			Creat_topyeuthich_guide();
			_getch();
			break;
		case 22:                //4.3 Top sach yeu thich
			Creat_danhsachdocgiaquahan_guide();
			_getch();
			break;
		case 100:              
			Close_windows_console();
			break;
		}
		SetBGColor(0);
		system("cls");
	}
	return 0;
}