/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 */

#ifndef _nsHTTPResponseListener_h_
#define _nsHTTPResponseListener_h_


#include "nsIChannel.h"
#include "nsIStreamListener.h"
#include "nsString.h"
#include "nsCOMPtr.h"
#include "nsIInputStream.h"

class nsIBufferInputStream;
class nsHTTPResponse;
class nsHTTPChannel;

/* 
    The nsHTTPResponseListener class is the response reader listener that 
    receives notifications of OnStartRequest, OnDataAvailable and 
    OnStopRequest as the data is received from the server. Each instance 
    of this class is tied to the corresponding transport that it reads the
    response data stream from. 

  
    The essential purpose of this class is to create the actual response 
    based on the data that is coming off the net. 

    This class is internal to the protocol handler implementation and 
    should theroetically not be used by the app or the core netlib.

    -Gagan Saksena 04/29/99
*/
class nsHTTPResponseListener : public nsIStreamListener
{

public:

    nsHTTPResponseListener(nsHTTPChannel* aConnection);
    virtual ~nsHTTPResponseListener();

    NS_DECL_ISUPPORTS
    NS_DECL_NSISTREAMOBSERVER
    NS_DECL_NSISTREAMLISTENER

    nsresult FireSingleOnData(nsIStreamListener *aListener, nsISupports *aContext);
    void     Abort() { mAborted = PR_TRUE; }
    void     SetResponseDataListener(nsIStreamListener *aListener) {
      mResponseDataListener = aListener;
    }

protected:
    // nsHTTPResponseListener methods...
    nsresult FireOnHeadersAvailable();
    nsresult FinishedResponseHeaders();

    nsresult ParseStatusLine(nsIBufferInputStream* in, PRUint32 aLength,
                             PRUint32 *aBytesRead);

    nsresult ParseHTTPHeader(nsIBufferInputStream* in, PRUint32 aLength, 
                             PRUint32* aBytesRead);

protected:
    nsCOMPtr<nsIStreamListener> mResponseDataListener;
    nsCString                   mHeaderBuffer;
    nsHTTPChannel*      	      mChannel;
    nsHTTPResponse*             mResponse;
    PRBool              	      mFirstLineParsed;
    PRBool              	      mHeadersDone;
    PRBool                      mAborted;

    nsCOMPtr<nsIInputStream>    mDataStream;
    PRUint32                    mBytesReceived; 
};

#endif /* _nsHTTPResponseListener_h_ */
