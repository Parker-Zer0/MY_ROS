// 需求: 实现基本的话题通信，一方发布数据，一方接收数据，
    //      实现的关键点:
    //      1.发送方
    //      2.接收方
    //      3.数据(此处为普通文本)

    //      PS: 二者需要设置相同的话题


    // 消息发布方:
    //     循环发布信息:HelloWorld 后缀数字编号

    // 实现流程:
    //     1.包含头文件 
    //     2.初始化 ROS 节点:命名(唯一)
    //     3.实例化 ROS 句柄
    //     4.实例化 发布者 对象
    //     5.组织被发布的数据，并编写逻辑发布数据

// 1.包含头文件 
#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息
#include <sstream>

int main(int argc, char  *argv[])
{   
setlocale(LC_ALL,"");

//2.初始化ROS节点：
/*
作用：ros初始化函数
参数：
    1.argc            ---封装实参的个数(n+1,第一个为文件自身)
    2.argv            ---封装参数的数组
    3.name          ---为节点命名（唯一性）
    4.options      ---节点启动选项

    返回值:void
使用：
    1.argc与argv的使用
        如果按照ros中的特定格式传入参数，那么ros可以加以使用，比如用来设置全局参数，给节点重命名等

        rosrun plumbing_apis plumbing_apis_pub  _length:=2(保持运行)
        rosparam get /erGouZi/length(后运行，会显示 2 )

    2.options的使用
        节点名称需要保证唯一，会导致同一节点不能重复启动（同样名字，后一个开启瞬间，会将前一个重名的关闭）
        
        现需求：可以多开
        解决方式：在原来节点名称的基础上添加随机数，从而保证不会重复
        在多次运行rosrun plumbing_apis plumbing_apis_pub之后
        使用
*/

//添加多开之前：ros::init(argc,argv,"erGouZi");
ros::init(argc,argv,"erGouZi",ros::init_options::AnonymousName);
//3.创建节点句柄；
ros::NodeHandle nh;
//4.创建发布者对象；
ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
//5.编写发布逻辑并发布数据
//要求以10Hz的频率发布数据，并且文本后添加编号
//先创建被发布的消息
std_msgs::String msg;
//发布频率
ros::Rate rate(1);
//设置编号
int count =1;
std::string msg_front = "Hello 你好！";

//保证能够正常发送与接收第一条信息
//延长注册时间
ros::Duration(3).sleep();
//节点不死
while (ros::ok())
{
    //使用 stringstream 拼接字符串与编号
    std::stringstream ss;
    ss << msg_front << count;
    msg.data = ss.str();
    //发布消息
    pub.publish(msg);
    //加入调试，打印发送的消息
    ROS_INFO("发送的消息:%s",msg.data.c_str());

    //根据前面制定的发送贫频率自动休眠 休眠时间 = 1/频率；
    rate.sleep();
    count++;//循环结束前，让 count 自增
    //暂无应用
    ros::spinOnce();
    }


return 0;
}
