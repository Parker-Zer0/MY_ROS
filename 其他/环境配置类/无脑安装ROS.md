> 这里以18的melodic为例
>
> 官网：http://wiki.ros.org/cn/ROS/Installation
>
> ros init解决参考：https://www.bilibili.com/video/BV1bg41177xC?vd_source=b22a8a85fd5162c02e33c60b51bf6270#reply125718735168



# 安装ROS

打开终端，依次输入以下命令

1.设置sources.list

```
sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.ustc.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
```

2.设置密钥

> 这里建议还是去官网对照一下密钥

```
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

3.确定软件都问最新

```
sudo apt update
```

4.安装桌面版

```
sudo apt install ros-melodic-desktop-full
```

5.安装解决方法

```
sudo apt-get install python3-pip
```

```
sudo pip3 install 6-rosdep
```

```
sudo 6-rosdep
```

6.初始化 rosdep

```
sudo rosdep init
```

```
rosdep update
```

7.设置环境

```
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
```

```
source ~/.bashrc
```

8.构建工厂依赖

```
sudo apt-get install python-rosinstall python-rosinstall-generator python-wstool build-essential
```





# 检验是否安装成功

1.运行

```
roscore
```

2.新建一个终端，运行运行turtlesim功能包

```
rosrun turtlesim turtlesim_node
```

3.新建一个终端，运行键盘控制

```
rosrun turtlesim turtle_teleop_key
```

4.如果这些步骤能正常启动和小乌龟可以由键盘正常控制行走，那么安装就比较成功了。

> 光标要停在键盘控制的窗口
