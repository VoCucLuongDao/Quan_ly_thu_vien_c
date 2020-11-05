#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_
    #include "iostream"
    #include <iomanip>      
    #include ".\Support\Func_Support.h"
    #include ".\Support\Khunghienthi.h"
    #include ".\Support\Table.h"

    void SetWindowSize(SHORT width, SHORT height);
	void Creat_main_guide(int &lua_chon);
	void Creat_timkiemsach_guide();
	void Creat_qlmuontra_guide();
	void Creat_qldocgia_guide();
	void Creat_qlsach_guide();
	void Creat_topyeuthich_guide(); 
	void Creat_danhsachsachchuatra_guide();
	void Creat_danhsachdocgiaquahan_guide();
	void Creat_thongkedulieu_guide();
	void Creat_caidattrogiup_guide();
	/*****************************************************************/
#endif