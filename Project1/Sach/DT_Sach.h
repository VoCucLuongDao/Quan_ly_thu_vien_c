#ifndef _DT_SACH_
#define _DT_SACH_

#include "iostream"
#include "string"
class DT_Sach
{
private:
	std::string Ma_Sach;
	std::string Ten_Sach;
	std::string Tac_Gia;
	std::string Nha_Xuat_Ban;
	int Nam_xuatban;
	std::string Trang_Thai;
	std::string Vi_Tri;
public:
	DT_Sach();
	DT_Sach(std::string t_ma_sach, std::string t_ten_sach, std::string t_tac_gia, 
		    std::string t_nha_xb, int t_nam_xuat_ban, std::string t_trang_thai, std::string t_vi_tri);
	void Set_Ma_sach();

};
#endif

