#include "DT_Docgia.h"

DT_Docgia::DT_Docgia()
{
	this->Ma_docgia = " ";
	this->Hoten = " ";
	this->Ngaysinh.Ngay = 1;
	this->Ngaysinh.Thang = 1;
	this->Ngaysinh.Nam = 1900;
	this->SDT = "000000000";
	this->Gioitinh = " ";
	this->Trangthai = " ";
}

DT_Docgia::DT_Docgia(std::string t_Ma_Doc_Gia, std::string t_Hoten, v_date t_Ngaysinh, std::string t_SDT, std::string t_Gioitinh, std::string t_Trangthai)
{
	this->Ma_docgia = t_Ma_Doc_Gia;
	this->Hoten = t_Hoten;
	this->Ngaysinh.Ngay = t_Ngaysinh.Ngay;
	this->Ngaysinh.Thang = t_Ngaysinh.Thang;
	this->SDT = t_SDT;
	this->Gioitinh = t_Gioitinh;
	this->Trangthai = t_Trangthai;
}
