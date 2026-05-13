/* By Claude. This isn't already in my standard compiler!?
 *
 * stdrot.h — C23 §7.18 bit and byte utilities (rotate subset)
 *
 * __STDC_VERSION_STDROT_H__  is defined by the header itself (C23 §7.18p3).
 * __STDC_ENDIAN_LITTLE__ / __STDC_ENDIAN_BIG__ / __STDC_ENDIAN_NATIVE__ are
 * also defined by this header (C23 §7.18p4–6); they are NOT predefined macros.
 *
 * Typed functions are static inline so the header is self-contained and
 * linkage-collision-free.  The type-generic macros require C11 _Generic;
 * they are omitted on older dialects.
 */

#ifndef STDROT_H
#define STDROT_H

/* ── §7.18p3  version stamp ──────────────────────────────────────────────── */
#define __STDC_VERSION_STDROT_H__  202311L

/* ── §7.18p4-6  endianness constants ────────────────────────────────────── */
/*
 * The standard mandates that all three macros are defined here and that
 * __STDC_ENDIAN_LITTLE__ != __STDC_ENDIAN_BIG__.  Specific numeric values
 * are implementation-defined; the conventional choices are used below.
 */
#define __STDC_ENDIAN_LITTLE__  1234
#define __STDC_ENDIAN_BIG__     4321

/*
 * Detect native byte order.  Compilers expose __BYTE_ORDER__ reliably on
 * GCC ≥ 4.6, Clang ≥ 3.2, MSVC ≥ 19.x (x86/x64 are always LE there).
 * For mixed-endian (PDP, etc.) __STDC_ENDIAN_NATIVE__ differs from both.
 */
#if defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) \
 && defined(__ORDER_BIG_ENDIAN__)
#  if   __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#    define __STDC_ENDIAN_NATIVE__  __STDC_ENDIAN_LITTLE__
#  elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#    define __STDC_ENDIAN_NATIVE__  __STDC_ENDIAN_BIG__
#  else
#    define __STDC_ENDIAN_NATIVE__  0   /* mixed / PDP endian */
#  endif
#elif defined(_MSC_VER)
   /* MSVC only targets x86, x86-64, ARM (all little-endian) */
#  define __STDC_ENDIAN_NATIVE__  __STDC_ENDIAN_LITTLE__
#else
#  error "Cannot determine native byte order; define __STDC_ENDIAN_NATIVE__ manually."
#endif

/* ── Implementation detail ───────────────────────────────────────────────── */
#include <limits.h>   /* CHAR_BIT */

/*
 * Rotation width is always sizeof(T)*CHAR_BIT.
 * count is reduced modulo width so that:
 *   - rotate_N(x, 0)     == x          (identity)
 *   - rotate_N(x, width) == x          (full wrap)
 * The explicit count==0 guard avoids undefined behaviour from
 * shifting an N-bit type by exactly N (C §6.5.7p3).
 */

/* ── stdc_rotate_left ────────────────────────────────────────────────────── */

static inline unsigned char
stdc_rotate_left_uc(unsigned char value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (unsigned char)((value << count) | (value >> (w - count)));
}

static inline unsigned short
stdc_rotate_left_us(unsigned short value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (unsigned short)((value << count) | (value >> (w - count)));
}

static inline unsigned int
stdc_rotate_left_ui(unsigned int value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (value << count) | (value >> (w - count));
}

static inline unsigned long
stdc_rotate_left_ul(unsigned long value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (value << count) | (value >> (w - count));
}

static inline unsigned long long
stdc_rotate_left_ull(unsigned long long value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (value << count) | (value >> (w - count));
}

/* ── stdc_rotate_right ───────────────────────────────────────────────────── */

static inline unsigned char
stdc_rotate_right_uc(unsigned char value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (unsigned char)((value >> count) | (value << (w - count)));
}

static inline unsigned short
stdc_rotate_right_us(unsigned short value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (unsigned short)((value >> count) | (value << (w - count)));
}

static inline unsigned int
stdc_rotate_right_ui(unsigned int value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (value >> count) | (value << (w - count));
}

static inline unsigned long
stdc_rotate_right_ul(unsigned long value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (value >> count) | (value << (w - count));
}

static inline unsigned long long
stdc_rotate_right_ull(unsigned long long value, unsigned int count)
{
    const unsigned int w = (unsigned int)(sizeof value * CHAR_BIT);
    count %= w;
    if (count == 0) return value;
    return (value >> count) | (value << (w - count));
}

/* ── Type-generic macros (C11 _Generic required) ────────────────────────── */
/*
 * C23 §7.18 specifies stdc_rotate_left / stdc_rotate_right as type-generic
 * functions.  _Generic is the portable C11 mechanism; the macros are omitted
 * on pre-C11 compilers to avoid a hard error.
 */
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L

#define stdc_rotate_left(value, count)          \
    _Generic((value),                           \
        unsigned char:      stdc_rotate_left_uc,  \
        unsigned short:     stdc_rotate_left_us,  \
        unsigned int:       stdc_rotate_left_ui,  \
        unsigned long:      stdc_rotate_left_ul,  \
        unsigned long long: stdc_rotate_left_ull  \
    )((value), (count))

#define stdc_rotate_right(value, count)         \
    _Generic((value),                           \
        unsigned char:      stdc_rotate_right_uc,  \
        unsigned short:     stdc_rotate_right_us,  \
        unsigned int:       stdc_rotate_right_ui,  \
        unsigned long:      stdc_rotate_right_ul,  \
        unsigned long long: stdc_rotate_right_ull  \
    )((value), (count))

#endif /* __STDC_VERSION__ >= 201112L */

#endif /* STDROT_H */
