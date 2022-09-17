#! /usr/bin/env python3
import rospy

"""
    需求：修改乌龟GUI的颜色

        1.初始化ROS节点
        2.设置参数

"""

if __name__ =="__main__":
    rospy.init_node("change_bgColor_p")
    #修改背景色
    rospy.set_param("/turtlesim/background_r",100)
    rospy.set_param("/turtlesim/background_g",50)
    rospy.set_param("/turtlesim/background_b",200)

    