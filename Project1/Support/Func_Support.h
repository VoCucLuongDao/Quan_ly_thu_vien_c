#pragma once 
#include <stdio.h> 
#include <conio.h>
#include <tchar.h> 
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

// Cac HotKey
// Quay con tro ve 1 don vi char
#define BACKSPACE 8
// OK
#define ENTER 13
// thoat truc tiep va ve Menu chinh
#define ESC  27
// Di len
#define KEY_UP 72
// Di xuong
#define KEY_DOWN 80
// Di qua trai
#define KEY_LEFT 75
// Di qua phai 
#define KEY_RIGHT 77
// Luu
#define KEY_F2 60
// Xoa
#define KEY_F3 61
// Hieu chinh
#define KEY_F4 62
// Save
#define KEY_F10 68
// Cuon page xuong duoi
#define PAGE_DOWN 81
// Cuon page len tren
#define PAGE_UP 73
// Khoang trang
#define SPACE  32
//  Tim kiem
#define KEY_F9 67

// Tro ve
#define TAB 9

// thay unsigned int thanh uint
typedef unsigned int uint;

// ma mau
#define AQUA 3
#define PURPLE 5
#define LIGHT_AQUA 11
#define LIGHT_YELLOW 14
#define LIGHT_GREEN 10 
#define BLACK 0
#define WHITE 7
#define GREEN 2
#define BRIGHT_WHITE 15
#define BLUE 1
#define LIGHT_RED 12
#define LIGHT_ORANGE 78

// size man hinh
#define GWIDTH 120
#define GHEIGHT 36

void Disable_maximize();
void Close_windows_console();
void gotoxy(short y, short x);
int wherex(void);
int wherey(void);
void textcolor(WORD color);
void SetBGColor(WORD color);
void setColor(int maunen, int mauchu);
void Show_point(bool value);

bool KiemTraTen(string);
void ThongBaoNhapNhay(string s, int maunen, int mauchu, int cot, int hang);
void BangThongBaoLoi(string);
void XoaBangThongBaoLoi();
void KhungHinh(int, int, int, int);
void XoaMang(int y, int x, int h, int w, int color);
bool KiemTraNhapSoNguyen(char a[], int &DuLieu);
void BangLuaChon(int y, int x, string noidung, bool &btn_Co);
void KhungNhapMaDocGia(int y, int x);
void ThanhTru(int y, int x, int maunen, int mauchu, int makitu);
void ThanhNgang(int y, int x, int w, int maunen, int mauchu, int makitu);
void KhungNho(int y, int x, int w, int h, string noidung , int bg);

void Ghifile(string name_file, std::string data);
void Docfile(int y, int x, string namefile);
std::string Getfile(string name_file);

std::string Xoa_khoang_trang_dau_cuoi(std::string data);
std::string Xoa_khoang_trang_giua(std::string data);
std::string Xoa_khoang_trang_thua(std::string t_data);
