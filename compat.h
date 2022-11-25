/*-
 * Copyright (c) 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef __IDSTRING
#define __IDSTRING(_n,_s) \
        static const char _n[] __attribute((__unused__)) = _s
#endif

#ifndef __COPYRIGHT
#define __COPYRIGHT(_s) __IDSTRING(copyright,_s)
#endif

#ifndef __RCSID
#define __RCSID(_s) 	__IDSTRING(rcsid,_s)
#endif

#ifndef __UNCONST
#define __UNCONST(a) 	((void *)(unsigned long)(const void *)(a))
#endif

#ifndef ALLPERMS
#endif

#ifdef _SYS_STAT_H
#define ALLPERMS 	(S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
#define DEFFILEMODE 	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#define S_ISTXT 	S_ISVTX
#endif

#define __dead  	__attribute__((__noreturn__))

#ifdef _ERR_H
__dead void 	errc(int, int, const char *, ...)
                        __attribute__((__format__(printf, 3, 4)));
__dead void 	verrc(int, int, const char *, va_list)
                        __attribute__((__format__(printf, 3, 0)));
#endif

extern char *__progname;
