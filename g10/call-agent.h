/* call-agent.h - Divert operations to the agent
 * Copyright (C) 2003 Free Software Foundation, Inc.
 *
 * This file is part of GnuPG.
 *
 * GnuPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GnuPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifndef GNUPG_G10_CALL_AGENT_H
#define GNUPG_G10_CALL_AGENT_H 

/* Check whether the secret key for the key identified by HEXKEYGRIP
   is available.  Return 0 for yes or an error code. */
int agent_havekey (const char *hexkeygrip);

/* Ask the agent to let the user change the passphrase of the secret
   key identified by HEXKEYGRIP. */
int agent_passwd (const char *hexkeygrip);




#endif /*GNUPG_G10_CALL_AGENT_H*/
