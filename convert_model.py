import sys
import subprocess
import os

def convert_DLC_model(onnx_file_path, output_folder, encode_choice, encoding_file_path):
    try:
        base_name = os.path.splitext(os.path.basename(onnx_file_path))[0]
        dlc_fp32_path = os.path.join(output_folder, f"{base_name}_fp32.dlc")
        dlc_encode_fp32_path = os.path.join(output_folder, f"{base_name}_encode_fp32.dlc")
        
        if encode_choice == "YES" and encoding_file_path:
            dlc_command = [
                "snpe-onnx-to-dlc",
                "--input_network", onnx_file_path,
                "--quantization_overrides", encoding_file_path,
                "--output_path", dlc_encode_fp32_path
            ]
            print(f"Executing encoded DLC command: {dlc_command}")
        else:
            dlc_command = [
                "snpe-onnx-to-dlc",
                "--input_network", onnx_file_path,
                "--output_path", dlc_fp32_path
            ]
            print(f"Executing non-encoded DLC command: {dlc_command}")

        # Run the DLC conversion command
        dlc_result = subprocess.run(dlc_command, capture_output=True, text=True)
        if dlc_result.returncode != 0:
            print(f"Error during DLC conversion: {dlc_result.stderr}")
            return "Error during DLC conversion"

        return "DLC_CONVERSION_SUCCESS"

    except Exception as e:
        print(f"Exception during DLC conversion: {str(e)}")
        return f"Error during DLC conversion: {str(e)}"


def convert_DLC_quantized_model(onnx_file_path, output_folder, quantize_folder, encode_choice):
    try:
        base_name = os.path.splitext(os.path.basename(onnx_file_path))[0]
        dlc_fp32_path = os.path.join(output_folder, f"{base_name}_fp32.dlc")
        dlc_encode_fp32_path = os.path.join(output_folder, f"{base_name}_encode_fp32.dlc")
        dlc_int8_path = os.path.join(output_folder, f"{base_name}_int8.dlc")
        dlc_encode_int8_path = os.path.join(output_folder, f"{base_name}_encode_int8.dlc")
        image_list_path = os.path.join(quantize_folder, "image_file_list.txt")

        # Check if fp32 model exists before proceeding with quantization
        input_dlc = dlc_encode_fp32_path if encode_choice == "YES" else dlc_fp32_path
        output_dlc = dlc_encode_int8_path if encode_choice == "YES" else dlc_int8_path

        if not os.path.exists(input_dlc):
            print(f"Error: DLC model {input_dlc} does not exist for quantization.")
            return "Error: DLC model not found for quantization"
            
        if encode_choice == "YES":
            dlc_command = [
                "snpe-dlc-quantize",
                "--input_dlc", input_dlc,
                "--override_params",
                "--input_list", image_list_path,
                "--output_dlc", output_dlc
            ]
        else:
            dlc_command = [
                "snpe-dlc-quantize",
                "--input_dlc", input_dlc,
                "--input_list", image_list_path,
                "--output_dlc", output_dlc
            ]
        print(f"Executing quantization command: {dlc_command}")

        # Run the quantization command
        dlc_result = subprocess.run(dlc_command, capture_output=True, text=True)
        if dlc_result.returncode != 0:
            print(f"Quantization Error: {dlc_result.stderr}")
            return "Error during DLC quantization"

        return "DLC quantized successfully"

    except Exception as e:
        print(f"Exception during quantization: {str(e)}")
        return f"Error during quantization: {str(e)}"


if __name__ == "__main__":
    if len(sys.argv) != 7:
        print("Usage: python3 convert_model.py <onnx_file_path> <output_folder> <encode_choice> <encoding_file_path> <quantize_choice> <quantize_folder>")
        sys.exit(1)

    onnx_file_path = sys.argv[1]
    output_folder = sys.argv[2]
    encode_choice = sys.argv[3]  # "YES" or "NO"
    encoding_file_path = sys.argv[4] if sys.argv[3] == "YES" else ""
    quantize_choice = sys.argv[5]  # "YES" or "NO"
    quantize_folder = sys.argv[6] if sys.argv[5] == "YES" else ""

    # Step 1: Convert the ONNX model to DLC (fp32 or encoded fp32)
    conversion_result = convert_DLC_model(onnx_file_path, output_folder, encode_choice, encoding_file_path)
    print(conversion_result)

    # Step 2: If quantization is selected, convert the DLC to int8
    if quantize_choice == "YES":
        quantization_result = convert_DLC_quantized_model(onnx_file_path, output_folder, quantize_folder, encode_choice)
        print(quantization_result)

