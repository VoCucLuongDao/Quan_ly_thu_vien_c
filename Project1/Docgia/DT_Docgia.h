#ifndef _DT_DOCGIA_H_
#define _DT_DOCGIA_H_
#include "iostream"
#include "string"
#include "../Support/date_ht.h"

class DT_Docgia
{
private:
	std::string Ma_docgia;
	std::string Hoten;
	v_date Ngaysinh;
	std::string SDT;
	std::string Gioitinh;
	std::string Trangthai;
public:
	DT_Docgia();
	DT_Docgia(std::string t_Ma_Doc_Gia, std::string t_Hoten, v_date t_Ngaysinh, std::string SDT, std::string t_Gioitinh, std::string t_Trangthai);
};

#endif