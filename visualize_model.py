import sys
import subprocess
import os
import shutil

def visualize_DLC_model(dlc_file_path):
    try:
        # Extract base name and directory
        base_name = os.path.splitext(os.path.basename(dlc_file_path))[0]
        output_folder = os.path.dirname(dlc_file_path)
        dlc_file_path = os.path.join(output_folder, f"{base_name}.dlc")
        
        # Define the log file paths
        log_file = os.path.join(output_folder, f"{base_name}_output.txt")

        
        # Run the command
        dlc_command = [
            "snpe-dlc-info",
            "-i", dlc_file_path
        ]
        dlc_result = subprocess.run(dlc_command, capture_output=True, text=True)
        
        # Capture both stdout and stderr
        with open(log_file, 'w') as log:
            result = subprocess.run(dlc_command, stdout=log, stderr=subprocess.STDOUT, text=True)
        
        if result.returncode != 0:
            return f"Error during DLC conversion. Check logs in {log_file}."

        return f"DLC file information stored in {log_file}."

    except Exception as e:
        return f"Error during conversion: {str(e)}"

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 visualize_model.py <dlc_file_path>")
        sys.exit(1)

    dlc_file_path = sys.argv[1]
    result = visualize_DLC_model(dlc_file_path)

    print(result)
