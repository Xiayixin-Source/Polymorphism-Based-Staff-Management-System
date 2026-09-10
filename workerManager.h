#pragma once//防止头文件重复包含
#include<iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

class WorkerManager {
public:
	WorkerManager();
	//展示菜单
	void show_Menu();
	//退出系统
	void ExistSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//添加职工
	void Add_Emp();
	~WorkerManager();
};