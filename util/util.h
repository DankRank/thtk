/*
 * Redistribution and use in source and binary forms, with
 * or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain this list
 *    of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce this
 *    list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */
#ifndef UTIL_H_
#define UTIL_H_

#include <config.h>
#include <stdio.h>
#include <inttypes.h>
#include <stddef.h>

#ifndef MIN
#  define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
#  define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

typedef struct {
    const char *str;
    size_t len;
} stringref_t;

#define stringref(str) (const stringref_t) { str, strlen(str) }

int util_strcmp_ref(
    const char *str,
    const stringref_t ref);

/* Allocates memory and aborts with an error message if the allocation failed. */
void* util_malloc(
    size_t size);

void util_print_version(
    void);

/* Returns an unique string representation of a float.  Returns a pointer to a
 * static buffer, not thread-safe. */
const char* util_printfloat(
    const void* data);

/* Creates all components of the path. */
void util_makepath(
    const char* path);

/* Typical amortized O(1) dynamic array resize function */
int util_vec_ensure(
    void *data, /* It's actually void **. This is done to avoid casts. */
    size_t *cap,
    size_t size,
    size_t element_size);

/* Scan directories recursively.  After use, result should be freed manually. */
int util_scan_files(
    const char* dir,
    char*** result);

/* XOR each byte by key.  Key is incremented by step, which is in turn
 * incremented by step2. */
void util_xor(
    unsigned char* data,
    size_t data_length,
    unsigned char key,
    unsigned char step,
    unsigned char step2);

/* Changes current directory */
int util_chdir(
    const char *path);
#endif
