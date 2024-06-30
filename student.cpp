//
// Created by Mac on 2024/6/27.
//
#include "student.h"

//默认构造
Student::Student() {

}

//有参构造   参数:学号 姓名 密码
Student::Student(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_pwd = pwd;
}

//菜单界面
void Student::openMenu() {
    cout << "欢迎学生代表:" << this->m_Name << "登陆!" << endl;
    cout << "\t\t------------------------\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          1.申请预约    |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          2.查看我的预约  |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          3.查看所有预约  |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          4.取消预约     |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t|          0.退出        |\n";
    cout << "\t\t|                       |\n";
    cout << "\t\t------------------------\n";
    cout << "输入您的选择:";
}

//申请预约
void Student::applyOrder() {

}

//查看自身预约
void Student::showMyOrder() {

}

//查看所有预约
void Student::showAllOrder() {

}

//取消预约
void Student::cancelOrder() {

}

