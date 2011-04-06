// Copyright (c) 2011, Robert Escriva
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of po6 nor the names of its contributors may be used
//       to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

// Google Test
#include <gtest/gtest.h>

// po6
#include "po6/threads/mutex.h"

#pragma GCC diagnostic ignored "-Wswitch-default"

namespace
{

TEST(MutexTest, CtorAndDtor)
{
    po6::threads::mutex mtx;
}

TEST(MutexTest, LockAndUnlock)
{
    po6::threads::mutex mtx;
    mtx.lock();
    mtx.unlock();
}

TEST(MutexTest, TryLock)
{
    po6::threads::mutex mtx;
    EXPECT_TRUE(mtx.trylock());
    EXPECT_FALSE(mtx.trylock());
    mtx.unlock();
}

TEST(MutexTest, LockAndDtorThrows)
{
    bool caught = false;

    try
    {
        po6::threads::mutex mtx;
        mtx.lock();
    }
    catch (std::logic_error e)
    {
        caught = true;
    }

    ASSERT_TRUE(caught);
}

} // namespace
