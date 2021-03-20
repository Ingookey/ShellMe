# awk -f marks.awk marks.txt
#{
#	print $3 "\t" $4
#}

# awk '/a/ {print $1}' marks.txt

# awk '/a/{cnt++} END{print "count:", cnt}' marks.txt //统计匹配模式的行数
# awk  -F ":" '{print $1}' /etc/passwd   #以":"为分隔符打印/etc/passwd文件的第一例内容
:'
	# awk内置的变量
	ARGC 	命令行参数个数
	CONVFMT 数字的约定格式, 默认值是%.6g
	ENVIRON 环境变量
	FILENAME 当前文件名
	FS 输入字段的分隔符
	NF 字段数目
	NR 行号
	FNR 行号（相对当前文件）
	# awk 'BEGIN{print "var : ", OFMT}'	//OFMT 输出格式数字
	OFS 输出字段分隔符
	ORS 输出行分隔符

BEGIN{
	print "args num: ", ARGC
}
{}
END{
	for(i=0; i < ARGC-1; i++)
		printf "ARGV[%d] = %s\n", i, ARGV[i]
}
'

{
	print
}