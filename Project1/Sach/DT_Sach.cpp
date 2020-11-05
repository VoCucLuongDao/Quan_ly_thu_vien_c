#include "DT_Sach.h"

DT_Sach::DT_Sach() 
{
	this -> Ma_Sach = "";
	this -> Ten_Sach = "";
	this -> Nam_xuatban = 0;
	this -> Tac_Gia = "";
	this -> Nha_Xuat_Ban = "";
	this->Trang_Thai = "";
	this -> Vi_Tri = "";
}

DT_Sach::DT_Sach(std::string t_ma_sach, std::string t_ten_sach, std::string t_tac_gia,
	            std::string t_nha_xb, int t_nam_xuat_ban, std::string t_trang_thai, std::string t_vi_tri)
{
	this->Ma_Sach = t_ma_sach;
	this->Ten_Sach = t_ten_sach;
	this->Nam_xuatban = t_nam_xuat_ban;
	this->Tac_Gia = t_tac_gia;
	this->Nha_Xuat_Ban = t_nha_xb;
	this->Trang_Thai = t_trang_thai;
	this->Vi_Tri = t_vi_tri;
}