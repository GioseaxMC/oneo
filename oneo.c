#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// #include <math.h>

#undef bool
typedef _Bool bool;
#define true (bool)1
#define false (bool)0

#define or ||
#define and &&

#define __fmt(x) _Generic((x), \
    int: "%d", \
    unsigned int: "%u", \
    long: "%ld", \
    unsigned long: "%lu", \
    long long: "%lld", \
    unsigned long long: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char*: "%s", \
    const char*: "%s", \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    short: "%hd", \
    unsigned short: "%hu", \
    void*: "%p", \
    bool*: "%d", \
    default: "%%?" \
)

#define FAIL(msg) _Static_assert(0, msg)

#define FE_1(macro, x, ...) macro(x)
#define FE_2(macro, x, ...) FE_1(macro, x) FE_1(macro, __VA_ARGS__)
#define FE_3(macro, x, ...) FE_1(macro, x) FE_2(macro, __VA_ARGS__)
#define FE_4(macro, x, ...) FE_1(macro, x) FE_3(macro, __VA_ARGS__)
#define FE_5(macro, x, ...) FE_1(macro, x) FE_4(macro, __VA_ARGS__)
#define FE_6(macro, x, ...) FE_1(macro, x) FE_5(macro, __VA_ARGS__)
#define FE_7(macro, x, ...) FE_1(macro, x) FE_6(macro, __VA_ARGS__)
#define FE_8(macro, x, ...) FE_1(macro, x) FE_7(macro, __VA_ARGS__)
#define FE_9(macro, x, ...) FE_1(macro, x) FE_8(macro, __VA_ARGS__)
#define FE_10(macro, x, ...) FE_1(macro, x) FE_9(macro, __VA_ARGS__)
#define FE_11(macro, x, ...) FE_1(macro, x) FE_10(macro, __VA_ARGS__)
#define FE_12(macro, x, ...) FE_1(macro, x) FE_11(macro, __VA_ARGS__)
#define FE_13(macro, x, ...) FE_1(macro, x) FE_12(macro, __VA_ARGS__)
#define FE_14(macro, x, ...) FE_1(macro, x) FE_13(macro, __VA_ARGS__)
#define FE_15(macro, x, ...) FE_1(macro, x) FE_14(macro, __VA_ARGS__)
#define FE_16(macro, x, ...) FE_1(macro, x) FE_15(macro, __VA_ARGS__)
#define FE_17(macro, x, ...) FE_1(macro, x) FE_16(macro, __VA_ARGS__)
#define FE_18(macro, x, ...) FE_1(macro, x) FE_17(macro, __VA_ARGS__)
#define FE_19(macro, x, ...) FE_1(macro, x) FE_18(macro, __VA_ARGS__)
#define FE_20(macro, x, ...) FE_1(macro, x) FE_19(macro, __VA_ARGS__)
#define FE_21(macro, x, ...) FE_1(macro, x) FE_20(macro, __VA_ARGS__)
#define FE_22(macro, x, ...) FE_1(macro, x) FE_21(macro, __VA_ARGS__)
#define FE_23(macro, x, ...) FE_1(macro, x) FE_22(macro, __VA_ARGS__)
#define FE_24(macro, x, ...) FE_1(macro, x) FE_23(macro, __VA_ARGS__)
#define FE_25(macro, x, ...) FE_1(macro, x) FE_24(macro, __VA_ARGS__)
#define FE_26(macro, x, ...) FE_1(macro, x) FE_25(macro, __VA_ARGS__)
#define FE_27(macro, x, ...) FE_1(macro, x) FE_26(macro, __VA_ARGS__)
#define FE_28(macro, x, ...) FE_1(macro, x) FE_27(macro, __VA_ARGS__)
#define FE_29(macro, x, ...) FE_1(macro, x) FE_28(macro, __VA_ARGS__)
#define FE_30(macro, x, ...) FE_1(macro, x) FE_29(macro, __VA_ARGS__)
#define FE_31(macro, x, ...) FE_1(macro, x) FE_30(macro, __VA_ARGS__)
#define FE_32(macro, x, ...) FE_1(macro, x) FE_31(macro, __VA_ARGS__)

#define FE_END(...) FAIL("macro foreach accepts at max 32 arguments")
#define FE_START(...)

#define GET_MACRO( \
                start, end, _01,_02,_03,_04,_05,_06,_07,_08,_09,_10,_11,_12,_13,_14,_15,_16,\
                _17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,\
                NAME, ...) NAME

#define FOR_EACH(action, ...) \
    GET_MACRO(0, ##__VA_ARGS__, FE_END, FE_32,FE_31,FE_30,FE_29,FE_28,FE_27,FE_26,FE_25,FE_24,FE_23,FE_22,FE_21,\
            FE_20,FE_19,FE_18,FE_17,FE_16,FE_15,FE_14,FE_13,FE_12,FE_11,FE_10,FE_9,FE_8,FE_7,FE_6,FE_5,FE_4,FE_3,FE_2,FE_1,FE_START\
            ) (action, ##__VA_ARGS__)

#define _print_argument(x) _Generic(x, bool: printf(x?"true":"false"), default: printf(__fmt(x), x));
#define print(...) do {FOR_EACH(_print_argument, ##__VA_ARGS__) printf("\n"); } while (0)
#define prompt(...) do {FOR_EACH(_print_argument, ##__VA_ARGS__); } while (0)

#define __concat_impl(a, b) a##b
#define __concat_call(a, b) a b
#define ___concat(a, b) __concat_call(__concat_impl, (a, b))
#define unique_name ___concat(_unique_name, __COUNTER__)

#ifndef ARRAY_INIT_CAPACITY
#define ARRAY_INIT_CAPACITY 256
#endif // ARRAY_INIT_CAPACITY

#define ARR_SENTINEL (uintptr_t)0xDEADCAFEBULL
#define array(type) type*

typedef struct {
    uintptr_t probe;
    int len;
    int capacity;
} Array_header;

#define array_data(arr) (void*)(((Array_header*)(arr))+1)
#define arr_header(arr) (((Array_header*) (arr))-1)
void* allocate_inited_array(int sizeof_item, int init_capacity) {
    int size = sizeof_item*init_capacity+ARRAY_INIT_CAPACITY;
    Array_header* array = malloc(size);
    memset(array, 0, size);
    array->capacity = ARRAY_INIT_CAPACITY;
    array->probe = ARR_SENTINEL;
    return array_data(array);
}

#define new_array(type) (array(type)) allocate_inited_array(sizeof(type), ARRAY_INIT_CAPACITY);
#define is_array(arr) ((bool)((arr) and arr_header(arr)->probe==ARR_SENTINEL))
#define arr_len(arr) arr_header(arr)->len
#define arr_capacity(arr) arr_header(arr)->capacity
#define arr_start(arr) (arr)
#define arr_end(arr) ((arr)+arr_len(arr))
#define arr_ensure(arr, new_size) do { \
        (arr) = array_data(realloc(arr_header(arr), arr_capacity(arr)*2)); \
        arr_capacity(arr) = new_size; } while(0)
#define arr_push(arr, item) do { \
    if (!(arr)) (arr) = allocate_inited_array(sizeof(*arr), ARRAY_INIT_CAPACITY); \
    (arr)[arr_len(arr)++] = (item); \
    if (arr_len(arr) >= arr_capacity(arr)) arr_ensure((arr), arr_capacity(arr)*2); \
} while (0)
#define arr_unordered_remove(arr, index) (arr)[index] = (arr)[--arr_len(arr)]
#define arr_free(arr) free((void*)arr_header(arr))

#define in ,
#define foreach_impl(iter, arr) for(typeof(arr) iter = arr_start(arr); iter!=arr_end(arr); iter++)
#define foreach(...) foreach_impl(__VA_ARGS__)
#define repeat(name, count) for(int name=0; name<count; ++name)

typedef char* string;
typedef void* ptr_t;

typedef array(string) strings;
strings __library_strings=NULL;

int _get_line(string* buffer) {
    char temp[2048];
    fgets(temp, 2048, stdin);
    int size=0;
    for(; temp[size]!=0; size++) {};
    temp[--size] = 0;
    // assert(!*buffer && "expected uninitialized buffer");
    if (!*buffer) {
        *buffer = malloc(size+1);
        arr_push(__library_strings, *buffer);
    }
    strcpy(*buffer, temp);
    return size;
}

int _get_fmt(string fmt, string* ptr) {
    char _line[2048];
    string line = (string)_line;
    memset(line, 0, 2048);
    _get_line(&line);
    return sscanf(line, fmt, ptr);
}

#if defined(__GNUC__)
    #define __at_start_impl(FUNC) \
        static void FUNC(void) __attribute__((constructor)); \
        static void FUNC(void)
    #define at_start __at_start_impl(unique_name)
#else
    #error Imagine not using gnu c (skull emoji)
#endif

#define scan(type, var_ptr) do { \
    _Pragma("GCC diagnostic push"); \
    _Pragma("GCC diagnostic ignored \"-Wformat\""); \
    _Generic((type)0, \
        char*: _get_line((void*)var_ptr), \
        default: _get_fmt(__fmt((type)0), (void*)var_ptr) \
    ); \
    _Pragma("GCC diagnostic pop"); \
} while (0)

typedef void(*voidfn_t)(void);

array(voidfn_t) __at_exit_funcs = NULL;
void __at_exit_impl(void) {
    if (__at_exit_funcs) {
        foreach(func, __at_exit_funcs) {
            (*func)();
        }
        arr_free(__at_exit_funcs);
    }
    if (__library_strings) {
        foreach(str, __library_strings) {
            free(*str);
        }
        arr_free(__library_strings);
    }
}

void at_exit(voidfn_t fn) {
    arr_push(__at_exit_funcs, fn);
}

at_start {
    atexit(__at_exit_impl);
}

// end library

// experimenting:

void __free_ptr(ptr_t _ptr) {
    void** ptr = _ptr;
    if (*ptr) {
        free(*ptr);
        *ptr = NULL;
    }
}

#define scope __attribute__((cleanup(__free_ptr)))
#define free_later(ptr) \
    scope void* unique_name() = ptr;
