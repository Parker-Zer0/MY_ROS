#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

/*
    客户端：提交两个整数，并处理响应

        1.包含头文件
        2.创建ROS节点
        3.创建节点句柄
        4.创建客户端对象
        5.提交请求并处理响应
        
        实现参数的动态提交：
            1.格式 rosrun xxxxx xxxxx 12 34
            2.节点执行时，需要获取命令中的参数，并组织进request
*/

int main(int argc ,char *argv[]){
    setlocale(LC_ALL,"");

    //优化实现，获取命令中的参数
    if (argc !=3){
        ROS_INFO("提交的参数个数不对");
        return 1;
    }

    
    // 2.创建ROS节点
    ros::init(argc,argv,"daBao");
    // 3.创建节点句柄
    ros::NodeHandle nh;
    // 4.创建客户端对象
    ros::ServiceClient client=nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    // 5.提交请求并处理响应

    //调用判断服务器状态的函数
    //A.
    client.waitForExistence();
    //B.
    //ros::service::waitForService("addInts");

    plumbing_server_client::AddInts ai;
    //5.1组织请求
    ai.request.num1 =atoi(argv[1]);
    ai.request.num2 =atoi(argv[2]);
    //5.2处理响应
    bool flag = client.call(ai); 
    if (flag){
        ROS_INFO("响应成功");
        //获取结果
        ROS_INFO("响应结果 = %d",ai.response.sum);
    }else{
        ROS_INFO("响应失败");
    }
    
    return 0;
}