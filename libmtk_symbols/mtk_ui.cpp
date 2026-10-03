#include <stdint.h>
#include <string>

// Android 7.1 added the requestorName argument to this constructor, the 7.0
// blobs still call the old one.
extern "C" void _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
        void* thiz, uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage, std::string requestorName);

extern "C" void _ZN7android13GraphicBufferC1Ejjij(
        void* thiz, uint32_t inWidth, uint32_t inHeight, int inFormat, uint32_t inUsage) {
    _ZN7android13GraphicBufferC1EjjijNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE(
            thiz, inWidth, inHeight, inFormat, inUsage, "<Unknown>");
}
