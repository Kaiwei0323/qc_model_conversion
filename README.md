# Qualcomm Model Conversion

## Prerequisites
* OS: Ubuntu 22.04
* SNPE SDK: v2.22.6.240515
* Model: YOLOV8, DETR-Resnet101

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

## Download the repo
```
git clone https://github.com/Kaiwei0323/qc_model_conversion.git
```

## Run Application
```
cd qc_model_conversion/deploy
./qc_model_conversion_ui
```

## Application UI
![Screenshot from 2024-11-14 15-18-10](https://github.com/user-attachments/assets/26157c00-17d0-435c-86d9-88597f684c60)

## Model Conversion
* Step1:
Upload your ONNX model (.onnx)
* Step2:
Decide whether to encode the model 
    - If yes, upload the encoding file
* Step3:
Choose the target output folder
* Step4:
Decide whether to quantize the model
    - If yes, select the image folder (.jpg) for quantization and image input size
* Step5:
Click on the "Convert Model" button

## Model Visualization
* Step1:
Upload your DLC model (.dlc)
* Step2:
Click on the "Visualize" button

## Check Model Input / Output Layer
### YoloV8 (yolov8s_quantized_output.txt)
```
-----------------------------------------------------------------------------------------------------------------------------------------------
| Input Name  | Dimensions   | Type    | Encoding Info                                                                                        |
-----------------------------------------------------------------------------------------------------------------------------------------------
| images      | 1,640,640,3  | uFxp_8  | bitwidth 8, min -1.000000000000, max 0.992187500000, scale 0.007812500000, offset -128.000000000000  |
-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------
| Output Name  | Dimensions  | Type    | Encoding Info                                                                                        |
-----------------------------------------------------------------------------------------------------------------------------------------------
| output0      | 1,84,8400   | uFxp_8  | bitwidth 8, min -5.121949195862, max 647.926574707031, scale 2.560974597931, offset -2.000000000000  |
-----------------------------------------------------------------------------------------------------------------------------------------------
```
Summary:
* Input Layer
    - Name: images
    - Shape: (1, 640, 640, 3)
    - Type: uint8
* Output Layer
    - Name: output0
    - Shape: (1, 84, 8400)
    - Type: uint8
