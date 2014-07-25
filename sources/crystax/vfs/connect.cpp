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

#include "fileio/api.hpp"
#include "system/driver.hpp"

namespace crystax
{
namespace fileio
{

CRYSTAX_LOCAL
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    DBG("sockfd=%d, addrlen=%lu", sockfd, (unsigned long)addrlen);

    int extfd;
    if (!resolve(sockfd, NULL, &extfd, NULL, NULL))
        return -1;

    if (extfd == -1)
    {
        errno = EBADF;
        return -1;
    }

    int extconnfd = system_connect(extfd, addr, addrlen);
    if (extconnfd == -1)
        return -1;

    int connfd = alloc_fd(NULL, extconnfd, system::driver_t::instance());
    if (connfd < 0)
    {
        system_close(extconnfd);
        errno = EMFILE;
        return -1;
    }

    DBG("return fd=%d", connfd);
    return connfd;
}

} // namespace fileio
} // namespace crystax

CRYSTAX_GLOBAL
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return ::crystax::fileio::connect(sockfd, addr, addrlen);
}
