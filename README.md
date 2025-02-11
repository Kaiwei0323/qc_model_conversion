# Qualcomm Model Conversion

## Prerequisites
* OS: Ubuntu 22.04 (X86)
* SNPE SDK: v2.22.6.240515
* Model: YOLOV8, DETR-Resnet101

## SNPE SDK Installation
* [SNPE SDK](https://www.qualcomm.com/developer/software/neural-processing-sdk-for-ai)
* [ANDROID NDK](https://dl.google.com/android/repository/android-ndk-r26c-linux.zip)

## Clone the project repository
```
git clone https://github.com/Kaiwei0323/qc_model_conversion.git
```

## SNPE Environment Setup
1. Create and Activate Conda Environment
```
conda create --name snpe python=3.10
conda activate snpe
```
2. Set Environment Variables
```
export SNPE_ROOT=/home/inventec/Documents/qualcomm/sdk/v2.22.6.240515/qairt/2.22.6.240515
export ANDROID_NDK_ROOT=/home/inventec/Documents/qualcomm/sdk/android-ndk-r26c-linux/android-ndk-r26c
```

3. Run the Setup Script
```
sudo -E ./setup_env.sh && source ${SNPE_ROOT}/bin/envsetup.sh
```

## Run Application
```
cd deploy

```

## Application UI
![Screenshot from 2024-11-14 15-18-10](https://github.com/user-attachments/assets/26157c00-17d0-435c-86d9-88597f684c60)

## Model Installation
* [DETR-ResNet101 Model on Qualcomm AI Hub](https://aihub.qualcomm.com/models/detr_resnet101?searchTerm=detr)
* [YOLOv8 Documentation](https://docs.ultralytics.com/models/yolov8/)

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
