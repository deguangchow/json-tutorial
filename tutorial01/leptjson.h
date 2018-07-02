///    Copyright (C) 2018 DG.C, DGCHOW, deguangchow
///        deguangchow@qq.com
///
///    \brief    json-tutorial01：lept_json解析whitespace、null、true、false.
///
///    \author   deguangchow
///    \version  1.0
///    \2018/07/02
#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    lept_type type;
}lept_value;

typedef enum {
    LEPT_PARSE_OK = 0,              //解析成功
    LEPT_PARSE_EXPECT_VALUE,        //期望值：非 “json 关键字”，但是期望范围内的值。e.g.：' '、'\0'、'\t'、'\r'、'\n'
    LEPT_PARSE_INVALID_VALUE,       //非法值：非 “json 关键字” 和 “期望值” 的值。
    LEPT_PARSE_ROOT_NOT_SINGULAR    //除期望值外还有其他非 “whitespace” 字符
} lept_parse_ret;                   //lept_json 解析返回值

//lept_json parse the key words of json：whitespace、null、true、false.
int lept_parse(lept_value* v, const char* json);

//get lept_type of the lept_value`s json string.
lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
