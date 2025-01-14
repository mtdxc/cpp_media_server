#ifndef BYTE_CRYTO_HPP
#define BYTE_CRYTO_HPP

#include <stdint.h>
#include <stddef.h>
#include <string>
#include <random>

struct hmac_ctx_st;
typedef struct hmac_ctx_st HMAC_CTX;

#define SHA1_BUFFER_SIZE 20

class byte_crypto
{
public:
    static void init();
    static void deinit();
    static uint32_t get_random_uint(uint32_t min, uint32_t max);
    static uint32_t get_crc32(const uint8_t* data, size_t size);
    static uint8_t* get_hmac_sha1(const std::string& key, const uint8_t* data, size_t len);
    static std::string get_random_string(size_t len);

private:
    static std::default_random_engine random;
    static HMAC_CTX* hmac_sha1_ctx;
    static const uint32_t crc32_table[256];
};


#endif