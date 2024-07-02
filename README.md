# ComputerRoomManageMentSystem
# ComputerRoomManageMentSystem

first!!! 
ips: order.txt student.txt teacher.txt Computerroom.txt admin.txt 需在cmake-build-debug 下建立
并给student.txt teacher.txt admin.txt  按照初始写入格式:1 admin 123
在Computerroom.txt 写入电脑室的大小信息
1 20
2 50
3 100
ok~ play it


王牌飞行员大学预约系统
这是一个基于C++的简单预约系统，适用于学生、教师和管理员身份。该系统允许学生预约、取消预约，教师审核预约，管理员管理账号和机房信息等功能。

文件结构
main.cpp: 主程序入口，包含用户登录和身份验证功能。
identity.h: 身份类的声明文件，包括学生（Student）、教师（Teacher）、管理员（Manager）的基本信息和操作。
globalFile.h: 全局文件声明，包括预约信息等。
student.h: 学生类的声明和实现，包括预约申请、查看预约等功能。
teacher.h: 教师类的声明和实现，包括审核预约等功能。
manager.h: 管理员类的声明和实现，包括添加账号、清空预约等功能。
如何使用
编译和运行：

使用C++编译器编译 main.cpp 文件。
运行生成的可执行文件，根据提示选择身份和操作。
登录信息：

学生登录需要学号、用户名和密码。
教师登录需要职工号、用户名和密码。
管理员登录需要用户名和密码。
功能说明：

学生功能包括预约申请、查看个人和所有人预约、取消预约。
教师功能包括查看所有预约、审核预约。
管理员功能包括添加账号、查看账号、查看机房信息、清空预约。
注意事项
确保运行环境中包含C++编译器和支持文件操作的运行环境。
文件路径和权限需要根据实际情况进行设置和调整。


README (English)

ips: order.txt student.txt teacher.txt Computerroom.txt admin.txt must be created in cmake-build-debug 
txt is written to student.txt teacher.txt admin. TXT in the initial format :1 admin 123 
Write the size of the computer room in Computerroom.txt 
1 20 
2 50 
3 100 
ok~ play it

Ace Pilot University Reservation System
This is a simple reservation system based on C++, suitable for students, teachers, and administrators. The system allows students to make reservations, cancel them, teachers to approve reservations, and administrators to manage accounts and room information.

File Structure
main.cpp: Main program entry, including user login and authentication functions.
identity.h: Header file for identity classes, including Student, Teacher, and Manager with their basic information and operations.
globalFile.h: Global file declarations, including reservation information.
student.h: Header and implementation of the Student class, including reservation application, view reservation functions, etc.
teacher.h: Header and implementation of the Teacher class, including approval of reservations, etc.
manager.h: Header and implementation of the Manager class, including adding accounts, clearing reservations, etc.
How to Use
Compile and Run:

Compile main.cpp using a C++ compiler.
Run the generated executable file and choose your identity and operation as prompted.
Login Information:

Students require student ID, username, and password to log in.
Teachers require employee ID, username, and password to log in.
Administrators require username and password to log in.
Functionality:

Student functionalities include reservation application, viewing personal and all reservations, canceling reservations.
Teacher functionalities include viewing all reservations, approving reservations.
Manager functionalities include adding accounts, viewing accounts, viewing room information, clearing reservations.
Notes
Ensure the environment has a C++ compiler and supports file operations.
File paths and permissions need to be adjusted according to the actual environment and setup.
