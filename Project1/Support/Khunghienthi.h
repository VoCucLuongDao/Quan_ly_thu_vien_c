#pragma once
#include "iostream"
#include "string"
#include "Func_Support.h"

class Khunghienthi
{
private:
	int toado_0x;
	int toado_0y;
	int chieucao;
	int chieurong;
	int modevien;
	int maubackgound;
	std::string noidung;
public:
	Khunghienthi();
	Khunghienthi(int y, int x, int h, int w, int bg, int mode_vien);
	Khunghienthi(int y, int x, int h, int w, int bg);

	void SetToaDo(int ,int );
	void SetKichThuoc(int ,int );
	void SetModeVien(int );
	void SetBackground(int );
	void SetNoiDung(std::string);
	int  Get0y();
	int  Get0x();
	std::string GetNoiDung();
	void DrawKhunghienthi();
	void XoaNoiDung(int );
	void XoaAll(int );

	void AddNoidung();
	void Doinen(int );
};

