//
// Created by Mac on 2024/6/27.
//
#pragma once
#ifndef COMPUTERROOM_STUDENT_H
#define COMPUTERROOM_STUDENT_H

#include "iostream"
#include "string"

using namespace std;

#include "identity.h"

//学生类
class Student : public identity {
public:
    //默认构造
    Student();

    //有参构造   参数:学号 姓名 密码
    Student(int id, string name, string pwd);

    //菜单界面
    virtual void openMenu();

    //申请预约
    void applyOrder();

    //查看自身预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_Id;

};


#endif //COMPUTERROOM_STUDENT_H
