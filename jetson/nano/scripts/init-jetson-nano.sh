#!/bin/bash

set -e

dirCuda="/usr/local/cuda/"

# Main starts from here
# System update
sudo apt-get update && sudo apt-get upgrade

# CUDA Env path
if [ -d "$dirCuda" ]; then
  echo "** Add CUDA stuffs into ~/.bashrc"
  echo >> ${HOME}/.bashrc
  echo "export PATH=/usr/local/cuda/bin:\${PATH}" >> ${HOME}/.bashrc
  echo "export LD_LIBRARY_PATH=/usr/local/cuda/lib64:\${LD_LIBRARY_PATH}" >> ${HOME}/.bashrc
fi

# Enable Swap
sudo fallocate -l 8G /mnt/8GB.swap
sudo mkswap /mnt/8GB.swap
sudo swapon /mnt/8GB.swap
if ! grep swap /etc/fstab > /dev/null; then \
    echo "/mnt/8GB.swap  none  swap  sw  0  0" | sudo tee -a /etc/fstab; \
fi

# Enable 10 W Performance
sudo nvpmodel -m 0
sudo jetson_clocks

