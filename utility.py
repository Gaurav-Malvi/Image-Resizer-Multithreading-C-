import os

# Specify the directory to iterate over
directory_path = './data'

# Open a file in write mode (it will create the file if it doesn't exist)
with open("images_path.txt", "w") as f:
    # Walk through the directory, including subdirectories
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            # Get the full path of the file
            file_path = os.path.join(root, file)
            # Replace backslashes with forward slashes
            file_path = file_path.replace('\\', '/')
            # Write the modified path to the text file
            f.write(file_path + "\n")

print("Paths have been written to file_paths.txt")
