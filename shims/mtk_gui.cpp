#include <stdint.h>

#include <gui/BufferQueue.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/SurfaceControl.h>

namespace android {

// Android 8.0 dropped the allocator argument
void createBufferQueueCompat(sp<IGraphicBufferProducer>* outProducer,
        sp<IGraphicBufferConsumer>* outConsumer, const void* allocator)
        __asm__("_ZN7android11BufferQueue17createBufferQueueEPNS_2spINS_22IGraphicBufferProducerEEEPNS1_INS_22IGraphicBufferConsumerEEERKNS1_INS_19IGraphicBufferAllocEEE");

void createBufferQueueCompat(sp<IGraphicBufferProducer>* outProducer,
        sp<IGraphicBufferConsumer>* outConsumer, const void* /*allocator*/) {
    BufferQueue::createBufferQueue(outProducer, outConsumer);
}

// Layers became signed in Android 8.0
status_t setLayerCompat(SurfaceControl* thiz, uint32_t layer)
        __asm__("_ZN7android14SurfaceControl8setLayerEj");

status_t setLayerCompat(SurfaceControl* thiz, uint32_t layer) {
    return thiz->setLayer(static_cast<int32_t>(layer));
}

// Android 8.0 added the parent, the window type and the owner
sp<SurfaceControl> createSurfaceCompat(SurfaceComposerClient* thiz, const String8& name,
        uint32_t w, uint32_t h, PixelFormat format, uint32_t flags)
        __asm__("_ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij");

sp<SurfaceControl> createSurfaceCompat(SurfaceComposerClient* thiz, const String8& name,
        uint32_t w, uint32_t h, PixelFormat format, uint32_t flags) {
    return thiz->createSurface(name, w, h, format, flags);
}

} // namespace android

extern "C" {

// Skia calls of the debug overlay of libaal.so that are gone; it only draws a
// test pattern with them
bool _ZN8SkBitmap14tryAllocPixelsEPNS_9AllocatorEP12SkColorTable(void*, void*, void*) {
    return false;
}

void _ZN8SkCanvas9drawColorEjN10SkXfermode4ModeE(void*, uint32_t, int) {
}

}
