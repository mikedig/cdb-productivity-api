/*************************************************************************
Copyright (c) 2019 Cognitics, Inc.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
****************************************************************************/
/*! \brief Provides cts::ProjInfo.
\author Aaron Brinton <abrinton@cognitics.net>
\date 16 May 2011
*/
#pragma once

#include <string>

namespace cts
{
    //! Provides access to reading and writing projInfo.txt files
    struct ProjInfo
    {
        std::string csm;
        double originlat;
        double originlon;
        double zunits;
        int selectorId;
        std::string dcType;
        int dcSelectorId;
        double txpOffsetX;
        double txpOffsetY;
        double txpOffsetZ;

        ProjInfo(const std::string &filename = std::string());

        void clear(void);
        bool read(const std::string &filename);
        bool write(const std::string &filename);

    };

}

