## Linux

Q: 在Linux中，如何kill process?

	ps -e | grep “processName/processPart”
	kill processId

Q: find [path] [option] [expression]

	find . -print
	find ./subFolder/

	find ./subFolder/ -name "*.cpp"
	find ./subFolder/ -iname "*.cPP"		//忽略大小写
	find ./subFolder/ -maxdepth 2 -name "*.cpp"	//最多只查找2层内的子目录
	find ./subFolder/ -mindepth 2 -name "*.cpp"	//至少到达第2层子目录才开始查找文件
	find ./subFolder/ -not -name "*.cpp"	//反向查找
	find ./subFolder/ ! -name "*.cpp"
	find ./subFolder -name "st*" ! -name "*.cpp"	//多个查找条件
	find ./subFolder -name "st*" -o -name "*.cpp"	//OR操作符
	find ./subFolder -type f -name "st*"			//只查找文件， d只查找目录
	find ./subFolder1 ./subFolder2 -type f -name "st*"	//同时查找多个路径
	find ./subFolder -type f -name ".*"		//查找隐藏文件
	find ./subFolder -type f ! -perm 0777	//按权限查找
	find ./subFolder -maxdepth 1 -perm /u=r 2>/dev/null //x, s，清除输出中的错误信息
	find ./subFolder  -user ingookey -name '*.php'		// 查找属于ingookey用户的文件
	find ./subFolder -group ingoos	//查找属于特定用户组的文件
	
	stat ~/.bashrc	// stat可查看文件的atime, ctime, mtime
	chmod 777 fileName or directoryName	//0421
	find / -mtime +50 -mtime -100	//时间段内被修改的文件,ctime, mtime, atime
	find / -atime +50 -atime -100	//时间段内被访问的文件,50天之前，100之内
	find / -cmin -60	//状态发生改变折文件，cmin 改变， mmin 修改， amin访问，60分钟之内
	find / -size +50M -size -100M   //按文件大小查找
	find ./tes/ -size +5k -exec cp '{}' ./Desktop/ \;
	find / -type f -exec ls -s {} \; | sort -n -r | head 5
	find / -exec ls -ld {} \;
	find / -type f -name "*.cpp" -exec rm -f {} \; // -ok rm -f {} \; more security way
	find / -type d -name "dir*" -exec rm -rf {} \;
	find / -type f -empty			//查找空文件，d 空目录



Q: diff

	diff [-wV] [-n<文件名长度>] [-p<文件名长度>]
	根据diff的比较结果，显示统计数字
	-w	控制输出栏位的宽度
	-V  version
	
	diff tes/tes1.doc tes/tes2.doc | diffstat	// 进行比较结果的统计显示
	cat tes/tes1.doc		// 查看文件中的内容


Q: gitview [-bchilv][文件] 

	补充说明：gitview指令可用于观看文件的内容，它会同时显示十六进制和ASCII格式的字码。
	
	参数：
	  -b 　单色模式，不使用ANSI控制码显示彩色。 
	  -c 　彩色模式，使用ANSI控制码显示色彩。 
	  -h 　在线帮助。 
	  -i 　显示存放gitview程序的所在位置。 
	  -l 　不使用先前的显示字符。 
	  -v 　显示版本信息。
  
Q: file [-beLvz][-f <名称文件>][-m <魔法数字文件>...][文件或目录...]

	Linux file命令用于辨识文件类型。
	参数：
	-b 　列出辨识结果时，不显示文件名称。
	-c 　详细显示指令执行过程，便于排错或分析程序执行的情形。
	-f<名称文件> 　指定名称文件，其内容有一个或多个文件名称呢感，让file依序辨识这些文件，格式为每列一个文件名称。
	-L 　直接显示符号连接所指向的文件的类别。
	-m<魔法数字文件> 　指定魔法数字文件。
	-v 　显示版本信息。
	-z 　尝试去解读压缩文件的内容。
	[文件或目录...] 要确定类型的文件列表，多个文件之间使用空格分开，可以使用shell通配符匹配多个文件。


----------
## Git
Git
Diff
diff file.1 file.2 -y 	// -y 并排展示, -c 横排展示
diff3 

Q: git config

	vi ~/.gitconfig
	ssh-keygen -C "Ingookey@gmail.com" -t rsa
	git config --global user.email Ingookey@gmail.com
	git config --global user.name "Ingookey"
	git config --global diff.tool bc3  //bc3, meld, araxis, emerge...
	git config --global difftool.bc3.path "S:/Programs/Beyond\ Compare\ 4/BCompare.exe"

Q: git并强制覆盖本地修改?

	git reset --hard
	git pull

Q: 如果Fork别人的项目或者多人合作项目，最好每人都拥有一个独立分支，然后由项目维护人合并，如何建立自己的分支？

	git branch yourbranch 		// 分支的创建和合并
	git checkout yourbranch    	// 切换到yourbranch
 
	开发yourbranch分支，然后开发之后与master分支合并
	git checkout master
	git merge yourbranch
	git branch -d yourbranch    // 合并完后删除本地分支

Q: 如何将牛人的远程分支更新到自己的本地分支？

	git remote						// 查看当前项目下远程
	git remote add niuren giturl	// 增加新的分支链接，例如
	git fetch niuren				// 获取牛人的远程更新
	git merge niuren/master			// 将牛人的远程更新合并到本地分支

Q: Git tools

1. git@github.com:trybeee/GitStats.git
	
	统计自己的每个项目的工作量，从而看到工作进展

	- git clone git://github.com/trybeee/GitStats.git
	- python ~/dev/gitstats/git-stats /youproject public
