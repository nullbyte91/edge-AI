# Jetson Nano
## Getting Started
![Beaglebone AI](../images/jetson-nano-dev-kit-top-r6-HR-B01.png "Beaglebone")


1. microSD card slot for main storage
2. 40-pin expansion header
3. Micro-USB port for 5V power input or for data
4. Gigabit Ethernet port
5. USB 3.0 ports (x4)
6. HDMI output port
7. DisplayPort connector
8. DC Barrel jack for 5V power input
9. MIPI CSI camera connectors

###  microSD card Prepration
1. Download Jetson Nano Developer Kit SD Card image [Jetpack4.4 Image](https://developer.nvidia.com/jetson-nano-sd-card-image).
2. Use [etcher](https://www.balena.io/etcher) to burn a image.

### System dependencies
```bash
sudo apt-get update
sudo apt-get install -y build-essential make cmake cmake-curses-gui
sudo apt-get install -y git g++ pkg-config curl libfreetype6-dev
sudo apt-get install -y libcanberra-gtk-module libcanberra-gtk3-module
sudo apt-get install -y python3-dev python3-testresources python3-pip
sudo pip3 install -U pip
```

### Install Tensorflow

```bash
# Tensorflow dep
sudo apt-get install -y libhdf5-serial-dev hdf5-tools libhdf5-dev zlib1g-dev zip libjpeg8-dev liblapack-dev libblas-dev gfortran
sudo pip3 install -U pip testresources setuptools
sudo pip3 install -U numpy==1.16.1 future mock h5py keras_preprocessing keras_applications gast futures pybind11
```

```bash
# Latest Version
sudo pip3 install --pre --extra-index-url https://developer.download.nvidia.com/compute/redist/jp/v44 tensorflow-gpu
```

```bash
# Tensorflow 1.x
sudo pip3 install --pre --extra-index-url https://developer.download.nvidia.com/compute/redist/jp/v44 tensorflow==1.15.2
```

```bash
# Test
python3 -c "import tensorflow as tf" 
```
