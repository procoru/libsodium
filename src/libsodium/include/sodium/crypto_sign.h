#ifndef crypto_sign_H
#define crypto_sign_H

/*
 * THREAD SAFETY: crypto_sign_keypair() is thread-safe,
 * provided that you called sodium_init() once before using any
 * other libsodium function.
 * Other functions, including crypto_sign_seed_keypair() are always thread-safe.
 */

#include <stddef.h>

#include "crypto_sign_ed25519.h"
#include "export.h"

#ifdef __cplusplus
# ifdef __GNUC__
#  pragma GCC diagnostic ignored "-Wlong-long"
# endif
extern "C" {
#endif

#define crypto_sign_BYTES crypto_sign_ed25519_BYTES
SODIUM_EXPORT
size_t  crypto_sign_bytes(void);

#define crypto_sign_SEEDBYTES crypto_sign_ed25519_SEEDBYTES
SODIUM_EXPORT
size_t  crypto_sign_seedbytes(void);

#define crypto_sign_PUBLICKEYBYTES crypto_sign_ed25519_PUBLICKEYBYTES
SODIUM_EXPORT
size_t  crypto_sign_publickeybytes(void);

#define crypto_sign_SECRETKEYBYTES crypto_sign_ed25519_SECRETKEYBYTES
SODIUM_EXPORT
size_t  crypto_sign_secretkeybytes(void);

#define crypto_sign_PRIMITIVE "ed25519"
SODIUM_EXPORT
const char *crypto_sign_primitive(void);

SODIUM_EXPORT
int crypto_sign_seed_keypair(unsigned char *pk, unsigned char *sk,
                             const unsigned char *seed);

SODIUM_EXPORT
int crypto_sign_keypair(unsigned char *pk, unsigned char *sk);

SODIUM_EXPORT
int crypto_sign(unsigned char *sm, unsigned long long *smlen_p,
                const unsigned char *m, unsigned long long mlen,
                const unsigned char *sk);

SODIUM_EXPORT
int crypto_sign_open(unsigned char *m, unsigned long long *mlen_p,
                     const unsigned char *sm, unsigned long long smlen,
                     const unsigned char *pk)
            __attribute__ ((warn_unused_result));

SODIUM_EXPORT
int crypto_sign_detached(unsigned char *sig, unsigned long long *siglen_p,
                         const unsigned char *m, unsigned long long mlen,
                         const unsigned char *sk);

SODIUM_EXPORT
int crypto_sign_verify_detached(const unsigned char *sig,
                                const unsigned char *m,
                                unsigned long long mlen,
                                const unsigned char *pk)
            __attribute__ ((warn_unused_result));

SODIUM_EXPORT
int crypto_sign_verify_cosi(const unsigned char *sig,
			    unsigned long siglen,
                            const unsigned char *m,
                            unsigned long long mlen,
                            const unsigned char *pklist,
			    unsigned long pkcount,
			    crypto_sign_cosi_policy policy,
			    void *policy_data)
            __attribute__ ((warn_unused_result));

SODIUM_EXPORT
int crypto_sign_threshold_policy(const unsigned char *mask,
				 unsigned long pkcount,
				 void *data);
#ifdef __cplusplus
}
#endif

#endif
