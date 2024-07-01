//
// Created by Mac on 2024/7/1.
//
#include "orderFile.h"

// 构造函数
OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }

    string date, interval, stuId, stuName, roomId, status;
    this->m_Size = 0; // 预约记录条数
    while (ifs >> date >> interval >> stuId >> stuName >> roomId >> status) {
        map<string, string> m;
        m["date"] = date.substr(date.find(":") + 1);
        m["interval"] = interval.substr(interval.find(":") + 1);
        m["stuId"] = stuId.substr(stuId.find(":") + 1);
        m["stuName"] = stuName.substr(stuName.find(":") + 1);
        m["roomId"] = roomId.substr(roomId.find(":") + 1);
        m["status"] = status.substr(status.find(":") + 1);
        this->m_orderData[this->m_Size++] = m;
    }
    ifs.close();
}

// 更新预约记录
void OrderFile::updateOrder() {
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    if (!ofs.is_open()) {
        cout << "文件打开失败！" << endl;
        return;
    }

    for (int i = 0; i < this->m_Size; i++) {
        ofs << "date:" << this->m_orderData[i]["date"] << " ";
        ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_orderData[i]["status"] << endl;
    }
    ofs.close();
}
