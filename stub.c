#include <cuda.h>
#include <cuviddec.h>
#include <nvcuvid.h>

#define STUB_IMPL(...)               \
  __VA_ARGS__ {                      \
    return CUDA_ERROR_NOT_SUPPORTED; \
  }

STUB_IMPL(CUresult cuvidCreateDecoder(
    CUvideodecoder* phDecoder,
    CUVIDDECODECREATEINFO* pdci))

STUB_IMPL(CUresult cuvidCreateVideoParser(
    CUvideoparser* pObj,
    CUVIDPARSERPARAMS* pParams))

STUB_IMPL(CUresult cuvidCtxLockCreate(CUvideoctxlock* pLock, CUcontext ctx))

STUB_IMPL(CUresult cuvidCtxLockDestroy(CUvideoctxlock lck))

STUB_IMPL(CUresult cuvidDecodePicture(
    CUvideodecoder hDecoder,
    CUVIDPICPARAMS* pPicParams))

STUB_IMPL(CUresult cuvidDestroyDecoder(CUvideodecoder hDecoder))

STUB_IMPL(CUresult cuvidDestroyVideoParser(CUvideoparser obj))

STUB_IMPL(CUresult cuvidGetDecodeStatus(
    CUvideodecoder hDecoder,
    int nPicIdx,
    CUVIDGETDECODESTATUS* pDecodeStatus))

STUB_IMPL(CUresult cuvidParseVideoData(
    CUvideoparser obj,
    CUVIDSOURCEDATAPACKET* pPacket))

STUB_IMPL(CUresult cuvidReconfigureDecoder(
    CUvideodecoder hDecoder,
    CUVIDRECONFIGUREDECODERINFO* pDecReconfigParams));

#if !defined(__CUVID_DEVPTR64) || defined(__CUVID_INTERNAL)

STUB_IMPL(CUresult cuvidMapVideoFrame(
    CUvideodecoder hDecoder,
    int nPicIdx,
    unsigned int* pDevPtr,
    unsigned int* pPitch,
    CUVIDPROCPARAMS* pVPP))

STUB_IMPL(
    CUresult cuvidUnmapVideoFrame(CUvideodecoder hDecoder, unsigned int DevPtr))

#else

STUB_IMPL(CUresult cuvidMapVideoFrame64(
    CUvideodecoder hDecoder,
    int nPicIdx,
    unsigned long long* pDevPtr,
    unsigned int* pPitch,
    CUVIDPROCPARAMS* pVPP))

STUB_IMPL(CUresult cuvidUnmapVideoFrame64(
    CUvideodecoder hDecoder,
    unsigned long long DevPtr))

#endif
