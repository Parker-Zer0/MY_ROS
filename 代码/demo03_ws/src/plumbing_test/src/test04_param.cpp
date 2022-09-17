#include "ros/ros.h"

/*
    需求：修改参数服务器中的turtlesim背景色相关的参数
        1.初始化ros节点
        2.不一定需要创建节点句柄
        3.修改参数
*/

int main(int argc, char *argv[])
{
        // 1.初始化ros节点
    ros::init(argc,argv,"change_bgColor");
        // 2.不一定需要创建节点句柄
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r",0);
    nh.setParam("background_g",0);
    nh.setParam("background_b",0);
        // 3.修改参数
        //如果调用ros::param 不需要创建节点句柄
    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);

    
    return 0;
}
