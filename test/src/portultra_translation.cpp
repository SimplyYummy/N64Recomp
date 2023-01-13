#include <memory>
#include "../portultra/ultra64.h"
#include "../portultra/multilibultra.hpp"
#include "recomp.h"

extern "C" void osInitialize_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    osInitialize();
}

extern "C" void __osInitialize_common_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    osInitialize();
}

extern "C" void osCreateThread_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    osCreateThread(rdram, (int32_t)ctx->r4, (OSId)ctx->r5, (int32_t)ctx->r6, (int32_t)ctx->r7,
        (int32_t)MEM_W(0x10, ctx->r29), (OSPri)MEM_W(0x14, ctx->r29));
}

extern "C" void osStartThread_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    osStartThread(rdram, (int32_t)ctx->r4);
}

extern "C" void osStopThread_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    osStopThread(rdram, (int32_t)ctx->r4);
}

extern "C" void osDestroyThread_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    osDestroyThread(rdram, (int32_t)ctx->r4);
}

extern "C" void osSetThreadPri_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    osSetThreadPri(rdram, (int32_t)ctx->r4, (OSPri)ctx->r5);
}

extern "C" void osGetThreadPri_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = osGetThreadPri(rdram, (int32_t)ctx->r4);
}

extern "C" void osGetThreadId_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = osGetThreadId(rdram, (int32_t)ctx->r4);
}

extern "C" void osCreateMesgQueue_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    osCreateMesgQueue(rdram, (int32_t)ctx->r4, (int32_t)ctx->r5, (s32)ctx->r6);
}

extern "C" void osRecvMesg_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    ctx->r2 = osRecvMesg(rdram, (int32_t)ctx->r4, (int32_t)ctx->r5, (s32)ctx->r6);
}

extern "C" void osSendMesg_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    ctx->r2 = osSendMesg(rdram, (int32_t)ctx->r4, (OSMesg)ctx->r5, (s32)ctx->r6);
}

extern "C" void osJamMesg_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    ctx->r2 = osJamMesg(rdram, (int32_t)ctx->r4, (OSMesg)ctx->r5, (s32)ctx->r6);
}

extern "C" void osSetEventMesg_recomp(uint8_t* restrict rdram, recomp_context* restrict ctx) {
    osSetEventMesg(rdram, (OSEvent)ctx->r4, (int32_t)ctx->r5, (OSMesg)ctx->r6);
}

extern "C" void osViSetEvent_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    osViSetEvent(rdram, (int32_t)ctx->r4, (OSMesg)ctx->r5, (u32)ctx->r6);
}

extern "C" void osGetCount_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = osGetCount();
}

extern "C" void osGetTime_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    uint64_t total_count = osGetTime();
    ctx->r2 = (uint32_t)(total_count >> 32);
    ctx->r3 =  (int32_t)(total_count >> 0);
}

extern "C" void osVirtualToPhysical_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = osVirtualToPhysical((int32_t)ctx->r2);
}

extern "C" void osInvalDCache_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void osInvalICache_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void osWritebackDCache_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void osWritebackDCacheAll_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void osSetIntMask_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void __osDisableInt_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void __osRestoreInt_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ;
}

extern "C" void __osSetFpcCsr_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = 0;
}

extern "C" void __checkHardware_msp_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = 0;
}

extern "C" void __checkHardware_kmc_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = 0;
}

extern "C" void __checkHardware_isv_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    ctx->r2 = 0;
}

extern "C" void __osInitialize_msp_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
}

extern "C" void __osInitialize_kmc_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
}

extern "C" void __osInitialize_isv_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
}

extern "C" void __osRdbSend_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
    gpr buf = ctx->r4;
    size_t size = ctx->r5;
    u32 type = (u32)ctx->r6;
    std::unique_ptr<char[]> to_print = std::make_unique<char[]>(size);

    for (size_t i = 0; i < size; i++) {
        to_print[i] = MEM_B(i, buf);
    }
    to_print[size] = '\x00';

    fwrite(to_print.get(), 1, size, stdout);

    ctx->r2 = size;
}

// For the Mario Party games (not working)
//extern "C" void longjmp_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
//    RecompJmpBuf* buf = TO_PTR(RecompJmpBuf, ctx->r4);
//
//    // Check if this is a buffer that was set up with setjmp
//    if (buf->magic == SETJMP_MAGIC) {
//        // If so, longjmp to it
//        // Setjmp/longjmp does not work across threads, so verify that this buffer was made by this thread
//        assert(buf->owner == Multilibultra::this_thread());
//        longjmp(buf->storage->buffer, ctx->r5);
//    } else {
//        // Otherwise, check if it was one built manually by the game with $ra pointing to a function
//        gpr sp = MEM_W(0, ctx->r4);
//        gpr ra = MEM_W(4, ctx->r4);
//        ctx->r29 = sp;
//        recomp_func_t* target = LOOKUP_FUNC(ra);
//        if (target == nullptr) {
//            fprintf(stderr, "Failed to find function for manual longjmp\n");
//            std::quick_exit(EXIT_FAILURE);
//        }
//        target(rdram, ctx);
//
//        // TODO kill this thread if the target function returns
//        assert(false);
//    }
//}
//
//#undef setjmp_recomp
//extern "C" void setjmp_recomp(uint8_t * restrict rdram, recomp_context * restrict ctx) {
//    fprintf(stderr, "Program called setjmp_recomp\n");
//    std::quick_exit(EXIT_FAILURE);
//}
//
//extern "C" int32_t osGetThreadEx(void) {
//    return Multilibultra::this_thread();
//}
