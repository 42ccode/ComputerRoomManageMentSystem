//
// Created by Mac on 2024/7/1.
//
#pragma once
#ifndef COMPUTERROOM_ORDERFILE_H
#define COMPUTERROOM_ORDERFILE_H

#include "iostream"

using namespace std;

#include "globalFile.h"
#include "fstream"
#include "string"
#include "map"

class OrderFile {
public:
    //构造函数
    OrderFile();

    //更新预约记录
    void updateOrder();

    //记录预约条数
    int m_Size;
    //记录所有预约信息的容器  key记录条数 value 具体记录信息
    map<int, map<string, string>> m_orderData;
};

#endif //COMPUTERROOM_ORDERFILE_H
