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

## Compile CV-Bridge from Source
```python
The defauly cv-bridge packages compiled against default opencv that is part of 
ubuntu 18.04. If you compile opencv from source then there will be conflict issue.
The below method to resolve that conflict issue.
```
```bash 
# Remove system ros-melodic-cv-bridge
sudo apt-get remove ros-melodic-cv-bridge

# Create a catkin_ws 
source /opt/ros/melodic/setup.bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make

cd src && git clone https://github.com/ros-perception/vision_opencv && git checkout melodic

vim vision_opencv/cv_bridge/CMakeLists.txt
# Edit OpenCV PATHS in CMakeLists and include cmake file
find_package(OpenCV 3 REQUIRED PATHS /usr/local/share/OpenCV NO_DEFAULT_PATH
  COMPONENTS
    opencv_core
    opencv_imgproc
    opencv_imgcodecs
  CONFIG
)
include(/usr/local/share/OpenCV/OpenCVConfig.cmake) #under catkin_python_setup()

# Build
cd .. && catkin_make

# Source the Package path
source devel/setup.bash
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

## Image transport
