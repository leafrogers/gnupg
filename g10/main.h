/* main.h
 *	Copyright (C) 1998 Free Software Foundation, Inc.
 *
 * This file is part of GNUPG.
 *
 * GNUPG is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GNUPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifndef G10_MAIN_H
#define G10_MAIN_H
#include "types.h"
#include "iobuf.h"
#include "cipher.h"
#include "keydb.h"


typedef struct {
    int header_okay;
    PKC_LIST pkc_list;
    cipher_filter_context_t cfx;
} encrypt_filter_context_t;


/*-- g10.c --*/
#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 5 )
  void g10_exit(int rc) __attribute__ ((noreturn));
#else
  void g10_exit(int rc);
#endif

/*-- encode.c --*/
int encode_symmetric( const char *filename );
int encode_store( const char *filename );
int encode_crypt( const char *filename, STRLIST remusr );
int encrypt_filter( void *opaque, int control,
		    IOBUF a, byte *buf, size_t *ret_len);


/*-- sign.c --*/
int sign_file( STRLIST filenames, int detached, STRLIST locusr,
	       int encrypt, STRLIST remusr, const char *outfile );
int clearsign_file( const char *fname, STRLIST locusr, const char *outfile );
int sign_key( const char *username, STRLIST locusr );
int edit_keysigs( const char *username );
int delete_key( const char *username, int secure );
int change_passphrase( const char *username );

/*-- sig-check.c --*/
int check_key_signature( KBNODE root, KBNODE node, int *is_selfsig );

/*-- keygen.c --*/
void generate_keypair(void);

/*-- openfile.c --*/
int overwrite_filep( const char *fname );
IOBUF open_outfile( const char *fname, int mode );
IOBUF open_sigfile( const char *iname );

/*-- seskey.c --*/
void make_session_key( DEK *dek );
MPI encode_session_key( DEK *dek, unsigned nbits );
MPI encode_md_value( MD_HANDLE md, unsigned nbits );

/*-- comment.c --*/
KBNODE make_comment_node( const char *s );
KBNODE make_mpi_comment_node( const char *s, MPI a );

/*-- elg.c --*/
void g10_elg_encrypt( PKT_public_cert *pkc, PKT_pubkey_enc *enc, DEK *dek );
void g10_elg_sign( PKT_secret_cert *skc, PKT_signature *sig,
					 MD_HANDLE md, int digest_algo );

/*-- rsa.c --*/
void g10_rsa_encrypt( PKT_public_cert *pkc, PKT_pubkey_enc *enc, DEK *dek );
void g10_rsa_sign( PKT_secret_cert *skc, PKT_signature *sig,
					 MD_HANDLE md, int digest_algo );

/*-- import.c --*/
int import_pubkeys( const char *filename );
/*-- export.c --*/
int export_pubkeys( STRLIST users );
/* dearmor.c --*/
int dearmor_file( const char *fname );
int enarmor_file( const char *fname );

/*-- revoke.c --*/
int gen_revoke( const char *uname );

/*-- keylist.c --*/
void ext_key_list( STRLIST names );

#endif /*G10_MAIN_H*/
