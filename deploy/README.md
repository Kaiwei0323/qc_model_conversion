# Environment Setup

## Prerequisites
* OS: Ubuntu 22.04
* SNPE SDK: v2.22.6.240515
* Model: YOLOv5 or YOLOv8

## SNPE SDK Installation
[SNPE SDK](https://www.qualcomm.com/developer/software/neural-processing-sdk-for-ai)

[ANDROID NDK](https://dl.google.com/android/repository/android-ndk-r26c-linux.zip)

## Setup SNPE Environment
```
conda create --name snpe python=3.10
conda activate snpe
export SNPE_ROOT=/home/inventec/Documents/Qualcomm/model_conversion/v2.22.6.240515/qairt/2.22.6.240515
${SNPE_ROOT}/bin/check-python-dependency
sudo bash ${SNPE_ROOT}/bin/check-linux-dependency.sh
sudo apt-get install make
export ANDROID_NDK_ROOT=/home/inventec/Documents/Qualcomm/model_conversion/android-ndk-r26c-linux/android-ndk-r26c
export PATH=${ANDROID_NDK_ROOT}:${PATH}
${SNPE_ROOT}/bin/envcheck -c
pip install onnx==1.12.0
pip install onnxruntime==1.17.1
pip install ultralytics
source ${SNPE_ROOT}/bin/envsetup.sh
```
