import sys
import subprocess
import os
import shutil

def convert_ONNX_model(pt_file_path, output_folder, model_type):
    try:
        base_name = os.path.splitext(os.path.basename(pt_file_path))[0]
        pt_folder_dir = os.path.dirname(pt_file_path)
        temp_onnx_file_path = os.path.join(pt_folder_dir, f"{base_name}.onnx")
        final_onnx_file_path = os.path.join(output_folder, f"{base_name}.onnx")
        if model_type == "yolov5":
            # Construct the command to call YOLOv5 export script
            yolov5_script = "../yolov5/export.py"
            command = [
                "python3", yolov5_script,
                "--weights", pt_file_path,
                "--include", "onnx",
            ]
            # Run the YOLOv5 export script
            result = subprocess.run(command, capture_output=True, text=True)
            if result.returncode == 0:
                if os.path.isfile(temp_onnx_file_path):
                    shutil.move(temp_onnx_file_path, final_onnx_file_path)
                return f"SUCCESS"
            else:
                return f"Error during conversion: {result.stderr}"
                
        elif model_type == "yolov8":
            # Construct the command to call YOLOv8 conversion
            from ultralytics import YOLO
            model = YOLO(pt_file_path)
            model.export(format="onnx")
            if os.path.isfile(temp_onnx_file_path):
                shutil.move(temp_onnx_file_path, final_onnx_file_path)
            return f"SUCCESS"
        else:
            return "Unknown model type."
           

    except Exception as e:
        return f"Error during conversion: {str(e)}"
        
def convert_DLC_model(pt_file_path, output_folder):
    try:
        base_name = os.path.splitext(os.path.basename(pt_file_path))[0]
        onnx_file_path = os.path.join(output_folder, f"{base_name}.onnx")
        dlc_file_path = os.path.join(output_folder, f"{base_name}.dlc")
       
        
        dlc_command = [
            "snpe-onnx-to-dlc",
            "--input_network", onnx_file_path,
            "--output_path", dlc_file_path
        ]
        dlc_result = subprocess.run(dlc_command, capture_output=True, text=True)
        if dlc_result.returncode != 0:
            return f"Error during DLC conversion: {dlc_result.stderr}"

        return "DLC_CONVERSION_SUCCESS"

    except Exception as e:
        return f"Error during conversion: {str(e)}"
        
def convert_DLC_quantized_model(pt_file_path, output_folder, quantize_folder):
    try:
        base_name = os.path.splitext(os.path.basename(pt_file_path))[0]
        dlc_file_path = os.path.join(output_folder, f"{base_name}.dlc")
        dlc_quantized_file_path = os.path.join(output_folder, f"{base_name}_quantized.dlc")
        dlc_quantized_image_file_path = os.path.join(quantize_folder, "image_file_list.txt")
       
        
        dlc_command = [
            "snpe-dlc-quantize",
            "--input_dlc", dlc_file_path,
            "--input_list",dlc_quantized_image_file_path,
            "--output_dlc", dlc_quantized_file_path
        ]
        dlc_result = subprocess.run(dlc_command, capture_output=True, text=True)
        if dlc_result.returncode != 0:
            return f"Error during DLC conversion: {dlc_result.stderr}"

        return dlc_file_path

    except Exception as e:
        return f"Error during conversion: {str(e)}"

if __name__ == "__main__":
    if len(sys.argv) != 6:
        print("Usage: python3 convert_model.py <pt_file_path> <output_folder> <model_type>")
        sys.exit(1)

    pt_file_path = sys.argv[1]
    output_folder = sys.argv[2]
    model_type = sys.argv[3]  # This will be "yolov5" or "yolov8"
    quantize_choice = sys.argv[4] # "YES" or "NO"
    quantize_folder = sys.argv[5] 
    result = convert_ONNX_model(pt_file_path, output_folder, model_type)
    if result == "SUCCESS":
        result = convert_DLC_model(pt_file_path, output_folder)
        if quantize_choice == "YES":
            result = convert_DLC_quantized_model(pt_file_path, output_folder, quantize_folder)
    print(result)

