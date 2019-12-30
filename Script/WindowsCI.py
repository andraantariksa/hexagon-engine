import urllib.request as request
import zipfile
import os

# Assuming we're using x64 architecture
ARCH = "x64"

# Download the SDL2 Development VC
url = "https://www.libsdl.org/release/SDL2-devel-2.0.10-VC.zip"
file_handle, _ = request.urlretrieve(url)
zip_file_object = zipfile.ZipFile(file_handle, "r")
zip_file_object.extractall("temp/")

# Move the dll file
os.rename(f"temp/SDL2-2.0.10/lib/{ARCH}/SDL2.dll", "SDL2.dll")
