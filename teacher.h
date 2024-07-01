//
// Created by Mac on 2024/6/27.
//
#pragma once
#ifndef COMPUTERROOM_TEACHER_H
#define COMPUTERROOM_TEACHER_H
#include "iostream"
#include "string"
#include "orderFile.h"
#include "vector"
using namespace std;
#include "identity.h"
//教师类
class Teacher:public identity
{
public:
    //默认构造
    Teacher();
    //有参构造
    Teacher(int empId,string name,string pwd);

    //菜单
    virtual void openMenu();
    //查看所有预约
    void showAllOrder();
    //审核预约
    void validOrder();
    //职工号
    int m_EmpId;

};


#endif //COMPUTERROOM_TEACHER_H
