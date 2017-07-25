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
 *******************************************************************************
 *
 * File:    mrparam.h
 * Purpose: Handle parameter lists as follows:
 *          - the list is stored in a string as "a=value\nb=value"
 *          - values can contain all characters but "\n"
 *          - for efficiency, keys are limited to one character
 *          - we expect the packed string to be well formatted and do not
 *            allow spaces around the key; spaces right of the value are trimmed
 *
 *******************************************************************************
 *
 * Known keys:
 *
 * 'U'npromoted group
 * 'P'hysically delete group after message sending
 * 'r'ead receipt wanted
 * 'R'eferences header last used for a chat
 *
 ******************************************************************************/


#ifndef __MRPARAM_H__
#define __MRPARAM_H__
#ifdef __cplusplus
extern "C" {
#endif


#define MRP_FILE              'f'  /* for msgs */
#define MRP_WIDTH             'w'  /* for msgs */
#define MRP_HEIGHT            'h'  /* for msgs */
#define MRP_DURATION          'd'  /* for msgs */
#define MRP_MIMETYPE          'm'  /* for msgs */
#define MRP_AUTHORNAME        'N'  /* for msgs: name of author or artist */
#define MRP_TRACKNAME         'n'  /* for msgs: name of author or artist */
#define MRP_GUARANTEE_E2EE    'c'  /* for msgs: 'c'rypted in original/guarantee E2EE or the message is not send */
#define MRP_ERRONEOUS_E2EE    'e'  /* for msgs: decrypted with validation errors, if neither 'c' nor 'e' are preset, the messages is only transport encrypted */
#define MRP_WANTS_MDN         'r'  /* for msgs: an incoming message which requestes a MDN (aka read receipt) */
#define MRP_FWD_NAME          'A'  /* for msgs */
#define MRP_FWD_ADDR          'a'  /* for msgs */
#define MRP_GHOST_CC          'G'  /* for msgs: Ghost-CC, parameter is the original msg_id */
#define MRP_SYSTEM_CMD        'S'  /* for msgs */
#define MRP_SYSTEM_CMD_PARAM  'E'  /* for msgs */

#define MRP_SERVER_FOLDER     'Z'  /* for jobs */
#define MRP_SERVER_UID        'z'  /* for jobs */
#define MRP_TIMES             't'  /* for jobs: times a job was tried */
#define MRP_TIMES_INCREATION  'T'  /* for jobs: times a job was tried, used for increation */

#define MRP_PROFILE_IMAGE     'i'  /* for groups and contacts */


typedef struct mrparam_t
{
	char*    m_packed;    /* != NULL */
} mrparam_t;


mrparam_t*    mrparam_new          ();
void          mrparam_unref        (mrparam_t*);

void          mrparam_empty        (mrparam_t*);
void          mrparam_set_packed   (mrparam_t*, const char*); /* overwrites all existing parameters */

int           mrparam_exists       (mrparam_t*, int key);
char*         mrparam_get          (mrparam_t*, int key, const char* def); /* the value may be an empty string, "def" is returned only if the value unset.  The result must be free()'d in any case. */
int32_t       mrparam_get_int      (mrparam_t*, int key, int32_t def);
void          mrparam_set          (mrparam_t*, int key, const char* value);
void          mrparam_set_int      (mrparam_t*, int key, int32_t value);


/*** library-private **********************************************************/

#ifdef __cplusplus
} /* /extern "C" */
#endif
#endif /* __MRPARAM_H__ */

