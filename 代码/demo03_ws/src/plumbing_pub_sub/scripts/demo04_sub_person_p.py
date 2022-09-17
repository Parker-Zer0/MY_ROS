#! /usr/bin/env python3
"""
订阅方：订阅人的消息
                1.导包
                2.初始化ROS节点
                3.创建订阅者对象
                4.处理订阅数据
                5.spin()

"""
import rospy
from plumbing_pub_sub.msg import Person

def doPerson(p):
    #4.处理订阅的数据
    rospy.loginfo("小伙子的数据：姓名:%s, 年龄:%d, 身高:%.2f",p.name, p.age, p.height)

if __name__ == "__main__":
    #2.初始化 ROS 节点
    rospy.init_node("daYe")
    #3.创建订阅者对象
    sub = rospy.Subscriber("jiaoSheTou",Person,doPerson)
    rospy.spin()
