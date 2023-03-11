#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define true 1

uint64_t my_strlen(const char *s) {
    uint64_t offset = 0;
    while (*(s + offset) != '\0') {
        offset++;
    }
    return offset;
}

char *my_strcpy(char* dst,const char* src) {
    uint64_t offset = 0;

    while ((*(dst + offset) = *(src + offset)) != '\0') {
        offset++;
    }
    
    return dst;
}

char* my_strncpy(char* dst, const char* src, size_t n) {
    size_t offset;
    
    for (offset = 0; offset < n && src[offset] != '\0'; ++offset) {
        dst[offset] = src[offset];
    }

    for (; offset < n; ++offset) {
        dst[offset] = '\0';
    }

    return dst;
}

int my_strcmp(const char* s1, const char* s2) {
    size_t offset = 0;
    int result = 0;
    while (s1[offset] != '\0' && s2[offset] != '\0') {
        result = s1[offset] - s2[offset];
        if (result != 0) {
            break;
        }
        offset++;
    }

    result = s1[offset] - s2[offset];

    return result;
}

int my_strncmp(const char* s1, const char* s2, size_t n) {
    int result = 0;
    size_t i = 0;
    for (i = 0; i < n && s1[i] != '\0' && s2[i] != 0; ++i) {
        result = s1[i] - s2[i];
        if (result != 0) {
            break;
        }
    }

    if ((i != n) && (s1[i] == '\0' || s2[i] == '\0')) {
        result = s1[i] - s2[i];
    }

    return result;
}

void* my_memset(void* v,int c,size_t n) {
    char *iv = (char *)v;
    for (int i = 0; i < n; ++i) {
        iv[i] = c;
    }
    return v;
}

void* my_memmove(void* dst,const void* src,size_t n) {
    char *cdst = (char *)dst;
    char *csrc = (char *)src;
    for (size_t i = 0; i < n; ++i) {
        cdst[i] = csrc[i];
    }
    return dst;
}

int my_memcmp(const void* s1, const void* s2, size_t n) {
    char *cs1 = (char *)s1;
    char *cs2 = (char *)s2;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        result = cs1[i] - cs2[i];
        if (result != 0) {
            break;
        }
    }

    return result;
}

// current only support Decimal
static inline int itoa(int num, char *dest, int base) {
    int offset = 0;
    int rem = 0;
    char neg_flag = 0;
    
    if (num < 0) {
        neg_flag = 1;
        dest[offset++] = '-';
    }

    while (num != 0) {
        rem = neg_flag == 1 ? -(num % base) : num % base;
        dest[offset++] = '0' + rem;
        num /= base;
    }

    dest[offset] = '\0';

    char temp = 0;
    for (int i = 0 + neg_flag; i < ((offset + neg_flag) >> 1); ++i) {
        temp = dest[i];
        dest[i] = dest[offset - 1 - i + neg_flag];
        dest[offset - 1 - i + neg_flag] = temp;
    }

    // return length
    return offset;
}

int my_sprintf(char *out, const char *fmt, ...) {
    va_list ap;

    size_t fmt_index = 0;
    size_t out_index = 0;
    int cmp = 0;

    int integer = 0;
    int length_integer_str = 0;

    char * str = NULL;
    

    va_start(ap, fmt);
    char temp_buf[128] = {0};

    while (fmt[fmt_index] != '\0') {
        cmp = strncmp(fmt + fmt_index, "%d", 2);
        if (0 == cmp) {
            
            integer = va_arg(ap, int);
            length_integer_str = itoa(integer, temp_buf, 10);
            strcpy(out + out_index, temp_buf);
            
            out_index += length_integer_str;
            fmt_index += 2;

            continue;
        }

        cmp = strncmp(fmt + fmt_index, "%s", 2);
        if (0 == cmp) {
            
            str = va_arg(ap, char *);
            strcpy(out + out_index, str);
            out_index += strlen(str);
            fmt_index += 2;

            continue;
        }
        
        out[out_index] = fmt[fmt_index];
        ++out_index;
        ++fmt_index;
    }
    
    out[out_index] = '\0';
}


int main(int argc, char *argv[]) {
    // char *temp1 = "abcdefgi";

    // uint64_t temp2 = my_strlen(temp1);
    // uint64_t temp3 = strlen(temp1);
    
    // char *des1 = (char*)malloc(sizeof(char) * temp2 * 2);
    // char *des2 = (char*)malloc(sizeof(char) * temp2 * 2);
    // char *ret1 = my_strcpy(des1, temp1);
    // char *ret2 = strcpy(des2, temp1);
    
    // char *ret3 = my_strncpy(des1, temp1, sizeof(char) * temp2 * 2);
    // char *ret4 = strncpy(des2, temp1, sizeof(char) * temp2 * 2);

    // char *temp4 = "ABCDEFZZZZZ";
    // char *temp5 = "ABCDEFZ";

    // int res5 = my_strncmp(temp4, temp5, 7);
    // int res6 = strncmp(temp4, temp5, 7);

    // int *temp6 = (int *)malloc(sizeof(int) * 11);
    // int *temp7 = (int *)malloc(sizeof(int) * 11);
    // int *ret7 = memset(temp6, 6, 11);
    // int *ret8 = my_memset(temp7, 6, 11);
    
    // char *temp1 = "12345678910";
    // char *des1 = (char*)malloc(sizeof(char) * strlen(temp1) * 2);
    // char *ret1 = memmove(des1, temp1, strlen(temp1) + 1);
    // char *ret2 = my_memmove(des1, temp1, strlen(temp1) + 1);

    // ret1 = memmove(des1, des1 + 3, 4);
    // ret2 = my_memmove(des1, des1 + 3, 4);

    // char *temp1 = "ABCDA";
    // char *temp2 = "EBCDD";
    // int ret1 = my_memcmp(temp1, temp2, 5);
    // int ret2 = memcmp(temp1, temp2, 5);

    // printf("\\aaa\n");

    // char * temp1 = "\\";
    // char * temp2 = "a\%d";
    // char * temp3 = "a%d";

    // printf("a \\%d\n", 11);

    char temp[1024] = {0};
    //my_itoa(1234567, temp, 10);
    my_sprintf(temp, "aa%daa", -13432);
    my_sprintf(temp, "aa%daa", 13432);

    my_sprintf(temp, "aa %d ss %s %s aa %d ", -13432, "hello", "world", 22221);

}