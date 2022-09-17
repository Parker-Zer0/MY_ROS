#! .usr/bin/env python
#coding=utf-8
#如果py编码错误，在文件开头加入 # -*- coding: UTF-8 -*-    或者 #coding=utf-8 就行了

#导包
import rospy
#入口
if __name__=="__main__":
            #初始化ros节点
            rospy.init_node("hello_p")
            #输出日志
            rospy.loginfo("hello,这里是python")