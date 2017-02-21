/*
 * Copyright (c) 2008-2016 Allwinner Technology Co. Ltd.
 * All rights reserved.
 *
 * File : CdxSSLStream.h
 * Description : SSLStream
 * History :
 *
 */

#ifndef CDX_SSL_UTILS_H
#define CDX_SSL_UTILS_H
#include <CdxTypes.h>
#include <CdxLog.h>

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#include <mbedtls/net.h>
#include <mbedtls/debug.h>
#include <mbedtls/ssl.h>
#include <mbedtls/entropy.h>
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/error.h>
#include <mbedtls/certs.h>

typedef enum SslType
{
    _OPENSSL,
    _MBEDTLS    
}SslTypeT;

struct CdxSSLUtilsOpsS
{
    cdx_int32 (*create)(void * /*ctx*/);
    cdx_int32 (*connect)(void * /*ctx*/, cdx_int32 sockfd, const char *hostname, const char *port,
                        cdx_long timeoutUs, cdx_int32 *pForceStop);
    cdx_int32 (*handshake)(void * /*ctx*/);
    cdx_int32 (*read)(void * /*ctx*/, void * /*buf*/, cdx_uint32 /*len*/);
    cdx_int32 (*write)(void * /*ctx*/, void * /*buf*/, cdx_uint32 /*len*/);
    cdx_int32 (*close)(void * /*ctx*/);
    cdx_int32 (*free)(void * /*ctx*/);
};

typedef struct CdxSSLUtils
{
    SSL *ssl;
    SSL_CTX *ctx;

    mbedtls_ssl_context mbedtls_ssl_ctx;
    mbedtls_net_context mbedtls_net_ctx;
    struct CdxSSLUtilsOpsS *ops;
    //add more
}CdxSSLUtilsT;

extern cdx_int32 CdxSSLUtilsCreate(CdxSSLUtilsT *ssl, SslTypeT type);
extern cdx_int32 CdxSSLUtilsFree(CdxSSLUtilsT *ssl);


typedef struct _MBEDTLS_SESSION {
    mbedtls_net_context      mbedNetCtx;
    mbedtls_ssl_context      mbedSslCtx;
    mbedtls_ssl_config       mbedSslConf;
    mbedtls_ctr_drbg_context mbedDrbgCtx;
    mbedtls_entropy_context  mbedEtpyCtx;
    mbedtls_x509_crt         mbedX509Crt;
} MbedTLSSession_st;
extern void MbedTlsClientInit(MbedTLSSession_st *session, unsigned char *entropy, size_t entropyLen);
extern int AMCMbedTlsClientConnect(MbedTLSSession_st *session, const char *serverHost, int serverPort);
#endif
