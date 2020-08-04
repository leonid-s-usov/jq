
#ifndef JQ_PLUGIN_H
#define JQ_PLUGIN_H

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

typedef void* (*jq_hopen_f)(jq_state *, jv uri, jv* error);
typedef jv (*jq_hclose_f)(jq_state *, void *, jv input);
typedef jv (*jq_hreset_f)(jq_state *, void *, jv input);
typedef jv (*jq_heof_f)(jq_state *, void *, jv input);
typedef jv (*jq_hio_f)(jq_state *, void *, jv input, jv arg);

struct jq_io_table {
  jq_hopen_f open;
  jq_hclose_f close;
  jq_hreset_f reset;
  jq_heof_f at_eof;
  jq_hio_f io;
};

jv jq_handle_register_scheme(jq_state * jq, const char * scheme, struct jq_io_table * io_table);

jv jq_handle_open(jq_state *jq, jv uri);
jv jq_handle_close(jq_state *jq, jv jhandle, jv input);
jv jq_handle_reset(jq_state *jq, jv jhandle, jv input);
jv jq_handle_io(jq_state *jq, jv jhandle, jv input, jv arg);
jv jq_handle_at_eof(jq_state *jq, jv jhandle, jv input);


#define MAX_CFUNCTION_ARGS 10
typedef void (*cfunction_ptr)();
struct cfunction {
  cfunction_ptr fptr;
  const char* name;
  int nargs;
  unsigned int pure:1;
  unsigned int exported:1;
};

/* GENERATED BY dwarf2h START */
typedef jv (*jq_get_error_message_f)(jq_state*);
typedef jv (*jq_get_exit_code_f)(jq_state*);
typedef int (*jq_halted_f)(jq_state*);
typedef int (*jq_finished_f)(jq_state*);
typedef void (*jq_halt_f)(jq_state*,jv,jv);
typedef void (*jq_get_debug_cb_f)(jq_state*,jq_msg_cb*,void **);
typedef void (*jq_set_debug_cb_f)(jq_state*,jq_msg_cb,void *);
typedef void (*jq_get_input_cb_f)(jq_state*,jq_input_cb*,void **);
typedef void (*jq_set_input_cb_f)(jq_state*,jq_input_cb,void *);
typedef void (*jq_dump_disassembly_f)(jq_state*,int);
typedef jv (*jq_get_attr_f)(jq_state*,jv);
typedef jv (*jq_io_policy_check_f)(jq_state *, jv);
typedef jv (*jq_set_io_policy_f)(jq_state *, jv);
typedef void (*jq_set_attr_f)(jq_state*,jv,jv);
typedef void (*jq_set_attrs_f)(jq_state*,jv);
typedef jv (*jq_handle_register_scheme_f)(jq_state *, const char *, struct jq_io_table *);
typedef jv (*jq_handle_open_f)(jq_state *, jv);
typedef jv (*jq_handle_close_f)(jq_state *, jv);
typedef jv (*jq_handle_reset_f)(jq_state *, jv);
typedef jv (*jq_handle_io_f)(jq_state *, jv, jv, jv);
typedef jv (*jq_handle_at_eof_f)(jq_state *, jv);
typedef jv (*jq_get_lib_dirs_f)(jq_state*);
typedef jv (*jq_get_prog_origin_f)(jq_state*);
typedef jv (*jq_get_jq_origin_f)(jq_state*);
typedef int (*jq_compile_f)(jq_state*,const char*);
typedef int (*jq_compile_args_f)(jq_state*,const char*,jv);
typedef void (*jq_teardown_f)(jq_state**);
typedef void (*jq_start_f)(jq_state*,jv,int);
typedef void (*jq_get_error_cb_f)(jq_state*,jq_msg_cb*,void **);
typedef void (*jq_set_error_cb_f)(jq_state*,jq_msg_cb,void *);
typedef jq_state* (*jq_init_f)();
typedef jv (*jq_format_error_f)(jv);
typedef jv (*jq_next_f)(jq_state*);
typedef void (*jq_report_error_f)(jq_state*,jv);
typedef void * (*jv_mem_realloc_f)(void *,size_t);
typedef void (*jv_mem_free_f)(void *);
typedef char* (*jv_mem_strdup_unguarded_f)(const char*);
typedef char* (*jv_mem_strdup_f)(const char*);
typedef void * (*jv_mem_calloc_unguarded_f)(size_t,size_t);
typedef void * (*jv_mem_calloc_f)(size_t,size_t);
typedef void * (*jv_mem_alloc_unguarded_f)(size_t);
typedef void * (*jv_mem_alloc_f)(size_t);
typedef jv (*jv_group_f)(jv,jv);
typedef jv (*jv_sort_f)(jv,jv);
typedef int (*jv_cmp_f)(jv,jv);
typedef jv (*jv_keys_f)(jv);
typedef jv (*jv_keys_unsorted_f)(jv);
typedef jv (*jv_delpaths_f)(jv,jv);
typedef jv (*jv_getpath_f)(jv,jv);
typedef jv (*jv_setpath_f)(jv,jv,jv);
typedef jv (*jv_has_f)(jv,jv);
typedef jv (*jv_set_f)(jv,jv,jv);
typedef jv (*jv_get_f)(jv,jv);
typedef jv (*jv_load_file_f)(const char*,int);
typedef int (*jv_contains_f)(jv,jv);
typedef int (*jv_identical_f)(jv,jv);
typedef int (*jv_equal_f)(jv,jv);
typedef int (*jv_get_refcnt_f)(jv);
typedef void (*jv_free_f)(jv);
typedef jv (*jv_copy_f)(jv);
typedef jv (*jv_object_iter_value_f)(jv,int);
typedef jv (*jv_object_iter_key_f)(jv,int);
typedef int (*jv_object_iter_next_f)(jv,int);
typedef int (*jv_object_iter_f)(jv);
typedef int (*jv_object_iter_valid_f)(jv,int);
typedef jv (*jv_object_merge_recursive_f)(jv,jv);
typedef jv (*jv_object_merge_f)(jv,jv);
typedef int (*jv_object_length_f)(jv);
typedef jv (*jv_object_delete_f)(jv,jv);
typedef jv (*jv_object_set_f)(jv,jv,jv);
typedef int (*jv_object_has_f)(jv,jv);
typedef jv (*jv_object_get_f)(jv,jv);
typedef jv (*jv_object_f)();
typedef jv (*jv_string_fmt_f)(const char*,...);
typedef jv (*jv_string_vfmt_f)(const char*,va_list);
typedef jv (*jv_string_append_str_f)(jv,const char*);
typedef jv (*jv_string_append_codepoint_f)(jv,uint32_t);
typedef jv (*jv_string_append_buf_f)(jv,const char*,int);
typedef jv (*jv_string_concat_f)(jv,jv);
typedef jv (*jv_string_slice_f)(jv,int,int);
typedef const char* (*jv_string_value_f)(jv);
typedef long unsigned int (*jv_string_hash_f)(jv);
typedef jv (*jv_string_implode_f)(jv);
typedef jv (*jv_string_explode_f)(jv);
typedef jv (*jv_string_split_f)(jv,jv);
typedef jv (*jv_string_indexes_f)(jv,jv);
typedef int (*jv_string_length_codepoints_f)(jv);
typedef int (*jv_string_length_bytes_f)(jv);
typedef jv (*jv_string_f)(const char*);
typedef jv (*jv_string_empty_f)(int);
typedef jv (*jv_string_sized_f)(const char*,int);
typedef jv (*jv_array_indexes_f)(jv,jv);
typedef jv (*jv_array_slice_f)(jv,int,int);
typedef jv (*jv_array_concat_f)(jv,jv);
typedef jv (*jv_array_append_f)(jv,jv);
typedef jv (*jv_array_set_f)(jv,int,jv);
typedef jv (*jv_array_get_f)(jv,int);
typedef int (*jv_array_length_f)(jv);
typedef jv (*jv_array_f)();
typedef jv (*jv_array_sized_f)(int);
typedef int (*jv_is_integer_f)(jv);
typedef double (*jv_number_value_f)(jv);
typedef jv (*jv_number_f)(double);
typedef int (*jv_invalid_has_msg_f)(jv);
typedef jv (*jv_invalid_get_msg_f)(jv);
typedef jv (*jv_invalid_f)();
typedef jv (*jv_invalid_with_msg_f)(jv);
typedef jv (*jv_bool_f)(int);
typedef jv (*jv_null_f)();
typedef jv (*jv_false_f)();
typedef jv (*jv_true_f)();
typedef const char* (*jv_kind_name_f)(jv_kind);
typedef jv_kind (*jv_get_kind_f)(jv);
typedef jv (*jv_parse_f)(const char*);
typedef jv (*jv_parse_sized_f)(const char*,int);
typedef jv (*jv_parser_next_f)(jv_parser*);
typedef void (*jv_parser_set_buf_f)(jv_parser*,const char*,int,int);
typedef int (*jv_parser_remaining_f)(jv_parser*);
typedef void (*jv_parser_free_f)(jv_parser*);
typedef jv_parser* (*jv_parser_new_f)(int);
typedef char* (*jv_dump_string_trunc_f)(jv,char*,size_t);
typedef jv (*jv_dump_string_f)(jv,int);
typedef void (*jv_show_f)(jv,int);
typedef void (*jv_dump_f)(jv,int);
typedef void (*jv_dumpf_f)(jv,FILE*,int);
typedef int (*jq_set_colors_f)(const char*);
typedef jv (*jq_util_input_next_input_f)(jq_util_input_state*);
typedef jv (*jq_util_input_get_current_line_f)(jq_state*);
typedef jv (*jq_util_input_get_current_filename_f)(jq_state*);
typedef jv (*jq_util_input_get_position_f)(jq_state*);
typedef jv (*jq_util_input_next_input_cb_f)(jq_state*,void *);
typedef int (*jq_util_input_errors_f)(jq_util_input_state*);
typedef void (*jq_util_input_add_input_f)(jq_util_input_state*,const char*);
typedef void (*jq_util_input_free_f)(jq_util_input_state**);
typedef void (*jq_util_input_set_parser_f)(jq_util_input_state*,jv_parser*,int);
typedef jq_util_input_state* (*jq_util_input_init_f)(jq_util_msg_cb,void *);
typedef jv (*jq_realpath_f)(jv);
struct jq_plugin_vtable {
  jq_get_error_message_f jq_get_error_message;
  jq_get_exit_code_f jq_get_exit_code;
  jq_halted_f jq_halted;
  jq_finished_f jq_finished;
  jq_halt_f jq_halt;
  jq_get_debug_cb_f jq_get_debug_cb;
  jq_set_debug_cb_f jq_set_debug_cb;
  jq_get_input_cb_f jq_get_input_cb;
  jq_set_input_cb_f jq_set_input_cb;
  jq_dump_disassembly_f jq_dump_disassembly;
  jq_get_attr_f jq_get_attr;
  jq_set_attr_f jq_set_attr;
  jq_set_attrs_f jq_set_attrs;
  jq_get_lib_dirs_f jq_get_lib_dirs;
  jq_handle_register_scheme_f jq_handle_get_kind;
  jq_handle_open_f jq_handle_get;
  jq_handle_close_f jq_handle_close;
  jq_handle_reset_f jq_handle_reset;
  jq_handle_io_f jq_handle_write;
  jq_handle_at_eof_f jq_handle_read;
  jq_get_prog_origin_f jq_get_prog_origin;
  jq_get_jq_origin_f jq_get_jq_origin;
  jq_compile_f jq_compile;
  jq_compile_args_f jq_compile_args;
  jq_teardown_f jq_teardown;
  jq_start_f jq_start;
  jq_get_error_cb_f jq_get_error_cb;
  jq_set_error_cb_f jq_set_error_cb;
  jq_init_f jq_init;
  jq_format_error_f jq_format_error;
  jq_next_f jq_next;
  jq_report_error_f jq_report_error;
  jv_mem_realloc_f jv_mem_realloc;
  jv_mem_free_f jv_mem_free;
  jv_mem_strdup_unguarded_f jv_mem_strdup_unguarded;
  jv_mem_strdup_f jv_mem_strdup;
  jv_mem_calloc_unguarded_f jv_mem_calloc_unguarded;
  jv_mem_calloc_f jv_mem_calloc;
  jv_mem_alloc_unguarded_f jv_mem_alloc_unguarded;
  jv_mem_alloc_f jv_mem_alloc;
  jv_group_f jv_group;
  jv_sort_f jv_sort;
  jv_cmp_f jv_cmp;
  jv_keys_f jv_keys;
  jv_keys_unsorted_f jv_keys_unsorted;
  jv_delpaths_f jv_delpaths;
  jv_getpath_f jv_getpath;
  jv_setpath_f jv_setpath;
  jv_has_f jv_has;
  jv_set_f jv_set;
  jv_get_f jv_get;
  jv_load_file_f jv_load_file;
  jv_contains_f jv_contains;
  jv_identical_f jv_identical;
  jv_equal_f jv_equal;
  jv_get_refcnt_f jv_get_refcnt;
  jv_free_f jv_free;
  jv_copy_f jv_copy;
  jv_object_iter_value_f jv_object_iter_value;
  jv_object_iter_key_f jv_object_iter_key;
  jv_object_iter_next_f jv_object_iter_next;
  jv_object_iter_f jv_object_iter;
  jv_object_iter_valid_f jv_object_iter_valid;
  jv_object_merge_recursive_f jv_object_merge_recursive;
  jv_object_merge_f jv_object_merge;
  jv_object_length_f jv_object_length;
  jv_object_delete_f jv_object_delete;
  jv_object_set_f jv_object_set;
  jv_object_has_f jv_object_has;
  jv_object_get_f jv_object_get;
  jv_object_f jv_object;
  jv_string_fmt_f jv_string_fmt;
  jv_string_vfmt_f jv_string_vfmt;
  jv_string_append_str_f jv_string_append_str;
  jv_string_append_codepoint_f jv_string_append_codepoint;
  jv_string_append_buf_f jv_string_append_buf;
  jv_string_concat_f jv_string_concat;
  jv_string_slice_f jv_string_slice;
  jv_string_value_f jv_string_value;
  jv_string_hash_f jv_string_hash;
  jv_string_implode_f jv_string_implode;
  jv_string_explode_f jv_string_explode;
  jv_string_split_f jv_string_split;
  jv_string_indexes_f jv_string_indexes;
  jv_string_length_codepoints_f jv_string_length_codepoints;
  jv_string_length_bytes_f jv_string_length_bytes;
  jv_string_f jv_string;
  jv_string_empty_f jv_string_empty;
  jv_string_sized_f jv_string_sized;
  jv_array_indexes_f jv_array_indexes;
  jv_array_slice_f jv_array_slice;
  jv_array_concat_f jv_array_concat;
  jv_array_append_f jv_array_append;
  jv_array_set_f jv_array_set;
  jv_array_get_f jv_array_get;
  jv_array_length_f jv_array_length;
  jv_array_f jv_array;
  jv_array_sized_f jv_array_sized;
  jv_is_integer_f jv_is_integer;
  jv_number_value_f jv_number_value;
  jv_number_f jv_number;
  jv_invalid_has_msg_f jv_invalid_has_msg;
  jv_invalid_get_msg_f jv_invalid_get_msg;
  jv_invalid_f jv_invalid;
  jv_invalid_with_msg_f jv_invalid_with_msg;
  jv_bool_f jv_bool;
  jv_null_f jv_null;
  jv_false_f jv_false;
  jv_true_f jv_true;
  jv_kind_name_f jv_kind_name;
  jv_get_kind_f jv_get_kind;
  jv_parse_f jv_parse;
  jv_parse_sized_f jv_parse_sized;
  jv_parser_next_f jv_parser_next;
  jv_parser_set_buf_f jv_parser_set_buf;
  jv_parser_remaining_f jv_parser_remaining;
  jv_parser_free_f jv_parser_free;
  jv_parser_new_f jv_parser_new;
  jv_dump_string_trunc_f jv_dump_string_trunc;
  jv_dump_string_f jv_dump_string;
  jv_show_f jv_show;
  jv_dump_f jv_dump;
  jv_dumpf_f jv_dumpf;
  jq_set_colors_f jq_set_colors;
  jq_util_input_next_input_f jq_util_input_next_input;
  jq_util_input_get_current_line_f jq_util_input_get_current_line;
  jq_util_input_get_current_filename_f jq_util_input_get_current_filename;
  jq_util_input_get_position_f jq_util_input_get_position;
  jq_util_input_next_input_cb_f jq_util_input_next_input_cb;
  jq_util_input_errors_f jq_util_input_errors;
  jq_util_input_add_input_f jq_util_input_add_input;
  jq_util_input_free_f jq_util_input_free;
  jq_util_input_set_parser_f jq_util_input_set_parser;
  jq_util_input_init_f jq_util_input_init;
  jq_realpath_f jq_realpath;
  jq_set_io_policy_f jq_set_io_policy;
  jq_io_policy_check_f jq_io_policy_check;
};
#ifdef JQ_PLUGIN
#define jv_string_append_buf ((*(struct jq_plugin_vtable **)jq)->jv_string_append_buf)
#define jv_object_iter_next ((*(struct jq_plugin_vtable **)jq)->jv_object_iter_next)
#define jq_get_lib_dirs ((*(struct jq_plugin_vtable **)jq)->jq_get_lib_dirs)
#define jv_mem_free ((*(struct jq_plugin_vtable **)jq)->jv_mem_free)
#define jq_get_error_cb ((*(struct jq_plugin_vtable **)jq)->jq_get_error_cb)
#define jv_string_vfmt ((*(struct jq_plugin_vtable **)jq)->jv_string_vfmt)
#define jv_number_value ((*(struct jq_plugin_vtable **)jq)->jv_number_value)
#define jv_mem_alloc_unguarded ((*(struct jq_plugin_vtable **)jq)->jv_mem_alloc_unguarded)
#define jv_true ((*(struct jq_plugin_vtable **)jq)->jv_true)
#define jv_object_set ((*(struct jq_plugin_vtable **)jq)->jv_object_set)
#define jv_mem_calloc ((*(struct jq_plugin_vtable **)jq)->jv_mem_calloc)
#define jv_parser_next ((*(struct jq_plugin_vtable **)jq)->jv_parser_next)
#define jv_dump_string ((*(struct jq_plugin_vtable **)jq)->jv_dump_string)
#define jv_invalid_get_msg ((*(struct jq_plugin_vtable **)jq)->jv_invalid_get_msg)
#define jq_util_input_set_parser ((*(struct jq_plugin_vtable **)jq)->jq_util_input_set_parser)
#define jv_copy ((*(struct jq_plugin_vtable **)jq)->jv_copy)
#define jv_get ((*(struct jq_plugin_vtable **)jq)->jv_get)
#define jv_mem_calloc_unguarded ((*(struct jq_plugin_vtable **)jq)->jv_mem_calloc_unguarded)
#define jv_string_value ((*(struct jq_plugin_vtable **)jq)->jv_string_value)
#define jv_identical ((*(struct jq_plugin_vtable **)jq)->jv_identical)
#define jq_get_prog_origin ((*(struct jq_plugin_vtable **)jq)->jq_get_prog_origin)
#define jv_invalid_with_msg ((*(struct jq_plugin_vtable **)jq)->jv_invalid_with_msg)
#define jv_equal ((*(struct jq_plugin_vtable **)jq)->jv_equal)
#define jq_dump_disassembly ((*(struct jq_plugin_vtable **)jq)->jq_dump_disassembly)
#define jv_object_iter ((*(struct jq_plugin_vtable **)jq)->jv_object_iter)
#define jv_dump ((*(struct jq_plugin_vtable **)jq)->jv_dump)
#define jv_array_sized ((*(struct jq_plugin_vtable **)jq)->jv_array_sized)
#define jv_string_append_str ((*(struct jq_plugin_vtable **)jq)->jv_string_append_str)
#define jq_get_exit_code ((*(struct jq_plugin_vtable **)jq)->jq_get_exit_code)
#define jv_getpath ((*(struct jq_plugin_vtable **)jq)->jv_getpath)
#define jq_get_attr ((*(struct jq_plugin_vtable **)jq)->jq_get_attr)
#define jq_halted ((*(struct jq_plugin_vtable **)jq)->jq_halted)
#define jq_finished ((*(struct jq_plugin_vtable **)jq)->jq_finished)
#define jv_array_length ((*(struct jq_plugin_vtable **)jq)->jv_array_length)
#define jv_array_concat ((*(struct jq_plugin_vtable **)jq)->jv_array_concat)
#define jv_string_implode ((*(struct jq_plugin_vtable **)jq)->jv_string_implode)
#define jv_string_explode ((*(struct jq_plugin_vtable **)jq)->jv_string_explode)
#define jq_start ((*(struct jq_plugin_vtable **)jq)->jq_start)
#define jq_teardown ((*(struct jq_plugin_vtable **)jq)->jq_teardown)
#define jv_parser_remaining ((*(struct jq_plugin_vtable **)jq)->jv_parser_remaining)
#define jq_util_input_get_position ((*(struct jq_plugin_vtable **)jq)->jq_util_input_get_position)
#define jv_group ((*(struct jq_plugin_vtable **)jq)->jv_group)
#define jv_false ((*(struct jq_plugin_vtable **)jq)->jv_false)
#define jv_string_fmt ((*(struct jq_plugin_vtable **)jq)->jv_string_fmt)
#define jq_set_input_cb ((*(struct jq_plugin_vtable **)jq)->jq_set_input_cb)
#define jq_util_input_init ((*(struct jq_plugin_vtable **)jq)->jq_util_input_init)
#define jv_null ((*(struct jq_plugin_vtable **)jq)->jv_null)
#define jv_setpath ((*(struct jq_plugin_vtable **)jq)->jv_setpath)
#define jv_string_split ((*(struct jq_plugin_vtable **)jq)->jv_string_split)
#define jv_set ((*(struct jq_plugin_vtable **)jq)->jv_set)
#define jv_mem_strdup_unguarded ((*(struct jq_plugin_vtable **)jq)->jv_mem_strdup_unguarded)
#define jq_get_jq_origin ((*(struct jq_plugin_vtable **)jq)->jq_get_jq_origin)
#define jq_halt ((*(struct jq_plugin_vtable **)jq)->jq_halt)
#define jv_show ((*(struct jq_plugin_vtable **)jq)->jv_show)
#define jq_init ((*(struct jq_plugin_vtable **)jq)->jq_init)
#define jv_kind_name ((*(struct jq_plugin_vtable **)jq)->jv_kind_name)
#define jv_string_append_codepoint ((*(struct jq_plugin_vtable **)jq)->jv_string_append_codepoint)
#define jq_get_error_message ((*(struct jq_plugin_vtable **)jq)->jq_get_error_message)
#define jv_array_get ((*(struct jq_plugin_vtable **)jq)->jv_array_get)
#define jv_object_merge ((*(struct jq_plugin_vtable **)jq)->jv_object_merge)
#define jq_compile_args ((*(struct jq_plugin_vtable **)jq)->jq_compile_args)
#define jq_util_input_next_input ((*(struct jq_plugin_vtable **)jq)->jq_util_input_next_input)
#define jv_dump_string_trunc ((*(struct jq_plugin_vtable **)jq)->jv_dump_string_trunc)
#define jq_next ((*(struct jq_plugin_vtable **)jq)->jq_next)
#define jv_parse_sized ((*(struct jq_plugin_vtable **)jq)->jv_parse_sized)
#define jv_cmp ((*(struct jq_plugin_vtable **)jq)->jv_cmp)
#define jv_number ((*(struct jq_plugin_vtable **)jq)->jv_number)
#define jv_dumpf ((*(struct jq_plugin_vtable **)jq)->jv_dumpf)
#define jv_object_get ((*(struct jq_plugin_vtable **)jq)->jv_object_get)
#define jv_parse ((*(struct jq_plugin_vtable **)jq)->jv_parse)
#define jq_io_policy_check ((*(struct jq_plugin_vtable **)jq)->jq_io_policy_check)
#define jq_set_io_policy ((*(struct jq_plugin_vtable **)jq)->jq_set_io_policy)
#define jq_set_attr ((*(struct jq_plugin_vtable **)jq)->jq_set_attr)
#define jq_util_input_get_current_line ((*(struct jq_plugin_vtable **)jq)->jq_util_input_get_current_line)
#define jv_parser_new ((*(struct jq_plugin_vtable **)jq)->jv_parser_new)
#define jv_object_iter_value ((*(struct jq_plugin_vtable **)jq)->jv_object_iter_value)
#define jv_invalid_has_msg ((*(struct jq_plugin_vtable **)jq)->jv_invalid_has_msg)
#define jv_string_length_bytes ((*(struct jq_plugin_vtable **)jq)->jv_string_length_bytes)
#define jv_object_iter_key ((*(struct jq_plugin_vtable **)jq)->jv_object_iter_key)
#define jq_report_error ((*(struct jq_plugin_vtable **)jq)->jq_report_error)
#define jv_is_integer ((*(struct jq_plugin_vtable **)jq)->jv_is_integer)
#define jv_string ((*(struct jq_plugin_vtable **)jq)->jv_string)
#define jv_contains ((*(struct jq_plugin_vtable **)jq)->jv_contains)
#define jv_mem_alloc ((*(struct jq_plugin_vtable **)jq)->jv_mem_alloc)
#define jv_string_hash ((*(struct jq_plugin_vtable **)jq)->jv_string_hash)
#define jv_string_slice ((*(struct jq_plugin_vtable **)jq)->jv_string_slice)
#define jv_load_file ((*(struct jq_plugin_vtable **)jq)->jv_load_file)
#define jq_compile ((*(struct jq_plugin_vtable **)jq)->jq_compile)
#define jv_get_kind ((*(struct jq_plugin_vtable **)jq)->jv_get_kind)
#define jv_object_merge_recursive ((*(struct jq_plugin_vtable **)jq)->jv_object_merge_recursive)
#define jv_bool ((*(struct jq_plugin_vtable **)jq)->jv_bool)
#define jq_util_input_get_current_filename ((*(struct jq_plugin_vtable **)jq)->jq_util_input_get_current_filename)
#define jv_object_iter_valid ((*(struct jq_plugin_vtable **)jq)->jv_object_iter_valid)
#define jv_has ((*(struct jq_plugin_vtable **)jq)->jv_has)
#define jv_array_set ((*(struct jq_plugin_vtable **)jq)->jv_array_set)
#define jv_object_delete ((*(struct jq_plugin_vtable **)jq)->jv_object_delete)
#define jq_set_debug_cb ((*(struct jq_plugin_vtable **)jq)->jq_set_debug_cb)
#define jv_string_empty ((*(struct jq_plugin_vtable **)jq)->jv_string_empty)
#define jq_realpath ((*(struct jq_plugin_vtable **)jq)->jq_realpath)
#define jq_set_error_cb ((*(struct jq_plugin_vtable **)jq)->jq_set_error_cb)
#define jq_util_input_next_input_cb ((*(struct jq_plugin_vtable **)jq)->jq_util_input_next_input_cb)
#define jv_get_refcnt ((*(struct jq_plugin_vtable **)jq)->jv_get_refcnt)
#define jq_set_colors ((*(struct jq_plugin_vtable **)jq)->jq_set_colors)
#define jv_array_slice ((*(struct jq_plugin_vtable **)jq)->jv_array_slice)
#define jv_mem_realloc ((*(struct jq_plugin_vtable **)jq)->jv_mem_realloc)
#define jv_array ((*(struct jq_plugin_vtable **)jq)->jv_array)
#define jv_parser_set_buf ((*(struct jq_plugin_vtable **)jq)->jv_parser_set_buf)
#define jv_keys_unsorted ((*(struct jq_plugin_vtable **)jq)->jv_keys_unsorted)
#define jv_delpaths ((*(struct jq_plugin_vtable **)jq)->jv_delpaths)
#define jv_sort ((*(struct jq_plugin_vtable **)jq)->jv_sort)
#define jv_parser_free ((*(struct jq_plugin_vtable **)jq)->jv_parser_free)
#define jv_array_indexes ((*(struct jq_plugin_vtable **)jq)->jv_array_indexes)
#define jv_string_concat ((*(struct jq_plugin_vtable **)jq)->jv_string_concat)
#define jv_object_has ((*(struct jq_plugin_vtable **)jq)->jv_object_has)
#define jv_invalid ((*(struct jq_plugin_vtable **)jq)->jv_invalid)
#define jq_util_input_free ((*(struct jq_plugin_vtable **)jq)->jq_util_input_free)
#define jv_object_length ((*(struct jq_plugin_vtable **)jq)->jv_object_length)
#define jq_get_input_cb ((*(struct jq_plugin_vtable **)jq)->jq_get_input_cb)
#define jv_string_sized ((*(struct jq_plugin_vtable **)jq)->jv_string_sized)
#define jv_string_length_codepoints ((*(struct jq_plugin_vtable **)jq)->jv_string_length_codepoints)
#define jq_format_error ((*(struct jq_plugin_vtable **)jq)->jq_format_error)
#define jv_array_append ((*(struct jq_plugin_vtable **)jq)->jv_array_append)
#define jv_string_indexes ((*(struct jq_plugin_vtable **)jq)->jv_string_indexes)
#define jv_free ((*(struct jq_plugin_vtable **)jq)->jv_free)
#define jq_get_debug_cb ((*(struct jq_plugin_vtable **)jq)->jq_get_debug_cb)
#define jq_util_input_errors ((*(struct jq_plugin_vtable **)jq)->jq_util_input_errors)
#define jv_mem_strdup ((*(struct jq_plugin_vtable **)jq)->jv_mem_strdup)
#define jq_util_input_add_input ((*(struct jq_plugin_vtable **)jq)->jq_util_input_add_input)
#define jv_object ((*(struct jq_plugin_vtable **)jq)->jv_object)
#define jv_keys ((*(struct jq_plugin_vtable **)jq)->jv_keys)
#define jq_set_attrs ((*(struct jq_plugin_vtable **)jq)->jq_set_attrs)
#define jq_handle_register_scheme ((*(struct jq_plugin_vtable **)jq)->jq_handle_register_scheme)
#define jq_handle_open ((*(struct jq_plugin_vtable **)jq)->jq_handle_open)
#define jq_handle_close ((*(struct jq_plugin_vtable **)jq)->jq_handle_close)
#define jq_handle_reset ((*(struct jq_plugin_vtable **)jq)->jq_handle_reset)
#define jq_handle_io ((*(struct jq_plugin_vtable **)jq)->jq_handle_io)
#define jq_handle_at_eof ((*(struct jq_plugin_vtable **)jq)->jq_handle_at_eof)
#endif /* JQ_PLUGIN */
/* GENERATED BY dwarf2h END */

typedef int (*jq_plugin_init_f)
                  (int,                       /* jq plugin min supported ABI version */
                   int,                       /* jq plugin current       ABI version */
                   struct jq_state *,
                   const char **,             /* error string */
                   const char **,             /* jq-coded module contents */
                   size_t *,                  /* jq-coded module contents size */
                   struct cfunction **,       /* array of C-coded function descriptors */
                   size_t *);

/*
 * jq ABI identifiers.
 *
 * There are two: one for minimum supported ABI, the other for the current
 * (max) ABI supported.
 *
 * These are constructed as MAJOR x 10,000 + MINOR x 100 + MICRO.
 */
#define JQ_CURRENT_ABI  10700 /* 1.7.0 */
#define JQ_MIN_ABI      10700 /* 1.7.0 */
#define JQ_MAX_ABI      JQ_CURRENT_ABI

#define JQ_BUILTIN_INIT_FUN(n, c, ...)                                  \
    static int n (int minabi, int maxabi, jq_state *jq, const char **e, \
                  const char **contents, size_t *contents_sz,           \
                  struct cfunction **cfuncs, size_t *ncfuncs) {         \
      static struct cfunction f[] = {                                   \
        __VA_ARGS__                                                     \
      };                                                                \
      if ((minabi) > JQ_CURRENT_ABI || (maxabi) < JQ_CURRENT_ABI)       \
        return (*e = "JQ ABI mismatch"), -1;                            \
      *e = NULL; *contents = (c); *contents_sz = 0;                     \
      *cfuncs = f; *ncfuncs = sizeof(f) / sizeof(f[0]);                 \
      return 0;                                                         \
    }

#endif /* JQ_PLUGIN_H */
