/*
 * array-macros
 * Copyright (C) 2025  Thomas George Hodgkinson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ARRAY_MACROS_H
#define ARRAY_MACROS_H

#include <stdbool.h>
#include <stddef.h> // for size_t
#include <stdint.h> // for SIZE_MAX
#include <stdio.h>
#include <stdlib.h>

#define DECLARE_ARRAY_STRUCT(prefix, name) \
    typedef struct prefix##_array name##Array;

#define DECLARE_ARRAY_FUNCTIONS(prefix, name, type)                                     \
    name##Array *prefix##_array_create(size_t initial_capacity);                        \
    void prefix##_array_free(name##Array *prefix##_array);                              \
                                                                                        \
    const type *prefix##_array_get_data(const name##Array *prefix##_array);             \
    type *prefix##_array_get_data_mut(name##Array *prefix##_array);                     \
    size_t prefix##_array_get_count(const name##Array *prefix##_array);                 \
    size_t prefix##_array_get_capacity(const name##Array *prefix##_array);              \
                                                                                        \
    bool prefix##_array_push(name##Array *prefix##_array, type item);                   \
    bool prefix##_array_insert(name##Array *prefix##_array, size_t index, type item);   \
    bool prefix##_array_set(name##Array *prefix##_array, size_t index, type item);      \
    bool prefix##_array_remove(name##Array *prefix##_array, size_t index);              \
    bool prefix##_array_get(name##Array *prefix##_array, size_t index, type *out_item); \
    bool prefix##_array_is_empty(const name##Array *prefix##_array);                    \
    bool prefix##_array_is_full(const name##Array *prefix##_array);                     \
    void prefix##_array_clear(name##Array *prefix##_array);

#define DEFINE_ARRAY_STRUCT(prefix, name, type) \
    typedef struct prefix##_array               \
    {                                           \
        type *data;                             \
        size_t count;                           \
        size_t capacity;                        \
    } name##Array;

#define DEFINE_ARRAY_FUNCTIONS(prefix, name, type)                              \
    static inline bool prefix##_array_grow_impl(name##Array *prefix##_array);   \
                                                                                \
    name##Array *prefix##_array_create(size_t initial_capacity)                 \
    {                                                                           \
        if (!initial_capacity)                                                  \
        {                                                                       \
            fprintf(                                                            \
                stderr,                                                         \
                "%s: Initial capacity cannot be 0\n",                           \
                __func__);                                                      \
            return NULL;                                                        \
        }                                                                       \
                                                                                \
        name##Array *prefix##_array = malloc(sizeof(*prefix##_array));          \
        if (!prefix##_array)                                                    \
        {                                                                       \
            perror(#prefix "_array allocation failure");                        \
            return NULL;                                                        \
        }                                                                       \
                                                                                \
        if (initial_capacity > SIZE_MAX / sizeof(*prefix##_array->data))        \
        {                                                                       \
            fprintf(                                                            \
                stderr,                                                         \
                "%s: Initial capacity cannot be greater than %zu\n",            \
                __func__,                                                       \
                SIZE_MAX / sizeof(*prefix##_array->data));                      \
            free(prefix##_array);                                               \
            return NULL;                                                        \
        }                                                                       \
                                                                                \
        prefix##_array->count = 0;                                              \
        prefix##_array->capacity = initial_capacity;                            \
        prefix##_array->data = malloc(                                          \
            prefix##_array->capacity * sizeof(*prefix##_array->data));          \
        if (!prefix##_array->data)                                              \
        {                                                                       \
            perror(#prefix "_array data allocation failure");                   \
            free(prefix##_array);                                               \
            return NULL;                                                        \
        }                                                                       \
                                                                                \
        return prefix##_array;                                                  \
    }                                                                           \
                                                                                \
    void prefix##_array_free(name##Array *prefix##_array)                       \
    {                                                                           \
        free(prefix##_array->data);                                             \
        free(prefix##_array);                                                   \
    }                                                                           \
                                                                                \
    const type *prefix##_array_get_data(const name##Array *prefix##_array)      \
    {                                                                           \
        return prefix##_array->data;                                            \
    }                                                                           \
                                                                                \
    type *prefix##_array_get_data_mut(name##Array *prefix##_array)              \
    {                                                                           \
        return prefix##_array->data;                                            \
    }                                                                           \
                                                                                \
    size_t prefix##_array_get_count(const name##Array *prefix##_array)          \
    {                                                                           \
        return prefix##_array->count;                                           \
    }                                                                           \
                                                                                \
    size_t prefix##_array_get_capacity(const name##Array *prefix##_array)       \
    {                                                                           \
        return prefix##_array->capacity;                                        \
    }                                                                           \
                                                                                \
    bool prefix##_array_push(name##Array *prefix##_array, type item)            \
    {                                                                           \
        if (!prefix##_array_grow_impl(prefix##_array))                          \
            return false;                                                       \
        prefix##_array->data[prefix##_array->count++] = item;                   \
        return true;                                                            \
    }                                                                           \
                                                                                \
    bool prefix##_array_insert(name##Array *prefix##_array, size_t index, type item)          \
    {                                                                                         \
        if (!prefix##_array_grow_impl(prefix##_array))                                        \
            return false;                                                                     \
                                                                                              \
        if (index > prefix##_array->count)                                                    \
        {                                                                                     \
            fprintf(                                                                          \
                stderr,                                                                       \
                "%s: Index (%zu) out of bounds (%zu)\n",                                      \
                __func__,                                                                     \
                index,                                                                        \
                prefix##_array->count);                                                       \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        if (index == prefix##_array->count)                                                   \
        {                                                                                     \
            prefix##_array->data[prefix##_array->count++] = item;                             \
            return true;                                                                      \
        }                                                                                     \
                                                                                              \
        memmove(                                                                              \
            &prefix##_array->data[index + 1],                                                 \
            &prefix##_array->data[index],                                                     \
            (prefix##_array->count - index) * sizeof(*prefix##_array->data));                 \
                                                                                              \
        prefix##_array->data[index] = item;                                                   \
        prefix##_array->count++;                                                              \
                                                                                              \
        return true;                                                                          \
    }                                                                                         \
                                                                                              \
    bool prefix##_array_set(name##Array *prefix##_array, size_t index, type item)             \
    {                                                                                         \
        if (prefix##_array->count == 0)                                                       \
        {                                                                                     \
            fprintf(stderr, "%s: Array is empty (count 0)\n", __func__);                      \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        if (index >= prefix##_array->count)                                                   \
        {                                                                                     \
            fprintf(                                                                          \
                stderr,                                                                       \
                "%s: Index (%zu) out of bounds (%zu)\n",                                      \
                __func__,                                                                     \
                index,                                                                        \
                prefix##_array->count);                                                       \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        prefix##_array->data[index] = item;                                                   \
                                                                                              \
        return true;                                                                          \
    }                                                                                         \
                                                                                              \
    bool prefix##_array_remove(name##Array *prefix##_array, size_t index)                     \
    {                                                                                         \
        if (prefix##_array->count == 0)                                                       \
        {                                                                                     \
            fprintf(stderr, "%s: Array is empty (count 0)\n", __func__);                      \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        if (index >= prefix##_array->count)                                                   \
        {                                                                                     \
            fprintf(                                                                          \
                stderr,                                                                       \
                "%s: index (%zu) out of bounds (%zu)\n",                                      \
                __func__,                                                                     \
                index,                                                                        \
                prefix##_array->count);                                                       \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        if (index == prefix##_array->count - 1)                                               \
        {                                                                                     \
            prefix##_array->count--;                                                          \
            return true;                                                                      \
        }                                                                                     \
                                                                                              \
        memmove(                                                                              \
            &prefix##_array->data[index],                                                     \
            &prefix##_array->data[index + 1],                                                 \
            (prefix##_array->count - index + 1) * sizeof(*prefix##_array->data));             \
                                                                                              \
        prefix##_array->count--;                                                              \
                                                                                              \
        return true;                                                                          \
    }                                                                                         \
                                                                                              \
    bool prefix##_array_get(name##Array *prefix##_array, size_t index, type *out_item)        \
    {                                                                                         \
        if (prefix##_array->count == 0)                                                       \
        {                                                                                     \
            fprintf(stderr, "%s: Array is empty (count 0)\n", __func__);                      \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        if (index >= prefix##_array->count)                                                   \
        {                                                                                     \
            fprintf(                                                                          \
                stderr,                                                                       \
                "%s: Index (%zu) out of bounds (%zu)\n",                                      \
                __func__,                                                                     \
                index,                                                                        \
                prefix##_array->count);                                                       \
            return false;                                                                     \
        }                                                                                     \
                                                                                              \
        *out_item = prefix##_array->data[index];                                              \
                                                                                              \
        return true;                                                                          \
    }                                                                                         \
                                                                                              \
    bool prefix##_array_is_empty(const name##Array *prefix##_array)             \
    {                                                                           \
        return !prefix##_array->count;                                          \
    }                                                                           \
                                                                                \
    bool prefix##_array_is_full(const name##Array *prefix##_array)              \
    {                                                                           \
        return prefix##_array->count == prefix##_array->capacity;               \
    }                                                                           \
                                                                                \
    void prefix##_array_clear(name##Array *prefix##_array)                      \
    {                                                                           \
        prefix##_array->count = 0;                                              \
    }                                                                           \
                                                                                \
    static inline bool prefix##_array_grow_impl(name##Array *prefix##_array)    \
    {                                                                           \
        if (prefix##_array->count < prefix##_array->capacity)                   \
            return true;                                                        \
                                                                                \
        if (prefix##_array->capacity > SIZE_MAX / 2)                            \
        {                                                                       \
            fprintf(                                                            \
                stderr,                                                         \
                "%s: Capacity (%zu) cannot be doubled without overflow. "       \
                "Max allowed is %zu entries.\n",                                \
                __func__,                                                       \
                prefix##_array->capacity,                                       \
                SIZE_MAX / 2);                                                  \
            return false;                                                       \
        }                                                                       \
                                                                                \
        const size_t new_capacity = prefix##_array->capacity * 2;               \
                                                                                \
        if (new_capacity > SIZE_MAX / sizeof(*prefix##_array->data))            \
        {                                                                       \
            fprintf(                                                            \
                stderr,                                                         \
                "%s: Increasing capacity would overflow malloc. "               \
                "Max capacity in bytes is %zu\n",                               \
                __func__,                                                       \
                SIZE_MAX / sizeof(*prefix##_array->data));                      \
            return false;                                                       \
        }                                                                       \
                                                                                \
        type *new_data = realloc(                                               \
            prefix##_array->data,                                               \
            new_capacity * sizeof(*prefix##_array->data));                      \
                                                                                \
        if (!new_data)                                                          \
        {                                                                       \
            perror(#prefix "_array_grow_impl: Error with realloc");             \
            return false;                                                       \
        }                                                                       \
                                                                                \
        prefix##_array->data = new_data;                                        \
        prefix##_array->capacity = new_capacity;                                \
                                                                                \
        return true;                                                            \
    }

#endif // ARRAY_MACROS_H
