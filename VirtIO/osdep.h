//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2007  Qumranet All Rights Reserved
//
// Module Name:
// osdep.h
//
// Abstract:
// Windows OS dependent definitions of data types
//
// Author:
// Yan Vugenfirer  - February 2007.
//
//////////////////////////////////////////////////////////////////////////////////////////

#if defined(IGNORE_VIRTIO_OSDEP_H)
// to make simulation environment easy
#include "external_os_dep.h"
#else

#ifndef __OS_DEP_H
#define __OS_DEP_H

#include <ntddk.h>

#define ktime_t ULONGLONG
#define ktime_get() KeQueryPerformanceCounter(NULL).QuadPart

#define likely(x) x
#define unlikely(x) x

#define ENOSPC 1
#define BUG_ON(a) ASSERT(!(a))
#define WARN_ON(a)
#define BUG() ASSERT(0)

#define BUILD_BUG_ON(condition) \
    static_assert(!(condition), "Compile-time assumption failed")

#if !defined(__cplusplus) && !defined(bool)
#define bool int
#define false FALSE
#define true TRUE
#endif

#define inline __forceinline

#ifdef DBG
#define DEBUG
#endif

#define mb()   KeMemoryBarrier()
#define rmb()  KeMemoryBarrier()
#define wmb()  KeMemoryBarrier()

#define ENOENT           2      /* No such file or directory */
#define ENOMEM          12      /* Out of Memory */
#define EBUSY           16      /* Device or resource busy */
#define ENODEV          19      /* No such device */
#define EINVAL          22      /* Invalid argument */
#define MAX_ERRNO       4095

#define BIT_ULL(nr) (1ULL << (nr))

#define IS_ERR_VALUE(x) unlikely((x) >= (ULONG_PTR)-MAX_ERRNO)

inline void *ERR_PTR(LONG_PTR error)
{
    return (void *)error;
}
inline LONG_PTR PTR_ERR(const void *ptr)
{
    return (LONG_PTR)ptr;
}
inline LONG_PTR IS_ERR(const void *ptr)
{
    return IS_ERR_VALUE((ULONG_PTR)ptr);
}

#define SMP_CACHE_BYTES 64

#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

#define IORESOURCE_IO           0x00000100      /* PCI/ISA I/O ports */
#define IORESOURCE_MEM          0x00000200

#endif
#endif
