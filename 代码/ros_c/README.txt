工作空间名称：ros_c
ROS功能包名称：helloworld_power_c
cpp内节点名称：helloworld_node_in_cpp
cpp文件名称：helloworld_c.cpp
用于映射的节点名称名称：helloworld_c_node


source ~/工作空间/devel/setup.bash可以添加进.bashrc文件，使用上更方便
可以在任意终端下执行
否则需要每次都
cd 工作空间
source ./devel/setup.bash
rosrun 包名 C++节点


添加方式1: 直接使用 gedit 或 vi 编辑 .bashrc 文件，最后添加该内容（建议）

添加方式2:echo "source ~/工作空间/devel/setup.bash" >> ~/.bashrc
工作空间：For_ros
包名：    hello
节点：    haha

记得跑的时候先另开一个roscore
