#ifndef __RPC_SYMBOLS_H__
#define __RPC_SYMBOLS_H__

#include "remote_wos.h"
#include <stdint.h>

#define MAX_NUMBER_OF_DSPs 12

typedef int(__cdecl *fnremote_handle64_open)(const char *name, remote_handle64 *ph);
typedef int(__cdecl *fnremote_handle64_close)(remote_handle64 h);
typedef int(__cdecl *fnremote_handle64_invoke)(remote_handle64 h, uint32_t dwScalars, remote_arg *pra);
typedef int(__cdecl *fnremote_session_control)(uint32_t req, void *data, uint32_t datalen);
typedef void *(__cdecl *fnrpcmem_alloc)(int heapid, uint32_t flags, int size);
typedef void(__cdecl *fnrpcmem_free)(void *po);

extern fnremote_handle64_open premote_handle64_open[MAX_NUMBER_OF_DSPs];
extern fnremote_handle64_close premote_handle64_close[MAX_NUMBER_OF_DSPs];
extern fnremote_handle64_invoke premote_handle64_invoke[MAX_NUMBER_OF_DSPs];
extern fnremote_session_control premote_session_control[MAX_NUMBER_OF_DSPs];
extern fnrpcmem_alloc prpcmem_alloc[MAX_NUMBER_OF_DSPs];
extern fnrpcmem_free prpcmem_free[MAX_NUMBER_OF_DSPs];

int fastrpc_load_symbols(int q6Processor, const char *dllPath);
void fastrpc_unload_symbols(int q6Processor);

#endif /* __RPC_SYMBOLS_H__ */
