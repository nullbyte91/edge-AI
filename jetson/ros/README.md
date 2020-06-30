# Getting Started with ROS on Jetson Nano

## Installation

```bash
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

sudo apt update

# Start with ros base then install necessary packages 
sudo apt install ros-melodic-ros-base
```

## Environment setup

```bash
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc

source /opt/ros/melodic/setup.bash

echo "source /opt/ros/melodic/setup.zsh" >> ~/.zshrc
source ~/.zshrc
```

## Dependencies for building packages

```bash
sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential

sudo apt install python-rosdep

sudo rosdep init
rosdep update
```

## Hello world - Simple publisher subscriber(c++)
```
mkdir -p pubsub/build/
cmake ..
make 

# Terminal 1
roscore

# Terminal 2
./build/talker

# Terminal 3
./build/listener
```