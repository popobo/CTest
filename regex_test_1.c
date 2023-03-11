#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

enum {
    KEY_NONE,
    KEY_WIDTH,
    KEY_HEIGHT,
};

static struct rule  {
    char *regex;
    int token_type;
} rules[] = {
    {"WIDTH:([0-9]+)", KEY_WIDTH},
    {"HEIGHT:([0-9]+)", KEY_HEIGHT},
};

#define NR_REGEX (sizeof(rules) / sizeof(rules[0]))

static regex_t re[NR_REGEX] = {};

static inline void init_regex() {
    int i = 0;
    char error_msg[128] = {};
    int ret = 0;
    for (int i = 0; i < NR_REGEX; ++i) {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
        if (ret != 0) {
            regerror(ret, &re[i], error_msg, 128);
            printf("reg comp error: %s\n", error_msg);
            return;
        }
    }
}

void test(int n) {
    int buf[n];
    printf("sizeof(buf):%d\n", sizeof(buf));
}


static inline int32_t get_value_by_key(char *source, char *key) {
    if (NULL == source || NULL == source) {
        return -1;
    }
    
    size_t key_len = strlen(key);
    char *digit_value = ":([0-9]+)";
    size_t digit_value_len = strlen(digit_value);
    char reg_buf[key_len + digit_value_len + 1];
    strcpy(reg_buf, key);
    strcpy(reg_buf + key_len, digit_value);
    

    regex_t rt = {};
    int32_t ret = regcomp(&rt, reg_buf, REG_EXTENDED);
    if (ret != 0) {
        return -1;
    }

    size_t buf_index = 0;
    size_t source_len = strlen(source);
    char buf[source_len + 1];
    for (int32_t i = 0; i < source_len; ++i) {
        if (source[i] != ' ' && source[i] != '\n') {
            buf[buf_index++] = source[i];
        }
    }

    buf[buf_index] = '\0';
    
    const size_t max_matches = 1;
    const size_t max_groups = 2;
    regmatch_t group_array[max_groups]; 
    if (regexec(&rt, buf, max_groups, group_array, 0) != 0) {
        return -1;
    }

    if (((size_t) - 1) == group_array[max_groups - 1].rm_so) {
        // no more groups
        return -1;
    }
    
    size_t digit_buf_len = group_array[max_groups - 1].rm_eo - group_array[max_groups - 1].rm_so + 1 + 1;
    char digit_buf[digit_buf_len];
    strncpy(digit_buf, buf + group_array[max_groups - 1].rm_so, digit_buf_len - 1);
    digit_buf[digit_buf_len - 1] = '\0';
    int32_t result = atoi(digit_buf);

    return result;
}


int main() {

    char *source = " HEIGHT: 188  WIDTH   : 640 \n HEIGHT : 480  ";
    
    int result = get_value_by_key(source, "WIDTH");


    //init_regex();


    /*
    size_t position = 0;
    size_t i = 0;
    size_t source_len = strlen(source);
    size_t buf_index = 0;
    char buf[source_len];

    for (i = 0; i < source_len; ++i) {
        if (source[i] != ' ' && source[i] != '\n') {
            buf[buf_index++] = source[i]; 
        }
    }
    buf[buf_index] = 0;
    printf("buf:%s\n", buf);
    
    const size_t max_matches = 1;
    const size_t max_groups = 2;
    uint32_t m = 0;
    uint32_t g = 0;
    uint32_t offset = 0;
    regmatch_t group_array[2] = {};
    char *cursor = buf;

    for (i = 0; i < NR_REGEX; ++i) {
        if (regexec(&re[i], buf, max_groups, group_array, 0) != 0) {
            continue;
        }
        for (g = 0; g < max_groups; ++g) {
            if (((size_t) - 1) == group_array[g].rm_so) {
                break;
            }
            
            char position_copy[strlen(buf) + 1];
            strcpy(position_copy, buf);
            position_copy[group_array[0].rm_eo] = 0;
            printf("Match %u, Group %u: [%2u-%2u]: %s\n",
            m, g, group_array[g].rm_so, group_array[g].rm_eo,
            position_copy + group_array[g].rm_so);
        }
    }

    // while (buf[position] != 0) {
    //     for (i = 0; i < NR_REGEX; ++i) {
    //          if (regexec(&re[i], buf + position, max_groups, group_array, 0) == 0 && group_array[0].rm_so == 0) {    
                
    //             for (g = 0; g < max_groups; ++g) {
    //                 if (group_array[g].rm_so == (size_t) - 1)
    //                     break;
                    
    //                 if (g == 0)
    //                     offset = group_array[g].rm_eo;

    //                 char position_copy[strlen(buf + position) + 1];
    //                 strcpy(position_copy, buf + position);
    //                 position_copy[group_array[g].rm_eo] = 0;
    //                 printf("Match %u, Group %u: [%2u-%2u]: %s\n",
    //                 m, g, group_array[g].rm_so + position, group_array[g].rm_eo + position,
    //                 position_copy + group_array[g].rm_so);
    //             }
    //             position += offset;
    //             break;
    //         }
    //     }

    //     if (i == NR_REGEX) {
    //         printf("no match at position %d\n%s\n%*.s^\n", position, buf, position, "");
    //         return 0;
    //     }
    // }
    return 0;
    */
}