/**************************************************************************************
 * MiniUPnPc                                                                          *
 * Copyright (c) 2005-2016, Thomas BERNARD                                            *
 * All rights reserved.                                                               *
 *                                                                                    *
 * Redistribution and use in source and binary forms, with or without                 *
 * modification, are permitted provided that the following conditions are met:        *
 *                                                                                    *
 *     * Redistributions of source code must retain the above copyright notice,       *
 *       this list of conditions and the following disclaimer.                        *
 *     * Redistributions in binary form must reproduce the above copyright notice,    *
 *       this list of conditions and the following disclaimer in the documentation    *
 *       and/or other materials provided with the distribution.                       *
 *     * The name of the author may not be used to endorse or promote products        *
 * 	  derived from this software without specific prior written permission.           *
 * This software is subject to the conditions detailed in the                         *
 * LICENCE file provided in this distribution.                                        *
 *                                                                                    *
 **************************************************************************************/
//this file uses miniupnp

#ifndef MINIUPNP_UTIL_H_
#define MINIUPNP_UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
#include <winsock2.h>
#define snprintf _snprintf
#endif
#include <miniupnpc/miniwget.h>
#include <miniupnpc/miniupnpc.h>
#include <miniupnpc/upnpcommands.h>
#include <miniupnpc/upnperrors.h>

//Define this variable follow the date of used MiniUPnP Library
//#define MINIUPNPC_API_VERSION	-3
#ifndef MINIUPNPC_API_VERSION
#error MINIUPNPC_API_VERSION is not defined. You may define one follow miniupnpc library version
	//2006/09/04 to 2007/10/01 => -7//Start return struct UPNPDev * for upnpDiscover
	//2007/10/16 => -6 upnpDiscover
	//2007/12/19 => -5 upnpDiscover
	//2008/09/25 => -4 upnpDiscover
	//2009/04/17 => -3 UPNP_AddPortMapping
	//2010/12/09 => -2 //struct IGDdatas_service CIF;
	//2011/02/15 => -1 UPNP_AddPortMapping
	//2011/03/14 => 6 //Start of MINIUPNPC_API_VERSION
#endif//>=-7

/* Ensure linking names are okay on OSX platform. (C interface) */

#ifdef  __cplusplus
extern "C" {
#endif


/* protofix() checks if protocol is "UDP" or "TCP" 
 * returns NULL if not */
const char * protofix(const char * proto);
void DisplayInfos(struct UPNPUrls * urls,
                  struct IGDdatas * data);

void GetConnectionStatus(struct UPNPUrls * urls,
                         struct IGDdatas * data);

void ListRedirections(struct UPNPUrls * urls,
                      struct IGDdatas * data);

int SetRedirectAndTest(struct UPNPUrls * urls,
                       struct IGDdatas * data,
                       const char * iaddr,
                       const char * iport,
                       const char * eport,
                       const char * proto,
                       const char *leaseDuration,
                       const char *description,
                       int addAny);

int TestRedirect(struct UPNPUrls * urls,
                               struct IGDdatas * data,
				const char * iaddr,
				const char * iport,
				const char * eport,
                       		const char * proto);

int RemoveRedirect(struct UPNPUrls * urls,
                    struct IGDdatas * data,
			   const char * eport,
			   const char * proto);

#ifdef  __cplusplus
}
#endif

/* EOF */
#endif
