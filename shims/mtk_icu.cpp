#include <unicode/ucnv.h>
#include <unicode/ucnv_err.h>

// The stock DRM helper library was linked against ICU 56

extern "C" {

UConverter* ucnv_open_56(const char* converterName, UErrorCode* err) {
    return ucnv_open(converterName, err);
}

void ucnv_close_56(UConverter* converter) {
    ucnv_close(converter);
}

void ucnv_convertEx_56(UConverter* targetCnv, UConverter* sourceCnv, char** target,
        const char* targetLimit, const char** source, const char* sourceLimit, UChar* pivotStart,
        UChar** pivotSource, UChar** pivotTarget, const UChar* pivotLimit, UBool reset,
        UBool flush, UErrorCode* pErrorCode) {
    ucnv_convertEx(targetCnv, sourceCnv, target, targetLimit, source, sourceLimit, pivotStart,
            pivotSource, pivotTarget, pivotLimit, reset, flush, pErrorCode);
}

void ucnv_setFromUCallBack_56(UConverter* converter, UConverterFromUCallback newAction,
        const void* newContext, UConverterFromUCallback* oldAction, const void** oldContext,
        UErrorCode* err) {
    ucnv_setFromUCallBack(converter, newAction, newContext, oldAction, oldContext, err);
}

void ucnv_setToUCallBack_56(UConverter* converter, UConverterToUCallback newAction,
        const void* newContext, UConverterToUCallback* oldAction, const void** oldContext,
        UErrorCode* err) {
    ucnv_setToUCallBack(converter, newAction, newContext, oldAction, oldContext, err);
}

void UCNV_FROM_U_CALLBACK_STOP_56(const void* context, UConverterFromUnicodeArgs* fromUArgs,
        const UChar* codeUnits, int32_t length, UChar32 codePoint,
        UConverterCallbackReason reason, UErrorCode* err) {
    UCNV_FROM_U_CALLBACK_STOP(context, fromUArgs, codeUnits, length, codePoint, reason, err);
}

void UCNV_TO_U_CALLBACK_STOP_56(const void* context, UConverterToUnicodeArgs* toUArgs,
        const char* codeUnits, int32_t length, UConverterCallbackReason reason,
        UErrorCode* err) {
    UCNV_TO_U_CALLBACK_STOP(context, toUArgs, codeUnits, length, reason, err);
}

}
