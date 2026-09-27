#include <iostream>
#include <fstream>
#include <cstdint>

#pragma pack(push, 1)

struct BmpHeader {
    char bitmapSignatureBytes[2] = { 'B', 'M' };
    uint32_t sizeOfBitmapFile = 54 + 786432;
    uint32_t reservedBytes = 0;
    uint32_t pixelDataOffset = 54;
} bmpHeader;

struct BmpInfoHeader {
    uint32_t sizeOfThisHeader = 40;
    int32_t width = 512; // in pixels
    int32_t height = 512; // in pixels
    uint16_t numberOfColorPlanes = 1; // must be 1
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0; // generally ignored
    int32_t horizontalResolution = 3780; // in pixel per meter
    int32_t verticalResolution = 3780; // in pixel per meter
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;
} bmpInfoHeader;

#pragma pack(pop)

int main()
{
    std::ofstream fout("red.bmp", std::ios::binary);

    fout.write(reinterpret_cast<const char*>(&bmpHeader), sizeof(bmpHeader));
    fout.write(reinterpret_cast<const char*>(&bmpInfoHeader), sizeof(bmpInfoHeader));

    uint8_t redPixel[3] = { 0,0,255 };
    for (int i = 0; i < 512 * 512; ++i) {
        fout.write(reinterpret_cast<const char*>(redPixel), 3);
    }
}