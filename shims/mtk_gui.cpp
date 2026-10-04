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

// Android 8.0 added the parent, the window type and the owner
sp<SurfaceControl> createSurfaceCompat(SurfaceComposerClient* thiz, const String8& name,
        uint32_t w, uint32_t h, PixelFormat format, uint32_t flags)
        __asm__("_ZN7android21SurfaceComposerClient13createSurfaceERKNS_7String8Ejjij");

sp<SurfaceControl> createSurfaceCompat(SurfaceComposerClient* thiz, const String8& name,
        uint32_t w, uint32_t h, PixelFormat format, uint32_t flags) {
    return thiz->createSurface(name, w, h, format, flags);
}

// Android 9 moved the state of a surface into transactions. Each of the old
// calls becomes a transaction of its own; the global transaction that the
// blobs wrap them in has nothing left to do.
status_t setLayerCompat(SurfaceControl* thiz, uint32_t layer)
        __asm__("_ZN7android14SurfaceControl8setLayerEj");
status_t hideCompat(SurfaceControl* thiz) __asm__("_ZN7android14SurfaceControl4hideEv");
status_t showCompat(SurfaceControl* thiz) __asm__("_ZN7android14SurfaceControl4showEv");
status_t setSizeCompat(SurfaceControl* thiz, uint32_t w, uint32_t h)
        __asm__("_ZN7android14SurfaceControl7setSizeEjj");
void openGlobalTransactionCompat()
        __asm__("_ZN7android21SurfaceComposerClient21openGlobalTransactionEv");
void closeGlobalTransactionCompat(bool synchronous)
        __asm__("_ZN7android21SurfaceComposerClient22closeGlobalTransactionEb");

status_t setLayerCompat(SurfaceControl* thiz, uint32_t layer) {
    return SurfaceComposerClient::Transaction()
            .setLayer(thiz, static_cast<int32_t>(layer)).apply();
}

status_t hideCompat(SurfaceControl* thiz) {
    return SurfaceComposerClient::Transaction().hide(thiz).apply();
}

status_t showCompat(SurfaceControl* thiz) {
    return SurfaceComposerClient::Transaction().show(thiz).apply();
}

status_t setSizeCompat(SurfaceControl* thiz, uint32_t w, uint32_t h) {
    return SurfaceComposerClient::Transaction().setSize(thiz, w, h).apply();
}

void openGlobalTransactionCompat() {
}

void closeGlobalTransactionCompat(bool /*synchronous*/) {
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
