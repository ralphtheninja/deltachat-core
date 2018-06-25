/*******************************************************************************
 *
 *                              Delta Chat Core
 *                      Copyright (C) 2017 Björn Petersen
 *                   Contact: r10s@b44t.com, http://b44t.com
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see http://www.gnu.org/licenses/ .
 *
 ******************************************************************************/


#ifndef __MRSMTP_H__
#define __MRSMTP_H__
#ifdef __cplusplus
extern "C" {
#endif


#include "dc_loginparam.h"


/*** library-private **********************************************************/

typedef struct dc_smtp_t
{
	mailsmtp*       m_hEtpan;
	char*           m_from;
	int             m_esmtp;

	int             m_log_connect_errors;
	int             m_log_usual_error;

	dc_context_t*   m_context; /* only for logging! */
} dc_smtp_t;

dc_smtp_t*   dc_smtp_new          (dc_context_t*);
void         dc_smtp_unref        (dc_smtp_t*);
int          dc_smtp_is_connected (const dc_smtp_t*);
int          dc_smtp_connect      (dc_smtp_t*, const dc_loginparam_t*);
void         dc_smtp_disconnect   (dc_smtp_t*);
int          dc_smtp_send_msg     (dc_smtp_t*, const clist* recipients, const char* data, size_t data_bytes);


#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MRPARAM_H__ */
