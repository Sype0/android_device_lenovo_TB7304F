#include <stdint.h>
#include <unistd.h>
#include <string>

struct native_handle;

extern "C" {

// Android 7.1 added the requestorName argument to this constructor, the 7.0
// blobs still call the old one.
void _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
        void* thiz, uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage, std::string requestorName);

void _ZN7android13GraphicBufferC1Ejjij(
        void* thiz, uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage) {
    _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
            thiz, inWidth, inHeight, inFormat, inUsage, "<Unknown>");
}

// Android 8.0 added the layer count
void _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(
        void* thiz, uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inLayerCount,
        uint32_t inUsage, uint32_t inStride, native_handle* inHandle, bool keepOwnership);

void _ZN7android13GraphicBufferC1EjjijjP13native_handleb(
        void* thiz, uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage,
        uint32_t inStride, native_handle* inHandle, bool keepOwnership) {
    _ZN7android13GraphicBufferC1EjjijjjP13native_handleb(
            thiz, inWidth, inHeight, inFormat, 1, inUsage, inStride, inHandle, keepOwnership);
}

// The destructor of android::Fence is inline since Android 9. The object is a
// reference count followed by the file descriptor.
void _ZN7android5FenceD1Ev(void* thiz) {
    int* fd = static_cast<int*>(thiz) + 1;
    if (*fd != -1) {
        close(*fd);
        *fd = -1;
    }
}

}
