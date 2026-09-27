# bare-bmp

Small C++ program that writes a raw 24-bit 512x512 BMP file (`red.bmp`) from scratch without external image libraries.

Packs the 54-byte headers (`BITMAPFILEHEADER` + `BITMAPINFOHEADER`) with `#pragma pack(push, 1)` and streams raw BGR bytes directly to disk.

## Build

```bash
# MSVC
cl /EHsc main.cpp

# GCC / Clang
g++ main.cpp -o bare-bmp
```

Or open `bmpImage.vcxproj` in Visual Studio and build.
