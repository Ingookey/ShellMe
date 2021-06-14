
# 查找当前目录下所有.c文件，返回值给src
src=$(wildcard ./*.c)
# 替换所有.c文件为.o文件
obj=$(patsubst ./%.c, ./%.o, $(src))

# $< :规则中的第一个依赖  $@：规则中的目标  $^：规则中所有的依赖
target=main
CC=gcc
$(target):$(obj)
		$(CC) $^ -o $@

%.o:%.c
		$(CC) -c $< -o $@

.PHONY:clean
clean:
		rm *.o -f
		rm main.exe -f