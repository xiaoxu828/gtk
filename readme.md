这是一个学习gtk,以及依托GTK制作小工具的code

## 1.cJSON是处理json格式开源库


/*

  Copyright (c) 2009 Dave Gamble

  Permission is hereby granted, free of charge, to any person obtaining a copy

  of this software and associated documentation files (the "Software"), to deal

  in the Software without restriction, including without limitation the rights

  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

  copies of the Software, and to permit persons to whom the Software is

  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in

  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN

  THE SOFTWARE.

*/

## dictionary/iniparser是一个读取配置文件的功能


/*-------------------------------------------------------------------------*/

/**

   @author  N. Devillard

*/

## mylog是一个自己实现的日志库

功能：打印日志，自动插入日期，时间，基于GIOChannel通道实现

1.my_log_creat；

2.gbooleanmy_log_write；

3.my_log_close

## mymalloc是一个基于glib实现的内存泄漏检测工具

1.重定义malloc函数

```
#define malloc(siz) MY_malloc(__FILE__,__FUNCTION__,"teset",__LINE__ , siz)
#define free(d) MY_free( d)
```

2.使用malloc函数申请内存

3.使用free函数释放内存

4.打印所有没被释放的内存 `free_print(prin);`

5.关闭组件功能 `MY_malloc_close();`
