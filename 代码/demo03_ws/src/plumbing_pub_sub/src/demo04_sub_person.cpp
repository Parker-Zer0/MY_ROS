#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"
/*
        订阅人:订阅消息
                1.包含头文件
                #include  "plumbing_pub_sub/Person.h"
                2.初始化ROS节点
                3.创建节点句柄
                4.创建订阅者对象
                5.编写回调函数，处理订阅的数据
                6.spin()
*/

void doPerson(const plumbing_pub_sub::Person::ConstPtr& person){
        ROS_INFO("订阅人的信息%s,%d,%.2f",person->name.c_str(),person->age,person->height);
}

int main(int argc, char *argv[]){
        //防止出现中文乱码
        setlocale(LC_ALL,"");

        ROS_INFO("订阅方实现");
        // 2.初始化ROS节点
        ros::init(argc,argv,"jiaZhang");
        // 3.创建节点句柄
        ros::NodeHandle nh;
        // 4.创建订阅者对象
        ros::Subscriber sub=nh.subscribe("liaoTian",10,doPerson);
        // 5.编写回调函数，处理订阅的数据
        // 6.spin()
        ros::spin();

        return 0;
}