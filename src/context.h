/*
 * Copyright (c) 2016 Johan Sköld
 * License: https://opensource.org/licenses/ISC
 */

#pragma once

#include <stddef.h> /* size_t */

#if defined(__cplusplus)
extern "C" {
#endif

    typedef void* sc_context_sp_t;

    typedef struct {
        sc_context_sp_t ctx;
        void* data;
    } sc_transfer_t;

    sc_transfer_t sc_jump_context (sc_context_sp_t to, void* vp);
    sc_context_sp_t sc_make_context (void* sp, size_t size, void(*fn)(sc_transfer_t));

    /* For the provided fcontext implementations, there's no necessary work to
       be done for freeing a context, but some custom backends (for proprietary
       hardware) do. */
#if defined(SC_CUSTOM_FREE_CONTEXT)
    void sc_free_context (sc_context_sp_t);
#else
    static void sc_free_context (sc_context_sp_t ctx) { (void)ctx; }
#endif

#if defined(__cplusplus)
} /* extern "C" */
#endif