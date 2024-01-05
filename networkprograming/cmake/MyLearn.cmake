message("=======================MyLearn.cmake Content Output Information Start==============================")
# 命令FILE相关操作
set(FILE_WORKSPACE_DIR ${CMAKE_SOURCE_DIR}/tempworkspace)

# 判断文件是否存在
# 读取文件
if (EXISTS ${FILE_WORKSPACE_DIR}/read.txt)
    FILE(READ ${FILE_WORKSPACE_DIR}/read.txt file_read_content)
    message("file ${FILE_WORKSPACE_DIR}/read.txt content is: \n")
    message(${file_read_content})
ELSE ()
    message("file ${FILE_WORKSPACE_DIR}/read.txt is not exists.\n")
ENDIF ()

# 写入文件
# 清空写入 WRITE
# 追加写入 APPEND
FILE(WRITE ${FILE_WORKSPACE_DIR}/write.txt ${file_read_content})
FILE(APPEND ${FILE_WORKSPACE_DIR}/write.txt "追加写入")

# 复制文件
FILE(COPY ${FILE_WORKSPACE_DIR}/write.txt DESTINATION ${FILE_WORKSPACE_DIR}/copy)

# 重命名文件
FILE(RENAME ${FILE_WORKSPACE_DIR}/copy/write.txt ${FILE_WORKSPACE_DIR}/copy/write.txt.bak)

# 删除文件
FILE(WRITE ${FILE_WORKSPACE_DIR}/del.txt "this is null")
FILE(REMOVE ${FILE_WORKSPACE_DIR}/del.txt)

# 创建目录
FILE(MAKE_DIRECTORY ${FILE_WORKSPACE_DIR}/abc)

# 修改文件权限
# FILE(CHMOD 644 ${FILE_WORKSPACE_DIR}/read.txt)

# MATCHES 正则匹配
IF ("Hello world 123" MATCHES ".*[0-9].*")
    message("字符串包含数字")
ENDIF ()

# 执行外部程序
# 例如执行统计指定目录存储空间
# du -sh .
# 注意 COMMAND 命令后面不能使用""将命令包含 否则会报错
execute_process(
        COMMAND du -sh ${FILE_WORKSPACE_DIR}
        WORKING_DIRECTORY ${FILE_WORKSPACE_DIR}
        TIMEOUT 3
        RESULT_VARIABLE use_space
        OUTPUT_VARIABLE space_out
)
message("目录: ${FILE_WORKSPACE_DIR} 空间占用: \n")
message(${space_out})

# 定义键值对变量
SET(
        PERSON_INFO
        Name "宋晓奎"
        AGE 18
        Address "中国"
        Work "程序员"
)

# 展开后 可以给指定对象配置值

# 函数定义
FUNCTION(sayHello)
    message("hello world")
ENDFUNCTION()

# 函数调用
sayHello()

FUNCTION(add opt a1 a2)
    MATH(EXPR result "${a1} ${opt} ${a2}")
    message("${a1} ${opt} ${a2} = ${result}")
ENDFUNCTION()

add("*" 1 2)
# 定义普通变量
# 定义列表变量
message("=======================MyLearn.cmake Content Output Information End==============================")