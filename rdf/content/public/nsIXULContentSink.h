/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Mozilla Communicator client code.
 *
 * The Initial Developer of the Original Code is Netscape Communications
 * Corporation.  Portions created by Netscape are Copyright (C) 1998
 * Netscape Communications Corporation.  All Rights Reserved.
 */


#ifndef nsIXULContentSink_h__
#define nsIXULContentSink_h__

#include "nsIXMLContentSink.h"

class nsIDocument;
class nsIRDFDataSource;

// {E49AA620-C16C-11d2-A6AA-00104BDE6048}
#define NS_IXULCONTENTSINK_IID \
{ 0xe49aa620, 0xc16c, 0x11d2, { 0xa6, 0xaa, 0x0, 0x10, 0x4b, 0xde, 0x60, 0x48 } }


class nsIXULContentSink : public nsIXMLContentSink
{
public:
    static const nsIID& GetIID() { static nsIID iid = NS_IXULCONTENTSINK_IID; return iid; }

    NS_IMETHOD Init(nsIDocument* aDocument) = 0;

    NS_IMETHOD UnblockNextOverlay() = 0;

    NS_IMETHOD UpdateOverlayCounters(PRInt32 aDelta) = 0;
};


nsresult
NS_NewXULContentSink(nsIXULContentSink** aResult);

#endif // nsIXULContentSink_h__
