//
// Created by Mac on 2024/6/27.
//
#pragma
#ifndef COMPUTERROOM_MANAGER_H
#define COMPUTERROOM_MANAGER_H
#include "iostream"
#include "string"
#include "fstream"
#include "globalFile.h"
#include "vector"
#include "student.h"
#include "teacher.h"
#include "algorithm"
#include "computerRoom.h"
using namespace std;
#include "identity.h"
//管理者类
class Manager:public identity
{
public:
    //默认构造
    Manager();
    //有参构造
    Manager(string name,string pwd);
    //菜单界面
    virtual void openMenu();
    //添加账号
    void addPerson();
    //查看账号
    void showPerson();
    //查看机房信息
    void showComputer();
    //清空预约记录
    void cleanFile();
    //初始化容器
    void initVector();
    //去重 //参数1 检测学号 2.检测类型
    bool checkRepeat(int id,int type);
    //学生容器
    vector<Student>vStu;
    //教师
    vector<Teacher>vTea;
    //机房信息
    vector<ComputerRoom>vCom;
};


#endif //COMPUTERROOM_MANAGER_H
