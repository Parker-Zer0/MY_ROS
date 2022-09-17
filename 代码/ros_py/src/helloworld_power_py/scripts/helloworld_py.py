#! /usr/bin/env python
# coding=UTF-8<code>
##指定解释器

#导包
import rospy

#编写主入口
if __name__ == "__main__":
    #初始化ROS节点
    rospy.init_node("Hello")
    #输出日志
    rospy.loginfo("Hello World!!!!")

