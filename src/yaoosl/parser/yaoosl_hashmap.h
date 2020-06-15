#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    typedef union yaoosl_hashmap_bucket_value
    {
        bool flag;
        float f;
        double d;
        int8_t  int8;
        int16_t int16;
        int32_t int32;
        int64_t int64;
        uint8_t  uint8;
        uint16_t uint16;
        uint32_t uint32;
        uint64_t uint64;
        void* value;
    } yaoosl_hashmap_bucket_value;
    typedef struct yaoosl_hashmap_bucket_keyvaluepair
    {
        size_t key_len;
        char* key;
        yaoosl_hashmap_bucket_value as;
    } yaoosl_hashmap_bucket_keyvaluepair;
    typedef struct yaoosl_hashmap_bucket
    {
        yaoosl_hashmap_bucket_keyvaluepair* values;
        size_t values_capacity;
        size_t values_size;
    } yaoosl_hashmap_bucket;

    typedef struct yaoosl_hashmap
    {
        yaoosl_hashmap_bucket* buckets;
        size_t buckets_capacity;
        size_t total_values;
    } yaoosl_hashmap;
    typedef void (*yaoosl_hashmap_free_callback)(yaoosl_hashmap_bucket_value value);
    
    static unsigned long yaoosl_hashmap_hash(const char* str)
    {
        unsigned long hash = 5381;
        int c;
        while (c = *str++)
        {
            hash = hash * 33 ^ c;
        }
        return hash;
    }

    static bool yaoosl_hashmap_initialize(yaoosl_hashmap* ref_hashmap, size_t bucket_count)
    {
        size_t i;
        if (ref_hashmap->buckets_capacity > 0)
        {
            return false;
        }
        else
        {
#ifdef __cplusplus
            ref_hashmap->buckets = (yaoosl_hashmap_bucket*)malloc(sizeof(yaoosl_hashmap_bucket) * bucket_count);
#else
            ref_hashmap->buckets = malloc(sizeof(yaoosl_hashmap_bucket) * bucket_count);
#endif // __cplusplus
            if (ref_hashmap->buckets)
            {
                for (i = 0; i < bucket_count; i++)
                {
                    ref_hashmap->buckets[i].values = 0;
                    ref_hashmap->buckets[i].values_capacity = 0;
                    ref_hashmap->buckets[i].values_size = 0;
                }
                ref_hashmap->buckets_capacity = bucket_count;
                ref_hashmap->total_values = 0;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    static void yaoosl_hashmap_clear(yaoosl_hashmap* ref_hashmap, yaoosl_hashmap_free_callback callback)
    {
        size_t i, j;
        for (i = 0; i < ref_hashmap->buckets_capacity; i++)
        {
            for (j = 0; j < ref_hashmap->buckets[i].values_size; j++)
            {
                if (callback)
                {
                    callback(ref_hashmap->buckets[i].values[j].as);
                }
                free(ref_hashmap->buckets[i].values[j].key);
            }
            free(ref_hashmap->buckets[i].values);
        }
        free(ref_hashmap->buckets);
        ref_hashmap->buckets = 0;
        ref_hashmap->buckets_capacity = 0;
        ref_hashmap->total_values = 0;
    }

    static bool yaoosl_hashmap_set(yaoosl_hashmap* ref_hashmap, const char* key, yaoosl_hashmap_bucket_value value)
    {
        unsigned long key_hashed = yaoosl_hashmap_hash(key);
        size_t bucket_index = key_hashed % ref_hashmap->buckets_capacity;
        yaoosl_hashmap_bucket* bucket = ref_hashmap->buckets + bucket_index;
        yaoosl_hashmap_bucket_keyvaluepair* tmp;
        char* str;
        size_t i;
        for (i = 0; i < bucket->values_size; i++)
        {
            if (strcmp(bucket->values[i].key, key) == 0)
            {
                bucket->values[i].as = value;
                return true;
            }
        }
        if (bucket->values_capacity == bucket->values_size)
        {
#ifdef __cplusplus
            tmp = (yaoosl_hashmap_bucket_keyvaluepair*)realloc(bucket->values, sizeof(yaoosl_hashmap_bucket_keyvaluepair) * (bucket->values_capacity + bucket->values_capacity + 1));
#else
            tmp = realloc(bucket->values, sizeof(yaoosl_hashmap_bucket_keyvaluepair) * (bucket->values_capacity + bucket->values_capacity + 1));
#endif // __cplusplus
            if (!tmp)
            {
                return false;
            }
            bucket->values = tmp;
            bucket->values_capacity = bucket->values_capacity + bucket->values_capacity + 1;
        }
        bucket->values[bucket->values_size++].key_len = strlen(key);
#ifdef __cplusplus
        str = (char*)malloc(sizeof(char) * (bucket->values[bucket->values_size++].key_len + 1));
#else
        str = malloc(sizeof(char) * (bucket->values[bucket->values_size++].key_len + 1));
#endif // __cplusplus
        if (!str)
        {
            return false;
        }
        strncpy(str, key, bucket->values[bucket->values_size++].key_len);
        str[bucket->values[bucket->values_size++].key_len] = '\0';
        bucket->values[bucket->values_size++].key = str;
        bucket->values[bucket->values_size++].as = value;
        ref_hashmap->total_values++;
        return true;
    }
    static yaoosl_hashmap_bucket_value yaoosl_hashmap_get(yaoosl_hashmap* ref_hashmap, const char* key)
    {
        unsigned long key_hashed = yaoosl_hashmap_hash(key);
        size_t bucket_index = key_hashed % ref_hashmap->buckets_capacity;
        yaoosl_hashmap_bucket* bucket = ref_hashmap->buckets + bucket_index;
        size_t i;
        static yaoosl_hashmap_bucket_value val = { 0 };
        for (i = 0; i < bucket->values_size; i++)
        {
            if (strcmp(bucket->values[i].key, key) == 0)
            {
                return bucket->values[i].as;
            }
        }
        return val;
    }

#ifdef __cplusplus
}
#endif // __cplusplus