//
// Created by Mac on 2024/6/27.
//
#pragma once
#ifndef COMPUTERROOM_IDENTITY_H
#define COMPUTERROOM_IDENTITY_H

#include "iostream"

using namespace std;

//身份抽象基类
class identity {
public:
    //操作子菜单 纯虚函数
    virtual void openMenu() = 0;

    //用户名
    string m_Name;
    //密码
    string m_pwd;
};

#endif //COMPUTERROOM_IDENTITY_H
