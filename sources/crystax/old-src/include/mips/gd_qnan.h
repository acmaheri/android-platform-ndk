/*
 * MD header for contrib/gdtoa
 *
 * This file can be generated by compiling and running contrib/gdtoa/qnan.c
 * on the target architecture after arith.h has been generated.
 *
 * $FreeBSD$
 */

/*
 * Copyright (c) 2011-2014 CrystaX .NET.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice, this list of
 *       conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright notice, this list
 *       of conditions and the following disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY CrystaX .NET ''AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL CrystaX .NET OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those of the
 * authors and should not be interpreted as representing official policies, either expressed
 * or implied, of CrystaX .NET.
 */

#pragma once

#include <endian.h>

#if BYTE_ORDER == BIG_ENDIAN
/* These values were gained on a running
 * Octeon in Big Endian order. They were gotten
 * by running ./qnan after arithchk was ran and
 * got us the proper values for arith.h.
 */
#define f_QNAN 0x7f900000
#define d_QNAN0 0x7ff80000
#define d_QNAN1 0x0
#define ld_QNAN0 0x7ff80000
#define ld_QNAN1 0x0
#define ld_QNAN2 0x0
#define ld_QNAN3 0x0
#define ldus_QNAN0 0x7ff8
#define ldus_QNAN1 0x0
#define ldus_QNAN2 0x0
#define ldus_QNAN3 0x0
#define ldus_QNAN4 0x0
#else
/* FIX FIX, need to run this on a Little Endian
 * machine and get the proper values, these here
 * were stolen fromn i386/gd_qnan.h
 */
#define f_QNAN 0x7fc00000
#define d_QNAN0 0x0
#define d_QNAN1 0x7ff80000
#define ld_QNAN0 0x0
#define ld_QNAN1 0xc0000000
#define ld_QNAN2 0x7fff
#define ld_QNAN3 0x0
#define ldus_QNAN0 0x0
#define ldus_QNAN1 0x0
#define ldus_QNAN2 0x0
#define ldus_QNAN3 0xc000
#define ldus_QNAN4 0x7fff
#endif
