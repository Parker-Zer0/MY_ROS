//1.ros的头文件
#include "ros/ros.h"

//2.编写main函数
int main(int argc, char *argv[])
{
    //3.执行 ros 节点初始化
    ros::init(argc,argv,"helloworld_node_in_cpp");
    //创建 ros 节点句柄(非必须)
    ros::NodeHandle n;
    //控制台输出 hello world
    //4.输出日志
    ROS_INFO("hello world! by Cpp");

    return 0;
}
